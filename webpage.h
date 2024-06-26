const char PAGE_MAIN[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home Page</title>
    <style>
         @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;500&display=swap');

* {
  box-sizing: border-box;
}

:root {
  --app-bg-dark: #01081f;
  --app-bg-before: linear-gradient(180deg, rgba(1,8,31,0) 0%, rgba(1,8,31,1) 100%);
  --app-bg-before-2: linear-gradient(0deg, rgba(1,8,31,0) 0%, rgba(1,8,31,1) 100%);
  --app-bg-light: #151c32;
  --app-logo: #3d7eff;
  --nav-link: #5e6a81;
  --nav-link-active: #fff;
  --list-item-hover: #0c1635;
  --main-color: #fff;
  --secondary-color: #5e6a81;
  --color-light: rgba(52, 129, 210, .2);
  --warning-bg: #ffe5e5;
  --warning-icon: #ff8181;
  --applicant-bg: #e3fff1;
  --applicant-icon: #61e1a1;
  --close-icon: #fdbc64;
  --draft-bg:  #fed8b3;
  --draft-icon:  #e9780e;
  --weather-text-color: #fff;  /* White color for readability */

  
}

body {
  height: 100vh;
  width: 100%;
  overflow: hidden;
  display: flex;
  justify-content: center;
  font-family: 'Poppins', sans-serif;
  background-color: #050e2d;
}

.weather-forecast-container {
    padding: 15px;  /* Adds space inside the container */
    margin: 20px 0; /* Adds space outside the container, between other elements */
    margin-top: 0px;
    text-align: left; /* Aligns text to the left */
    background-color: var(--app-bg-dark);
    color: var(--weather-text-color); /* Ensures text color is white, assuming this variable is defined */
    border-radius: 10px; /* Optional: rounds the corners of the container */
    display: flex; /* Uses Flexbox to layout child elements */
    flex-direction: row; /* Aligns children vertically */
    gap: 10px; /* Adds space between each child element */
    font-size: 16px;
}

.forecast-icon {
      text-align: center;
}

.app-container {
  width: 100%;
  height: 100%;
  display: flex;
  position: relative;
  max-width: 1680px;
}

.app-left {
  flex-basis: 240px;
  background-color: var(--app-bg-light);
  height: 100%;
  overflow-y: auto;
  overflow-x: hidden;
  padding: 24px 0;
  transition: all .4s ease-in;
  
  &.show {
    right: 0;
    opacity: 1;
  }
}

.app-main {
  flex: 1;
  height: 100%;
  overflow-y: auto;
  overflow-x: hidden;
  background-color: var(--app-bg-);
  padding: 24px;
  background: radial-gradient(circle, rgba(5,19,64,1) 1%, rgba(4,15,50,1) 100%);
}

.app-right {
  flex-basis: 320px;
  width: 320px;
  background-color: var(--app-bg-light);
  height: 100%;
  padding: 64px 0 0 0;
  display: flex;
  flex-direction: column;
  position: relative;
  transition: all .4s ease-in;
  margin-right: 20px;
  
  &:before {
    content: '';
    position: absolute;
    bottom: 0;
    height: 48px;
    width: 100%;
    background-image: var(--app-bg-before);
    z-index: 1;
  }
  
  &.show {
    right: 0;
    opacity: 1;
  }
  
  .close-right { display: none; }
}

.app-right-content {
  flex: 1;
  height: 100%;
  overflow-y: auto;
  overflow-x: hidden;
}

.app-logo {
  display: flex;
  align-items: center;
  color: var(--app-logo);
  margin-right: 16px;
  padding: 0 24px;
  
  span {
    color: #fff;
    display: inline-block;
    line-height: 24px;
    font-size: 16px;
    margin-left: 16px;
  }
}

ul {
  list-style-type: none;
  padding: 0;
}

a {
  text-decoration: none;
  cursor: pointer;
}

button { cursor: pointer; }

.nav-list {
  margin-top: 40px;
}

.nav-list-item {
  margin-bottom: 12px;
  
  &:not(.active):hover {
    background-color: var(--list-item-hover);
  }
  
  &.active {
    .nav-list-link {
      color: var(--nav-link-active);
      
      &:after {
        height: 100%;
        opacity: 1;
      }
    }
    
    svg {
      stroke: var(--app-logo);
    }
  }
}

.nav-list-link {
  font-weight: 300;
  font-size: 14px;
  line-height: 24px;
  padding: 8px 24px;
  color: var(--nav-link);
  display: flex;
  align-items: center;
  position: relative;
  
  svg {
    margin-right: 12px;
  }
  
  &:after {
    content: '';
    height: 100%;
    width: 2px;
    background-color: var(--app-logo);
    right: 0;
    top: 0;
    position: absolute;
    border-radius: 2px;
    opacity: 0;
    height: 0;
  }
}

.open-right-area {
  display: none;
  justify-content: center;
  align-items: center;
  border: none;
  background-color: var(--app-bg-dark);
  border-radius: 4px;
  height: 40px;
  width: 40px;
  padding: 0;
}

.main-header-line {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 16px;
  
  h1 {
    color: var(--main-color);
    margin: 0;
    font-size: 24px;
    line-height: 32px;
  }
  
  input {
    border-radius: 4px;
    background-color: var(--color-light);
    border: none;
    border: 1px solid var(--color-light);
    color: var(--main-color);
    height: 32px;
    padding: 0 8px 0 32px;
    font-size: 14px;
    background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' width='24' height='24' viewBox='0 0 24 24' fill='none' stroke='%233481d2' stroke-width='2' stroke-linecap='round' stroke-linejoin='round' class='feather feather-search'%3E%3Ccircle cx='11' cy='11' r='8'/%3E%3Cline x1='21' y1='21' x2='16.65' y2='16.65'/%3E%3C/svg%3E");
    background-position: center left 10px;
    background-repeat: no-repeat;
    background-size: 16px;
    outline: none;
    transition: .2s;
    width: 100%;
    max-width: 400px;
    margin-left: 16px;
    
    &:placeholder {
      font-size: 14px;
      color: rgba(255,255,255, 0.6);
    }
    
    &:hover, &:focus {
      border: 1px solid #3481d2;
      box-shadow: 0 0 0 3px var(--color-light);
    }
  }
}

.chart-row {
  display: flex;
  justify-content: space-between;
  margin: 0 -8px;
  
  &.three .chart-container-wrapper {
    width: 33.3%;
    
    .chart-container { justify-content: space-between; }
  }
  
  &.two {
    .big {
      flex: 1;
      max-width: 75.3%;
      
      .chart-container {
        flex-direction: column;
      }
    }
    
    .small {
      width: 35.7%;
      
      .chart-container {
        flex-direction: column;
        + .chart-container { margin-top: 16px; }
      }
    }
  }
}

.line-chart {
  width: 100%;
  margin-top: 24px;
}

.chart-container {
  width: 100%;
  border-radius: 10px;
  background-color: var(--app-bg-dark);
  padding: 16px;
  display: flex;
  align-items: center;
  
  &.applicants {
    max-height: 336px;
    overflow-y: auto;
    padding: 0px;
  }
}

.chart-container-wrapper {
  padding: 8px;
}

.chart-info-wrapper {
  flex-shrink: 0;
  flex-basis: 120px;
  
  h2 {
    color: var(--secondary-color);
    font-size: 12px;
    line-height: 16px;
    font-weight: 600;
    text-transform: uppercase;
    margin: 0 0 8px 0;
  }
  
  span {
    color: var(--main-color);
    font-size: 24px;
    line-height: 32px;
    font-weight: 500;
  }
}

.chart-svg {
  position: relative;
  max-width: 90px;
  min-width: 40px;
  flex: 1;
}

.circle-bg {
  fill: none;
  stroke: #eee;
  stroke-width: 1.2;
}

.circle {
  fill: none;
  stroke-width: 1.6;
  stroke-linecap: round;
  animation: progress 1s ease-out forwards;
}

.circular-chart {
  &.orange {
    .circle { stroke: #ff9f00; }
    .circle-bg {stroke: #776547; }
  }
  
  &.blue {
    .circle { stroke: #00cfde; }
    .circle-bg { stroke: #557b88; }
  }
  
  &.pink {
    .circle { stroke: #ff7dcb; }
    .circle-bg { stroke: #6f5684; }
  }
}

.percentage {
  fill: #fff;
  font-size: 0.5em;
  text-anchor: middle;
  font-weight: 400;
}

@keyframes progress {
  0% {
    stroke-dasharray: 0 100;
  }
}

.chart-container-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  width: 100%;
  margin-bottom: 12px;
  
  h2 {
    margin: 0;
    color: var(--main-color);
    font-size: 12px;
    line-height: 16px;
    opacity: .8;
  }
  
  span {
    color: var(--app-logo);
    font-size: 12px;
    line-height: 16px;
  }
}

.acquisitions-bar {
  width: 100%;
  height: 4px;
  border-radius: 4px;
  margin-top: 16px;
  margin-bottom: 8px;
  display: flex;
}

.bar-progress {
  height: 4px;
  display: inline-block;
  
  &.applications {
    background-color: rgba(66,253,66,1);
  }
  &.shortlisted {
    background-color: rgba(0,207,222,1);
  }
  &.on-hold {
    background-color: rgba(253,172,66,1);
  }
  &.rejected {
    background-color: rgba(255,92,92,1);
  }
}

.progress-bar-info {
  display: flex;
  align-items: center;
  margin-top: 8px;
  width: 100%;
}

.progress-color {
  width: 10px;
  height: 10px;
  border-radius: 50%;
  margin-right: 8px;
  
  &.applications {
    background-color: rgba(66,253,66,1);
  }
  
  &.shortlisted {
    background-color: rgba(0,207,222,1);
  }
  
  &.on-hold {
    background-color: rgba(253,172,66,1);
  }
  
  &.rejected {
    background-color: rgba(255,92,92,1);
  }
}

.progress-type {
  color: var(--secondary-color);
  font-size: 12px;
  line-height: 16px;
}

.progress-amount {
  color: var(--secondary-color);
  font-size: 12px;
  line-height: 16px;
  margin-left: auto;
}

.applicant-line {
  display: flex;
  align-items: center;
  width: 100%;
  margin-top: 12px;
  
  img {
    width: 32px;
    height: 32px;
    border-radius: 50%;
    object-fit: cover;
    margin-right: 10px;
    flex-shrink: 0;
  }
}

.applicant-info {
  span {
    color: var(--main-color);
    font-size: 14px;
    line-height: 16px;
  }
  
  p {
    margin : 4px 0;
    font-size: 12px;
    line-height: 16px;
    color: var(--secondary-color);
  }
}

.profile-box {
  display: flex;
  flex-direction: column;
  align-items: center;
  position: relative;
  
  &:before {
    content: '';
    position: absolute;
    top: 100%;
    height: 48px;
    width: 100%;
    background-image: var(--app-bg-before-2);
    z-index: 1;
  }
}

.profile-photo-wrapper {
  width: 80px;
  height: 80px;
  overflow: hidden;
  border-radius: 50%;
  margin-bottom: 16px;
  
  img {
    width: 100%;
    height: 100%;
    object-fit: cover;
  }
}

.profile-text, .profile-subtext {
  font-size: 12px;
  line-height: 16px;
  color: var(--secondary-color);
  margin: 0 0 8px 0;
}

.profile-text { font-weight: 600; }

.app-right-section-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 0 16px;
  margin-top: 16px;
  
  h2 {
    font-size: 14px;
    line-height: 24px;
    color: var(--secondary-color);
  }
  
  span {
    display: inline-block;
    color: var(--secondary-color);
    position: relative;
    
    &.notification-active:before {
      content: '';
      position: absolute;
      width: 6px;
      height: 6px;
      border-radius: 50%;
      background-color: var(--app-logo);
      top: -1px;
      right: -1px;
      box-shadow: 0 0 0 2px var(--app-bg-dark);
    }
  }
}

.message-line {
  display: flex;
  align-items: center;
  padding: 8px 16px;
  margin-bottom: 8px;
  
  &:hover {
    background-color: var(--list-item-hover);
  }
  
  img {
    width: 32px;
    height: 32px;
    border-radius: 50%;
    object-fit: cover;
    margin-right: 8px;
  }
}

.message-text-wrapper {
  max-width: calc(100% - 48px);
}

.message-text {
  font-size: 14px;
  line-height: 16px;
  color: var(--main-color);
  margin: 0;
  opacity: .8;
  width: 100%;
}

.message-subtext {
  font-size: 12px;
  line-height: 16px;
  color: var(--secondary-color);
  margin: 4px 0 0 0;
  white-space: nowrap;
  overflow: hidden;
  text-overflow: ellipsis;
  width: 100%;
}

.activity-line {
  padding: 8px 16px;
  display: flex;
  align-items: flex-start;
  margin-bottom: 8px;
}

.activity-link {
  font-size: 12px;
  line-height: 16px;
  color: var(--app-logo);
  text-decoration: underline;
}

.activity-text  {
  font-size: 12px;
  line-height: 16px;
  color: var(--secondary-color);
  width: 100%;
  margin: 0;
  
  strong {
    color: #fff;
    opacity: .4;
    font-weight: 500;
  }
}

.activity-icon {
  border-radius: 8px;
  width: 32px;
  height: 32px;
  display: flex;
  justify-content: center;
  align-items: center;
  flex-shrink: 0;
  margin-right: 8px;
  
  &.warning {
    background-color: var(--warning-bg);
    color: var(--warning-icon);
  }
  
  &.applicant {
    background-color: var(--applicant-bg);
    color: var(--applicant-icon);
  }
  
  &.close {
    background-color: var(--close-bg);
    color: var(--close-icon);
  }
  
  &.draft {
    background-color: var(--draft-bg);
    color: var(--draft-icon);
  }
}

.action-buttons {
  display: flex;
  align-items: center;
}

.menu-button {
  width: 40px;
  height: 40px;
  margin-left: 8px;
  display: none;
  justify-content: center;
  align-items: center;
  padding: 0;
  background-color: var(--app-bg-dark);
  border: none;
  color: var(--main-color);
  border-radius: 4px;
}

.close-menu {
  position: absolute;
  top: 16px;
  right: 16px;
  display: none;
  align-items: center;
  justify-content: center;
  border: none;
  background-color: transparent;
  padding: 0;
  color: var(--main-color);
  cursor: pointer;
}

@media screen and (max-width: 1350px) {
  .app-right {
    flex-basis: 240px;
    width: 240px;
  }
  
  .app-left {
    flex-basis: 200px;
  }
}

@media screen and (max-width: 1200px) {
  .app-right {
    position: absolute;
    opacity: 0;
    top: 0;
    z-index: 2;
    height: 100%;
    width: 320px;
    right: -100%;
    box-shadow: 0 0 10px 5px rgba(1, 8, 31, .4);
    
    .close-right {
      position: absolute;
      top: 16px;
      right: 16px;
      display: flex;
      align-items: center;
      justify-content: center;
      border: none;
      background-color: transparent;
      padding: 0;
      color: var(--main-color);
      cursor: pointer;
    }
  }
  
  .app-main .open-right-area {
    display: flex;
    color: var(--main-color);
  }
}

@media screen and (max-width: 1180px) {
  .chart-row.two {
    flex-direction: column;
  }
  
  .chart-row.two .big {
    max-width: 100%;
  }
  .chart-row.two .small {
    display: flex;
    justify-content: space-between;
    width: 100%;
    
    .chart-container {
      width: calc(50% - 8px);
      
      &.applicants {
        margin-top: 0;
      }
    }
  }
}

@media screen and (max-width: 920px) {
  .menu-button {
    display: flex;
  }
  
  .app-left {
    position: absolute;
    opacity: 0;
    top: 0;
    z-index: 2;
    height: 100%;
    width: 320px;
    right: -100%;
    box-shadow: 0 0 10px 5px rgba(1, 8, 31, .4);
  }
  
  .close-menu { display: flex;}
}

@media screen and (max-width: 650px) {
  .chart-row.three {
    flex-direction: column;
  }
  
  .chart-row.three .chart-container-wrapper {
    width: 100%;
  }
  
  .chart-svg {
    min-height: 60px;
    min-width: 40px;
  }
}

@media screen and (max-width: 520px) {
  .chart-row.two .small {
    flex-direction: column;
  }
  
  .chart-row.two .small .chart-container {
    width: 100%;
    
    &.applicants {
      margin-top: 16px;
    }
  }
  
  .main-header-line h1 {
    font-size: 14px;
  }
  
}


    </style>
</head>
<body>
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <div class="app-container">
  <div class="app-left">
    <button class="close-menu">
      <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-x"><line x1="18" y1="6" x2="6" y2="18"/><line x1="6" y1="6" x2="18" y2="18"/></svg>
    </button>
    <div class="app-logo">
      <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-bar-chart-2">
        <line x1="18" y1="20" x2="18" y2="10"/>
        <line x1="12" y1="20" x2="12" y2="4"/>
        <line x1="6" y1="20" x2="6" y2="14"/>       </svg>
      <span>Sunny Side Upgrade</span>
    </div>
    <ul class="nav-list">
      <li class="nav-list-item active">
        <a class="nav-list-link" href="#">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-columns"><path d="M12 3h7a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-7m0-18H5a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h7m0-18v18"/></svg>
          Dashboard
        </a>
      </li>
      <li class="nav-list-item">
        <a class="nav-list-link" href="#">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-briefcase"><rect x="2" y="7" width="20" height="14" rx="2" ry="2"/><path d="M16 21V5a2 2 0 0 0-2-2h-4a2 2 0 0 0-2 2v16"/></svg>
          Buildings
        </a>
      </li>
      <li class="nav-list-item">
        <a class="nav-list-link" href="#">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-file"><path d="M13 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V9z"/><polyline points="13 2 13 9 20 9"/></svg>
          Scheduled Events
        </a>
      </li>
      <li class="nav-list-item">
        <a class="nav-list-link" href="#">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-users"><path d="M17 21v-2a4 4 0 0 0-4-4H5a4 4 0 0 0-4 4v2"/><circle cx="9" cy="7" r="4"/><path d="M23 21v-2a4 4 0 0 0-3-3.87"/><path d="M16 3.13a4 4 0 0 1 0 7.75"/></svg>
          Team
        </a>
      </li>
      <li class="nav-list-item">
        <a class="nav-list-link" href="#">
          <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-pie-chart"><path d="M21.21 15.89A10 10 0 1 1 8 2.83"/><path d="M22 12A10 10 0 0 0 12 2v10z"/></svg>
          Reports
        </a>
      </li>
    </ul>
  </div>
  <div class="app-main">
    <div class="main-header-line">
      <h1>Application Dashboard</h1>
      <div class="action-buttons">
        <button class="open-right-area">
        <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-activity"><polyline points="22 12 18 12 15 21 9 3 6 12 2 12"/></svg>
      </button>
      <button class="menu-button">
        <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-menu"><line x1="3" y1="12" x2="21" y2="12"/><line x1="3" y1="6" x2="21" y2="6"/><line x1="3" y1="18" x2="21" y2="18"/></svg>
      </button>
      </div>
    </div>
    <div class="chart-row three">
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>Battery Charge</h2>
            <span id="batteryPercentage">Loading...</span>

          </div>
          <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart pink">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="30, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">30%</text>
    </svg>
          </div>
        </div>
      </div>
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>Live Power Reading</h2>
            <span id="extraEnergy">Loading...</span>
          </div>
          <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart blue">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="60, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">60%</text>
    </svg>
          </div>
        </div>
      </div>
      <div class="chart-container-wrapper">
        <div class="chart-container">
          <div class="chart-info-wrapper">
            <h2>Total Energy Produced Today</h2>
            <span id=totalEnergy>Loading...</span>
          </div>
           <div class="chart-svg">
            <svg viewBox="0 0 36 36" class="circular-chart orange">
      <path class="circle-bg" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <path class="circle" stroke-dasharray="90, 100" d="M18 2.0845
          a 15.9155 15.9155 0 0 1 0 31.831
          a 15.9155 15.9155 0 0 1 0 -31.831"></path>
      <text x="18" y="20.35" class="percentage">90%</text>
    </svg>
          </div>
        </div>
      </div>
    </div>
    <div class="chart-row two">
  <div class="chart-container-wrapper big">
      <div class="chart-container">
    <div class="chart-container-header">
      <h2>Live Video Stream</h2>
      </div>
      <div class="chart-container">
      <!-- Video Stream Embedding -->
    <div class="video-stream-container" style="margin-top: 20px;">
      <img id="videoStream" src="" alt="Live Video Stream" style="width:100%; max-width:640px; border: 1px solid #ddd; border-radius: 4px; padding: 5px;">
    </div>
        </div>
  </div>
  <div class="chart-container">
    <div class="chart-container-header">
      <h2>Energy Production Chart</h2>
      <span>Past Year</span>
    </div>
    <div class="line-chart">
      <canvas id="chart"></canvas>
    </div>
    <div class="chart-data-details">
      <div class="chart-details-header"></div>
    </div>
  </div>
</div>
      <div class="chart-container-wrapper small">
         <div class="weather-forecast-container"></div>
        <div class="chart-container">
          <div class="chart-container-header">
            <h2>Average Weather Data</h2>
            <span href="#">This Week</span>
          </div>
          <div class="acquisitions-bar">
           <span class="bar-progress rejected" style="width:8%;"></span>
            <span class="bar-progress on-hold" style="width:10%;"></span>
            <span class="bar-progress shortlisted" style="width:18%;"></span>
            <span class="bar-progress applications" style="width:64%;"></span>
          </div>
          <div class="progress-bar-info">
            <span class="progress-color applications"></span>
            <span class="progress-type">Sunny</span>
            <span class="progress-amount applications">64%</span>
          </div>
          <div class="progress-bar-info">
            <span class="progress-color shortlisted"></span>
            <span class="progress-type">Partly Cloudy</span>
            <span class="progress-amount shortlisted">18%</span>
          </div>
          <div class="progress-bar-info">
            <span class="progress-color on-hold"></span>
            <span class="progress-type">Cloudy</span>
            <span class="progress-amount on-hold">10%</span>
          </div>
          <div class="progress-bar-info">
            <span class="progress-color rejected"></span>
            <span class="progress-type">Rainy/Stormy</span>
            <span class="progress-amount rejected">8%</span>
          </div>
        </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="app-right">
    <button class="close-right">
      <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-x"><line x1="18" y1="6" x2="6" y2="18"/><line x1="6" y1="6" x2="18" y2="18"/></svg>
    </button>
    <div class="profile-box">
      <div class="profile-photo-wrapper">
        <img src="https://i.imgur.com/6nWUy3z.jpeg" alt="profile">
      </div>
      <p class="profile-text">Kevin Orozco</p>
       <p class="profile-subtext">Full Stack Engineer</p>
    </div>
    <div class="app-right-content">
      <div class="app-right-section">
      <div class="app-right-section-header">
        <h2>Messages</h2>
        <span class="notification-active">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-message-square"><path d="M21 15a2 2 0 0 1-2 2H7l-4 4V5a2 2 0 0 1 2-2h14a2 2 0 0 1 2 2z"/></svg>
        </span>
      </div>
      <div class="message-line">
        <img src="https://i.imgur.com/yB9dAdr.png" alt="profile">
        <div class="message-text-wrapper">
          <p class="message-text">Kevin Shaholli</p>
          <p class="message-subtext">Have you planned any deadline for this?</p>
        </div>
      </div>
      <div class="message-line">
        <img src="https://i.imgur.com/ff83Fh3.png" alt="profile">
        <div class="message-text-wrapper">
          <p class="message-text">Matthew Del Cid</p>
          <p class="message-subtext">Can we schedule another meeting for next thursday?</p>
        </div>
      </div>
      <div class="message-line">
        <img src="https://i.imgur.com/o7C0IPm.png" alt="profile">
        <div class="message-text-wrapper">
          <p class="message-text">Joel Mendez</p>
          <p class="message-subtext">Epic.</p>
        </div>
      </div>
    </div>
    <div class="app-right-section">
      <div class="app-right-section-header">
        <h2>Activity</h2>
        <span class="notification-active">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-bell"><path d="M18 8A6 6 0 0 0 6 8c0 7-3 9-3 9h18s-3-2-3-9"/><path d="M13.73 21a2 2 0 0 1-3.46 0"/></svg>
        </span>
      </div>
      <div class="activity-line">
        <span class="activity-icon warning">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-alert-circle"><circle cx="12" cy="12" r="10"/><line x1="12" y1="8" x2="12" y2="12"/><line x1="12" y1="16" x2="12.01" y2="16"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">Your Scheduled Event is executing in <strong>3 days.</strong></p>
           <a class="activity-link" href="#">Activate Now</a>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon applicant">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-file-plus"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="12" y1="18" x2="12" y2="12"/><line x1="9" y1="15" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">There are <strong>3 new updates</strong> for <strong>Leo Solar Array</strong></p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon close">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-x-circle"><circle cx="12" cy="12" r="10"/><line x1="15" y1="9" x2="9" y2="15"/><line x1="9" y1="9" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">Your teammate, <strong>Joel Mendez</strong> has closed the task of <strong>Back End Design</strong></p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon applicant">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-file-plus"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="12" y1="18" x2="12" y2="12"/><line x1="9" y1="15" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">There are <strong>4 new updates</strong> for <strong>Higgins Solar Array</strong></p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon applicant">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-file-plus"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="12" y1="18" x2="12" y2="12"/><line x1="9" y1="15" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">There are <strong>2 new updates</strong> for <strong>RLC Solar Array</strong></p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon close">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-x-circle"><circle cx="12" cy="12" r="10"/><line x1="15" y1="9" x2="9" y2="15"/><line x1="9" y1="9" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">Your teammate, <strong>Matthew Del Cid</strong> has closed the task of <strong>Solar Array Battery Optimization</strong></p>
        </div>
      </div>
      <div class="activity-line">
        <span class="activity-icon draft">
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-file-minus"><path d="M14 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V8z"/><polyline points="14 2 14 8 20 8"/><line x1="9" y1="15" x2="15" y2="15"/></svg>
        </span>
        <div class="activity-text-wrapper">
          <p class="activity-text">You have drafted a task for <strong>Web App Implementation</strong></p>
          <a href="#" class="activity-link">Complete Now</a>
        </div>
      </div>
    </div>
    </div>
  </div>
</div>
    <script>
var chart = document.getElementById('chart').getContext('2d'),
gradient = chart.createLinearGradient(0, 0, 0, 450);

gradient.addColorStop(0, 'rgba(0, 199, 214, 0.32)');
gradient.addColorStop(0.3, 'rgba(0, 199, 214, 0.1)');
gradient.addColorStop(1, 'rgba(0, 199, 214, 0)');

var data  = {
    labels: [ 'January', 'February', 'March', 'April', 'May', 'June', 'July','August','September','October', 'November','December' ],
    datasets: [{
			label: 'Energy Produced (Wh)',
			backgroundColor: gradient,
			pointBackgroundColor: '#00c7d6',
			borderWidth: 1,
			borderColor: '#0e1a2f',
			data: [40, 45, 50, 30, 60, 80,90,80,40,80,80,50]
    }]
};

var options = {
	responsive: true,
	maintainAspectRatio: true,
	animation: {
		easing: 'easeInOutQuad',
		duration: 520
	},
	scales: {
		yAxes: [{
      ticks: {
        fontColor: '#5e6a81'
      },
			gridLines: {
				color: 'rgba(200, 200, 200, 0.08)',
				lineWidth: 1
			}
		}],
    xAxes:[{
      ticks: {
        fontColor: '#5e6a81'
      }
    }]
	},
	elements: {
		line: {
			tension: 0.4
		}
	},
	legend: {
		display: false
	},
	point: {
		backgroundColor: '#00c7d6'
	},
	tooltips: {
		titleFontFamily: 'Poppins',
		backgroundColor: 'rgba(0,0,0,0.4)',
		titleFontColor: 'white',
		caretSize: 5,
		cornerRadius: 2,
		xPadding: 10,
		yPadding: 10
	}
};

var chartInstance = new Chart(chart, {
    type: 'line',
    data: data,
		options: options
});

document.querySelector('.open-right-area').addEventListener('click', function () {
    document.querySelector('.app-right').classList.add('show');
});

document.querySelector('.close-right').addEventListener('click', function () {
    document.querySelector('.app-right').classList.remove('show');
});

document.querySelector('.menu-button').addEventListener('click', function () {
    document.querySelector('.app-left').classList.add('show');
});

document.querySelector('.close-menu').addEventListener('click', function () {
    document.querySelector('.app-left').classList.remove('show');
});

function updateBatteryCharge() {
  fetch('/battery')
    .then(response => response.text())
    .then(percentage => {
            document.getElementById('batteryPercentage').innerText = percentage + '%';
      // Update the circular chart to reflect new battery percentage
      var circle = document.querySelector('.circular-chart.pink .circle');
      var fullLength = 100; // Total length of the path
      var filledLength = (fullLength * percentage) / 100;
      circle.style.strokeDasharray = `${filledLength}, ${fullLength}`;

      var percentageText = document.querySelector('.circular-chart.pink .percentage');
      percentageText.textContent = percentage + '%';
    })
    .catch(error => console.error('Error fetching battery data:', error));
}

// Call it once on page load
updateBatteryCharge();

// Update battery charge every 5 seconds
setInterval(updateBatteryCharge, 500);

function updateEnergyData() {
    fetch('/energy_data')
        .then(response => response.json())
        .then(data => {
            var { panelPower, totalEnergy } = data;

            // Update extra energy display
            var extraEnergyElement = document.getElementById('extraEnergy');
            extraEnergyElement.innerText = `${panelPower.toFixed(2)}W`;

            // Update total energy display
            var totalEnergyElement = document.getElementById('totalEnergy');
            totalEnergyElement.innerText = `${totalEnergy.toFixed(2)}Wh`;

            // Update circular charts
            updateCircularChart('.circular-chart.blue', panelPower, 120);
            updateCircularChart('.circular-chart.orange', totalEnergy, 832);
        })
        .catch(error => {
            console.error('Error fetching energy data:', error);
        });

    function updateCircularChart(chartClass, value, expectedValue) {
        var circle = document.querySelector(`${chartClass} .circle`);
        var fullLength = 100;
        var percentage = parseFloat(value) / expectedValue * 100;
        var filledLength = parseFloat(value) / expectedValue * fullLength;
        circle.style.strokeDasharray = `${filledLength}, ${fullLength}`;

        var percentageText = document.querySelector(`${chartClass} .percentage`);
        percentageText.textContent = `${percentage.toFixed(2)}%`;
    }
}

function fetchWeatherData() {
    const apiKey = 'f42f91a675d0f0955304d5503a1bfb12'; // Use your OpenWeatherMap API key
    const cityId = '5128581'; // Example: New York City ID
    const url = `http://api.openweathermap.org/data/2.5/forecast?id=${cityId}&appid=${apiKey}`;

    fetch(url)
        .then(response => response.json())
        .then(data => {
            updateWeatherForecast(data);
        })
        .catch(error => console.error('Error fetching weather data:', error));
}

function formatDate(d) {
    const days = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'];
    return `${days[d.getDay()]} ${d.getDate()}`;
}

function updateWeatherForecast(data) {
    // Assuming you have a container for the forecast in your HTML
    const forecastContainer = document.querySelector('.weather-forecast-container');

    forecastContainer.innerHTML = ''; // Clear existing forecast content

    // Iterate over each time interval in the forecast data
    data.list.forEach((forecast, index) => {
        if (index % 8 === 0) { // Assuming you want to display the forecast every 3 hours, adjust as necessary
            const dateTime = new Date(forecast.dt * 1000); // Convert Unix timestamp to JS Date object
            const formattedDate = formatDate(dateTime);
            const temp = ((forecast.main.temp - 273.15) * 9/5 + 32).toFixed(1);
            const description = forecast.weather[0].description;
            const icon = forecast.weather[0].icon;

            // Create the HTML for the forecast item
            const forecastHTML = `
                <div class="forecast-item">
                    <div class="forecast-date">${formattedDate}</div>
                    <div class="forecast-icon">
                        <img src="http://openweathermap.org/img/w/${icon}.png" alt="${description}" />
                    <div class="forecast-temp">${temp}°F</div>
                    <div class="forecast-desc">${description}</div>
                    </div>
                </div>
            `;

            // Append the forecast item to the container
            forecastContainer.innerHTML += forecastHTML;
        }
    });
}

// Call fetchWeatherData to update the forecast on page load
fetchWeatherData();

// might want to call fetchWeatherData at regular intervals, e.g., every hour
setInterval(fetchWeatherData, 3600000); // 3600000 ms = 1 hour

// For videostream ip
function updateVideoStream() {
  fetch('/ip')
    .then(response => response.text())
    .then(ip => {
      var videoStreamUrl = 'http://' + ip + '/stream';
      document.getElementById('videoStream').src = videoStreamUrl;
    })
    .catch(error => console.error('Error fetching IP:', error));
}

function updateAverageWeatherData() {
    const apiKey = 'f42f91a675d0f0955304d5503a1bfb12';  // Replace with your actual API key
    const cityId = '5128581';  // Replace with your actual city ID
    const url = `https://api.openweathermap.org/data/2.5/forecast?id=${cityId}&appid=${apiKey}&units=metric`;

    fetch(url)
        .then(response => response.json())
        .then(data => {
            const weatherCounts = {
                sunny: 0,
                partlyCloudy: 0,
                cloudy: 0,
                rainy: 0
            };

            data.list.forEach(forecast => {
                const main = forecast.weather[0].main;
                if (main.includes('Clear')) {
                    weatherCounts.sunny++;
                } else if (main.includes('Clouds')) {
                    if (forecast.weather[0].description.includes('few clouds')) {
                        weatherCounts.partlyCloudy++;
                    } else {
                        weatherCounts.cloudy++;
                    }
                } else if (main.includes('Rain') || main.includes('Storm')) {
                    weatherCounts.rainy++;
                }
            });

            const total = data.list.length;
            const percentages = {
                sunny: (weatherCounts.sunny / total * 100).toFixed(2),
                partlyCloudy: (weatherCounts.partlyCloudy / total * 100).toFixed(2),
                cloudy: (weatherCounts.cloudy / total * 100).toFixed(2),
                rainy: (weatherCounts.rainy / total * 100).toFixed(2)
            };

            document.querySelector('.bar-progress.applications').style.width = `${percentages.sunny}%`;
            document.querySelector('.bar-progress.shortlisted').style.width = `${percentages.partlyCloudy}%`;
            document.querySelector('.bar-progress.on-hold').style.width = `${percentages.cloudy}%`;
            document.querySelector('.bar-progress.rejected').style.width = `${percentages.rainy}%`;

            document.querySelector('.progress-amount.applications').innerText = `${percentages.sunny}%`;
            document.querySelector('.progress-amount.shortlisted').innerText = `${percentages.partlyCloudy}%`;
            document.querySelector('.progress-amount.on-hold').innerText = `${percentages.cloudy}%`;
            document.querySelector('.progress-amount.rejected').innerText = `${percentages.rainy}%`;
        })
        .catch(error => console.error('Error fetching weather data:', error));
}

// Call this function on page load and at intervals you deem necessary
document.addEventListener('DOMContentLoaded', function() {
  updateAverageWeatherData();
  setInterval(updateAverageWeatherData, 3600000); // Update hourly
  updateVideoStream();
  //setInterval(updateVideoStream, 500); // update every .5 seconds
  updateEnergyData();
  setInterval(updateEnergyData, 500); // update every .5 seconds
});
</script>
</body>
</html>
)=====";
