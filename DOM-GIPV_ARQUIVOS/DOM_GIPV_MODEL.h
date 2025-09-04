int maoJogador[2][21]; 

char JOGADOR_ATUAL; //JOGADOR_ATUAL
int COUNT_VEZ=0; //QTD DE VEZES QUE OP FOI 3


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

void gerarpecas();
void embaralharPecas();






