#include <Wire.h>
#include <SPI.h>
#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <ArduCAM.h>
#include <ESP32Servo.h>
#include "webpage.h"

Servo SolarServo1;
Servo SolarServo2;
int servoPin1 = 13;
int servoPin2 = 12;

int servo_y = 180;
int servo_x = 180;
const int CS = 5;

// WiFi Settings for WiFi Mode
const char* wifi_ssid = "Shahomie's Spot";
const char* wifi_password = "Kevo_360_Hot Spot";

// Access Point Settings for AP Mode
const char* ap_ssid = "SunnySideUpgrades_ESP32";
const char* ap_password = "solar_shimmey";

// Define dummy credentials for demonstration purposes
const String adminUsername = "admin";
const String adminPassword = "password";

// Configure IP addresses of the local access point
IPAddress local_IP(192,168,1,22);
IPAddress gateway(192,168,1,5);
IPAddress subnet(255,255,255,0);

WebServer server(80);
ArduCAM myCAM(OV2640, CS);

static const size_t bufferSize = 4096;
static uint8_t buffer[bufferSize] = {0xFF};
uint8_t temp = 0, temp_last = 0;
int i = 0;
bool is_header = false;

float getBatteryPercentage() {
  return 75.0; // Example percentage
}

void handleRoot(){
  server.send_P(200,"text/html",PAGE_MAIN);
}

void handleUpdateCoordinates() {
    if (server.hasArg("x") && server.hasArg("y")) {
        int x = server.arg("x").toInt();
        int y = server.arg("y").toInt();

        Serial.print("Received X coordinate: ");
        Serial.println(x);
        Serial.print("Received Y coordinate: ");
        Serial.println(y);

        // Assuming a resolution of 480x640 for the image
        int xRegions = 10; // Number of horizontal regions
        int yRegions = 10; // Number of vertical regions
        int xStep = 640 / xRegions;
        int yStep = 480 / yRegions;

        // Calculate the region index
        int regionX = x / xStep;
        int regionY = y / yStep;

        // Calculate the overall region number (0 to 99)
        int region = regionY * xRegions + regionX;

        // Print the region number to the serial monitor
        Serial.print("Region number: ");
        Serial.println(region);

        // You'll need to define how you want to map regions to servo positions
        // Here's an example for a simple linear mapping
        int servo_x = map(regionX, 30, xRegions - 1, 0, 150);
        int servo_y = map(regionY, 30, yRegions - 1, 0, 150);

        Serial.print("Writing servo_x: ");
        Serial.println(servo_x);
        Serial.print("Writing servo_y: ");
        Serial.println(servo_y);

        // Write the servo positions
        SolarServo1.write(servo_y);
        SolarServo2.write(servo_x);

        server.send(200, "text/plain", "Coordinates updated");
    } else {
        server.send(400, "text/plain", "Missing data");
    }
}
void start_capture(){
  myCAM.clear_fifo_flag();
  myCAM.start_capture();
}

void camCapture(ArduCAM myCAM){
WiFiClient client = server.client();
uint32_t len  = myCAM.read_fifo_length();
if (len >= MAX_FIFO_SIZE) //8M
{
  Serial.println(F("Over size."));
}
if (len == 0 ) //0 kb
{
  Serial.println(F("Size is 0."));
}
myCAM.CS_LOW();
myCAM.set_fifo_burst(); 
if (!client.connected()) return;
String response = "HTTP/1.1 200 OK\r\n";
response += "Content-Type: image/jpeg\r\n";
response += "Content-len: " + String(len) + "\r\n\r\n";
server.sendContent(response);
i = 0;
while ( len-- )
{
temp_last = temp;
temp =  SPI.transfer(0x00);
//Read JPEG data from FIFO
if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
{
buffer[i++] = temp;  //save the last  0XD9     
//Write the remain bytes in the buffer
if (!client.connected()) break;
client.write(&buffer[0], i);
is_header = false;
i = 0;
myCAM.CS_HIGH();
break; 
}  
if (is_header == true)
{ 
//Write image data to buffer if not full
if (i < bufferSize)
buffer[i++] = temp;
else
{
//Write bufferSize bytes image data to file
if (!client.connected()) break;
client.write(&buffer[0], bufferSize);
i = 0;
buffer[i++] = temp;
}        
}
else if ((temp == 0xD8) & (temp_last == 0xFF))
{
is_header = true;
buffer[i++] = temp_last;
buffer[i++] = temp;   
} 
} 
}

