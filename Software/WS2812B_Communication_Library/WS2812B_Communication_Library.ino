
//INPUTS
#define IN0 2
#define IN1 3
#define IN2 A4
#define IN3 A5
#define IN4 A6
#define IN5 A7

//OUTPUTS
#define LED 13
#define OUT0 A0
#define OUT1 A1
#define OUT2 A2
#define OUT3 A3
#define OUT4 4

//PWM OUT
#define PWM0 12 // 5V
#define PWM1 11 // 5V
#define PWM2 10 // 5V_1
#define PWM3 9  // 5V_1
#define PWM4 8  // 5V_2
#define PWM5 7  // 5V_2
#define PWM6 6  // 5V_2
#define PWM7 5  // 5V_2

#define NOP __asm__ __volatile__ ("nop\n\t")


long renk = 0xFFFFFFFF;

void led_clr(long renk,int times) {


   switch (bitRead(renk, 8)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 9)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 10)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 11)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 12)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 13)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 14)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 15)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  switch (bitRead(renk, 16)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 17)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 18)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 19)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 20)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 21)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 22)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 23)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  /////////////////////////////////////////////////////////////////////////////////////////////
  switch (bitRead(renk, 0)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 1)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 2)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 3)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 4)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 5)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 6)) {
    case 1:
      PORTB &= ~(1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB |= (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1<< PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
  switch (bitRead(renk, 7)) {
    case 1:
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;
      PORTB |=  (1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;
    case 0:
      PORTB |=  (1 << PORTB5);NOP;NOP;NOP;NOP;
      PORTB &= ~(1 << PORTB5);NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;NOP;break;}
PORTB &= ~(1 << PORTB5);
delay(times);
}

void reset(){

delay(1);
long res = 0x00000000;
led_clr(res,1);}

void setup() {

DDRB = B11111111;
Serial.begin(9600);
}

void loop() {


  
long renkk = 0x00ff0000; //RGB
led_clr(renkk,1000);reset();

long renk = 0x0000ff00;
led_clr(renk,1000);reset();

long renn = 0x000000ff; //RGB
led_clr(renn,1000);reset();
}
