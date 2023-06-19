# **RLCV2**

**RGB LED Controller Version 2**

---
# Table of Contents
- [**RLCV2**](#rlcv2)
- [Table of Contents](#table-of-contents)
- [Systemoverview](#systemoverview)
  - [Hardware](#hardware)
    - [Systemoverview](#systemoverview-1)
    - [Circuit Diagramm](#circuit-diagramm)
    - [Selected Parts / BOM](#selected-parts--bom)
  - [Software](#software)
    - [Concept](#concept)
    - [Uploading the Software (Flash the ESP32-C3)](#uploading-the-software-flash-the-esp32-c3)
    - [Bugs and improvements](#bugs-and-improvements)
- [Failed and Current Versions](#failed-and-current-versions)
  - [0.0 Breadboard](#00-breadboard)
  - [0.1 PCB ver. 15](#01-pcb-ver-15)
  - [0.2 PCB ver. 27](#02-pcb-ver-27)
  - [0.3 (Current Version) PCB ver.51](#03-current-version-pcb-ver51)

# Systemoverview

## Hardware

### Systemoverview 

The hardware of the RLCV2 is split in different functional parts as shown in the image below.
<figure class="image">
  <img src="Pictures/Hardware%20and%20System%20overview.svg">
  <figcaption>Hardware concept and mechanical System overview</figcaption>
</figure>
The outer doted line is the system boundry. Arrows pointed out or in are interactions to the outside of the system. 

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