#include <Servo.h>
Servo servohori;
int servoh_pin=5;
int servoh=0;
  
Servo servoverti;
int servov_pin=3;
int servov=0;

int highLimit=160;
int lowLimit=20;

//ldr
int ldrtopr=A0;
int ldrtopl=A3;
int ldrbotr=A2;
int ldrbotl=A1;
void setup()
{
 servohori.attach(servoh_pin);
 servohori.write(0);
 servoverti.attach(servov_pin);
 servoverti.write(0);
 Serial.begin(9600);
 delay(500);
}

void loop()
{
 servoh=servohori.read(); 
 servov=servoverti.read();
 
 int topl=analogRead(ldrtopl);
 int topr=analogRead(ldrtopr);
 int botl=analogRead(ldrbotl);
 int botr=analogRead(ldrbotr);

 int top=(topl+topr)/2;
 int bot=(botl+botr)/2;
 int left=(topl+botl)/2;
 int right=(topr+botr)/2;


 if (top < bot)
  {
    servoverti.write(servov +1);
    if (servov > highLimit)
     {
      servov = highLimit;
     }
    delay(10);
  }
  else if (bot < top)
  {
    servoverti.write(servov -1);
    if (servov < lowLimit)
  {
    servov = lowLimit;
  }
    delay(10);
  }
  else
  {
    servoverti.write(servov);
  }
 
  if (left > right)
  {
    servohori.write(servoh +1);
    if (servoh > highLimit)
    {
    servoh = highLimit;
    }
    delay(10);
  }
  else if (right > left)
  {
    servohori.write(servoh -1);
    if (servoh < lowLimit)
     {
     servoh = lowLimit;
     }
    delay(10);
  }
  else
  {
    servohori.write(servoh);
  }
  delay(50);
  Serial.print(servoh);
 Serial.print("  ");
 Serial.println(servov);
}
