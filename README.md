# Automatic Plant Watering System

An embedded IoT prototype designed to monitor soil moisture levels in real-time and deliver automated, targeted irrigation using an Arduino microcontroller, capacitive sensors, and relay-actuated pumping hardware.

## Features & Highlights
* **Corrosion-Resistant Sensing:** Utilizes a 1.2V capacitive soil sensor to prevent oxidation and ensure long-term data accuracy compared to resistive alternatives.
* **Calibrated Telemetry:** Maps raw analog voltage data into a normalized 0%–100% moisture scale with custom threshold logic.
* **Relay Control:** Isolates logic components from 5V motor loads to safely actuate fluid delivery.

## Hardware Components
* Elegoo UNO R3 (ATmega328P Microcontroller)
* Capacitive Soil Moisture Sensor v1.2
* 5V Relay Module
* 3-6V Submersible DC Water Pump / Motor
* 5V USB Power Supply

## Circuit & System Logic
1. **Analog Read:** The sensor samples soil moisture at regular intervals via Pin `A0`.
2. **Signal Conversion:** Analog inputs are mapped between `490` (Dry/0%) and `204` (Submerged/100%).
3. **Actuation:** If moisture drops below **30%**, Digital Pin `8` triggers the relay to activate the pump for 3 seconds.

## How to Run
1. Clone this repository.
2. Open `main.ino` in the Arduino IDE.
3. Select board `Arduino Uno` and choose your COM port.
4. Upload code to the microcontroller.
