#include <SoftwareSerial.h>
#include<Wire.h>
SoftwareSerial BT(0,1);   // 接收腳(RX), 傳送腳(TX)；接HC-06之TXD、RXD；先不要用0,1,因為USB用
int inSlider=0;
int Position1,Position2;
char temp[]="e";
char button;
String myString,tempString;

unsigned long time_now = 0; 
int period=3000;//計時的時間



void setup(){
  Serial.begin(9600); //for arduino serial port mointor 
  BT.begin(9600);
  BT.setTimeout(5);

  time_now = millis();

   }

void loop(){
  while(BT.available() ) {
    myString=BT.readString();
    split();
    Serial.println(BT.readString());
    Serial.print(myString);
     Serial.print(" ");
     Serial.print(button);
     Serial.print(" ");
     Serial.println(inSlider);
     }
      if(millis() > time_now + period){
        time_now = millis();
        Serial.println("Hello");
    }
     
}

void split(){
     Position1=myString.indexOf(',');
     Position2=myString.indexOf(',',Position1+1); 
     tempString=myString.substring(0,Position1);
     strcpy(temp,tempString.c_str());
     button=temp[0];
     tempString=myString.substring(Position1+1,Position2);
     inSlider=tempString.toInt();
}
