void readInputs(bool monitorEnable)
{
  sendData.analogPressure = analogRead(pressure);
  sendData.pumpState = pumpMode;
  sendData.flowFeedback = flowStatus;

  waterHeight = map(sendData.analogPressure, waterHeightMapValues[0], waterHeightMapValues[1], waterHeightMapValues[2], waterHeightMapValues[3]);

  flowStatus = softSerialRead();

  if (monitorEnable)
  {
    String messages[] = {"pressure", "pumpMode", "flowStatus", "waterHeight"};
    float data[] = {sendData.analogPressure, pumpMode, flowStatus, waterHeight};
    String format[] = {"analog", "_", "_", "cm"};
    plotData("readInputs",messages, data, format);
  }
}

int softSerialRead()
{
  if (mySerial.available() > 0)
    inputReaded = mySerial.read();
  String s = String(inputReaded);
  return s.toInt();
}

void setOutputs()
{
  if (emergencyStop)
  {
    ioSetup();
    return;
  }

  pumpMode = pumpModeRemote;

  if (circulationAutoEnable)
    pumpMode = CIRCULATION_ON_AUTO;

  switch (pumpMode)
  {
  case PUMP_OFF:
    digitalWrite(pump, HIGH);
    digitalWrite(valve, HIGH);
    digitalWrite(bypass, HIGH);
    break;
  case MANUAL_ON:
    digitalWrite(pump, LOW);
    break;
  case CIRCULATION_ON_MANUAL:
  case CIRCULATION_ON_AUTO:
    digitalWrite(pump, HIGH);
    delay(2000);
    digitalWrite(valve, LOW);
    delay(2000);
    digitalWrite(bypass, LOW);
    break;
  }
}
