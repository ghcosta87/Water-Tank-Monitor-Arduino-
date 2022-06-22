void checkWaterLevel(bool monitorEnable)
{
  if (!startupComplete && startupStopwatch(_statupDelay, true) && waterHeight != 0)
    resetHeight();
  if (heightReadyToCheck && compareHeightStopWatch())
    compareHeight();
  if (pumpMode == CIRCULATION_ON_AUTO || pumpMode == CIRCULATION_ON_MANUAL)
    autoCirculationStopWatch(false);

  if (monitorEnable)
  {
    String messages[] = {"waterHeight", "pumpMode", "circulationActive", "heightReadyToCheck", "startupStopwatch(_statupDelay)", "startupComplete"};
    unsigned long int data[] = {__floatToInt(waterHeight), __floatToInt(pumpMode), __floatToInt(circulationActive), __floatToInt(heightReadyToCheck), __floatToInt(startupStopwatch(_statupDelay, false)), __floatToInt(startupComplete)};
    String format[] = {"cm", "bool", "bool", "bool", "f_bool", "bool"};
    plotData("checkWaterLevel", messages, data, format, 6);
  }
}

void resetHeight()
{
  // Serial.println("\nRESETING HEIGHT\n");
  lastHeightCheck = millis();
  previousWaterHeight = waterHeight;
  startupComplete = true;
  heightReadyToCheck = true;
}

void compareHeight()
{
  //  Serial.println("\nCOMPARING HEIGHT\n");
  if (waterHeight > previousWaterHeight + HEIGHT_INCREASE_VALUE)
  {
    circulationAutoEnable = true;
    heightReadyToCheck = false;
    autoCirculationStopWatch(true);
  }
  else
  {
    heightReadyToCheck = true;
    resetHeight();
  }
}
