
/*
PINOUT:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D53
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D49
3.3V            3.3V         3.3V
*/
/* Include the standard Arduino SPI library */
#include <SPI.h>
/* Include the RFID library */
#include <RFID.h>

/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 53
#define RESET_DIO 49

#define Buton 7
#define buzzerPin 6
/*int trigPin1 = 9;
int echoPin1 = 10;*/

int trigPin2 = 3; 
int echoPin2 = 4; 

/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 

void setup()
{ 
 // Serial.begin(9600);
  Serial3.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
   pinMode(Buton, INPUT);

//ultrasonik sensörler 


 pinMode (trigPin2, OUTPUT); 
  pinMode (echoPin2, INPUT); 
  
 pinMode(buzzerPin, OUTPUT);
}


void beepSecond(){
   // play a tone on pin 10 
  tone(buzzerPin, 1000, 100);
  delay(20);
  // turn off tone function for pin 10:
  noTone(buzzerPin);
}
//.............


void secondsensor(){ // This function is for second sensor.
    int duration2, distance2;
    digitalWrite (trigPin2, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin2, LOW);
    duration2 = pulseIn (echoPin2, HIGH);
    distance2 = (duration2/2) / 29.1;
    if (distance2 <=30) {  // Change the number for long or short distances.
     beepSecond();
    }
 else {
      //-----
    }  
}
void loop()
{
secondsensor();
delay(150);

if (digitalRead(Buton) == 1)
  { /* Has a card been detected? */
    if (RC522.isCard())
    {
    /* If so then get its serial number */
      RC522.readCardSerial();
      for(int i=0;i<5;i++)
      {
      
      Serial3.print(RC522.serNum[i],DEC);
      //Serial.print(RC522.serNum[i],DEC);
     
      }
    
    }
  delay(1000);
 }
}
