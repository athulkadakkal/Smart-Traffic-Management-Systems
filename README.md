**Smart Traffic Management System**

This repository hosts the code and documentation for the Smart Traffic Management System designed to optimize traffic flow and improve road safety using Arduino technology, RFID, ultrasonic sensors, and an OLED display. This system manages and controls traffic efficiently at intersections, providing priority to emergency vehicles.

**Project Overview**

The Smart Traffic Management System integrates complex components including Arduino Mega and Nano, RFID tags for emergency vehicles, ultrasonic sensors for detecting vehicle queues, and LEDs for traffic signals. This system aims to reduce congestion and prioritize emergency responses, enhancing the safety and efficiency of urban traffic networks.

**Components**


Arduino Mega: Controls traffic lights and processes data from ultrasonic sensors to manage vehicle queues.

Arduino Nano: Dedicated to identifying emergency vehicles using RFID technology. Commands are sent to the Arduino Mega for priority handling.

RFID Reader and Tags: Tags are provided for emergency vehicles. The RFID reader on the Nano board detects these tags and communicates with the Mega to adjust traffic signals accordingly.

Ultrasonic Sensors: Four sensors are utilized, one for each direction of an intersection, to measure the queue length of vehicles.

LEDs: Serve as traffic lights, using different colors (Red, Yellow, Green) to control traffic.

OLED Display: Displays team details and project information.

**Features**


Emergency Vehicle Priority: Automatically detects emergency vehicles through RFID and provides them immediate passage by adjusting traffic lights.

Dynamic Traffic Signal Adjustment: The system adjusts signals in real-time based on data received from ultrasonic sensors regarding vehicle queues.

Priority Management: Operates on a FIFO basis when multiple traffic directions are detected, ensuring orderly and fair traffic management.

Energy Efficiency: Implements low power consumption modes during periods of low traffic density.

**Hardware Setup**


Arduino Mega
Connect the four ultrasonic sensors to the appropriate pins for distance measurement.
Connect LEDs for traffic signals to control traffic flow.
Receive commands from Arduino Nano through analog pins for emergency vehicle detection.

Arduino Nano
Program to manage RFID reading for emergency vehicle identification.
Setup communication to send control signals to the Arduino Mega when emergency vehicles are detected.

Ultrasonic Sensors
Install one sensor at each approach of an intersection to accurately gauge vehicle queues.

OLED Display
Connect to Arduino Mega to display project and team details continuously.


Software Installation - Arduino Ide
