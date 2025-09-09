//DOM-GIPV - Projeto Domino - Etapa 5
//09/09/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida
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
       if(quantJog == 1){
       	printf("Nome jogador 1:");
       	gets(nome1);
       	strcpy(nome2, "Pequenezza A.I");//easter egg
	   }
	   else{
	   	printf("\nNome jogador 1: ");
	   	gets(nome1);
		printf("Nome jogador 2: ");
	   	gets(nome2);
	   }
       
 	}while(quantJog == 0);
 	return quantJog;
}
	
char menuGeral(){
	char op;
	
	do {
		limpaTela();
		printf("1 - Começar Jogo\n");
		printf("0 - SAIR\n");
		printf("Escolha uma opção: ");
		op = getchar();
		fclear();
		if(op <= '0' || op >= '1'){
			return op;
		}
	} while(1);
	
}

char menuJogador(){

	char op;
	//limpaTela(); 
	apresentarMesa();
	printf("+----------------------------+\n");
	if(sitjogo.jogadorJogo == '1'){
		printf("Vez de %s\n", nome1);
	}
	else{
		printf("Vez de %s\n", nome2);
	}
	
	printf("+----------------------------+\n");
	apresentarPecasJogador(sitjogo.jogadorJogo);
	do{
		
		printf("\n0 - Finalizar jogo\n");
		printf("1 - Jogar\n");
		printf("2 - Comprar\n");
		printf("3 - Passar\n");
		printf("4 - Regras do jogo\n");
		printf("Escolha uma opção: ");
		op = getchar();
		if(op == 3) { COUNT_VEZ++; } //pensei em colocar uma condiÃ§Ã£o para toda vez que op for 3, ele adicionar +1 na variavel global
		// nao esquecer da viarvel global para poder ver toda vez que ele passar mais de uma vez
		
		fclear();
		if(op >= '0' || op <= '3')
		{
			return op;
		} 
		else
			printf("Escolha inválida");
		
		limpaTela(); 
	}while(1);
}

void apresentarMesa(){
	printf("\nMesa:\n\n");
	
	for(int i = 0; mesa[i].status != '0'; i++){
		printf("[%d|%d] ",mesa[i].ladoE, mesa[i].ladoD);
	}
	printf("\n\n");
	
}

void apresentarPecasJogador(char jogador){ 
	// ---:> DEPOIS Apresentar pessas de um jogador especifico
	printf("----------------------------------------------------------------\n");
    if(sitjogo.jogadorJogo == '1'){
		printf("Peças de %s\n\n", nome1);
	}
	else{
		printf("Peças de %s\n\n", nome2);
	}

    int indiceLetra = 0; //mostra letras em vez de números(bem melhor)
    for(int i = 0; i < 28; i++){
        if(pecas[i].status == sitjogo.jogadorJogo){
            printf("%c.[%d|%d]  ", 'a' + indiceLetra, pecas[i].lado1, pecas[i].lado2);
            indiceLetra++;
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

void mostrarRegras(){
	limpaTela();
    printf("------------------------------------- REGRAS DOMINO -----------------------------------\n\n");
    printf("1. O jogo pode ter 1 ou 2 jogadores.\n");
    printf("2. Cada jogador recebe 7 peças aleatoriamente.\n");
    printf("3. O jogador com a maior peça dupla (ex: [6|6]) comeca o jogo.\n");
    printf("5. Se ninguem tiver uma peça dupla, comeca quem tiver maior soma dos valores da peça.\n");
    printf("4. O primeiro a ficar sem peças ganha o jogo.\n");
    printf("\n---------------------------------------------------------------------------------------\n\n");
    system("pause");
    limpaTela();
}

/*void boasVindas(){
	printf("					Bem-Vindo						\n");

}
*/
//Função para exibir uma tela inicial, terminar depois

