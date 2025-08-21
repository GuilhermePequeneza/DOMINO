#include "DOM_GIPV_CONTROLLER.h"
#include "DOM_GIPV_VIEW.cpp"

void jogar(){
	char op;
	do{
		
		op = menuGeral();
		switch(op)
		{
			case '1':
				prepararJogo(); // ---:> entrega as peï¿½as para os dois jogadores
				//IniciaJogo(); // ---:> nao sei ainda
				exibirPecas();
				embaralharPecas();
				exibirPecas();
				break;
			case '0':
				exit(0);
				break;
		}
	}while(0);
}
	//bom dia, segue os arquivos zipados do grupo GIPV.
void primeiraJogada(){
	int pecaMaior = 0;
	for(int i = 1; i < 14; i++){    
		if(pecas[pecaMaior].lado1 == pecas[pecaMaior].lado2){ // PRIMEIRO CHECAS SE NOSSA PESSA MAIOR FOR DUPLA
			if(pecas[i].lado1 == pecas[i].lado2){ 
				if(pecas[pecaMaior].lado1 < pecas[i].lado1){ //SE FOR CHECAR SE A OUTRA É DUPLA E MAIOR
				pecaMaior = i;
				}
			}
		}
		else if(pecas[i].lado1 == pecas[i].lado2){ //SE NAO FOR CHECAR SE A OUTRA É DUPLA
			pecaMaior = i;
		}
		else if(pecas[i].lado1 + pecas[i].lado2 > pecas[pecaMaior].lado1 + pecas[pecaMaior].lado2) //SE NENHUMA DAS DUAS FOR DUPLA CHECAR QUAL SOMA É MAIOR
			pecaMaior = i;
		}
	}

void prepararJogo(){
	
	for(int i = 0; i < 7; i++){
		jogador[0][i] = i;
		pecas[i].status = '1';
		jogador[1][i] = i+7;
		pecas[i + 7].status = '2';
		
	}
	
}
/*
void jogadaJogador(int jogador){
	
}

void jogadaComputador(){
	
}
*/





