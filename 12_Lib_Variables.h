//  ➤ Local variables
int waterHeight = 0;
int previousWaterHeight = 0;
bool flowStatus = false;
bool emergencyStop = false;

//  ➤ Local variables imported from radio structure
int pumpMode = 0;
int previousMode = 0;
int waterHeightMapValues[] = {40, 87, 0, 49};
int pumpModeRemote = 0;

//  ➤ Software Serial variables
char inputReaded;

//  ➤ Timer control variables
bool lowFlowCounterEnable = true;

//  ➤ Timer variables
unsigned long lowFlowInitialTime = 0;
unsigned long measureInterval = 1;
unsigned long lastHeightCheck = 0;
unsigned long circulationInitialTime = 0;
unsigned long setFaultAutoReset = 0;

//  ➤ Circulation control variables
bool heightReadyToCheck = false;
bool startupComplete = false;
bool circulationAutoEnable = false;
bool circulationActive = false;
