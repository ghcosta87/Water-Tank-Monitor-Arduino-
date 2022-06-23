#define READ_MONITOR 0
#define WATERLEVEL_MONITOR 0
#define RF_MONITOR_INPUT 0
#define ERROR_MONITOR 0
#define READ_STATUS 0
#define RF_MONITOR_OUTPUT 0
#define STOPWATCH_MONITOR 0

#if (READ_MONITOR == 1) || (WATERLEVEL_MONITOR == 1) || (RF_MONITOR_INPUT == 1) || (ERROR_MONITOR == 1) || (READ_STATUS == 1) || (RF_MONITOR_OUTPUT == 1) || (STOPWATCH_MONITOR == 1)
#define _HOUR " hour"
#define _MIN " min"
#define _SEC " sec"
#define _OF " of "
#define _SPACER "\n------ "
#define _FLOW_TITLE "low Flow limit: "
#define _ESTOP_TITLE "E-Stop reset: "
#else
#define _HOUR ""
#define _MIN ""
#define _SEC ""
#define _SPACER ""
#define _OF ""
#define _FLOW_TITLE ""
#define _ESTOP_TITLE ""
#endif

int ___convertPotToPressure(int inputValue)
{
    return map(inputValue, 0, 1023, 40, 87);
}
