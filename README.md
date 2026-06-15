<img width="1032" height="1032" alt="Frame" src="https://github.com/user-attachments/assets/0f6d7c56-ce42-44fd-baff-69bb2dc7045a" />

# OpenAGV

A fully autonomous railcar for item transportation. When called remotely via wifi, the railcar autonomously navigates along a set of tracks using preplaced NFC tags to navigate to its destination. 
The car can be called from WiFi in an app. Doors should automatically open when it arrives at its destination. From there, load or unload your items, complete the task in the app, and the railcar will navigate to its next destination. 
I built this because I'm a lazy bigback and I don't like pausing my coding/CADing/anythinging sessions to grab a snack, deliver an item, or for any reason. 

GitHub really doesn't like large STEP files so here's my onshape link

https://cad.onshape.com/documents/e8be59947376d7d19e89c19e/w/32dc181e05829722aa1fd0af/e/f831f93934d4714405e4e068


## Drivetrain

<img width="1244" height="998" alt="Screenshot 2026-06-13 at 5 10 01 PM" src="https://github.com/user-attachments/assets/acd96746-8602-4253-b3c7-66337a74d4dc" />

Uses dual 100KV 3536 motors with a 3:1 reduction to independently control left and right wheels.
Wheels are 85mm in diameter and 26mm thick
Includes two servo pointers for steering on top of asymmetric drive
Uses a PN532 NFC reader to confirm its position along tracks and intersections


## Electrical

<img width="996" height="601" alt="Screenshot 2026-06-13 at 4 59 33 PM" src="https://github.com/user-attachments/assets/1c9831b4-b67b-42de-89ea-ff7100107c8e" />

The electrical bay in the back of the railcar hold the primary electrical components including the Echo control board and all three batteries. The primary two batteries are independently wired to their respective motors while the third smaller battery is used to power onboard components.
Wires are routed through channels in the windshield, cargo bay, and door to their destinations. 

The control board is a 3DBuffalo Echo powered by an ESP32-S3. This board controls the drive motors through ESC, steering servos, door motors, navigation NFC reader and eight LiDAR sensors through a shared I2C bus, SD card slot, speaker, and three onboard LED matrices. 
One 64x8 LED matrix is placed inside of the railcar on the electrical bay.

This railcar supports UART communication, up to four bay servos, and up to three bay DC motors through pogo pins in the cargo bay for custom loading, unloading, and processing mechanisms.

## Windshield

<img width="804" height="822" alt="Screenshot 2026-06-13 at 5 07 01 PM" src="https://github.com/user-attachments/assets/3e25e2a0-1adb-46c5-a042-e49ada2c5b31" />

Each railcar has two windshields, one at each end. Each windshield includes four VL53L1X Lidar sensors for collision avoidance and an LED matrix to display relevant information. 
The top 28mm and bottom 32mm of each windshield consists of channels for running wires from other components into the electrical bay and to hold the sliding door. 
The majority of the remaining space in the windshield is taken up by a 3mm thick window.

## Cargo Bay & Door

<img width="856" height="574" alt="Screenshot 2026-06-13 at 5 22 42 PM" src="https://github.com/user-attachments/assets/de45edba-08e1-40cf-88fa-0bbb2a56b5db" />

The cargo bay has a storage volume of 336mm x 168mm x 180mm, all of which is directly accessible when the door is opened. The gridfinity baseplate along with pogo pins on the base allow for endless custom bay configurations for different use cases. 
The door uses a 7-panel hinged design driven by a N20 motor to rotate out of the way while requiring zero external clearance. A magnetic latch at the end of the door keeps it locked during standard operation. 
Door panels and the bay roof are entirely transparent allowing users to view the cargo from nearly all angles. 


## Tech Specs

<br>

|  |  |
| --- | --- |
| Cargo volume | 336mm x 168mm x 180mm |
| Railcar size | --- x 384mm x --- |
| Cargo bay interface  | Gridfinity |
| UI | Dual 32x8 LED dot display + 64x8 LED dot display |
| Supported auxillary servos | 4 |
| Lidar sensors | 8 |
| Battery size | 195.36 Wh |
| Motors | Dual A3536 100KV |
| Reduction | 3:1 |
| Control board | 3DBuffalo Echo |

