# Hermes
This is a project that detects motion/object presence. It  uses a TOF distance sensor to detect an object moving or in general. Once the sensor detects it, it sends the signal to the LED to flash. There is also a button that allows for the ability to change units and modes. This makes it work like a motion sensor too, batteries have been included for better mobility and placement of this device.

# Why
I made this project so I can do more complex things in Kicad and have a better understanding on how to use footprints and symbols. This is the first time that I had to go and find them completely on my own. I also added SMD components that will make it cooler. I also added an OLED screen that I can integrate functionality into. Overall, its just a complexity upgrade from my last project so that I can get more into hardware

# Some Pics
<img width="1360" height="766" alt="Screenshot 2026-04-07 163425" src="https://github.com/user-attachments/assets/0677e3e8-99cd-44cf-af4e-764ec9d4a7df" />
<img width="1431" height="981" alt="image" src="https://github.com/user-attachments/assets/3a4a8b57-43a9-4d4a-8c75-79b85d52d922" />
<img width="1552" height="770" alt="image" src="https://github.com/user-attachments/assets/586cfc9c-8503-47ff-8f67-09e8dc4bbdf3" />
<img width="1184" height="620" alt="image" src="https://github.com/user-attachments/assets/042cfd47-7f8c-4c3d-9f53-4804132fd615" />
<img width="1228" height="612" alt="image" src="https://github.com/user-attachments/assets/4d0bfce5-8d68-4fd9-aff5-e14dc89be5ad" />

# BOM Table
| Name | Purpose | Quantity | Total Cost (USD) | Distributor | Link |
|------|---------|:--------:|-----------------:|-------------|------|
| PCB | Where everything is on top of | 1 | $2.00 | JLCPCB | N/A |
| VL53L1CXV0FY/1 | Proximity Sensor | 1 | $5.77 | Digikey | [Buy](https://www.digikey.com/en/products/detail/stmicroelectronics/VL53L1CXV0FY-1/8258055) |
| CONN HEADER VERT 1POS 2.54MM | Connection from battery pack | 10 | $0.29 | Digikey | [Buy](https://www.digikey.com/en/products/detail/adam-tech/PH1-01-UA/9830231) |
| RES 110 OHM 5% 1/8W AXIAL | Resistor | 10 | $0.22 | Digikey | [Buy](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF18JT110R/1741570) |
| DIODE SCHOTTKY 20V 1A DO41 | Prevent reverse flow into batteries | 1 | $0.18 | Digikey | [Buy](https://www.digikey.com/en/products/detail/smc-diode-solutions/1N5817/21705460) |
| XIAO RP2040 | MC | 1 | $4.68 | Digikey | [Buy](https://www.digikey.com/en/products/detail/seeed-technology-co-ltd/102010428/14672129) |
| RES 4.7K OHM 5% 1/8W AXIAL | Resistor | 10 | $0.20 | Digikey | [Buy](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF18JT4K70/1741708) |
| CONN HDR 4POS 0.1 GOLD PCB | 4 Pin connector | 1 | $0.38 | Digikey | [Buy](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PPPC041LFBN-RC/810176) |
| CAP CER 0.1UF 50V Z5U RADIAL | Capacitator | 2 | $0.72 | Digikey | [Buy](https://www.digikey.com/en/products/detail/kemet/C315C104M5U5TA/817927) |
| RES 10K OHM 5% 1/4W AXIAL | Resistor | 10 | $0.20 | Digikey | [Buy](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT10K0/1741265) |
| BATT HOLDER AA 3 CELL 6" LEADS | Hold Batteries | 1 | $1.76 | Digikey | [Buy](https://www.digikey.com/en/products/detail/keystone-electronics/2465/303814) |
| LED RED DIFFUSED 5MM ROUND T/H | For light | 1 | $0.16 | Digikey | [Buy](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/151051RS11000/4490012) |
| Solder Flux | For my Non-THT components | 1 | $5.99 | Amazon | [Buy](https://www.amazon.com/Solder-Liquid-Soldering-Electrical-Electronics/dp/B0FF793RRY/) |
| PCB Holder | To hold my THT components | 1 | $8.99 | Harbor Freight | N/A |
| D6R90 F2 LFS | Button | 1 | $1.56 | Digikey | [Buy](https://www.digikey.com/en/products/detail/c-k/D6R90-F2-LFS/1466352) |
| Shipping | Move these parts | 1 | $3.12 | JLCPCB, Digikey | N/A |
| Tax | I have to pay | 1 | $4.47 | Digikey | N/A |
| **Total** | | | *$40.69* | | |

