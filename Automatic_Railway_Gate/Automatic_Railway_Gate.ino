#include <Servo.h>

#define servo1 4
#define servo2 2


/*===========================================================================================================
                                 PROJECT: AUTOMATIC RAILWAY GATE CONTROL SYSTEM                          
  -----------------------------------------------------------------------------------------------------------
       Hardware: 
                        Component                               Quantity
                 Arduino Nano Microcontroller                       1
                 IR proximity sensors                               2
                 Servo motors  SG-90                                2
                 LEDs (GREEN and RED)                               2
                 Buzzor                                             1
 -----------------------------------------------------------------------------------------------------------
      Desription:
                 Aim of the project is to control the railway gates automatically without man presence
                 IR sensors mounted at differnt places detect the train and pass information to microcontroller
                 then the gates are operated accordingly using servo motors. Buzzor,LEDs is used to give caution
 ------------------------------------------------------------------------------------------------------------

      Circuit:
                                    ------------------
                         (D2)servo2-|-5              |
                         (D4)servo1-|-7              |
                                    |             26-|-(A7) IRsensor2
                                    |             24-|-(A5) IRsensor1
                      (D8)LED GREEN-|-11             |
                      (D9)BUZZOR ---|-12             |
                      (D10)LED RED--|-13             |
                                    ------------------
                                    
 -------------------------------------------------------------------------------------------------------------
      Author: Kiran Thallapally                                               Last Modified: 27-03-2018 13:42
 ================================================================================================================ */
   
int sens1=A5;
int sens2=A7;
int LED_RED=10;
int LED_GREEN=8;
int ALARM=9;

Servo gate1;
Servo gate2;
int pos=0;

//   boolen variables to check status of gates  //
boolean clos=0;  
boolean opn=0;


void setup() {
  
 // Serial.begin(9600);
  gate1.attach(servo1);
  gate2.attach(servo2);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(ALARM, OUTPUT);
}

void loop() {
 
  A:
   int sens1_val=analogRead(sens1);
  // Serial.println(sens1_val);
   if(sens1_val<100 && clos!=1){
    clos=1;
    opn=0;
    gate1.write(170);
    gate2.write(170);
    digitalWrite(LED_GREEN,LOW);
    digitalWrite(LED_RED,HIGH);
    digitalWrite(ALARM,HIGH);
   goto B;
   }
   B:
    int sens2_val=analogRead(sens2);
  //  Serial.println(sens2_val);
    if(sens2_val<100 && opn!=1){
     digitalWrite(LED_RED,LOW);
     digitalWrite(ALARM,LOW);
     digitalWrite(LED_GREEN,HIGH);
     opn=1;
     clos=0;
     gate1.write(110);
     gate2.write(110);
     goto A;
    }
   /*else
   {
     gate1.write(0);
     gate2.write(0);
   }*/
}

