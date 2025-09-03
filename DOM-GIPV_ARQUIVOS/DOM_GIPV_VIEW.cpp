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
       printf("Quantos Jogadores(1 ou 2)?\n");
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
		printf("Escolha uma opcao: ");
		op = getchar();
		fclear();
		if(op <= '0' || op >= '1'){
			return op;
		}
	} while(1);
	
}

char menuJogador(char jogador){
	char op;
	//limpaTela(); 
	apresentarMesa();
	printf("----------------------------------------------------------------\n");
	printf("Vez do jogador %c\n",JOGADOR_ATUAL);
	printf("----------------------------------------------------------------\n");
	apresentarPecasJogador(JOGADOR_ATUAL);
	do{
		
		printf("0 - Acabar\n");
		printf("1 - Jogar\n");
		printf("2 - Comprar\n");
		printf("3 - Passar\n");
		printf("Escolha uma opcao: ");
		op = getchar();
		fclear();
		if(op >= '0' || op <= '3')
		{
			return op;
		} 
		else
			printf("Escolha invalida");
		
		limpaTela(); 
	}while(1);
}

void apresentarMesa(){
	printf("Mesa:\n\n");
	
	for(int i = 0; mesa[i].status != '0'; i++){
		printf("[%d|%d] ",mesa[i].ladoE, mesa[i].ladoD);
	}
	printf("\n\n");
	
}

void apresentarPecasJogador(char jogador){ 
	// ---:> DEPOIS Apresentar pessas de um jogador especifico
	printf("----------------------------------------------------------------\n");
	printf("Pecas do jogador %c\n\n",JOGADOR_ATUAL);
	for(int i = 0; i < 28; i++){
		if(pecas[i].status == JOGADOR_ATUAL){
			printf("%d.[%d|%d]  ", i, pecas[i].lado1, pecas[i].lado2);
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


