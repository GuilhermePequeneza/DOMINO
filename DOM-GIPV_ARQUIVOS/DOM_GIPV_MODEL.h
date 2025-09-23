//DOM-GIPV - Projeto Domino - Etapa 5
//09/09/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida
int maoJogador[2][21]; 
int partidaCarregada;

char JOGADOR_ATUAL; //JOGADOR_ATUAL
int COUNT_VEZ = 0; //QTD DE VEZES QUE OP FOI 3
char nome1[15];
char nome2[10];


struct peca {
	int lado1;//lado direito
	int lado2;//lado esquerdo
	char status = 'N'; //NULL,'1','2','M'
} pecas[28];

struct mesa{
	int ladoE;
	int ladoD;
	char status = '0'; // '0', '1'
}mesa[28]; // PREENCHER POR FAVOR

struct Jogo
{
	int qtmesaJogo; //qtd de pessas na mesa
	char jogadorJogo; //jogador atual
	int jogadorComp = 0;// 2 = o computador sendo o jogador 2 
	int mesaDJogo; // extremidade direita da mesa
	int mesaEJogo; // extremidade esquerda da mesa
}sitjogo;


void gerarpecas();
void embaralharPecas();






