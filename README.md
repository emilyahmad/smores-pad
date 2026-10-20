# S'mores Pad

A s'mores themed macropad with 4 keys and a 0.91" OLED, powered by a XIAO ESP32-C3. The marshmallow keycaps (took apart from those popular toasted bread fidget keychains) and chocolate and graham-cracker inspired 3D printed make it a super cute accessory for fall. The XIAO's built-in USB-C is exposed on the side of the board for power and data.

Full build logs are in [JOURNAL.md](JOURNAL.md), and the parts list is in [bom.csv](bom.csv).

# Photos

| Schematic                           | PCB                           | Silkscreen                           |
| ----------------------------------- | ----------------------------- | ------------------------------------ |
| ![Schematic](/images/schematic4.png) | ![PCB](/images/final_pcb.png) | ![Silkscreen](/images/new_silkscreen.png) |

Board size: 45.87 x 57.85 mm

# BOM (Components)

| Item     | Purpose                | Quantity | Source                                                                                               |
| -------- | ---------------------- | -------- | ---------------------------------------------------------------------------------------------------- |
| U1       | XIAO ESP32-C3 (MCU)    | 1        | Seeed Studio                                                                                         |
| J1       | 0.91" 128x32 I2C OLED  | 1        | [Amazon](https://www.amazon.com/gp/product/B07PDFCVXL/ref=ox_sc_act_image_1?smid=A2ZDGCOOU4F0SF&psc=1) |
| J1       | 1x4 female pin socket  | 1        | for mounting the OLED                                                                                |
| R1, R2   | 4.7K I2C pull-ups (THT) | 2        | Arduino starter kit                                                                                  |
| SW1-SW4  | Cherry MX switches     | 4        | Amazon                                                                                               |
| Keycaps  | Marshmallow keycaps    | 4        | [Amazon](https://www.amazon.com/gp/product/B0GXKFVZB1/ref=ox_sc_act_title_2?smid=A2N8YDAE199BID&psc=1) |
| PCB      | Mounting and wiring    | 1        | JLCPCB                                                                                               |

# Firmware

Not written yet.
<!--  A test sketch that confirms the OLED works is in [Code/TestingOLED.cpp](Code/TestingOLED.cpp). Switches have no external pull-ups, so they'll use `INPUT_PULLUP` and be read as active-low.
 -->