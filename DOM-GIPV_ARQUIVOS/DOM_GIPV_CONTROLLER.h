//DOM-GIPV - Projeto Domino - Etapa 5
//09/09/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida
void jogar();
void prepararJogo();
void primeiraJogada();
void jogadaJogador();
int proximaJogada();
void comprarPecas();
int finalizarJogo();
int comparaLados(int peka, int livre);
void jogadaDupla(int pecca, int livree);
void jogadaSimples(int pecca, int livee);
void passarVez();
void salvarPartida(const char *arquivo);
int carregarPartida(const char *arquivo);
int jogoTrancado();
int jogadaPossivel();
//void jogadaComputador();
int querCarregar();
void jogadaComputador();
void jogadaIA(int pecca, int livre, char preferencia);
