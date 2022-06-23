void verifyErrors(bool monitorEnable)
{
  bool error[] = {false, false};
  error[0] = checkWaterHeightError();
  error[1] = checkFlowError(monitorEnable);

  if (error[0])
    sendData.fault = WATER_HEIGHT_ERROR;
  if (error[1])
    sendData.fault = FLOW_ERROR;
  if (error[0] && error[1])
    sendData.fault = FLOW_AND_HEIGHT_ERROR;
  if (sendData.fault > 0)
    emergencyStop = true;

  if (emergencyStop)
  {
    String myTexts[] = {_ESTOP_TITLE, String(_faultAutoReset) + _MIN};
    if (complexStopWatch(setFaultAutoReset, __MinToMiliSec(_faultAutoReset), HEIGHER_THAN, myTexts, true) && pumpModeRemote == PUMP_OFF)
    {
      emergencyStop = false;
      sendData.fault = 0;
    }
  }
  else
    setFaultAutoReset = millis();

  if (monitorEnable)
  {
    String messages[] = {"waterHeightError", "flowError", "fault"};
    unsigned long int data[] = {__floatToInt(error[0]), __floatToInt(error[1]), __floatToInt(sendData.fault)};
    String format[] = {"bool", "bool", "int"};
    plotData("verifyErrors", messages, data, format, 3);
  }
}

bool checkWaterHeightError()
{
  if (waterHeight <= minWaterHeight)
    return true;
  return false;
}

bool checkFlowError(bool monitorEnable)
{
  int flowValue = getFlow();
  if (monitorEnable)
  {
    String messages[] = {"flowValue", "lowFlowCounterEnable", "circulationActive"};
    unsigned long int data[] = {__floatToInt(flowValue), __floatToInt(lowFlowCounterEnable), __floatToInt(circulationActive)};
    String format[] = {"L/min", "bool", "bool"};
    plotData("checkFlowError", messages, data, format, 3);
  }
  if (lowFlowCounterEnable && circulationActive)
  {
    lowFlowInitialTime = millis();
    lowFlowCounterEnable = false;
  }
  String myTexts[] = {_FLOW_TITLE, (String)_lowFlowTimeLimit + _MIN};
  if (complexStopWatch(lowFlowInitialTime, __MinToMiliSec(_lowFlowTimeLimit), HEIGHER_THAN, myTexts, true) && !lowFlowCounterEnable)
  {
    if (circulationActive && flowValue < minimumFlow)
      return true;
    else
      lowFlowCounterEnable = true;
  }
  return false;
}
