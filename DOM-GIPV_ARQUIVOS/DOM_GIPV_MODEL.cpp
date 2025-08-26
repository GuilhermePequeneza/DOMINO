#include "DOM_GIPV_MODEL.h"
#include<time.h>
#include<stdlib.h>
int jogadorAtual;

void gerarPecas() {
	//---:>GERA AS PECAS QUE SAO USADAS PARA EMBARALHAR E TAMBEM AS DE EXIBICAO
	int cont = 0;
	for(int i = 0; i<=6; i++) {
		for(int j = i; j<=6; j++) {
			pecas[cont].lado1 = i;
			pecas[cont].lado2 = j;
			cont++;
		}
	}
}

void embaralharPecas(){
	//---:>SRAND USADO PARA DEIXAR RANDOMICO
	srand(time(NULL));
	int pecatroca;
	int lado1temp;
	int lado2temp;

	//---:>TROCAR PECAS POR UMA PECA ALEATORIA
	for(int k = 0; k<28; k++) {
		//---:> ESCOLHE UMA PECA ALEATORIA PRA TROCAR DE LUGAR
		pecatroca = rand() % 28;
		lado1temp = pecas[k].lado1;
		lado2temp = pecas[k].lado2;
		pecas[k].lado1 = pecas[pecatroca].lado1;
		pecas[k].lado2 = pecas[pecatroca].lado2;
		pecas[pecatroca].lado1 = lado1temp;
		pecas[pecatroca].lado2 = lado2temp;
	}
}