void serverCapture(){
  // double check if delay is necessary
  //delay(1000);
start_capture();

int total_time = 0;

total_time = millis();
while (!myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));
total_time = millis() - total_time;
//Serial.print(F("capture total_time used (in miliseconds):"));
Serial.println(total_time, DEC);

total_time = 0;

Serial.println(F("CAM Capture Done."));
total_time = millis();
camCapture(myCAM);
total_time = millis() - total_time;
Serial.print(F("send total_time used (in miliseconds):"));
Serial.println(total_time, DEC);
Serial.println(F("CAM send Done."));
}

void serverStream(){
WiFiClient client = server.client();

String response = "HTTP/1.1 200 OK\r\n";
response += "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n\r\n";
server.sendContent(response);

while (1){
start_capture();
while (!myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));
size_t len = myCAM.read_fifo_length();
if (len >= MAX_FIFO_SIZE) //8M
{
Serial.println(F("Over size."));
continue;
}
if (len == 0 ) //0 kb
{
Serial.println(F("Size is 0."));
continue;
} 
myCAM.CS_LOW();
myCAM.set_fifo_burst();
if (!client.connected()) break;
response = "--frame\r\n";
response += "Content-Type: image/jpeg\r\n\r\n";
server.sendContent(response); 
while ( len-- )
{
temp_last = temp;
temp =  SPI.transfer(0x00);

//Read JPEG data from FIFO
if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
{
buffer[i++] = temp;  //save the last  0XD9     
//Write the remain bytes in the buffer
myCAM.CS_HIGH();; 
if (!client.connected()) break;
client.write(&buffer[0], i);
is_header = false;
i = 0;
}  
if (is_header == true)
{ 
//Write image data to buffer if not full
if (i < bufferSize)
buffer[i++] = temp;
else
{
//Write bufferSize bytes image data to file
myCAM.CS_HIGH(); 
if (!client.connected()) break;
client.write(&buffer[0], bufferSize);
i = 0;
buffer[i++] = temp;
myCAM.CS_LOW();
myCAM.set_fifo_burst();
}        
}
else if ((temp == 0xD8) & (temp_last == 0xFF))
{
is_header = true;
buffer[i++] = temp_last;
buffer[i++] = temp;   
} 
}
if (!client.connected()) break;
}
}

void handleNotFound(){
String message = "Server is running!\n\n";
message += "URI: ";
message += server.uri();
message += "\nMethod: ";
message += (server.method() == HTTP_GET)?"GET":"POST";
message += "\nArguments: ";
message += server.args();
message += "\n";
server.send(200, "text/plain", message);
}

// Need to create/add a url location for dashboard now
void handleLogin() {
    if (server.hasArg("username") && server.hasArg("password")) {
        String username = server.arg("username");
        String password = server.arg("password");

        if (username == adminUsername && password == adminPassword) {
            // Credentials are correct
            Serial.println("Login successful");

            // Redirect to the dashboard or send user data
            // For now, we just send a simple text response
            server.send(200, "text/plain", "Login successful. Welcome to the dashboard!");

            // For a real application, you might redirect the user to another page
            // server.sendHeader("Location", "/dashboard");
            // server.send(302, "text/plain", ""); // HTTP status code 302: Found (Redirection)
        } else {
            // Credentials are incorrect
            Serial.println("Login failed");
            server.send(401, "text/plain", "Login failed. Invalid username or password.");
        }
    } else {
        server.send(400, "text/plain", "Login failed. Missing username or password.");
    }
}


