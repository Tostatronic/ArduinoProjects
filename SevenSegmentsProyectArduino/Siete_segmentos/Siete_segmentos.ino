#include "SevenSegmentsController.h"
int displayCatode1[]={39,40,41,42,43,44,45};
int displayCatode2[]={46,47,48,49,50,51,52};
String recepcion;
int numero;
SevenSegmentsController dis(COMMOM_CATODE,displayCatode1,COMMOM_CATODE,displayCatode2);//[2][1]
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    recepcion=Serial.readString();
    numero=recepcion.toInt();
    dis.Write(numero);
  }
  /*
  for(int i=0;i<100;i++)
  {
    dis.Write(i);
    delay(300);
  }*/
}
