
#include <Wire.h>
#include <SFE_TSL2561.h>
SFE_TSL2561 light;
unsigned int ms;
boolean gain;
float temp;
static int aprint=0;
static int tprint=0;
static int lprint=0;
int templed=10;
int lightled=11;
int airled=12;
void setup() 
{
 Serial.begin(9600); 
 Serial1.begin(9600);
 
 light.begin();
  gain = 0;
  unsigned char time = 2;
light.setTiming(gain,time,ms);
light.setPowerUp();
pinMode(templed, OUTPUT);
pinMode(lightled, OUTPUT);
pinMode(airled, OUTPUT);

}
void loop()
{
temp = (5.0 * analogRead(A0) * 100.0) / 1024;
Serial.println(temp);
delay(500);


int air;
  
  air = analogRead(A1);
  Serial.println("now the Air quality sensor is :");
  Serial.println(air);
  delay(700);
  
  
  unsigned int data0, data1;
   light.getData(data0,data1);
    
 double lux;
 boolean good;
 good = light.getLux(gain,ms,data0,data1,lux);
  Serial.print(" lux: ");
    Serial.print(lux); 
    Serial.println(" "); 
    
   

  
  
if(temp>40)
{
  if(tprint==0)
  {
 Serial1.write(" Temperature");
 tprint=tprint+1;
  }
tone(7, 25, 50); 
digitalWrite(templed, HIGH);
}


if(air>200)
  {
    if(aprint==0)
    {
    Serial1.write(" Air");
    aprint=aprint+1;
    }
   tone(7, 494, 50); 
 digitalWrite(airled, HIGH);
  }


if (lux>520)
   {
     if(lprint==0)
     {
     Serial1.write(" Light");
     lprint=lprint+1;
   }
     tone(7, 494, 50);
     digitalWrite(lightled, HIGH);
   }

delay(700);
}





