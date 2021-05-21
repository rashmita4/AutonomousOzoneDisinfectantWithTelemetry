# AutonomousOzoneDisinfectantWithTelemetry

The Covid-19 pandemic has made us realize the importance of disinfection and sanitation. Need of the hour is a disinfectant that is reliable, efficient and potent. Ozone is effective in deactivating various bacteria, fungi ,molds and viruses. A device that can harness this property of ozone and is both cost effective and time efficient will have various applications in society.  The proposed system is an Autonomous Ozone Disinfectant With Telemetry which uses an ozone generator for disinfection. It is a remotely controlled system that provides real-time ozone concentration values and remote switching through a mobile application as well.
# Hardware and Software Requirements
Programming Environment: Arduino IDE( Libraries used: Blynk and ESP8266)
Mobile application development: Blynk application
Hardware Components: 12g/hr ozone generator, MQ131 ozone sensor, 12V DC brushless fans, 5V Relay module, NodeMCU, power supply, breadboard and connecting wires.

# Process Flow
Following is the algorithm which outlines the working of our project. 

1. Deciding the concentration of ozone required for the process of disinfection.
The two important values in the algorithm are:
The ozone concentration which is necessary for disinfection which is 0.3ppm and Ozone concentration which is safe for humans, animals and plants which is 0.02ppm.

2. Necessary conditions to carry out the process.
The ozone disinfectant is placed in a closed room void of any humans, pets and plants.

3. Remotely accessing the device with the help of Blynk application.
The user has a mobile application called Blynk installed on their phone. Now  we switch on the  ozone generator, ozone sensor and fan through the app. The ozone generator generates ozone gas and the sensor monitors it at predefined intervals. The fan maintains the circulation in the room.

4. Displaying a message once it is safe to enter the room.
A message is displayed on the mobile app, in user friendly settings stating that it is now safe to enter the room. 

# Data Flow Diagram
![flowchart](https://user-images.githubusercontent.com/84565973/119112805-1c47af80-ba42-11eb-8a2f-e0a64ee67bd8.PNG)

