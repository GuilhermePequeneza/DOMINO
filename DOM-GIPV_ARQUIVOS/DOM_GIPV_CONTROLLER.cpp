#include "DOM_GIPV_CONTROLLER.h"
#include "DOM_GIPV_VIEW.cpp"

void jogar(){
	char op;
	do{
		op = menuGeral();
		limpaTela();
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

char primeiraJogada() {
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
        mesa.ladoE = pecas[pecaMaior].lado1;
        mesa.ladoD = pecas[pecaMaior].lado2;
        jogadorAtual = 2;
        return '1'; // Jogador 1
    } else {
        
        mesa.ladoE = pecas[pecaMaior].lado1;
        mesa.ladoD = pecas[pecaMaior].lado2;
        jogadorAtual = 1;
        return '2'; // Jogador 2
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
	printf("Jogador %c comeca\n\n", jogadorAtual);
}

/*void jogadaJogador(int maoJogador, char jogador){
	int jogada = 0;
	int livreDireita; // primeiro espaco livre na direita
	livreDireita = proximaJogada();
	if(jogador == '1')
    {
           printf("Que peca voce quer jogar?\n");
           apresenta
           scanf("%d", &jogada);
           
           if(mesa[1].ladoE == pecas[jogada].lado2) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
           {
                 //loop pra passar tudo pra direita
                 pecas[jogada].status = 'M';
           }
           else if(mesa[livreDireita-1].ladoD == pecas[jogada].lado1)
           {
                mesa[livreDireita] = jogada;
                mesa[livreDireita].ladoD = peca[jogada].lado2;
                pecas[jogada].status = 'M';
           }
           jogador = 2;
    }
    else{
         jogador = 1;
    }
}*/

/*
void jogadaComputador(){
	
}
*/

// for loop vendo at� quando o array mesa � diferente de 0
//o i que for 0 � a pr�xima jogada

/*int proximaJogada(){
    for(int i = 1; mesa[i] != 0; i++)
    {
            return i;                   //PARTE DE JOGAR FAZER DEPOIS.
    }
}*/



