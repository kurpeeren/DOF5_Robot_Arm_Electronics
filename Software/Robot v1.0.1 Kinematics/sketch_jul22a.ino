#include <FastLED.h>
#include <VarSpeedServo.h> 

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



//ROBOT ÖZELLİKLERİ
#define base_yukeklik 0
#define kol_uzunluk 120
#define dirsek_uzunluk 125
#define servo_hiz 125


#define ftl(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5)) 
#define DEVADDR 1
#define CONFVALUE 1

/* Arm dimensions( mm ) */
#define BASE_HGT 110.31      //base hight 2.65"
#define HUMERUS 110.05      //shoulder-to-elbow "bone" 5.75"
#define ULNA 127.325        //elbow-to-wrist "bone" 7.375"   
#define GRIPPER 100.00 
#define ftl(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5)) //float to long conversion



float hum_sq = HUMERUS*HUMERUS;
float uln_sq = ULNA*ULNA;
int servoSpeed=10;

int J_5(byte x,byte y,byte z){
return 180-J_2(x,y,z);
  
}
int J_3(byte x,byte y,byte z){
  float r;
  r=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
  //if (r>dirsek_uzunluk+kol_uzunluk){
  //+r=dirsek_uzunluk+kol_uzunluk;//}
  //else{
  float j3 = round(acos((-(r*r)+kol_uzunluk*kol_uzunluk+dirsek_uzunluk*dirsek_uzunluk)/(2*dirsek_uzunluk*kol_uzunluk))*(180/PI));
  r=0;
  //if (j3<0) return 30;
  //if (j3>180) return 180;
  if (0<j3<180) return 90+j3;
  }//}
  
 
int J_2(byte x,byte y,byte z){
  float r;
  r=sqrt(sq(x)+sq(y)+sq(z));
  //if (r>dirsek_uzunluk+kol_uzunluk){
  r=dirsek_uzunluk+kol_uzunluk;//}
  //if (z>r){z=r;}
  float j2 = (acos(z/r)+atan(dirsek_uzunluk/kol_uzunluk))*(180/PI);
  //if (j2<0) return 30;
  //if (j2>180) return 180;
  if (0<j2<180) return 90+j2;
  }
  

int J_1(byte x,byte y,byte z){
  float j1=atan(y/x)*(180/PI);
  //if (j1<0) return 30;
  //if (j1>180) return 180;
  if (0<j1<180) return 90+j1;
  }




//TANIMLAR
struct led{
  byte red;
  byte green;
  byte blue;
  byte nul;
  };
led LED_VALUE;

CRGB leds[1];

VarSpeedServo J1_SERVO;
VarSpeedServo J2_SERVO;
VarSpeedServo J3_SERVO;
VarSpeedServo J4_SERVO;
VarSpeedServo J5_SERVO;
VarSpeedServo J6_SERVO;


// OUTPUT TRIM



  
int J1_MIN = 30 , J1_TRIM = 100 , J1_MAX = 180 , J1_VALUE;
int J2_MIN = 30 , J2_TRIM = 100 , J2_MAX = 180 , J2_VALUE;
int J3_MIN = 30 , J3_TRIM = 100 , J3_MAX = 180 , J3_VALUE;
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
  J5_SERVO.attach(PWM3);
  J6_SERVO.attach(PWM2);

  DDRB = B00001111; //7~0 00111111
  DDRD = B11110000; //7~0
  DDRC = B00001111; //7~0
  
  Serial.begin(115200);
  Serial.setTimeout(1);
  FastLED.addLeds<NEOPIXEL, LED>(leds, 1);
  J1_SERVO.write(100);
  J2_SERVO.write(100);
  J3_SERVO.write(100);
  J5_SERVO.write(100);
  
  J4_SERVO.write(J4_TRIM);
  
  J6_SERVO.write(J6_TRIM);
  J1_VALUE=100;
  J2_VALUE=100;
  J3_VALUE=100;
  
  inputString.reserve(200);

                 // Seri Port Ekranı bağlantısı başlatılıyor
             // HC-06 Seri Port bağlantısı başlatılıyor
  Serial.println("Hazır"); 

  
  
}



//string: a variable of type String
//val: the value to search for - char or String
//from: the index to start the search from




void loop() {
    
 int x12,y12,z12,x,y,z;

  if (stringComplete) {
    
    sscanf(inputString.c_str(),"%d,%d,%d,%d,%d,%d,%ld",&J1_VALUE, &J2_VALUE, &J3_VALUE, &J4_VALUE, &J5_VALUE, &J6_VALUE, &LED_VALUE);
    //sscanf(inputString.c_str(),"%d,%d,%d",&x12, &y12, &z12 );
    //set_arm(x12/1,y12/1,z12/1,90);
    Serial.print(inputString);
    //sscanf(inputString.c_str(),"%hhd,%hhd,%hhd",&x12, &y12, &z12 );
    //Serial.print(inputString);
    //if (x==0 or y==0 or z==0)
    if (x!=0)x=x12;y=y12;z=z12;

    J1_SERVO.write(J_1(x12,y12,z12));
    J2_SERVO.write(J_2(x12,y12,z12));
    J3_SERVO.write(J_3(x12,y12,z12));
    Serial.print("eren: ");
    Serial.println(x12);//{x,y,z=x1,y1,z1;}
    Serial.println(y12);
    Serial.println(z12);
    leds[0] = CRGB(LED_VALUE.red, LED_VALUE.green, LED_VALUE.blue);
    FastLED.show();
    // clear the string:
    inputString = "";
    stringComplete = false; 
  }
    
    
    //}
  }
    


    
//    leds[0] = CRGB(LED_VALUE.red, LED_VALUE.green, LED_VALUE.blue);
 //   FastLED.show();


  
