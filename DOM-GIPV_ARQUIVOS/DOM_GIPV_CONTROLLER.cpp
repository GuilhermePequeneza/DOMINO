#include "DOM_GIPV_CONTROLLER.h"
#include "DOM_GIPV_VIEW.cpp"

void jogar(){
	char op;
	do{
		
		op = menuGeral();
		switch(op)
		{
			case '1':
				embaralharPecas();
				prepararJogo(); // ---:> entrega as pecas para os dois jogadores
				//IniciaJogo(); // ---:> nao sei ainda
				apresentarPecasJogador('1');
				printf("\n");
                apresentarMesa();
                printf("\n\n");
				apresentarPecasJogador('2');
				break;
			case '0':
				exit(0);
				break;
		}
	}while(0);
}

int primeiraJogada() {
    int pecaMaior = 0;
    for(int i = 1; i < 14; i++) {
        int atualEhDupla = (pecas[i].lado1 == pecas[i].lado2);
        int maiorEhDupla = (pecas[pecaMaior].lado1 == pecas[pecaMaior].lado2);

        /*printf("Comparando peca %d (%d|%d) com atual maior %d (%d|%d)\n", 
                i, pecas[i].lado1, pecas[i].lado2, 
                pecaMaior, pecas[pecaMaior].lado1, pecas[pecaMaior].lado2);*/

        if(maiorEhDupla && atualEhDupla) {
            if(pecas[i].lado1 > pecas[pecaMaior].lado1) {
                pecaMaior = i;
            }
        }
        else if(!maiorEhDupla && atualEhDupla) {
            pecaMaior = i;
        }
        else if(!maiorEhDupla && !atualEhDupla) {
            int somaAtual = pecas[i].lado1 + pecas[i].lado2;
            int somaMaior = pecas[pecaMaior].lado1 + pecas[pecaMaior].lado2;

            if(somaAtual > somaMaior) {
                pecaMaior = i;
            }
        }
    }

    // Agora decide qual jogador tem a peca maior
    if(pecaMaior < 7) {
        return 1; // Jogador 1
    } else {
        return 2; // Jogador 2
    }
}


void prepararJogo(){
	
	for(int i = 0; i < 7; i++){
		maoJogador[0][i] = i;
		pecas[i].status = '1';
		maoJogador[1][i] = i+7;
		pecas[i + 7].status = '2';
		
	}
	jogadorAtual = primeiraJogada();
	printf("jogador %d comeca\n\n", jogadorAtual);
}
/*
void jogadaJogador(int jogador){
	
}

void jogadaComputador(){
	
}
*/





