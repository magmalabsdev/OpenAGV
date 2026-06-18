<img width="1485" height="2100" alt="zine" src="https://github.com/user-attachments/assets/61d6504a-ef19-4695-88a7-2ccae41b2959" />

# OpenAGV

A fully autonomous railcar for item transportation. When called remotely via wifi, the railcar autonomously navigates along a set of tracks using preplaced NFC tags to navigate to its destination. 
The car can be called from WiFi in an app. Doors should automatically open when it arrives 
at its destination. From there, load or unload your items, complete the task in the app, and the railcar will navigate to its next destination. 

Onshape (cad)

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

# How to build

## Tools required
You will need access to an FDM 3d printer, and ideally an SLA 3d printer for transparent parts, though the car will function without transparent parts. 
Also needed are 
- Screwdriver
- Soldering iron and soldering materials
- Glue (for magnets)

## Building the drivetrain

### Parts needed
- Produce the following parts
  - 2X Side structural plate
  - 2X Motor Structural Plate
  - 1X Bottom Structural Plate
  - 1X Railcar Back Panel (in elec bay)
  - 4X 5mm OD 55mm L Steel Shaft
  - 4X 8mm OD 5mm ID 10mm L Spacer
  - 2X Servo horn to hinge coupler
  - 2X Rail Navigation Pointer
  - 2X Custom Servo Horn
  - 2X 3mm OD 10mm L Steel Shaft


- Prepare the following parts
  - 2X Brushless Motor D3536 100KV
  - 4X 2GT Timing Pulley Bore 2mm 60T
  - 2X 2GT Timing Pulley Bore 2mm 20T Double sided
  - 4X 85m Solid Large Load Bearing Rubber Tyre
  - 2X 2mm Pitch GT2 Timing Belt 108 Tooth
  - 2X MG995 55G (or similar) Servo Motor
  - 6X F624ZZ Ball Bearings
  - 2X PN532 NFC Reader
 
  - 4X M4x4 Socket Screw
  - 41X M4x8 Countersunk Screw
  - 4X M4x8 Socket Screw
  - 8X M3 Nut
  - 8X M3x6 Countersunk Screw
  - 8X M3x12 Socket Screw
  - 2X M2.5 Large Washer
  - 2X M2.5 X 6 Socket Screw
  - 8X M3x10 Socket Screw
  - 2X M3x6 Button Screw
  - 18X M3 Threaded Insert
  - 49X M4 Threaded Insert
 

### Assembling the motor plates

- Install 14 M4 threaded inserts on the edge holes of the motor plate
- Attach motor to motor plate using the included mounting bracket and four M3 nuts
- Push bearings into place on motor plate with the flange on the opposite side of the motor
- Attach dual 20T pulley to motor shaft using its coupler through the center bearing
- Install two steel shafts through the remaining bearings
- Install wheels on the motor side of the plate using their couplers
- Position the plate with the motor and wheels on the left side
- Install one 60T Pulley with its belt on the lower wheel
    - the coupler should facing right
- Place a 10mm spacer ton the other wheel shaft
- Install the other pulley with the coupler touching the spacer
- Install its matching belt
- Repeat for both motor plates, mirroring your steps the other one

### Assembling the drivetrain

- Ensure you have wires coming out of the servo motors and PN532 NFC readersm at least 100mm long
- Assemble two motor plates using the instructions above
- Install 16 M4 threaded inserts in the sides and on the servo mounting blocks of the bottom structural plate
- Install 2 M3 threaded inserts in the two PCB mounting standoffs on the bottom structural plate
- Install the PN532 using its two mounting holes and two M3x6 Button screws

- Assemble two servo motors using four M4x8 socket screws
- Place the railcar with the servo shafts facing up
- Install 4 M3 threaded inserts into each custom servo horn
- Assemble and screw down the custom servo horns using the M2.5 screws and washers
- Couple the servo horn to hinge couplers to the servo horn using four M3x10 socket screws each
- Install a 3mm OD 10mm L shaft to connect a coupler to a navigation pointer
- Lock the shaft into place using two M4x4
- Repeat for both servos

