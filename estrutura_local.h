//  ➤ Variáveis locais de recebimento de dados
bool comando_bomba = false;
bool filtragem = false; // comando interno INICIAL lig|desl filtragem_ativa

//  ➤ Variáveis para armazenar estado de erros
bool erro[] = {false, false};
bool nivel_baixo = false;
bool baixa_vazao = false;

//  ➤ Variáveis de monitoramento de comunicacao
//int sucesso = 0;
//int falha = 0;

//  ➤ Variáveis de entradas locais
int altura = 0;
int altura_ant = 0; //variavel para gravar anltura do loop anterior
int contador = 0; // número de loops até imprimir algo via serial
bool status_vazao = false;

//  ➤ Variáveis de temporizadores
//_______________________________________________________________________________
bool iniciar_cron_vazao = true; // liga e desliga contagem para alarmar vazao baixa
long tempo_baixa_vazao = 0; //armazena o tempo de inicio da falha
//_______________________________________________________________________________

//  ➤ Variáveis de controle local da filtragem
bool filtragem_ativa = false; // comando interno FINAL de liga|desl filtragem
bool filtragem_auto = false; // comando interno INICIAL lig|desl automatico da filtragem_ativa
bool filtragem_serial = false; // comando interno INICIAL lig|desl automatico da filtragem_ativa
bool hab_comparar_altura = false; // habilita contar tempo para checar a diferença de altura da coluna d'água
bool hab_valor_inicial = true; // habilitar igualar altura/altura_ant somente no inicio
long intervalo_d_medicao = 0; // armazena intervalo de tempo para checar a diferença de altura da coluna d'água
long tempo_inicial_d_filtragem = 0; // armazena intervalo de tempo inicial para manter a filtragem em funcionamento
