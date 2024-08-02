# smartHomeLightingSystem

OPOLOT LOUIS 23/U/2256/GIM/PS

Smart Home Lighting System

This project is a simple smart home lighting system controlled via Bluetooth. It uses an ESP32 microcontroller to manage the lighting of different rooms based on Bluetooth commands and ambient light levels detected by a sensor.

Hardware Requirements;

ESP32 Development Board
LEDs (for bedroom, security, sitting room, and kitchen)
Light Sensor (connected to pin 2)
Jumper wires
Breadboard (optional)

Software Requirements;

Arduino IDE with ESP32 board support installed
BluetoothSerial library
Pin Configuration
Bedroom Bulb: Pin 25
Security Bulb: Pin 13
Sitting Room Bulb: Pin 27
Kitchen Bulb: Pin 5
Light Sensor: Pin 2

Bluetooth Commands;

1: Turn on Bedroom Bulb
2: Turn off Bedroom Bulb
3: Turn on Security Bulb
4: Turn off Security Bulb
5: Turn on Sitting Room Bulb
6: Turn off Sitting Room Bulb
7: Turn on Kitchen Bulb
8: Turn off Kitchen Bulb

Setup Instructions;

Connect the LEDs to the respective pins on the ESP32 board.
Connect the light sensor to pin 2.
Upload the code to the ESP32 board using the Arduino IDE.
Open the Serial Monitor in the Arduino IDE to view the debug output.
Use a Bluetooth-enabled device to connect to the ESP32 (named "SMARTHOME").
Send the corresponding commands to control the lights.

Code Explanation;

Libraries;

BluetoothSerial.h: Library for Bluetooth communication on ESP32.

Constants;

bedroomBulb, securityBulb, sittingroomBulb, kitchenBulb: Pins for the respective bulbs.
sensorPin: Pin for the light sensor.

Variables;

lightInit: Initial light value read from the sensor.
lightVal: Current light value read from the sensor.
Objects;
SerialBT: BluetoothSerial object for Bluetooth communication.

setup() Function;

Initializes the serial communication and Bluetooth.
Sets the pin modes for the bulbs.
Reads the initial light value from the sensor.
Turns off all bulbs initially.

loop() Function;

Continuously reads the light value from the sensor.
Turns on the security bulb if the light value drops below a certain threshold.
Listens for Bluetooth commands to control the bulbs.


