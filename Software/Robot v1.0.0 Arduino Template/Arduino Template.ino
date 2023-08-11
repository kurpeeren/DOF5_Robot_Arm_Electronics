
#include <FastLED.h>
#include <Servo.h>

//INPUTS
#define IN0 2                     // PD2 DDDDDD
#define IN1 3                     // PD3 DDDDDD
#define IN2 A4                    // PC4
#define IN3 A5                    // PC5
#define IN4 A6                    // 
#define IN5 A7                    // 

//OUTPUTS
#define LED 13                    // PB5
#define OUT0 A0                   // PC0
#define OUT1 A1                   // PC1
#define OUT2 A2                   // PC2
#define OUT3 A3                   // PC3
#define OUT4 4                    // PD4 DDDDDD

//PWM OUT
#define PWM0 12 // 5V             // PB4
#define PWM1 11 // 5V             // PB3
#define PWM2 10 // 5V_1           // PB2
#define PWM3 9  // 5V_1           // PB1
#define PWM4 8  // 5V_2           // PB0
#define PWM5 7  // 5V_2           // PD7 DDDDDD
#define PWM6 6  // 5V_2           // PD6 DDDDDD
#define PWM7 5  // 5V_2           // PD5 DDDDDD



// ATMEL ATMEGA8 & 168 / ARDUINO
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9)  PWM
//                  +----+
//
//
//
//
//
//

struct led{
  byte red;
  byte green;
  byte blue;
  byte nul;
  };

CRGB leds[1];

Servo J1_SERVO;
Servo J2_SERVO;
Servo J3_SERVO;
Servo J4_SERVO;
Servo J5_SERVO;
Servo J6_SERVO;

// OUTPUT TRIM

led LED_VALUE;

  
int J1_MIN = 30 , J1_TRIM = 45 , J1_MAX = 100 , J1_VALUE;
int J2_MIN = 30 , J2_TRIM = 45 , J2_MAX = 100 , J2_VALUE;
int J3_MIN = 30 , J3_TRIM = 45 , J3_MAX = 100 , J3_VALUE;
int J4_MIN = 30 , J4_TRIM = 45 , J4_MAX = 100 , J4_VALUE;
int J5_MIN = 30 , J5_TRIM = 45 , J5_MAX = 100 , J5_VALUE;
int J6_MIN = 30 , J6_TRIM = 45 , J6_MAX = 100 , J6_VALUE;


String inputString = "";         // a String to hold incoming data
bool stringComplete = false;

void serialEvent() {
  while (Serial.available()) {


    char inChar = (char)Serial.read();


    inputString += inChar;


    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}




void setup() {
  J1_SERVO.attach(PWM7);
  J2_SERVO.attach(PWM6);
  J3_SERVO.attach(PWM5);
  J4_SERVO.attach(PWM4);
  J4_SERVO.attach(PWM3);
  J6_SERVO.attach(PWM2);

  DDRB = B00111111; //7~0
  DDRD = B11110000; //7~0
  DDRC = B00001111; //7~0

  Serial.begin(115200);
  Serial.setTimeout(1);
  FastLED.addLeds<NEOPIXEL, LED>(leds, 1);
  J1_SERVO.write(J1_TRIM);
  J2_SERVO.write(J2_TRIM);
  J3_SERVO.write(J3_TRIM);
  J4_SERVO.write(J4_TRIM);
  J4_SERVO.write(J5_TRIM);
  J6_SERVO.write(J6_TRIM);

  inputString.reserve(200);
}



//string: a variable of type String
//val: the value to search for - char or String
//from: the index to start the search from

void loop() {

  Serial.println(inputString);
  if (stringComplete) {
    Serial.println(inputString);
    sscanf(inputString.c_str(),"%d,%d,%d,%d,%d,%d,%ld",&J1_VALUE, &J2_VALUE, &J3_VALUE, &J4_VALUE, &J5_VALUE, &J6_VALUE, &LED_VALUE);
    // clear the string:
    Serial.println(J1_VALUE);
    inputString = "";
    stringComplete = false;
  }
  J1_SERVO.write(J1_VALUE);
  J2_SERVO.write(J2_VALUE);
  J3_SERVO.write(J3_VALUE);
  J4_SERVO.write(J4_VALUE);
  J5_SERVO.write(J5_VALUE);
  J6_SERVO.write(J6_VALUE);

    


    
    leds[0] = CRGB(LED_VALUE.red, LED_VALUE.green, LED_VALUE.blue);
    FastLED.show();

 


}



/*
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  myservo.write(pos);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15 ms for the servo to reach the position
  }

*/
