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
  readInputs(READ_MONITOR);            // 01_localControl.ino
  checkWaterLevel(WATERLEVEL_MONITOR); // 02_waterControl.ino
  receiveDataFromRF();
  recordDataFromRF(RF_MONITOR_INPUT);
  verifyErrors(ERROR_MONITOR);
  setOutputs(READ_STATUS);
  sendDataToRF(RF_MONITOR_OUTPUT); // 06_radioControl.ino
  delay(10);
}