void setup() {
  pinMode(34, ANALOG);
  analogReadResolution(12);
  Serial.begin(115200);
//*
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //*/
/*
  Serial.print("Setting up Access Point ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.print("Starting Access Point ... ");
  Serial.println(WiFi.softAP(ap_ssid, ap_password) ? "Ready" : "Failed!");
  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());
//*/
Serial.println("");
Serial.println("WiFi connected.");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
SolarServo1.attach(servoPin1);
SolarServo1.write(servo_y);

SolarServo2.attach(servoPin2);
SolarServo2.write(servo_y);
uint8_t vid, pid;
uint8_t temp;
pinMode(CS, OUTPUT);

// I2C START SDA, SCL
Wire.begin(21, 22);

// Initialize SPI: SCK, MISO, MOSI, SS
SPI.begin(18, 19, 23, 5);
SPI.setFrequency(4000000); //4MHz

// Check if the ArduCAM SPI bus is OK
myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
temp = myCAM.read_reg(ARDUCHIP_TEST1);
if (temp != 0x55) {
    Serial.println(F("SPI1 interface Error!"));
    while(1);
}

//Check if the camera module type is OV2640
myCAM.wrSensorReg8_8(0xff, 0x01);
myCAM.rdSensorReg8_8(OV2640_CHIPID_HIGH, &vid);
myCAM.rdSensorReg8_8(OV2640_CHIPID_LOW, &pid);
if ((vid != 0x26 ) && (( pid != 0x41 ) || ( pid != 0x42 )))
Serial.println(F("Can't find OV2640 module!"));
else
Serial.println(F("OV2640 detected."));


//Change to JPEG capture mode and initialize the OV2640 module
myCAM.set_format(JPEG);
myCAM.InitCAM();

myCAM.OV2640_set_JPEG_size(OV2640_640x480);
myCAM.clear_fifo_flag();

    // Start the server
    server.on("/",handleRoot);
    server.on("/capture", HTTP_GET, serverCapture);
    server.on("/stream", HTTP_GET, serverStream);
    server.on("/update_coordinates", HTTP_POST, handleUpdateCoordinates);
    server.onNotFound(handleNotFound);
      server.on("/battery", HTTP_GET, []() {
    float averageVoltage = getBatteryPercentage(); // Implement this function based on your setup
    server.send(200, "text/plain", String(averageVoltage));
  });
    server.onNotFound([]() {
    server.send(404, "text/plain", "404: Not found");
  });
    server.begin();
    Serial.println(F("Server started"));
  
    // Add login route
    server.on("/login", HTTP_POST, handleLogin);
  
}


unsigned long previousMillis = 0; // Stores the last time the average was output
const long interval = 1000; // Interval at which to attempt reading the average (milliseconds)

// Variables for handling the averaging process
const int readingsToCollect = 500;
int readingsCount = 0;
long readingsSum = 0;


void loop() {
  server.handleClient();
  
  if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n');
        command.trim();

        if (command.startsWith("X")) {
            int angle = command.substring(1).toInt();
            if (angle >= 0 && angle <= 180) {
                servo_x = angle;
                SolarServo2.write(servo_x);
                Serial.print("Servo X set to: ");
                Serial.println(servo_x);
            } else {
                Serial.println("Invalid angle for Servo X");
            }
        }
        else if (command.startsWith("Y")) {
            int angle = command.substring(1).toInt();
            if (angle >= 0 && angle <= 180) {
                servo_y = angle;
                SolarServo1.write(servo_y);
                Serial.print("Servo Y set to: ");
                Serial.println(servo_y);
            } else {
                Serial.println("Invalid angle for Servo Y");
            }
        } else {
            Serial.println("Invalid command");
        }
    }
    
  // Always collect readings, independent of the timing for output
  if (readingsCount < readingsToCollect) {
    int rawValue = analogRead(34);
    readingsSum += rawValue; // Add the raw value to the sum
    readingsCount++; // Increment the count of readings
  }
  
  unsigned long currentMillis = millis();
  
  // If we have collected 500 readings and the interval has passed, calculate and display the average
  if (readingsCount >= readingsToCollect && (currentMillis - previousMillis >= interval)) {
    float averageRawValue = (float)readingsSum / readingsCount;
    float averageVoltage = averageRawValue / 4095.0 * 3.3;
    
    Serial.print("Average Raw Value: ");
    Serial.println(averageRawValue);
    Serial.print("Average Voltage: ");
    Serial.println(averageVoltage);
    
    // Reset for the next averaging cycle
    readingsSum = 0;
    readingsCount = 0;
    previousMillis = currentMillis; // Update the time we last output the average
  }
  // No need for a delay here; loop will continue running, allowing for responsive client handling
  //String averageVoltage = String(averageVoltage);
  //server.send(200,"text/html",averageVoltage); 

  
}                 
