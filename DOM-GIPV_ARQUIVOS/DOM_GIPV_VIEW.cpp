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

char menuJogador(char jogador){
	char op;
	printf("----------------------------------------------------------------\n");
	printf("Vez do jogador %c\n\n",jogador);
	printf("\n----------------------------------------------------------------\n");
	
	do{
		printf("0 - Jogar\n");
		printf("1 - Comprar\n");
		printf("2 - Passar\n");
		op = getchar();
		if(op <= '0' || op >= '1' || op == '2'){
			return op;
		} 
	}while(1);
}

void apresentarMesa(){
	if(mesa[0].status == '0'){
		printf("Mesa Vazia\n");
	}
	else{
		for(int i = 0; mesa[i].status != '0'; i++){
			printf("%d|%d ",mesa[i].ladoE, mesa[i].ladoD);
		}
	}
}

void apresentarPecasJogador(char jogador){ 
	// ---:> DEPOIS Apresentar pessas de um jogador especifico
	printf("----------------------------------------------------------------\n");
	printf("Pecas do jogador %c\n\n",jogador);
	for(int i = 0; i < 28; i++){
		if(pecas[i].status == jogador){
			printf("%d. %d|%d  ", i, pecas[i].lado1, pecas[i].lado2);
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


