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
       	printf("\nNome jogador 1: ");
       	gets(nome1);
       	strcpy(nome2, "Pequenezza AI");//easter egg
       	sitjogo.jogadorComp = 2;
	   }
	   else{
	   	printf("\nNome jogador 1: ");
	   	gets(nome1);
		printf("Nome jogador 2: ");
	   	gets(nome2);
	   }
       
 	}while(quantJog != 1 && quantJog != 2);
 	limpaTela();
 	
	return quantJog;
}
	
char menuGeral(){
    
    char op;
    
    do {
        limpaTela();
        printf("----------- DOMINÓ -----------\n\n");
        printf("0 - Sair\n");
        printf("1 - Começar Jogo Novo\n");
        printf("2 - Carregar Partida Salva\n\n");
        printf("------------------------------\n\n");
        printf("Escolha: ");
        
        op = getchar();
        fclear();
        if(op >= '0' && op <= '2'){
            return op;
        }
        else {
            printf("Opção inválida. Pressione Enter...\n");
            getchar();
        }
    } while(1);
	
}

char menuJogador(){

	char op;
	do{
		apresentarMesa();
		printf("----------------\n");
		if(sitjogo.jogadorJogo == '1'){
			printf("Vez de %s\n", nome1);
		}
		else{
			printf("Vez de %s\n", nome2);
		}
		
		printf("----------------\n\n");
		apresentarPecasJogador();
	
		
		printf("\n0 - Finalizar jogo\n");
		printf("1 - Jogar\n");
		printf("2 - Comprar\n");
		printf("3 - Passar\n");
		printf("4 - Regras do jogo\n");
		printf("5 - Salvar jogo\n");	
		printf("Escolha uma opção: ");
		op = getchar();
		if(op == 3) { 
			COUNT_VEZ++; 
		} //pensei em colocar uma condiÃ§Ã£o para toda vez que op for 3, ele adicionar +1 na variavel global
		// nao esquecer da viarvel global para poder ver toda vez que ele passar mais de uma vez
		
		fclear();
		if(op >= '0' && op <= '5')
		{
			return op;
		} 
		else{
			printf("Escolha inválida. Tente novamente\n");
			system("pause");
			limpaTela();
		}
			
		
		limpaTela(); 
	}while(1);
}

void apresentarMesa(){
	printf("\n");
    
    //conta quantas peças estão na mesa
    int pecasNaMesa = 0;
    for(int i = 0; mesa[i].status != '0'; i++){
        pecasNaMesa++;
    }
    
    if(pecasNaMesa == 0) {
        printf("Mesa: (vazia)\n");
        return; //se a mesa for vazia interrompe a função 
    }
    
    //calcula o tamanho da linha baseado no número de peças
    int tamanhoLinha = (pecasNaMesa * 6) ; //8 caracteres por peça 
    
    //linha superior
    printf("Mesa: ");
    for(int i = 0; i < tamanhoLinha; i++) printf("-");
    printf("\n");
    
    //linha com as peças
    printf("      ");
    for(int i = 0; mesa[i].status != '0'; i++){
        printf("[%d|%d] ", mesa[i].ladoE, mesa[i].ladoD);
    }
    printf("\n");
    
    //linha inferior
    printf("      ");
    for(int i = 0; i < tamanhoLinha; i++) printf("-");
    printf("\n");
    
    // Mostra extremidades
    printf("      Extremidades: [%d] - [%d]\n", sitjogo.mesaEJogo, sitjogo.mesaDJogo);
    printf("\n");
	
}

void apresentarPecasJogador(){ 
	// ---:> DEPOIS Apresentar pessas de um jogador especifico
	int pecasJogador = 0;
    for(int i = 0; i < 28; i++){
        if(pecas[i].status == sitjogo.jogadorJogo){
            pecasJogador++;
        }
    }
    
    
    //calcula o tamanho da linha baseado no número de peças
    int tamanhoLinha = (pecasJogador * 8); //8 caracteres por peça 
    int contador = 0; //indice alfabetico das peças
    
    printf("Peças: \n\n");
    //printf("       ");
    for(int i = 0; i < tamanhoLinha; i++){
    	printf("-");
	}
		
    printf("\n");
    
    //linha com as peças
    //printf("       ");
    printf("\n");
    for(int i = 0; i < 28; i++){
        if(pecas[i].status == sitjogo.jogadorJogo){
            printf("%c.", 'a' + contador);
			
			printf("[%d|%d] ", pecas[i].lado1, pecas[i].lado2);
			
            contador++;
        }
    }
	printf("\n");
    
    // Linha inferior
    //printf("       ");
    printf("\n");
    for(int i = 0; i < tamanhoLinha; i++){
    	printf("-");
	}
		
    printf("\n\n");
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

void boasVindas(){
	printf("\n						   Bem-Vindo						\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\nEste é um jogo de dominó produzido como parte de trabalho educacional da Pontifícia Universidade Católica de São Paulo\n\n");
	printf("\nAlunos: \n");
	printf("Igor Dias da Silva\n");
	printf("Guilherme Pequeneza\n");
	printf("Pedro Cione Barbosa\n");
	printf("Vitor Seiji Colombo Nishida\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	system("pause");
    limpaTela();
}


