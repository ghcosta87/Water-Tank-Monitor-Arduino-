void receiveDataFromRF()
{
  long initialValue = millis();
  receivedData.pipeBegin = 0;
  receivedData.pipeEnd = 0;

  radio.startListening();
  String myTexts[2];
  while (!complexStopWatch(initialValue, random(MIN_COMM_DURATION, MAX_COMM_DURATION), HEIGHER_THAN, myTexts, false))
  {
    radio.read(&receivedData, sizeof(receivedData));
    if (checkStructure())
      break;
    // else comm error handler
  }
}

void recordDataFromRF(bool monitorEnable)
{
  if (checkStructure())
  {
    pumpModeRemote = PUMP_OFF;
    if (receivedData.pumpControl)
      pumpModeRemote = MANUAL_ON;
    if (receivedData.circulationControl)
      pumpModeRemote = CIRCULATION_ON_MANUAL;
  }
  if (monitorEnable)
  {
    String messages[] = {"pipeBegin", "pumpControl", "circulationControl", "pipeEnd"};
    unsigned long int data[] = {__floatToInt(receivedData.pipeBegin), __floatToInt(receivedData.pumpControl), __floatToInt(receivedData.circulationControl), __floatToInt(receivedData.pipeEnd)};
    String format[] = {"byte", "bool", "bool", "byte"};
    plotData("recordDataFromRF", messages, data, format, 4);
  }
}

void sendDataToRF(bool monitorEnable)
{
  radio.stopListening();
  long initialValue = millis();
  String myTexts[2];
  while (complexStopWatch(initialValue, random(MIN_COMM_DURATION, MAX_COMM_DURATION), LOWER_THAN, myTexts, false))
    !radio.write(&sendData, sizeof(sendData));
  if (monitorEnable)
  {
    String messages[] = {"pipeBegin", "analogPressure", "pumpState", "flowFeedback", "fault", "blank", "pipeEnd"};
    unsigned long int data[] = {__floatToInt(sendData.pipeBegin), __floatToInt(sendData.analogPressure), __floatToInt(sendData.pumpState), __floatToInt(sendData.flowFeedback), __floatToInt(sendData.fault), __floatToInt(sendData.blank), __floatToInt(sendData.pipeEnd)};
    String format[] = {"byte", "analog", "_", "_", "_", "_", "byte"};
    plotData("sendDataToRF", messages, data, format, 7);
  }
}
