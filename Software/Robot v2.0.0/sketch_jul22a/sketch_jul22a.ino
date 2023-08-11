#include <FastLED.h>
#include <VarSpeedServo.h> 
#include <EEPROM.h>

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


//TANIMLAR
struct led{
  byte red;
  byte green;
  byte blue;
  byte nul;
  };
  
led LED_VALUE;
bool ekset=1;
CRGB leds[1];

VarSpeedServo J1_SERVO;
VarSpeedServo J2_SERVO;
VarSpeedServo J3_SERVO;
VarSpeedServo J4_SERVO;
VarSpeedServo J5_SERVO;
VarSpeedServo J6_SERVO;


// OUTPUT TRIM
int J1_VALUE;
int J2_VALUE;
int J3_VALUE;
int J4_VALUE;
int J5_VALUE;
int J6_VALUE;



 unsigned long EEPROM_readlong(int address)
 {
 //use word read function for reading upper part
 unsigned long dword = EEPROM_readint(address);
 //shift read word up
 dword = dword << 16;
 // read lower word from EEPROM and OR it into double word
 dword = dword | EEPROM_readint(address+2);
 return dword;
}

//write word to EEPROM
 void EEPROM_writeint(int address, int value) 
{
 EEPROM.write(address,highByte(value));
 EEPROM.write(address+1 ,lowByte(value));
}

 
 //write long integer into EEPROM
 void EEPROM_writelong(int address, unsigned long value) 
{
 //truncate upper part and write lower part into EEPROM
 EEPROM_writeint(address+2, word(value));
 //shift upper part down
 value = value >> 16;
 //truncate and write
 EEPROM_writeint(address, word(value));
}


unsigned int EEPROM_readint(int address) 
{
 unsigned int word = word(EEPROM.read(address), EEPROM.read(address+1));
 return word;
}

void(* resetFunc) (void) = 0;



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
  //FastLED.addLeds<WS2812B, LED, GRB>(leds, 1); //Fastlede led dizimizi ekledik
  
  J1_SERVO.attach(PWM7);
  J2_SERVO.attach(PWM6);
  J3_SERVO.attach(PWM5);
  J4_SERVO.attach(PWM4);
  J5_SERVO.attach(PWM3);
  J6_SERVO.attach(PWM2);

  DDRB = B00111111; //7~0 00111111
  DDRD = B11110000; //7~0
  DDRC = B00001111; //7~0
  if ((EEPROM_readlong(10) == 9600 )or (EEPROM_readlong(10) == 19200) or (EEPROM_readlong(10) == 38400) or (EEPROM_readlong(10) == 57600) or (EEPROM_readlong(10) == 74880 )or( EEPROM_readlong(10) == 115200) )
  {
    Serial.begin(EEPROM_readlong(10));
    }
  else Serial.begin(9600);
  Serial.setTimeout(1);
  FastLED.addLeds<NEOPIXEL, LED>(leds, 1);
  FastLED.setBrightness(255); //Parlaklık ayarı 0-255
  J1_SERVO.write(100);
  J2_SERVO.write(100);
  J3_SERVO.write(100);
  J4_SERVO.write(100);
  J5_SERVO.write(100);
  J6_SERVO.write(100);
  inputString.reserve(200);
  bool ekset=1;
Serial.print("EK COMMAND (EK+SET): \n");
}

int select;