- Install four M4 threaded inserts into the holes of the side structural plates
- Install eight M4 threaded inserts into the mounting holes of the railcar back panel
- Attach the bottom structural plate to one motor plate using M4x8 Countersunk screws
  - It should be obvious where this plate goes, it is the one with the bent bottom
- Attach two side structural plates on either side of the motor/bottom plate using using M4x8 Countersunk screws
- Attach the railcar back panel using its mounting holes
- Pre-route your cables through the four cable channels on the back panel
- Install the other motor plate on the other side, sealing everything together


## Building the electrical bay

### Parts needed
- Produce the following parts
  - 1X Railcar Back Panel
  - 1X Elec Bay Bottom Channel
  - 1X Elec Bay Top Channel
  - 1X Echo Mounting Brace
  - 1X LED Matrix Mounting Brace
  - 1X I2C Multiplexer Mounting Brace
  - 2X Buck Converter Mounting Brace
  - 1X Elec-Cargo Bay Separation Panel
  - 5X Battery Clip
  - 2X Low Profile Battery Clip
  - 1X Secondary battery box
  - 14X 5mm OD 3.2mm ID 3mm H Custom Spacer
  - 8X 5mm OD 3.2mm ID 13mm H Custom Spacer
  - 10X 5mm OD 3.2mm ID 29mm H Custom Spacer


- Prepare the following parts
  - 1X 3DBuffalo Echo control board
  - 2X Zeee 4S 14.8V 3300mAh Lipo
  - 1X 650mAh 120C 3S Lipo
  - 2X 30A Brushless ESC
  - 1X XT30 to Bare Wire
  - 1X TCA9548A I2C 8-Channel Multiplexer
  - 2X LM2596 DC-DC Buck Converter Module
  - 1X MAX7219 Dot Matrix 8 in 1 Display Module
 
  - 10X M3x6 Button Screw
  - 18X M3x8 Button Screw
  - 4X M3x10 Button Screw
  - 8X M3x18 Button Screw
  - 3X M3x4 Countersunk Screw
  - 10X M3x35 Countersunk Screw
  - 45X M3 Threaded Insert

### Assembling the mounting hardware

- Install M3 threaded inserts in the mounting holes indicated on the diagram
(yellow dot = insert here)
<img width="415" height="636" alt="Screenshot 2026-06-17 at 4 54 59 PM" src="https://github.com/user-attachments/assets/425fe75d-cfc8-4cec-a721-1a355ef39668" />

- Tape down any wires you routed from the drivetrain temporarily
- Install M3 threaded inserts in the following positions on each mounting brace
  - Echo: The four corner holes on the ourside
  - Buck converter: The two holes on the ends
  - I2C Multiplexer: The two holes in the center
- Install 12 M3 threaded inserts in the mounting holes on the top and bottom electrical channels respectively
- Mount both channels to the back panel. The panel is symmetric so position does not matter for now
- Install the small battery box using three M3x4 countersunk screws
- Place the secondary battery into this box with wires facing outward
- Install the Echo mounting brace in the area between all four rectangular routing holes using M3x8 screws
  - There is only one position that fits

- Install two buck converter braces in the positions shown on the diagram with M3x8 screws
- Install the I2C Multiplexer brace in the position indicated in the diagram using M3x8 screws
- Install five battery clips using M3x6 screws as indicated in the diagram
- Install two low profile battery clips bordering the battery and LED matrix using M3x6 screws

### Assembling the electronics

- Install the Echo using M3x8 screws through 3mm spacers to its mounting brace, ensuring the GPIO is on the I2C Multiplexer side
- Install the buck converters onto their mounting braces ensuring IN faces the battery (for the echo) and the OUT faces the near end of the LED matrix (for the led matrix)
- Install the I2C Multiplexer onto its mounting brace using M3x8 screws
- Install the LED matrix onto its mounting brace from behind, using the 13mm spacers and M3x18 screws
- Install the LED matrix mounting brace onto the board using M3x10 screws and placing 3mm spacers below the brace
- Place both batteries in the locations indicated by the diagram
  - Route battery wires through the holes in the low profile battery clips
