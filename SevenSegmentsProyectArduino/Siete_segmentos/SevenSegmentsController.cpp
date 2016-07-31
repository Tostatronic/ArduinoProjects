#include "SevenSegmentsController.h"
SevenSegmentsController::SevenSegmentsController(int _kindOfDisplay1,int* _pins1)
{
  displays[0].SetPins(_pins1,_kindOfDisplay1);
  numPins=1;//Un diplay declarado
}
SevenSegmentsController::SevenSegmentsController(int _kindOfDisplay1,int* _pins1,int _kindOfDisplay2,int* _pins2)
{
  displays[0].SetPins(_pins1,_kindOfDisplay1);
  displays[1].SetPins(_pins2,_kindOfDisplay2);
  numPins=2;
}
SevenSegmentsController::SevenSegmentsController(int _kindOfDisplay1,int* _pins1,int _kindOfDisplay2,int* _pins2,int _kindOfDisplay3,int* _pins3)
{
  displays[0].SetPins(_pins1,_kindOfDisplay1);
  displays[1].SetPins(_pins2,_kindOfDisplay2);
  displays[2].SetPins(_pins3,_kindOfDisplay3);
  numPins=3;
}
SevenSegmentsController::SevenSegmentsController(int _kindOfDisplay1,int* _pins1,int _kindOfDisplay2,int* _pins2,int _kindOfDisplay3,int* _pins3,int _kindOfDisplay4,int* _pins4)
{
  displays[0].SetPins(_pins1,_kindOfDisplay1);
  displays[1].SetPins(_pins2,_kindOfDisplay2);
  displays[2].SetPins(_pins3,_kindOfDisplay3);
  displays[3].SetPins(_pins4,_kindOfDisplay4);
  numPins=4;
}
void SevenSegmentsController::Write(short int number)
{
  for(int i=0;i<numPins;i++)
    displays[i].Reset();
  //127
  int numPositions=NumberOfPotitions(number);
  String a=String(number);//de un entero a un string
  //a=127
  /*
   * La clase string hereda de la clase primitiva char
   * String = char*
   * a[0]=1
   * a[1]=2
   * a[3]=7
   */
  switch(numPositions)
  {
    case 1:
      displays[0].WriteNumber(a[0]);
    break;
    case 2:
    displays[0].WriteNumber(a[1]);
    displays[1].WriteNumber(a[0]);
    break;
    case 3:
    displays[0].WriteNumber(a[2]);//[][][7]
    displays[1].WriteNumber(a[1]);//[][2][7]
    displays[2].WriteNumber(a[0]);//[1][2][7]
    break;
    case 4:
    displays[0].WriteNumber(a[3]);
    displays[1].WriteNumber(a[2]);
    displays[2].WriteNumber(a[1]);
    displays[3].WriteNumber(a[0]);
    break;
  }
}
int SevenSegmentsController::NumberOfPotitions(short int number)
{
  if(number>9999)
    number=9999;
  if(number>999)//1000..... 
    return 4;
  else if( number>99)//100...
    return 3;
  else if( number>9)//10..
    return 2;
  else//0..9
    return 1;
}