void loop() {
  
  if (ekset==1){
  if (stringComplete) {

    
    if (inputString == "EK+SET\n")
      {ekset=0;
      Serial.print("EK+SET on.\n");
      
      }
    else Serial.print("Normal Mod: " + inputString);
    sscanf(inputString.c_str(),"%d,%d,%d,%d,%d,%d,%hhd,%hhd,%hhd",&J1_VALUE, &J2_VALUE, &J3_VALUE, &J4_VALUE, &J5_VALUE, &J6_VALUE, &LED_VALUE.red, &LED_VALUE.green, &LED_VALUE.blue);
    //sscanf(inputString.c_str(),"%d,%d,%d",&x12, &y12, &z12 );
    //set_arm(x12/1,y12/1,z12/1,90);
     
    //sscanf(inputString.c_str(),"%hhd,%hhd,%hhd",&x12, &y12, &z12 );
    //Serial.print(inputString);
    //if (x==0 or y==0 or z==0)
/*
    J1_SERVO.write(J1_VALUE);
    J2_SERVO.write(J2_VALUE);
    J3_SERVO.write(J3_VALUE);
    J4_SERVO.write(J4_VALUE);
    J5_SERVO.write(J5_VALUE);
    J6_SERVO.write(J6_VALUE);
 */   
    //100,100,100,100,100,100,255,0,0
    
    
    /*
    Serial.print(LED_VALUE.red);
    Serial.print(" : ");
    Serial.print(LED_VALUE.green);
    Serial.print(" : ");
    Serial.println(LED_VALUE.blue);
    */
    //leds[0].setRGB(0, 255, 0);
    leds[0] = CRGB(LED_VALUE.red, LED_VALUE.green, LED_VALUE.blue);
    FastLED.show();


    
    // clear the string:
    inputString = "";
    stringComplete = false; 
    
  }}



  
  else if (ekset==0){
 
    if (stringComplete) {

    if (inputString=="EK+SETC\n"){
      Serial.println("EK+SET off.");
      ekset=1;
      }
     
    else if (inputString.substring(0,15)=="EK+INPUT+SELECT"){
      
      if (inputString.substring(15,16)=="?"){
        if((select==0)||(select==1)||(select==2)||(select==3)||(select==4)||(select==5))
        Serial.print(select);
        }
       
      
      else if((inputString.substring(15,16)=="0")||(inputString.substring(15,16)=="1")||(inputString.substring(15,16)=="2")||(inputString.substring(15,16)=="3")||(inputString.substring(15,16)=="4")||(inputString.substring(15,16)=="5"))
        {select=inputString.substring(15,16).toInt();
        Serial.print(select);Serial.println(" selected");}
      else Serial.println("Not Selected.");
        
      
      
      
      }
    else if (inputString.substring(0,6)=="EK+ACT"){
      
      int select;
      
      while(1){
        
      sscanf(inputString.c_str(),"EK+ACT%d,%d,%d,%d,%d,%d,%hhd,%hhd,%hhd",&J1_VALUE, &J2_VALUE, &J3_VALUE, &J4_VALUE, &J5_VALUE, &J6_VALUE, &LED_VALUE.red, &LED_VALUE.green, &LED_VALUE.blue);
      Serial.println("EK+ACTJ1,J2,J3,J4,J5,J6,R,G,B");
      Serial.println("EK+ACT%d,%d,%d,%d,%d,%d,%hhd,%hhd,%hhd");
      J1_SERVO.write(J1_VALUE,30);
      J2_SERVO.write(J2_VALUE,30);
      J3_SERVO.write(J3_VALUE,30);
      J4_SERVO.write(J4_VALUE,30);
      J5_SERVO.write(J5_VALUE,30);
      J6_SERVO.write(J6_VALUE,30);
      leds[0] = CRGB(LED_VALUE.red, LED_VALUE.green, LED_VALUE.blue);
      FastLED.show();
      
      if(inputString.substring(0,11)=="EK+ACT+SAVE"){
      EEPROM_writelong(20+1*4*select,J1_VALUE);
      EEPROM_writelong(20+2*4*select,J2_VALUE);
      EEPROM_writelong(20+3*4*select,J3_VALUE);
      EEPROM_writelong(20+4*4*select,J4_VALUE);
      EEPROM_writelong(20+5*4*select,J5_VALUE);
      EEPROM_writelong(20+6*4*select,J6_VALUE);
      EEPROM.write(20+7*4*select,LED_VALUE.red);
      EEPROM.write(20+7*4*select+1,LED_VALUE.blue);
      EEPROM.write(20+7*4*select+2,LED_VALUE.green);
      Serial.println("Action Saved.");
      break;
      
      }
      

      else if(inputString.substring(0,12)=="EK+ACT+DSAVE"){
      Serial.println("Action Dont Saved.");  
      break;
        }
      }
      }
    else if (inputString.substring(0,7) == "EK+KONT"){

      
      sscanf(inputString.c_str(),"EK+KONT%d,%d,%d,%d,%d,%d,%hhd,%hhd,%hhd",&J1_VALUE, &J2_VALUE, &J3_VALUE, &J4_VALUE, &J5_VALUE, &J6_VALUE, &LED_VALUE.red, &LED_VALUE.green, &LED_VALUE.blue);
      Serial.println("EK+KONTJ1,J2,J3,J4,J5,J6,R,G,B");
      Serial.println("EK+KONT%d,%d,%d,%d,%d,%d,%hhd,%hhd,%hhd");
      J1_SERVO.write(J1_VALUE,30);
      J2_SERVO.write(J2_VALUE,30);
      J3_SERVO.write(J3_VALUE,30);
      J4_SERVO.write(J4_VALUE,30);
      J5_SERVO.write(J5_VALUE,30);
      J6_SERVO.write(J6_VALUE,30);
      Serial.println(J1_VALUE);
      leds[0] = CRGB(LED_VALUE.red, LED_VALUE.green, LED_VALUE.blue);
      FastLED.show();
      }





    
    else if (inputString=="EK+RESET\n"){
      Serial.print("4");
      resetFunc();
      }
    else if (inputString.substring(0,7)=="EK+BAUD"){
      if (inputString.substring(7,8)=="?"){
        Serial.println(EEPROM_readlong(10));
        }
      int a=inputString.substring(7,8).toInt();
      switch(a){
      case(1):
        EEPROM_writelong(10, 9600);
        Serial.print(EEPROM_readlong(10));Serial.println(" OK please reboot.");
      break;
      case(2):
        EEPROM_writelong(10, 19200);
        Serial.print(EEPROM_readlong(10));Serial.println(" OK please reboot.");
        break;
      case(3):
        EEPROM_writelong(10, 38400);
        Serial.print(EEPROM_readlong(10));Serial.println(" OK please reboot.");
        break;
      case(4):
        EEPROM_writelong(10, 57600);
        Serial.print(EEPROM_readlong(10));Serial.println(" OK please reboot.");
        break;
      case(5):
        EEPROM_writelong(10, 74880);
        Serial.print(EEPROM_readlong(10));Serial.println(" OK please reboot.");
        break;
      case(6):
        EEPROM_writelong(10, 115200);
        Serial.print(EEPROM_readlong(10));Serial.println(" OK please reboot.");
        
        break;
      default:
        break;
              }
      }
      else if (inputString=="EK+HELP\n"){
      Serial.println("EK+SETC Exit");
      Serial.println("EK+ACT? Action");
      Serial.println("EK+INPUT+SELECT? (1-6 INPUT PORT)");
      Serial.println("EK+BAUD? (1:9600,2:19200,3:38400,4:57600,5:74880,6:115200) ");
      }
      else Serial.println("EK+HELP");
  
  inputString = "";
    stringComplete = false; 
  }}}
    


    
//    leds[0] = CRGB(LED_VALUE.red, LED_VALUE.green, LED_VALUE.blue);
 //   FastLED.show();


  