- Use the remaining mounting holes to zip tie ESCs to the board
- Connect the ESC power wires to the motor and battery

### Routing the wires
- Route wires according to this wiring diagram

<img width="996" height="601" alt="Screenshot 2026-06-13 at 4 59 33 PM" src="https://github.com/user-attachments/assets/1c9831b4-b67b-42de-89ea-ff7100107c8e" />

- When done routing wires
  - Place 10 29mm spacers on the edges of the board
  - Place the elec-cargo separation panel on top of these spacers
  - Screw down the panel using the M3x35 countersunk screws
 

## Building the windshields

### Parts needed
- Produce the following parts
  - 2X Unibody Windshield Frame
  - 2X Window
  - 14X Logo tile (6 spokes + 1 core)


- Prepare the following parts
  - 8X VL53L1X Lidar Sensor (4 per windshield)
  - 2X MAX7219 Dot Matrix 4 in 1 Display Module
 
  - 6X M3x5 Socket Screw
  - 8X M2x5 Socket Screw
  - 8X M3x5 Countersunk Screw

  - 18X M3 threaded insert


### Assembling the windshield

- Ensure you have wires running out of the LED matrices and Lidar sensors
- Install eight M4 threaded inserts in the sides of the windshield
- Install six M3 threaded inserts in the window mounting holes
- Paint or glue the seven colors of the logo as follows
  - Center: purple core
  - Top: Blue
  - Bottom: Green
  - Upper right: White
  - Lower right: yellow
  - Upper left: red
  - Lower left: orange
- Install the LED matrix using the M3x5 countersunk screws. 
- Install the window using the M3x5 socket screws
- Install four VL53L1X Lidar sensors using the M2 screws
- Route wires through the top and bottom channels of the windshield to the electrical bay
- Repeat for both windshields


## Building the door

### Parts needed
- Produce the following parts
  - 1X Door Bay Bottom Channel
  - 1X Door Bay Top Channel
  - 2X Door Bay Cap
  - 2X Upper Belt Clamp
  - 2X Lower Belt Clamp
  - 2X Door Endstop Magnetic Latch
  - 14X Custom Transparent Door Panel
  - 2X 3mm OD 30mm L Steel Shaft
  - 16X 2mm OD 150mm L Aluminum Shaft


- Prepare the following parts
  - 2X GA12-N20 (12V 500RPM) Gear Motor
  - 4X 20 Teeth 3mm Bore Timing Pulley
  - 2X 2mm Pitch GT2 Timing Belt 188 Tooth
  - 1X Set Screw Collars 3.05mm (10pcs)
  - 1X Flanged Ball Bearing 3mmx6mmx2.5mm (10pcs)
 
  - 4X M2x5 Socket Screw
  - 28X M3x10 Socket Screw
  - 4X M1.6x3 Socket Screw
  - 24X M3x5 Countersunk Screw
  - 4X M2 Nut
  - 6X 6x2 Round Magnet
  - 32X M3 Helicoil Insert
  - 24X M3 Heat Set Insert
  - 24X M4 Heat Set Insert


### Assembling the motion system

- Install M4 heat set inserts into the holes nearest the connecting bottom plate on the top and bottom chanels
- Install M3 heat set inserts into the countersunk holes on the top and bottom channels
- Push and lock four flanged bearings into the four larger holes in the center of the bottom channel, with the flange on the inside
- Install a 3mm shaft with a 20T pulley, shaft collar, and GT2 belt through both sets of bearings
- Clamp the shaft collar on the side of channel with wings
- Clamp the pulley with the collar facing towards the other shaft collar on the other side
- Using the M1.6 screws, install N20 motors onto the wings of the door bay bottom channel
- Couple a 20T 3mm pulley onto each motor shaft, connecting the other side of the belt
- Clamp the upper and lower belt clamps together on the belt, drilling small holes as needed and using the M2 screws


