#include "DOM_GIPV_CONTROLLER.h"
#include "DOM_GIPV_VIEW.cpp"

void jogar(){
	char op;
	do{
		
		op = menuGeral();
		switch(op)
		{
			case '1':
				//prepararJogo(); // ---:> entrega as pe�as para os dois jogadores
				//IniciaJogo(); // ---:> nao sei ainda
				exibirPecas();
				embaralharPecas();
				exibirPecas();
				break;
			case '0':
				exit(0);
				break;
		}
	}while(0)
	
	//bom dia, segue os arquivos zipados do grupo GIPV.

/*
void primeiraJogada(){
	
}

void jogadaJogador(int jogador){
	
}

void jogadaComputador(){
	
}
*/


}


