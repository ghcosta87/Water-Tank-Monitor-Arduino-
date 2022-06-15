bool startupStopwatch(int inputValue)
{
    return (millis() > __MinToMiliSec(inputValue)) ? true : false;
}

bool compareHeightStopWatch()
{
    long elapsedTime = millis() - lastHeightCheck;
    return (elapsedTime > __MinToMiliSec(_waterHeightMeasureInterval)) ? true : false;
}

bool autoCirculationStopWatch(bool begin)
{
    if (begin)
        circulationInitialTime = millis();
    long elapsedTime = millis() - circulationInitialTime;
    if (elapsedTime > __HourToMiliSec(_circulationTotalTime))
    {
        pumpMode = PUMP_OFF;
        circulationAutoEnable=false;
        resetHeight();
        return true;
    }
    return false;
}

bool complexStopWatch(long initialValue, int setpoint, int stopWatchType)
{
    switch (stopWatchType)
    {
    case HEIGHER_THAN:
        return ((millis() - initialValue) > setpoint) ? true : false;
    case LOWER_THAN:
        return ((millis() - initialValue) < setpoint) ? true : false;
    }
}