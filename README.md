# **RLCV2**

**RGB LED Controller Version 2**

---
# Table of Contents
- [**RLCV2**](#rlcv2)
- [Table of Contents](#table-of-contents)
- [Systemoverview](#systemoverview)
  - [Hardware](#hardware)
    - [Systemoverview](#systemoverview-1)
    - [Selected Parts / BOM](#selected-parts--bom)
  - [Software](#software)
    - [Concept](#concept)
    - [Uploading the Software](#uploading-the-software)
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

### Selected Parts / BOM
Below is the part list for building a RGB LED Tube with the controller inside. To assemble only a controller not all parts are needed. Total cost around 52,23 € (2023.05.16) for one lamp. I planned and bought these components to manifacture 10 lamps. Some Parts may therefore be cheaper per part.
<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  overflow:hidden;padding:10px 5px;word-break:normal;}
.tg th{border-color:black;border-style:solid;border-width:1px;font-family:Arial, sans-serif;font-size:14px;
  font-weight:normal;overflow:hidden;padding:10px 5px;word-break:normal;}
.tg .tg-3qbk{border-color:inherit;color:#3166ff;text-align:left;vertical-align:top}
.tg .tg-h6w4{border-color:inherit;font-size:15px;font-weight:bold;text-align:left;vertical-align:top}
.tg .tg-0pky{border-color:inherit;text-align:left;vertical-align:top}
</style>
<table class="tg">
<thead>
  <tr>
    <th class="tg-h6w4">Name</th>
    <th class="tg-h6w4">Distributor</th>
    <th class="tg-h6w4">Part number</th>
    <th class="tg-h6w4">Cost per Part</th>
    <th class="tg-h6w4">Amount</th>
    <th class="tg-h6w4">Cost</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td class="tg-0pky">R 120</td>
    <td class="tg-0pky">Reichelt</td>
    <td class="tg-0pky">RND 1551206 AH</td>
    <td class="tg-0pky">0,02 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,02 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Knob Rotary Enc</td>
    <td class="tg-0pky">Reichelt</td>
    <td class="tg-0pky">KNOPF 10-150B</td>
    <td class="tg-0pky">0,16 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,16 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">DC Jack</td>
    <td class="tg-0pky">Reichelt</td>
    <td class="tg-0pky">LUM NEBJ 21</td>
    <td class="tg-0pky">0,62 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,62 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">R 20 k</td>
    <td class="tg-0pky">Reichelt</td>
    <td class="tg-0pky">SMD 1/4W 20K</td>
    <td class="tg-0pky">0,06 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,06 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Buchsenleiste</td>
    <td class="tg-0pky">Reichelt</td>
    <td class="tg-0pky">MPE 094-1-004</td>
    <td class="tg-0pky">0,21 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,21 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Rotary Encoder</td>
    <td class="tg-0pky">Reichelt</td>
    <td class="tg-0pky">STEC12E08</td>
    <td class="tg-0pky">2,35 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">2,35 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">RJ45</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">530-SS-90000-013</td>
    <td class="tg-0pky">1,22 €</td>
    <td class="tg-0pky">2</td>
    <td class="tg-0pky">2,44 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Diode SK 14</td>
    <td class="tg-0pky">Reichelt</td>
    <td class="tg-0pky">SK 14 DIO</td>
    <td class="tg-0pky">0,07 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,07 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">C 100n 1206</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">80-C1206104K5RAC7867</td>
    <td class="tg-0pky">0,04 €</td>
    <td class="tg-0pky">5</td>
    <td class="tg-0pky">0,19 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Switch</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">611-OS102011MA1QN1</td>
    <td class="tg-0pky">0,39 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,39 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">SN75176</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">595-SN75176BDR</td>
    <td class="tg-0pky">1,09 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">1,09 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Mosfet</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">942-IRLML0040TRPBF</td>
    <td class="tg-0pky">0,39 €</td>
    <td class="tg-0pky">3</td>
    <td class="tg-0pky">1,16 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">R 10k</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">279-CRG1206F10K</td>
    <td class="tg-0pky">0,02 €</td>
    <td class="tg-0pky">8</td>
    <td class="tg-0pky">0,19 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Switching Regulator</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">595-LMR54406FDBVR</td>
    <td class="tg-0pky">0,75 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,75 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">C 10u</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">80-C0805C106K8P</td>
    <td class="tg-0pky">0,07 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,07 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">C 100n 0805</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">581-08055C104K</td>
    <td class="tg-0pky">0,04 €</td>
    <td class="tg-0pky">2</td>
    <td class="tg-0pky">0,07 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Inductor 15uH</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">963-NRS6045T150MMGK</td>
    <td class="tg-0pky">0,24 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,24 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">C 4,7u</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">81-GRM21BZ7YA475KE5K</td>
    <td class="tg-0pky">0,13 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,13 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Rfbt</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">652-CR0805FX-1153ELF</td>
    <td class="tg-0pky">0,03 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,03 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Rfbb</td>
    <td class="tg-0pky">Mouser</td>
    <td class="tg-0pky">708-RMCF0805FT22K1</td>
    <td class="tg-0pky">0,02 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,02 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">PCB</td>
    <td class="tg-0pky">JLCPCB</td>
    <td class="tg-3qbk"><a href="https://jlcpcb.com/" target="_blank" rel="noopener noreferrer">https://jlcpcb.com/</a></td>
    <td class="tg-0pky">0,54 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">0,54 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Display</td>
    <td class="tg-0pky">Amazon</td>
    <td class="tg-3qbk"><a href="https://www.amazon.de/dp/B09J7T5SCL?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details" target="_blank" rel="noopener noreferrer">https://www.amazon.de/dp/B09J7T5SCL?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details</a></td>
    <td class="tg-0pky">2,83 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">2,83 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">RGB LED Strip</td>
    <td class="tg-0pky">Amazon</td>
    <td class="tg-3qbk"><a href="https://www.amazon.de/dp/B0B3RQ8LR7?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details" target="_blank" rel="noopener noreferrer">https://www.amazon.de/dp/B0B3RQ8LR7?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details</a></td>
    <td class="tg-0pky">11,20 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">11,20 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">LED Profile</td>
    <td class="tg-0pky">Amazon</td>
    <td class="tg-3qbk"><a href="https://www.amazon.de/dp/B07548TMKN?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details" target="_blank" rel="noopener noreferrer">https://www.amazon.de/dp/B07548TMKN?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details</a></td>
    <td class="tg-0pky">11,95 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">11,95 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Filament</td>
    <td class="tg-0pky">Amazon</td>
    <td class="tg-3qbk"><a href="https://www.amazon.de/dp/B083Y5G2GJ?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details" target="_blank" rel="noopener noreferrer">https://www.amazon.de/dp/B083Y5G2GJ?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details</a></td>
    <td class="tg-0pky">5,00 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">5,00 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Stativ</td>
    <td class="tg-0pky">Amazon</td>
    <td class="tg-3qbk"><a href="https://www.amazon.de/dp/B09LQP5XXM?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details" target="_blank" rel="noopener noreferrer">https://www.amazon.de/dp/B09LQP5XXM?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details</a></td>
    <td class="tg-0pky">5,00 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">5,00 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Threaded inserts</td>
    <td class="tg-0pky">Amazon</td>
    <td class="tg-3qbk"><a href="https://www.amazon.de/dp/B09CL453M5?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details" target="_blank" rel="noopener noreferrer">https://www.amazon.de/dp/B09CL453M5?psc=1&amp;ref=ppx_yo2ov_dt_b_product_details</a></td>
    <td class="tg-0pky">0,24 €</td>
    <td class="tg-0pky">2</td>
    <td class="tg-0pky">0,48 €</td>
  </tr>
  <tr>
    <td class="tg-0pky">Microcontroller</td>
    <td class="tg-0pky">Seeed Studio</td>
    <td class="tg-3qbk"><a href="https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html" target="_blank" rel="noopener noreferrer">https://www.seeedstudio.com/Seeed-XIAO-ESP32C3-p-5431.html</a></td>
    <td class="tg-0pky">5,00 €</td>
    <td class="tg-0pky">1</td>
    <td class="tg-0pky">5,00 €</td>
  </tr>
</tbody>
</table>

## Software

### Concept 
<figure class="image">
  <img src="Pictures/Software%20concept.svg">
  <figcaption>Software concept of the different pages and modes</figcaption>
</figure>

### Uploading the Software
The easiest way to upload the code to the ESP32-C3 Board is to use the Arduino IDE. 

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