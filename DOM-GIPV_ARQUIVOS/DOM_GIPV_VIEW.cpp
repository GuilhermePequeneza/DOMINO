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

int quantosJogadores(){
     int quantJog = 0;
     	//Definir quantidade de jogadores
	do{
       printf("Quantos Jogadores?\n");
       scanf("%d", &quantJog);
	   fclear();
       
 }while(quantJog == 0);
 return quantJog;
     }
char menuGeral(){
	char op;

	do {
		limpaTela();
		printf("1 - Comecar Jogo\n");
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
	for(int i = 0; i < 29; i++){
		
	}
}

void apresentarPecasJogador(char jogador){ 
	// ---:> DEPOIS Apresentar pessas de um jogador especifico
	printf("----------------------------------------------------------------\n");
	printf("Pecas do jogador %c\n\n",jogador);
	for(int i = 0; i < 28; i++){
		if(pecas[i].status == jogador){
			printf("%d|%d  ", pecas[i].lado1, pecas[i].lado2);
		}
	}
	printf("\n----------------------------------------------------------------\n");
}

void fclear(){
	char carac;
	while( (carac = fgetc(stdin)) != EOF && carac != '\n'){}
}

void limpaTela(){
	system("cls");
}


