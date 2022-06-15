//  ➤ Pinout
#define pump 2
#define bypass 5
#define valve 4
#define flow 7
#define pressure A0
#define rxPin 9
#define txPin 10

//  ➤ Constants
//  ~ pmp control ~
#define PUMP_OFF 0
#define MANUAL_ON 1
#define CIRCULATION_ON_MANUAL 2
#define CIRCULATION_ON_AUTO 3
//  ~ water height control ~
#define HEIGHT_INCREASE_VALUE 3
//  ~ radio control ~
#define PIPE_BEGIN 155
#define PIPE_END 255
//  ~ errors control ~
#define FLOW_ERROR 0
#define WATER_HEIGHT_ERROR 1
#define FLOW_AND_HEIGHT_ERROR 2
//  ~ aux funcitions control ~
#define HEIGHER_THAN 0
#define LOWER_THAN 1
#define MIN_COMM_DURATION 200 // nome fora do padrao arrumar depois
#define MAX_COMM_DURATION 600 // nome fora do padrao arrumar depois

//  ➤ Setpoints
#define _waterHeightMeasureInterval  5 // in minutes
#define _waterHeightFinishMeasure 3 // in minutes
#define _statupDelay 1 // in minutes
#define _circulationTotalTime 6 // in hour

//  ➤ Alarms
#define lowFlowTimeLimit 1 // in minutes
#define minWaterHeight 2 // in centimeters
#define normalWaterHeight 10 // in centimeters
