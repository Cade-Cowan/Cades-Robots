#include <math.h>



//functions
void getRval(void);
void getGval(void);
void getBval(void);
void setval(void);

// pins that are connected on arduino for controlling red, green, and blue LED colors
int Rpin = 3;
int Gpin = 4;
int Bpin = 5;


// pins that are connected to arduino analog to receive info from the potentiometers
int Rget = A0;
int Gget = A1;
int Bget = A2;

// values for red, green, and blue that will be set to brightness percentages
float Rval = 0;
float Gval = 0;
float Bval = 0;

void setup() {
  // setup red, green, and blue control pins as outputs
  pinMode(Rpin,OUTPUT);
  pinMode(Gpin,OUTPUT);
  pinMode(Bpin,OUTPUT);
  digitalWrite(Rpin,HIGH);
  digitalWrite(Gpin,HIGH);
  digitalWrite(Bpin,HIGH);
  Serial.begin(9600);
}


void loop() {
  getRval(); // update Rval using function im going to write
  getGval(); // update Gval using function im going to write
  getBval(); // update Bval using function im going to write
  setval();  // set Rval,Gval,and Bval to led as 1 cycle using function im going to write
}


// update Rval function
void getRval(void){
  Rval = analogRead(Rget);
  Rval = Rval/1023;
  
}

// update Gval function
void getGval(void){
  Gval = analogRead(Gget);
  Gval = Gval/1023;
}

// update Bval function
void getBval(void){
  Bval = analogRead(Bget);
  Bval = Bval/1023;
}


// set values to led in 1 cycle
void setval(void){

  //red, green and blue times (in microseconds) to be on and off
  int r_on = 1000*Rval;
  int r_off = 1000 - r_on;

  int g_on = 1000*Gval;
  int g_off = 1000 - g_on;

  int b_on = 1000*Bval;
  int b_off = 1000 - b_on;


  // red cycle
  if (r_on > 0){
    digitalWrite(Rpin,LOW);
    delayMicroseconds(r_on);
  }
  digitalWrite(Rpin,HIGH);
  delayMicroseconds(r_off);

  // blue cycle
  if (b_on > 0){
    digitalWrite(Bpin,LOW);
    delayMicroseconds(b_on);
  }
  digitalWrite(Bpin,HIGH);
  delayMicroseconds(b_off);

  // green cycle
  if (g_on > 0){
    digitalWrite(Gpin,LOW);
    delayMicroseconds(g_on);
  }
  digitalWrite(Gpin,HIGH);
  delayMicroseconds(g_off);
  
}



