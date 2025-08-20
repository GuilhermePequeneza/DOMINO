#include <stdio.h>
#include <stdlib.h>
#include "DOM_GIPV_VIEW.h"



void exibirPecas() {
	//---:>EXIBIR AS PECAS
	for(int i = 0; i <28; i++) {
		printf("[%d|",pecas[i].lado1);
		printf("%d] ",pecas[i].lado2);
	}
}

void pecasOrdenadas(){ //----> EXIBIR PECAS EM ORDEM
	for(int i = 0; i<=6; i++) {
		for(int j = i; j<=6; j++) {
			printf("[%d|%d] ", i, j);
		}
	}
}


void menu(){

	char menu;

	gerarPecas();

	printf("Pecas Organizadas:\n");
	exibirPecas();

	printf("\n\n");

	system("pause");

	embaralharPecas();

	printf("\nPecas Embaralhadas:\n");
	exibirPecas();

	
	do {

		

		printf("\n\n");

		printf("0. Sair\n1. Embaralhar novamente\n2. Pecas em ordem\n");

		printf("Digite a opcao desejada: ");
		scanf("%c", &menu);
		fclear();

        //---:> MENU
		switch (menu) {
		case '0':
			break;
		case '1':
		    printf("\nNovo embaralhamento: \n");
		    embaralharPecas();
		    exibirPecas();
		    break;
		case '2':
			printf("Pecas ordenadas:\n");
			pecasOrdenadas();
			break;
		default:
			printf("Opcao Invalida");
			break;
		}
		
	} while(menu != '0');
	
	
	
}



void fclear(){
	char carac;
	while( (carac = fgetc(stdin)) != EOF && carac != '\n'){}
}


