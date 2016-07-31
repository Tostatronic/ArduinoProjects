#ifndef SEVEN_SEGMENTS_CONTROLLER_H
#define SEVEN_SEGMENTS_CONTROLLER_H
#include <Arduino.h>
#include "SevenSegmentDisplay.h"
class SevenSegmentsController
{
 public:
 SevenSegmentsController(int _kindOfDisplay,int* _pins1);
 SevenSegmentsController(int _kindOfDisplay1,int* _pins1,int _kindOfDisplay2,int* _pins2);
 SevenSegmentsController(int _kindOfDisplay,int* _pins1,int _kindOfDisplay2,int* _pins2,int _kindOfDisplay3,int* _pins3);
 SevenSegmentsController(int _kindOfDisplay,int* _pins1,int _kindOfDisplay2,int* _pins2,int _kindOfDisplay3,int* _pins3,int _kindOfDisplay4,int* _pins4);
 void Write(short int number);
 private: 
 int numPins;//Numero de display que se declaran
 SevenSegments displays[4];
 int NumberOfPotitions(short int number);
 int* pins;//You have tu put the pins in order according tu your display(s)
 bool kindOfDisplay;
};
#endif
