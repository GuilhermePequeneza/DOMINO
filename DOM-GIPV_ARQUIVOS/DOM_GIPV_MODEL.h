int maoJogador[2][21]; 
int mesa[29];

struct peca {
	int lado1;
	int lado2;
	char status = 'NULL'; //NULL,'1','2','M'
} pecas[28];

struct mesa{
	int ladoE;
	int ladoD;
}; // PREENCHER POR FAVOR

void gerarpecas();
void embaralharPecas();






