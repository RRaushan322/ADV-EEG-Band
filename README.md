# ADV-EEG-Band


The EEG Wearable Band is a unique device designed for monitoring brain activity in real-time. This repository contains the code and documentation for the wearable band.

## Components

The wearable band consists of the following components:

- **ESP32 Module**: Processes and transmits EEG data.
- **3.7V LiPo Battery**: Provides power to the wearable band.
- **Bio-Pill Module**: Collects EEG signals from the brain.
- **Switch**: Allows user control for turning the device on/off.
- **Resistor**: Used for circuit protection and signal conditioning.
- **Charging Module**: Charges the LiPo battery.

## Functionality

The wearable band operates as follows:

1. **EEG Signal Acquisition**: Three electrodes on the band are placed on the user's head to capture EEG signals from the brain.

2. **Bio-Pill Module**: The EEG signals are received and amplified by the Bio-Pill module, which also filters the data to remove noise and artifacts.

3. **ESP32 Processing**: The processed EEG data is then transmitted to the ESP32 module, which further processes the data and prepares it for transmission.

4. **Bluetooth Transmission**: The ESP32 module communicates with a mobile application via Bluetooth to send the EEG data in real-time.

## Setup Instructions

To set up the EEG Wearable Band, follow these steps:

1. **Hardware Assembly**:
   - Connect the electrodes to the Bio-Pill module and ensure they are properly positioned on the user's head.
   - Connect all components (ESP32, LiPo battery, Bio-Pill module, switch, resistor, and charging module) according to the circuit diagram.

2. **Software Setup**:
   - Upload the provided code to the ESP32 module.
   - Install the mobile application on the user's smartphone for receiving EEG data via Bluetooth.

3. **Power On/Off**:
   - Use the switch to turn the device on or off as needed.

## Usage

Once the EEG Wearable Band is set up and powered on, it will start capturing and transmitting EEG data to the mobile application. Users can monitor their brain activity in real-time using the mobile app.

## Troubleshooting

If you encounter any issues with the EEG Wearable Band, please refer to the following troubleshooting steps:

- Check the connections between components to ensure they are securely connected.
- Ensure the LiPo battery is fully charged and properly connected to provide power.
- Verify the code uploaded to the ESP32 module for any errors or bugs.

If the issue persists, please consult the documentation or seek assistance from the project maintainers.

