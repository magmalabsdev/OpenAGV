#include <EchoLib.h>
#include <LedControl.h>
#include <Servo.h>
#include <SPI.h>
#include <SD.h>

#define SPEAKER_PIN 40;

#define UPPER_MOTOR_PIN  41;
#define LOWER_MOTOR_PIN  42;

#define LEDMTX_DIN  9;
#define LEDMTX_CS  14;
#define LEDMTX_CLK  39;

#define WEST_DOOR_MOTOR  1;
#define EAST_DOOR_MOTOR  2;



MotorControllers mc =  MotorControllers();
LedControl lc = LedControl(DIN, CLK, CS,0);
ServoDriver sd;

Servo UPPER_ESC;
Servo LOWER_ESC;  


void setup() {



    Serial.begin(115200);
    
    while (!Serial) {
    
    }


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

    motorControllers.set(WEST_DOOR_MOTOR, 1);
    delay(1000);


    for(int j=0;j<8;j++){
         for(int i=0;i<8;i++){
            lc.setLed(0,j,i,false);
         }
    }

    UPPER_ESC.write(0);
    delay(1000);

}