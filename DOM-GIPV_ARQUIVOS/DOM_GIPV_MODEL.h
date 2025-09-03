int maoJogador[2][21]; 

char JOGADOR_ATUAL; //JOGADOR_ATUAL

struct peca {
	int lado1;
	int lado2;
	char status = 'N'; //NULL,'1','2','M'
} pecas[28];

struct mesa{
	int ladoE;
	int ladoD;
	char status = '0'; // '0', '1'
}mesa[28]; // PREENCHER POR FAVOR

void gerarpecas();
void embaralharPecas();






