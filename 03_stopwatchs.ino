bool startupStopwatch(int inputValue, bool printEnable)
{
    if (STOPWATCH_MONITOR && printEnable)
    {
        Serial.print("\n------ startupStopwatch elapsed: ");
        Serial.print(__MiliSecToTime(millis()));
        Serial.print(" of ");
        Serial.println((String)inputValue + _MIN);
    }

    return (millis() > __MinToMiliSec(inputValue)) ? true : false;
}

bool compareHeightStopWatch()
{
    unsigned long elapsedTime = millis() - lastHeightCheck;
    if (STOPWATCH_MONITOR)
    {
        Serial.print("\n------ compareHeightStopWatch elapsed: ");
        Serial.print(__MiliSecToTime(elapsedTime));
        Serial.print(" of ");
        Serial.println((String)_waterHeightMeasureInterval + _MIN);
    }
    return (elapsedTime > __MinToMiliSec(_waterHeightMeasureInterval)) ? true : false;
}

bool autoCirculationStopWatch(bool begin)
{
    if (begin)
        circulationInitialTime = millis();
    unsigned long elapsedTime = millis() - circulationInitialTime;
    if (STOPWATCH_MONITOR)
    {
        Serial.print("\n------ autoCirculationStopWatch elapsed: ");
        Serial.print(__MiliSecToTime(elapsedTime));
        Serial.print(" of ");
        Serial.println((String)_circulationTotalTime + _HOUR);
    }
    if (elapsedTime > __HourToMiliSec(_circulationTotalTime))
    {
        pumpMode = PUMP_OFF;
        circulationAutoEnable = false;
        resetHeight();
        return true;
    }
    return false;
}

bool complexStopWatch(unsigned long initialValue, unsigned int setpoint, int stopWatchType, String myStrings[], bool enable)
{
    if (STOPWATCH_MONITOR && enable)
    {
        Serial.print(_SPACER + myStrings[0]);
        Serial.print(__MiliSecToTime(millis() - initialValue));
        Serial.print(_OF);
        Serial.println(myStrings[1]);
    }
    switch (stopWatchType)
    {
    case HEIGHER_THAN:
        return ((millis() - initialValue) > setpoint) ? true : false;
    case LOWER_THAN:
        return ((millis() - initialValue) < setpoint) ? true : false;
    default:
        return false;
    }
}
