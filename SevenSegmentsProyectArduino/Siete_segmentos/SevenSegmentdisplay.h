#ifndef SEVEN_SEGMENT_DISPLAY_H
#define SEVEN_SEGMENT_DISPLAY_H
#define COMMOM_CATODE 1
#define COMMOM_ANODE 2
#include <Arduino.h>
class SevenSegments
{
  public:
  SevenSegments(int* _segments,int definition);
  SevenSegments();
  void WriteNumber(char number);
  int ReadNumber();
  void SetPins(int* pins,int definition);
  void Reset();
  private:
  int kindOfDisplay;
  void Write(byte* number);
  void WriteA(byte* number);
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
     *       a
     *     ----
     *     |b
     *     |
     *     |c
     *     |
     *      
     *      
     */
    //a,b,c,d,e,f,g
    //        {a,b,c,d,e,f,g};
    // !-->Signo de negacion
  byte off[7]={0,0,0,0,0,0,0};
  //           {a,b,c,d,e,f,g};
  byte zero[7]={1,1,1,1,1,1,0};
  byte one[7]={0,1,1,0,0,0,0};
  byte two[7]={1,1,0,1,1,0,1};
  byte three[7]={1,1,1,1,0,0,1};
  byte four[7]={0,1,1,0,0,1,1};
  byte five[7]={1,0,1,1,0,1,1};
  byte six[7]={1,0,1,1,1,1,1};
  byte seven[7]={1,1,1,0,0,0,0};
  byte eight[7]={1,1,1,1,1,1,1};
  byte nine[7]={1,1,1,0,0,1,1};
  int* segments;
};
#endif