### Assembling the door panels

- Install helicoil inserts into the holes on the ends of door panels
- To attach two door panels together, thread a hole between their hinges and use M3x10 screws to lock them in place
- Repeat until you have 7 panels connected together
- Ensure one of your rods (the one on one end) is longer and extends below the door panels
- On the ends of the doors, attach magnetic endstop latches the same way
- Glue magnets in holes into the latches
- Assemble the door bay caps using the countersunk holes and M3x5 countersunk screws
- Glue the extended rod into the belt clamp's hole through the channel in the door bay caps

## Building the cargo bay


### Parts needed
- Completed assemblies required
  - Electrical bay
  - 2X windshield
  - Door 

- Produce the following parts
  - 1X Cargo Bay Bottom Panel
  - 1X Cargo Bay Base
  - 1X Cargo Bay Cover
  - 1X Front Cover Plate
  - 1X 8x4 Gridfinity Baseplate


- Prepare the following parts
  - 4X Pogo Pins Kit
 
  - 46X M4x10 Countersunk Screw
  - 24X M4x15 Socket Screw
  - 24X M3x8 Button Screw
  - 24X M3x5 Countersunk Screw
  - 104X 6x2 Round Magnet
  - 48X M3 Threaded Insert
  - 70X M4 Threaded Insert

### Assembly instructions

- Install M4 threaded inserts into the up-down facing spacers on the cargo bay base
- Install M3 threaded inserts into the small holes in the panel of the cargo bay base
- Mount both windshields to the electrical bay panel using M4x10 Countersunk Screws
- Mount pogo pin pads in holes on the cargo bay base using M1.6x8 screws and nuts
- Mount gridfinity baseplate onto cargo bay base using M3x8 button screws
- Route pogo pin wires through windshield channels to electrical bay
- Glue magnets in the remaining holes on the baseplate, ensuring the magnet's north pole faces up
- Mount the cargo bay base to the electrical bay channel using M4x15 Socket screws
- Similarly, mount the cargo bay cover window to the electrical bay channel
- Install the upper door channel with the cover plate preinstalled next to the cargo bay cover window using M4x15 screws
- Install the door assembly on the bottom using M4x15 screws, ensuring the screws on the door panels fit into the channels on the cover plates
- Cover the cargo bay base using the cargo bay cover and the M4x10 countersunk screws
- Finally, install the front cover plate using M4x10 Countersunk Screws



# Why I built this

Smart appliances exist everywhere now: washing machines, robot vacuum cleaners, and dishwashers all automate some component of a repetitive chore. But something these appliances don't have is integration. After one is done, you still have to manually transport items to the next appliance to begin its next operation. You still have to refill its supplies manually. 

OpenAGV bridges this gap. This railcar is designed to be able to move in any orientation and carry a large volume of items. It supports up to seven auxillary bay motors for the cases where the railcar alone can't fully automate a task. And the base is fully modular to allow for infinite configurations for unique, high complexity tasks.

Imagine your roomba runs out of cleaning fluid. After notifying a railcar, the car can drive to a specially designed shelf, pick up the required item, drive to the roomba's docking station, and refill it entirely automatically. 

Or say you're cooking dinner and forget a specific ingredient. Instead of taking your hands off the task at hand, you tell your smart speaker assistant to bring it to you. It sends a command to the railcar which navigates to the shelf, picks up the item, and brings it to you. 

OpenAGV can also be used within machines where destination count is high and traffic is low enough that building a conveyor belt would be impractical. 

These are just the surface of what a compact, wall mounted railcar like this enables. [zine.pdf](https://github.com/user-attachments/files/29071181/zine.pdf)
[zine.pdf](https://github.com/user-attachments/files/29071178/zine.pdf)



