#include "10_Libs.h" //  ➤ Main Library

#define version "2.0"

void setup()
{
  ioBegin();
  ioSetup();
  serialSetup();
  radioSetup();
}

void loop()
{
  readInputs(READ_MONITOR); // 01_localControl.ino
  checkWaterLevel();
  receiveDataFromRF();
  recordDataFromRF();
  verifyErrors();
  setOutputs();
  sendDataToRF();
  delay(10);
}