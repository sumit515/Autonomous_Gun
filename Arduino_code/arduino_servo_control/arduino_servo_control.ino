#include<Servo.h>
Servo ser1;
Servo ser2;
Servo ser3;

void setup() {
 ser1.attach(2);//the first servo is attached to A0 which is the X axis servo
 ser2.attach(0);//the second servo is attached to A1 which is the Y axis servo
 ser3.attach(1);//the third servo is attached to A2 which is the trigger servo
 ser3.write(0);
 Serial.begin(250000);
}
String a,c; 
int b,d,val;
void loop() {
  if(Serial.available())
  {
    a=Serial.readStringUntil('\n'); //reads the angle values for both X and Y servos
    b=a.toInt();                    //converts the angles to integer
    while(!Serial.available()){}
    c=Serial.readStringUntil('\n'); // reads whether the value obtained is to be written on X Servo or Y servo
   // Serial.println(c);
    if(c=="a")
    ser1.write(b);            //if we obtain 'a' then the X servo moves
    else if(c=="b")
    {val = map(b, 180, 0, 0, 180);
    ser2.write(180-val); }           //if we obtain 'b' then the Y servo moves
    else if(c=="c")           //if we obtain 'c' then the trigger servo is pulled
    {
    for (int pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      ser1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
        }
    delay(1000);
    
    }//Serial.println(a);
  }
}
