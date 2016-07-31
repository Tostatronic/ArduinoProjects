#include "SevenSegmentDisplay.h"
SevenSegments::SevenSegments()
{
}
SevenSegments::SevenSegments(int* _segments,int definition)
{
  segments=_segments;
  kindOfDisplay=definition;
  for(int i=0;i<7;i++)
    pinMode(segments[i],OUTPUT);
}
void SevenSegments::SetPins(int* pins,int definition)
{
  segments=pins;
  kindOfDisplay=definition;
  for(int i=0;i<7;i++)
  {
    pinMode(segments[i],OUTPUT);
  }
}
void SevenSegments::Reset()
{
  if(kindOfDisplay==COMMOM_CATODE)
    Write(off);
  else
    WriteA(off);
}
void SevenSegments::WriteNumber(char number)
{
  /*
   * REFERENCE 1
   * -->positon 0:a
   * -->positon 1:b
   * -->positon 2:c
   * -->positon 3:d
   * -->positon 4:e
   * -->positon 5:f
   * -->positon 6:g
   */
   /*
     *      a
     *     ----
     *  f |    |b
     *    | _g_|
     *  e |    |c
     *    |    |
     *     ----
     *       d
     */
    //a,b,c,d,e,f,g
    //Position of the bits{a,b,c,d,e,f,g}
  if(kindOfDisplay==COMMOM_CATODE)
  {
    switch(number)//We use the switch to indentify the number
    {
      case '0':
        Write(zero);
      break;
      case '1':
       Write(one);
      break;
      case '2':
       Write(two);
      break;
      case '3':
        Write(three);
      break;
      case '4':
        Write(four);
      break;
      case '5':
        Write(five);
      break;
      case '6':
        Write(six);
      break;
      case '7':
        Write(seven);
      break;
      case '8':
        Write(eight);
      break;
      case '9':
        Write(nine);
      break;
    }
  }
  else
  {
    switch(number)//We use the switch to indentify the number
    {
      case '0':
        WriteA(zero);
      break;
      case '1':
       WriteA(one);
      break;
      case '2':
       WriteA(two);
      break;
      case '3':
        WriteA(three);
      break;
      case '4':
        WriteA(four);
      break;
      case '5':
        WriteA(five);
      break;
      case '6':
        WriteA(six);
      break;
      case '7':
        WriteA(seven);
      break;
      case '8':
        WriteA(eight);
      break;
      case '9':
        WriteA(nine);
      break;
    }
  }
}
void SevenSegments::Write(byte* number)
{
  //zero[7]={1,1,1,1,1,1,0}
  //segments[7]={2,3,4,5,6,7,8}
  for(int i=0;i<7;i++)
    digitalWrite(segments[i],number[i]);
}
void SevenSegments::WriteA(byte* number)
{
  //zero[7]={1,1,1,1,1,1,0}
  //segments[7]={2,3,4,5,6,7,8}
  //zeroNegado[7]={1,1,1,1,1,1,0}
  //i=0
  /*
   * {0,1,1,1,1,1,0}
   * i=1
   * {0,0,1,1,1,1,0}
   * i=2
   * {0,0,0,1,1,1,0}
   * .
   * .
   * .
   * i=6
   * {0,0,0,0,0,0,1}
   */
  
  for(int i=0;i<7;i++)
    digitalWrite(segments[i],!number[i]);
}
int SevenSegments::ReadNumber()
{
  byte num[7];
  for(int i=0;i<7;i++)
    num[i]=digitalRead(segments[i]);
  if(num==zero)
    return 0;
  else if(num==one)
    return 1;
  else if(num==two)
    return 2;
  else if(num==three)
    return 3;
  else if(num==four)
    return 4;
  else if(num==five)
    return 5;
  else if(num==six)
    return 6;
  else if(num==seven)
    return 7;
  else if(num==eight)
    return 8;
  else
    return 9;
}

