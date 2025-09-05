int maoJogador[2][21]; 

char JOGADOR_ATUAL; //JOGADOR_ATUAL
int COUNT_VEZ = 0; //QTD DE VEZES QUE OP FOI 3


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
	int jogadorComp;// 2 = o computador sendo o jogador 2 
	int mesaDJogo; // extremidade direita da mesa
	int mesaEJogo; // extremidade esquerda da mesa
}sitjogo;


void gerarpecas();
void embaralharPecas();






