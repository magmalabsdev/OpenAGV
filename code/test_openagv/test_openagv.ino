#include <EchoLib.h>
#include <LedControl.h>
#include <Servo.h>
#include <SPI.h>
#include <SD.h>
#include <string>
#include <Wire.h>
#include <array>

#define SPEAKER_PIN 40;

#define UPPER_MOTOR_PIN  41;
#define LOWER_MOTOR_PIN  42;

#define LEDMTX_DIN  9;
#define LEDMTX_CS  14;
#define LEDMTX_CLK  39;

#define WEST_DOOR_MOTOR  1;
#define EAST_DOOR_MOTOR  2;

#define MUX_ADDR 0x70 



MotorControllers mc =  MotorControllers();
LedControl lc = LedControl(DIN, CLK, CS,0);
ServoDriver sd;

Servo UPPER_ESC;
Servo LOWER_ESC;  

std::array<Adafruit_VL53L1X, 8> lidar {};

void setup() {



    Serial.begin(115200);
    
    while (!Serial) {
    delay(10);
    }
    Wire.begin();


    if (!SD.begin(10)) {
        Serial.println("initialization failed!");
        while (1);
    }

    File myFile = SD.open("test.txt");
    string text = myFile.read()
    Serial.write(text);
    myFile.close();

    UPPER_ESC.attach(UPPER_MOTOR_PIN,1000,2000);
    LOWER_ESC.attach(LOWER_MOTOR_PIN,1000,2000);

    servoDriver.init();
    
    lc.shutdown(0,false);
    lc.setIntensity(0,0);
    lc.clearDisplay(0);
    

}

void loop() {
    for(int j=0;j<8;j++){
         for(int i=0;i<8;i++){
            lc.setLed(0,j,i,true);
         }
    }

    UPPER_ESC.write(1023);




    for(int j=0;j<8;j++){
         for(int i=0;i<8;i++){
            lc.setLed(0,j,i,false);
         }
    }

    UPPER_ESC.write(0);
    delay(1000);

}


void tcaSelect(uint8_t bus) {
  if (bus > 7) return; // Only 8 channels available (0-7)
  
  Wire.beginTransmission(MUX_ADDR);
  Wire.write(1 << bus);          // Send a bitmask representing the active channel
  Wire.endTransmission();
}

void initializeLidar(){
    for(int i=0; i<8; i++){
        tcaSelect(i);
        Adafruit_VL53L1X vl53 = Adafruit_VL53L1X();
        lidar[i] = vl53;

        if (!vl53.begin(0x29 + i, &Wire)) {
            Serial.print("Error on init of VL sensor: ");
            Serial.println(vl53.vl_status);
            while (1) delay(10);
        }
        
        Serial.println("VL53L1X sensor found!");
        
        // Set distance range mode (1 = Short, 2 = Medium, 3 = Long)
        vl53.setDistanceMode(3);
        
        // Set timing budget (20ms, 33ms, or 100ms)
        vl53.setTimingBudget(100);

        // Start continuous ranging with 100ms inter-measurement period
        vl53.startRanging();

    }
    

}

void setMotorPower(float percentage){
    int toServoDegrees = (int) (percentage * 90 + 90)
    UPPER_ESC.write(toServoDegrees);
    LOWER_ESC.write(toServoDegrees);
}

std::array<int, 4> readWestLidar(){
    std::array<int, 4> westLidarChannels = {0, 1, 2, 3};
    std::array<int, 4> westLidarValues = {};

    for (int ch : westLidarChannels) {
        tcaSelect(ch);
        Adafruit_VL53L1X vl53 = lidar[ch]

        if (vl53.dataReady()) {
            int16_t distance = vl53.distance();
            
            if (distance == -1) {
            Serial.print("Couldn't get distance: ");
            Serial.println(vl53.vl_status);
            return;
            }
            westLidarValues[ch] = distance;
            
            vl53.clearInterrupt();
        }

    }       
    return westLidarValues;

}

std::array<int, 4> readEastLidar(){
    std::array<int, 4> eastLidarChannels = {4, 5, 6, 7};
    std::array<int, 4> eastLidarValues = {};

    for (int ch : eastLidarChannels) {
        tcaSelect(ch);
        Adafruit_VL53L1X vl53 = lidar[ch]

        if (vl53.dataReady()) {
            int16_t distance = vl53.distance();
            
            if (distance == -1) {
            Serial.print("Couldn't get distance: ");
            Serial.println(vl53.vl_status);
            return;
            }
            eastLidarValues[ch] = distance;
            
            vl53.clearInterrupt();
        }

    }       
    return eastLidarValues;
}

void openDoor(){
    motorControllers.set(WEST_DOOR_MOTOR, 100);
    motorControllers.set(EAST_DOOR_MOTOR, 100);
    delay(1000);
    motorControllers.set(WEST_DOOR_MOTOR, 0);
    motorControllers.set(EAST_DOOR_MOTOR, 0);
}

void closeDoor(){
    motorControllers.set(WEST_DOOR_MOTOR, -100);
    motorControllers.set(EAST_DOOR_MOTOR, -100);
    delay(1000);
    motorControllers.set(WEST_DOOR_MOTOR, 0);
    motorControllers.set(EAST_DOOR_MOTOR, 0);
}

void setLedMatrixText(const std::string &main, const std::string &east, const std::string &west){
    const int MAIN_MODULES = 8; // 64x8 (8 modules)
    const int EAST_MODULES = 4; // 32x8 (4 modules)
    const int WEST_MODULES = 4; // 32x8 (4 modules)
    const int MAIN_OFFSET = 0;
    const int EAST_OFFSET = MAIN_OFFSET + MAIN_MODULES;
    const int WEST_OFFSET = EAST_OFFSET + EAST_MODULES;

    auto writeToModules = [&](const std::string &s, int modules, int offset){
        for(int m = 0; m < modules; ++m){
            int dev = offset + m;
            lc.clearDisplay(dev);
            char ch = ' ';
            if(m < (int)s.length()) ch = s[m];
            // show a single character on this 8x8 module
            lc.setChar(dev, 0, ch, false);
        }
    };

    writeToModules(main, MAIN_MODULES, MAIN_OFFSET);
    writeToModules(east, EAST_MODULES, EAST_OFFSET);
    writeToModules(west, WEST_MODULES, WEST_OFFSET);
}