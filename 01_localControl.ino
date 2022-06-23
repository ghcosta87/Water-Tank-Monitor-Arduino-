void readInputs(bool monitorEnable)
{
  // sendData.analogPressure = analogRead(pressure);
  sendData.analogPressure = ___convertPotToPressure(analogRead(pressure));
  sendData.pumpState = pumpMode;
  sendData.flowFeedback = flowStatus;

  waterHeight = map(sendData.analogPressure, waterHeightMapValues[0], waterHeightMapValues[1], waterHeightMapValues[2], waterHeightMapValues[3]);

  flowStatus = checkFlowStatus();

  if (monitorEnable)
  {
    String messages[] = {"pressure", "pumpMode", "flowStatus", "waterHeight"};
    unsigned long int data[] = {__floatToInt(sendData.analogPressure), __floatToInt(pumpMode), __floatToInt(flowStatus), __floatToInt(waterHeight)};
    String format[] = {"analog", "_", "_", "cm"};
    plotData("readInputs", messages, data, format, 4);
  }
}

void setOutputs(bool monitorEnable)
{
  bool eStopActive = false;
  if (emergencyStop)
  {
    ioSetup();
    eStopActive = true;
  }
  if (!eStopActive)
  {
    pumpMode = pumpModeRemote;

    if (circulationAutoEnable)
      pumpMode = CIRCULATION_ON_AUTO;

    switch (pumpMode)
    {
    case PUMP_OFF:
      digitalWrite(pump, HIGH);
      digitalWrite(valve, HIGH);
      digitalWrite(bypass, HIGH);
      circulationActive = false;
      break;
    case MANUAL_ON:
      digitalWrite(pump, LOW);
      digitalWrite(valve, HIGH);
      digitalWrite(bypass, HIGH);
      circulationActive = false;
      break;
    case CIRCULATION_ON_MANUAL:
    case CIRCULATION_ON_AUTO:
      circulationActive = true;
      digitalWrite(pump, HIGH);
      digitalWrite(valve, LOW);
      if (!(previousMode == CIRCULATION_ON_MANUAL || previousMode == CIRCULATION_ON_AUTO))
        delay(2000);
      digitalWrite(bypass, LOW);
      break;
    }
    previousMode = pumpMode;
    if (monitorEnable)
    {
      String messages[] = {"pump", "valve", "bypass", "pumpMode"};
      unsigned long int data[] = {__floatToInt(digitalRead(pump)), __floatToInt(digitalRead(valve)), __floatToInt(digitalRead(bypass)), __floatToInt(pumpMode)};
      String format[] = {"bool", "bool", "bool", "int"};
      plotData("setOutputs", messages, data, format, 4);
    }
  }
  else
    pumpMode = PUMP_OFF;
}
