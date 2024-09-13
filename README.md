# smart-parking-system_iot-Based


**Description**
The Smart Parking System is an IoT-based solution developed using ESP32 and IR sensors to optimize the management of parking spaces. The system allows real-time monitoring of parking slot availability both locally and online, providing users with up-to-date information before entering a parking area. The system automates gate control based on parking slot occupancy and displays available spaces on an entrance display.

This project features a combination of Arduino-based programming for the ESP32 module and a simple web interface for online monitoring. It aims to make parking management more efficient, reducing congestion and saving users time by avoiding fully occupied parking lots.

**Key Features**
Real-time Parking Slot Monitoring: IR sensors in each parking slot detect the presence of vehicles. This data is processed by the ESP32 and used to monitor slot availability.
Automated Gate Control: The entrance gate will automatically open or close depending on the availability of parking spaces. If the lot is full, the gate will remain closed.
Display at Entrance: A display at the parking entrance shows the number of available slots in real-time, helping users quickly determine if parking is available.
Online Monitoring: Users can check parking availability through an online platform. The web interface updates in real-time and can be accessed via a browser.

**WiFi-Enabled ESP32 Module**: The ESP32 module connects to a local WiFi network, allowing the system to communicate with the web server and display real-time data both locally and online.

### **System Components**
1. **ESP32 Module**: Central controller responsible for processing data from the IR sensors and controlling the entrance gate. It also serves as the communication bridge between the sensors and the web server.
2. **IR Sensors**: Each parking slot is equipped with an IR sensor to detect whether the slot is occupied or free.
3. **Entrance Gate Control**: Automatically controlled by the ESP32 based on slot availability. If no slots are available, the gate remains closed to prevent entry.
4. **Display Panel**: Positioned at the entrance, this panel shows the current number of available parking slots.
5. **Web Interface**: An online dashboard that allows users to remotely check the parking lot's status in real-time.

### **Hardware Requirements**
- **ESP32 Development Board**: Acts as the central controller.
- **IR Sensors**: One sensor per parking slot.
- **Entrance Gate Mechanism**: A simple servo or motor mechanism controlled by ESP32 to open and close the gate.
- **WiFi Connection**: For ESP32 to connect to the web server and enable online monitoring.

### **Software Requirements**
- **Arduino IDE**: To upload the code to the ESP32 module.
- **ESPAsyncWebServer Library**: For handling HTTP requests.
- **HTML, CSS, and JavaScript**: For the web interface to display parking information online.
  
### **How It Works**
1. **Slot Detection**: Each IR sensor continuously monitors the parking slot. When a vehicle enters or exits a slot, the sensor detects this change.
2. **Data Processing**: The ESP32 gathers data from all the IR sensors, updates the count of available parking slots, and sends this data to the display at the entrance and the online monitoring system.
3. **Entrance Gate Automation**: Based on slot availability, the ESP32 controls the entrance gate. If parking is full, the gate will not open.
4. **Online Monitoring**: The ESP32 hosts a simple web server that allows users to view real-time parking slot availability from any device connected to the internet.

### **Project Structure**
- **Arduino Code**: Manages sensor data and gate control.
- **Web Interface**: Displays the available parking slots online, with updates every few seconds.
- **Circuit Diagrams**: Guides for wiring the IR sensors and ESP32 module.
  
### **Usage**
1. **Hardware Setup**: Connect IR sensors to the appropriate GPIO pins of the ESP32 and set up the entrance gate mechanism.
2. **Upload Code**: Use Arduino IDE to upload the `main.ino` code to the ESP32.
3. **Monitor Slots**: Once set up, the system automatically updates the entrance display and online interface with the available parking slots.
4. **Control Gate**: The entrance gate opens or closes automatically depending on the number of available parking slots.

### **System Diagrams**
- **System Architecture**: Shows the overall layout of the components.
- **Circuit Diagram**: Depicts the wiring between the IR sensors, ESP32, and gate mechanism.
- **Flowchart**: Describes the logical flow of the system, including gate control and slot detection.

