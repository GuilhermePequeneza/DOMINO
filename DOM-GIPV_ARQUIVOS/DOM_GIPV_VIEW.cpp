#include <stdio.h>
#include <stdlib.h>
#include "DOM_GIPV_VIEW.h"



void exibirPecas() {
	//---:>EXIBIR AS PECAS
	for(int i = 0; i <28; i++) {
		printf("[%d|",pecas[i].lado1);
		printf("%d] ",pecas[i].lado2);
	}
	printf("\n");
}


char menuGeral(){
	char op;
	do {
		printf("1 - Mostrar Peças\n");
		printf("0 - SAIR\n");
		op = getchar();
		
		if(op <= '0' || op >= '1'){
			return op;
		}
	} while(1);
	
}

char menuJogador(){
	// ---:> opcoes do jogador doq fazer
}

void apresentarMesa(){
	// ---:> Mostrar pessas na mesa
}

void apresentarPecasJogador(int jogador){
	// ---:> Apresentar pessas de um jogador especifico
	// ---:> qual pessa jogar
	// ---:> qual lado da mesa jogar (se necessario escolher)
}




void fclear(){
	char carac;
	while( (carac = fgetc(stdin)) != EOF && carac != '\n'){}
}


