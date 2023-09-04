# **RLCV2**

**RGB LED Controller Version 2**

---
# Table of Contents
- [**RLCV2**](#rlcv2)
- [Table of Contents](#table-of-contents)
- [Systemoverview](#systemoverview)
  - [Hardware](#hardware)
    - [Concept](#concept)
    - [Input Voltage and Voltage converter](#input-voltage-and-voltage-converter)
    - [RS485 / DMX module](#rs485--dmx-module)
    - [ESP32-C3 Microcontroller](#esp32-c3-microcontroller)
    - [LED Strip and Mosfets](#led-strip-and-mosfets)
    - [Periphery (OLED and rotary encoder)](#periphery-oled-and-rotary-encoder)
    - [Conclusion Hardware](#conclusion-hardware)
    - [Circuit Diagramm](#circuit-diagramm)
    - [Selected Parts / BOM](#selected-parts--bom)
  - [Software](#software)
    - [Concept](#concept-1)
    - [Uploading the Software (Flash the ESP32-C3)](#uploading-the-software-flash-the-esp32-c3)
    - [Bugs and improvements](#bugs-and-improvements)
- [Failed and Current Versions](#failed-and-current-versions)
  - [0.0 Breadboard](#00-breadboard)
  - [0.1 PCB ver. 15](#01-pcb-ver-15)
  - [0.2 PCB ver. 27](#02-pcb-ver-27)
  - [0.3 (Current Version) PCB ver.51](#03-current-version-pcb-ver51)

# Systemoverview

## Hardware

### Concept
The hardware of the RLCV2 is split in different functional parts as shown in the image below.
<figure class="image">
  <img src="Pictures/Hardware%20and%20System%20overview.svg">
  <figcaption>Hardware concept and mechanical System overview</figcaption>
</figure>
The outer doted line is the system boundry. Arrows pointed out or in are interactions to the outside of the system. 

### Input Voltage and Voltage converter
The voltage regulator serves as a crucial element in the power supply setup, ensuring stable and regulated voltage levels for the different components. With an input voltage range of 12-24 V, it can accommodate a wide variety of power sources commonly used in electronic systems.

A switch-mode DC-DC regulator is employed to efficiently convert the higher input voltage to a steady 5 V supply. This regulator utilizes switching techniques to minimize power dissipation and maximize energy efficiency. Its primary purpose is to power components that require a 5 V operating voltage.

Within the microcontroller, there is an internal regulator responsible for generating a regulated voltage of 3.3 V. This internal regulator serves as a dedicated power source for the microcontroller itself and other components that operate at 3.3 V, such as the rotary encoder. This ensures that the microcontroller and associated peripherals receive the appropriate voltage level for reliable operation.

Furthermore, certain components within the system, namely the OLED display and RS485 chip, require a 5 V power supply. These components are connected to the 5 V output of the switch-mode DC-DC regulator, providing them with the necessary voltage for their proper functioning.

To assemble this power supply system, you can refer to the Bill of Materials (BOM) list, which provides a detailed inventory of all the required parts. The BOM list will guide you in procuring the specific voltage regulator, microcontroller, internal regulator, switch-mode DC-DC regulator, rotary encoder, OLED display, RS485 chip, and any other necessary components to build the power supply system.

By implementing this voltage regulator and power supply setup, you can ensure reliable and stable power distribution to the various components in your microcontroller-based system, enabling them to operate efficiently and effectively within their designated voltage ranges.

### RS485 / DMX module
The RS485 chip (SN 75176BD) plays a crucial role in receiving DMX data in the described system. This chip is specifically designed for reliable long-distance data communication using the RS485 standard. It enables the microcontroller to interface with DMX devices and interpret the incoming data.

To ensure proper communication with the RS485 chip, pull-up resistors are employed on the read and write data lines. These resistors serve to maintain the voltage levels and stabilize the communication signals between the microcontroller and the RS485 chip.

To facilitate signal looping, two RJ45 sockets are integrated into the system. These sockets allow for easy connection of the DMX signal, following the wiring conventions outlined in the English Wikipedia article for DMX. By adhering to these guidelines, the system can achieve compatibility and seamless integration with other DMX devices and networks.

In order to manipulate the waveform of the DMX signal, a wave resistor can be added to the circuit. This resistor can be toggled using a switch, allowing the user to determine the signal characteristics according to their requirements. This feature provides flexibility in controlling the signal behavior and adapting it to specific applications.

To protect the microcontroller's port from potential damage caused by the 5 V signal from the RS485 chip, a voltage divider circuit is implemented. This circuit converts the 5 V signal to a safer 3.3 V level, ensuring that the microcontroller's input port operates within its specified voltage range. This voltage divider prevents any potential harm to the microcontroller while enabling seamless communication between the RS485 chip and the microcontroller.

By incorporating the RS485 chip, pull-up resistors, RJ45 sockets, adherence to DMX wiring conventions, wave resistor with switch, and voltage divider circuit, the system can effectively receive DMX data, ensure reliable communication, and protect the microcontroller from potential voltage-related issues.

### ESP32-C3 Microcontroller
The microcontroller at the heart of the system is the ESP32-C3, a ready-to-use module available from Seeedstudio. This module incorporates the ESP32-C3 microcontroller chip, which offers a wide range of features and capabilities for seamless integration into various applications.

One of the notable strengths of the ESP32-C3 is its comprehensive connectivity functions. It supports various communication protocols, including Wi-Fi, Bluetooth, and UART, enabling seamless wireless communication with other devices and networks. These connectivity options provide flexibility and facilitate the exchange of data between the microcontroller and other devices or cloud-based services.

Operating within a 5 V input voltage range, the ESP32-C3 module can easily interface with power sources commonly found in electronic systems. This feature enhances the module's compatibility and simplifies the integration process.

As the central brain of the system, the ESP32-C3 microcontroller plays a pivotal role in controlling and coordinating the overall operation. It executes the program logic, processes incoming data, manages peripheral devices, and facilitates communication between different components. With its processing power, memory capacity, and built-in peripherals, the ESP32-C3 enables efficient and effective operation of the entire system.

The ESP32-C3 module, in its compact and ready-to-use form factor from Seeedstudio, offers a convenient solution for incorporating a powerful microcontroller into the system. With its connectivity functions, support for 5 V input voltage, and its role as the central brain of the system, the ESP32-C3 microcontroller module provides a solid foundation for building a wide range of applications.

### LED Strip and Mosfets
The system incorporates a 24 V COB RGB LED strip, chosen for its high brightness and the absence of visible dots. This type of LED strip offers an enhanced lighting experience, providing vibrant and uniform illumination.

To connect the LED strip to the circuit, soldering is required. Specifically, the LED strip needs to be soldered to the pin header JP1, as indicated in the circuit diagram. This ensures a secure and reliable electrical connection between the LED strip and the control circuitry.

The RGB channels of the LED strip are controlled using three MOSFETs. MOSFETs are widely used in power electronics due to their high switching speed, low power dissipation, and efficient power handling capabilities. In this case, the MOSFETs serve as electronic switches, enabling precise control over the RGB channels of the LED strip.

To ensure proper operation of the MOSFETs and prevent unintended activation, pull-down resistors are incorporated into the circuit. Pull-down resistors provide a defined low voltage level when the MOSFETs are not actively driven, ensuring that the RGB channels remain off by default. This helps maintain stability and prevent any unintended illumination of the LED strip when the MOSFETs are not actively controlled.

By employing a 24 V COB RGB LED strip, soldering it to pin header JP1, utilizing three MOSFETs for RGB channel control, and incorporating pull-down resistors, the system can effectively and precisely control the brightness and color of the LED strip, providing visually appealing and uniform lighting effects as desired.

### Periphery (OLED and rotary encoder)
The system incorporates an OLED display to provide visual information to the user. This display serves as a convenient interface between the hardware and the human user, offering a clear and concise way to present relevant data. The OLED display utilizes the I2C communication protocol, enabling seamless and efficient data transfer between the microcontroller and the display module.

In terms of the hardware design, the pull-up resistors for the OLED display are not necessary, as they are enabled in software. The software implementation takes care of setting up the internal pull-up resistors on the microcontroller's I2C bus, simplifying the hardware design by eliminating the need for additional external pull-up resistors.

To facilitate user input and navigation through the software, a rotary encoder with a button is employed. The rotary encoder allows the user to scroll through different pages or menus, making it easier to interact with the system. The button integrated into the encoder enables the user to make selections or trigger specific actions within the software.

In the hardware design, pull-up resistors for the rotary encoder are implemented at the hardware level and connected to the 3.3 V supply, as indicated in the circuit diagram. These resistors ensure a stable logic level for the signals from the rotary encoder, preventing any potential floating or undefined states that could impact the reliability of user input.

By incorporating the OLED display for information display, utilizing I2C communication, enabling software-based pull-up resistors for the display, and implementing hardware-based pull-up resistors for the rotary encoder, the system provides an intuitive and user-friendly interface. Users can easily view information on the OLED display while interacting with the system through the rotary encoder, enhancing the overall user experience.

### Conclusion Hardware
In conclusion, the described system incorporates various components and features to create an efficient and user-friendly interface between hardware and user. The system utilizes a voltage regulator and power supply setup to provide stable and regulated voltages to different components. The microcontroller, specifically the ESP32-C3 module, acts as the central brain, offering connectivity functions and operating within a 5 V input voltage range.

For data reception, an RS485 chip (SN 75176BD) is used, with pull-up resistors ensuring reliable communication. Two RJ45 sockets enable signal looping as per the DMX wiring conventions. The DMX signal can be manipulated using a wave resistor, and a voltage divider protects the microcontroller's port from a 5 V signal.

Controlling a high-brightness 24 V COB RGB LED strip is achieved through the use of three MOSFETs, with pull-down resistors to prevent unintended activation. An OLED display, utilizing I2C communication, provides visual information, while a rotary encoder with a button facilitates user input and navigation through the software.

Additionally, decoupling capacitors are employed for the power pins of the ICs. These capacitors serve to stabilize the power supply, reducing noise and voltage fluctuations that may interfere with the proper functioning of the integrated circuits. By strategically placing decoupling capacitors near the power pins, the system maintains clean and stable power delivery, enhancing the overall performance and reliability of the ICs.

Overall, the embedded system, comprising the power supply, microcontroller, RS485 chip, LED strip control, OLED display, and rotary encoder, provides a robust and user-friendly hardware and software interface. It enables efficient power distribution, reliable communication, visual feedback, and intuitive user input, making it suitable for various applications.

### Circuit Diagramm
<figure class="image">
  <img src="Pictures/Circuit%20Diagramm.svg">
  <figcaption>Circuit diagram of the PCB</figcaption>
</figure>

### Selected Parts / BOM
Below is the part list for building a RGB LED Tube with the controller inside. To assemble only a controller not all parts are needed. Total cost around 52,06 € (Y-M-D: 2023-05-16) for one lamp. I planned and bought these components to manifacture 10 lamps. Some Parts may therefore be cheaper per part. A BOM CSV file with the contents of the table below can be found in the PCB foulder.

|Name on PCB                   |Package                              |Value             |Name               |Vender      |Part Nbr.                                                                   |Price One at buy|Quantity|Total  |
|------------------------------|-------------------------------------|------------------|-------------------|------------|----------------------------------------------------------------------------|----------------|--------|-------|
|                              |                                     |                  |Display            |Amazon      |https://www.amazon.de/dp/B09J7T5SCL?psc=1&ref=ppx_yo2ov_dt_b_product_details|2,83 €          |1       |2,83 € |
|                              |                                     |                  |LED Profile        |Amazon      |https://www.amazon.de/dp/B07548TMKN?psc=1&ref=ppx_yo2ov_dt_b_product_details|11,95 €         |1       |11,95 €|
|                              |                                     |                  |Filament           |Amazon      |https://www.amazon.de/dp/B083Y5G2GJ?psc=1&ref=ppx_yo2ov_dt_b_product_details|5,00 €          |1       |5,00 € |
|                              |                                     |                  |Stativ             |Amazon      |https://www.amazon.de/dp/B09LQP5XXM?psc=1&ref=ppx_yo2ov_dt_b_product_details|5,00 €          |1       |5,00 € |
|                              |                                     |                  |Threaded inserts   |Amazon      |https://www.amazon.de/dp/B09CL453M5?psc=1&ref=ppx_yo2ov_dt_b_product_details|0,24 €          |2       |0,48 € |
|J1                            |694106402002                         |                  |DC Jack            |Reichelt    |LUM NEBJ 21                                                                 |0,62 €          |1       |0,62 € |
|C7, C9                        |C0805                                |100n              |                   |Mouser      |581-08055C104K                                                              |0,04 €          |2       |0,07 € |
|C1, C2, C3, C4, C5            |C1206                                |100n              |                   |Mouser      |80-C1206104K5RAC7867                                                        |0,04 €          |5       |0,19 € |
|R1, R2, R3, R4, R5, R7, R8, R9|R1206                                |10k               |                   |Mouser      |279-CRG1206F10K                                                             |0,02 €          |8       |0,16 € |
|C6                            |C0805                                |10uF              |                   |Mouser      |80-C0805C106K8P                                                             |0,07 €          |1       |0,07 € |
|R11                           |R0805                                |115k              |Rfbb               |Mouser      |708-RMCF0805FT22K1                                                          |0,02 €          |1       |0,02 € |
|R10                           |R1206                                |120               |R 120              |Reichelt    |RND 1551206 AH                                                              |0,02 €          |1       |0,02 € |
|L1                            |SRN6045                              |15uH              |Inductor 15uH      |Mouser      |963-NRS6045T150MMGK                                                         |0,24 €          |1       |0,24 € |
|R6                            |R1206                                |20k               |R 20 k             |Reichelt    |SMD 1/4W 20K                                                                |0,06 €          |1       |0,06 € |
|R12                           |R0805                                |22.1k             |Rfbt               |Mouser      |652-CR0805FX-1153ELF                                                        |0,03 €          |1       |0,03 € |
|C8                            |C0805                                |4.7uF             |C 4,7u             |Mouser      |81-GRM21BZ7YA475KE5K                                                        |0,13 €          |1       |0,13 € |
|Q1, Q2, Q3                    |SOT23                                |IRLML 0040        |Mosfet             |Mouser      |942-IRLML0040TRPBF                                                          |0,39 €          |3       |1,17 € |
|JP1                           |1X04                                 |                  |LED Strip          |Amazon      |https://www.amazon.de/dp/B0B3RQ8LR7?psc=1&ref=ppx_yo2ov_dt_b_product_details|11,20 €         |1       |11,20 €|
|H1                            |3,2-PAD                              |MOUNT-PAD-ROUND3.2|                   |            |                                                                            |0,00 €          |1       |0,00 € |
|JP2                           |1X04                                 |OLED              |Buchsenleiste      |Reichelt    |MPE 094-1-004                                                               |0,21 €          |1       |0,21 € |
|EN1                           |PEC11L-4220F-S0015                   |PEC11L-4220F-S0015|Rotary Encoder     |Reichelt    |STEC12E08                                                                   |2,35 €          |1       |2,35 € |
|J2, J3                        |555153-1                             |RJ45 8P8C         |RJ45               |Mouser      |530-SS-90000-013                                                            |1,22 €          |2       |2,44 € |
|D1                            |DO-214AC                             |SK 14 DIO         |Diode SK 14        |Reichelt    |SK 14 DIO                                                                   |0,07 €          |1       |0,07 € |
|IC1                           |SO08                                 |SN 75176BD        |SN75176            |Mouser      |595-SN75176BDR                                                              |1,09 €          |1       |1,09 € |
|TP1, TP2, TP3                 |PAD.03X.04                           |TEST-POINT3X4     |                   |            |                                                                            |0,00 €          |3       |0,00 € |
|S1                            |TL3XYO                               |TL36YO            |Switch             |Mouser      |611-OS102011MA1QN1                                                          |0,39 €          |1       |0,39 € |
|U2                            |TEXAS_SOT23-6                        |TPS560430         |Switching Regulator|Mouser      |595-LMR54406FDBVR                                                           |0,75 €          |1       |0,75 € |
|U1                            |XIAO-ESP32C3-MODULE14P-2.54-21X17.8MM|XIAO-ESP32C3      |Microcontroller    |Seeed Studio|https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html                  |5,00 €          |1       |5,00 € |

## Software

### Concept 
<figure class="image">
  <img src="Pictures/Software%20concept.svg">
  <figcaption>Software concept of the different pages and modes</figcaption>
</figure>
With the push of the button you can cycle through a submenu. A long press of that button will cycle through the main menu. With a double click you can save the current variables to the EEPROM (simulated with portion of the flash memory). 
 
### Uploading the Software (Flash the ESP32-C3)
The easiest way to upload the code to the ESP32-C3 Board is to use the Arduino IDE. 
<figure class="image">
  <img src="Pictures/Arduino%20IDE.png">
  <figcaption>Arduino IDE preferences</figcaption>
</figure>

In order to flash the board, you need to add the following link to the prefercences under the section **_Additional boards manager URLs:_** https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json. Hit ok and search for ESP32 with the boards manager of arduino. Install the esp32 boards by Espressif Systems. You can then select the XIAO ESP32-C3 board and upload the software to the microcontroller.

### Bugs and improvements
If you find any bugs or have suggestions for improvments, let me know via GitHub.

# Failed and Current Versions
## 0.0 Breadboard
Before designing and ordering a PCB a breadboard with jumper cables were used to build a prototype. As it was working I moved on to build a pcb with all components.

## 0.1 PCB ver. 15
The first attempt of designing the pcb for the controller failed as I got the footprint of the L7805 voltage regulator wrong. I didn't check the footprint before. Always check, if the footprint you are using is the right one and don't be as silly as I was. 
Another Problem is that the regulator got really hot when feeding 24 V. 
<Picture>

## 0.2 PCB ver. 27
The seccond pcb has now the right footprint for the voltage regulator. The voltage Regulator still gets hot but I thought with some vias and ground planes I can fix this issue. Turns out after running the pcb for a while, the regulator can't supply enough current due to getting too hot for all parts to work properly.

## 0.3 (Current Version) PCB ver.51
The current version of the pcb has now a switch mode DC-DC converter instead of a linear regulator. The pull up and pull down resitors of the RS-485 Bus have been removed. The 10k resitor of the voltage divider for the RX signal has been moved to the other resitor of that divider. 