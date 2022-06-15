//  ➤ Local variables
int waterHeight = 0;
int previousWaterHeight = 0;
bool flowStatus = false;
bool emergencyStop = false;
// int contador = 0; // número de loops até imprimir algo via serial

//  ➤ Local variables imported from radio structure
int pumpMode = 0;
int waterHeightMapValues[] = {40, 87, 0, 49};
int pumpModeRemote = 0;
// bool comando_bomba = false;
// bool filtragem = false; // comando interno INICIAL lig|desl filtragem_ativa

//  ➤ Software Serial variables
char inputReaded;

//  ➤ Timer control variables
bool lowFlowCounterEnable = true;

//  ➤ Timer variables
long lowFlowInitialTime = 0;
long measureInterval = 1;
long lastHeightCheck = 0;
long circulationInitialTime = 0;

//  ➤ Circulation control variables
bool heightReadyToCheck = false;
bool startupComplete = false;
bool circulationAutoEnable = false;
bool circulationActive=false;

bool filtragem_serial = false; // comando interno INICIAL lig|desl automatico da filtragem_ativa
