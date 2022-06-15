void checkWaterLevel()
{
  if (startupComplete && startupStopwatch(_statupDelay) && waterHeight != 0)
    resetHeight();
  if (heightReadyToCheck && compareHeightStopWatch())
    compareHeight();
  autoCirculationStopWatch(false);
}

void resetHeight()
{
  lastHeightCheck = millis();
  previousWaterHeight = waterHeight;
  startupComplete = false;
  heightReadyToCheck = true;
}

void compareHeight()
{
  if (waterHeight > previousWaterHeight + HEIGHT_INCREASE_VALUE)
  {
    circulationAutoEnable = true;
    heightReadyToCheck = false;
    autoCirculationStopWatch(true);
  }
  else
    heightReadyToCheck = true;
}
