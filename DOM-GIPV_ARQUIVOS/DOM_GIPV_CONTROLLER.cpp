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
				//apresentarPecasJogador('1');
				//printf("\n");
                apresentarMesa();
                printf("\n\n");
				//apresentarPecasJogador('2');
				
				jogadaJogador('1');
				printf("debug2");
				printf("\n\n\n\n\n\n\n\n\n\n\n");
				apresentarMesa();
				printf("\n");
				apresentarPecasJogador('1');
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
    mesa[0].status = '1';
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
        mesa[0].ladoE = pecas[pecaMaior].lado1;
        mesa[0].ladoD = pecas[pecaMaior].lado2;
        jogadorAtual = 2;
        pecas[pecaMaior].status = 'M';
        return '1'; // Jogador 1
    } else {
        mesa[0].ladoE = pecas[pecaMaior].lado1;
        mesa[0].ladoD = pecas[pecaMaior].lado2;
        jogadorAtual = 1;
        pecas[pecaMaior].status = 'M';
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

void jogadaJogador(char jogador){
	system("pause");
 	int jogada = 0;
	int tempE;
	int tempD;
	int livreDireita; // primeiro espaco livre na direita
	livreDireita = proximaJogada();
	if(jogador == '1')
    {
           printf("Que peca voce quer jogar?\n");
           apresentarPecasJogador(jogador);
           scanf("%d", &jogada);
           
           if(mesa[0].ladoE == pecas[jogada].lado2) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
           {
           		mesa[livreDireita].status = '1';
                for(int i = 0;i<livreDireita;i++){
                 	
                 	tempE = mesa[i+1].ladoE;
                 	tempD = mesa[i+1].ladoD;
                 	if(i>0){
                 		mesa[i+1].ladoE = tempE;
                 		mesa[i+1].ladoD = tempD;
					}
					else{
						mesa[i+1].ladoE = mesa[i].ladoE;
                 		mesa[i+1].ladoD = mesa[i].ladoD;
					}
                 	
				 }
				 mesa[0].ladoD = pecas[jogada].lado2;
				 mesa[0].ladoE = pecas[jogada].lado1;
                 pecas[jogada].status = 'M';
           }
           else if(mesa[0].ladoE == pecas[jogada].lado1) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
           {
           		mesa[livreDireita].status = '1';
                for(int i = 0;i<livreDireita;i++){
                 	
                 	tempE = mesa[i+1].ladoE;
                 	tempD = mesa[i+1].ladoD;
                 	if(i>0){
                 		mesa[i+1].ladoE = tempE;
                 		mesa[i+1].ladoD = tempD;
					}
					else{
						mesa[i+1].ladoE = mesa[i].ladoE;
                 		mesa[i+1].ladoD = mesa[i].ladoD;
					}
                 	
				 }
				 mesa[0].ladoD = pecas[jogada].lado1;
				 mesa[0].ladoE = pecas[jogada].lado2;
                 pecas[jogada].status = 'M';
           }
           else if(mesa[livreDireita-1].ladoD == pecas[jogada].lado1)
           {
           		mesa[livreDireita].status = '1';
                mesa[livreDireita].ladoD = pecas[jogada].lado2;
                mesa[livreDireita].ladoE = pecas[jogada].lado1;
                pecas[jogada].status = 'M';
           }
           else if(mesa[livreDireita-1].ladoD == pecas[jogada].lado2)
           {
           	    mesa[livreDireita].status = '1';
                mesa[livreDireita].ladoD = pecas[jogada].lado1;
                mesa[livreDireita].ladoE = pecas[jogada].lado2;
                pecas[jogada].status = 'M';
           }
           jogador = 2;
    }
    else{
           printf("Que peca voce quer jogar?\n");
           apresentarPecasJogador(jogador);
           scanf("%d", &jogada);
           
           if(mesa[0].ladoE == pecas[jogada].lado2) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
           {
           		mesa[livreDireita].status = '1';
                for(int i = 0;i<livreDireita;i++){
                 	
                 	tempE = mesa[i+1].ladoE;
                 	tempD = mesa[i+1].ladoD;
                 	if(i>0){
                 		mesa[i+1].ladoE = tempE;
                 		mesa[i+1].ladoD = tempD;
					}
					else{
						mesa[i+1].ladoE = mesa[i].ladoE;
                 		mesa[i+1].ladoD = mesa[i].ladoD;
					}
                 	
				 }
				 mesa[0].ladoD = pecas[jogada].lado2;
				 mesa[0].ladoE = pecas[jogada].lado1;
                 pecas[jogada].status = 'M';
           }
           else if(mesa[0].ladoE == pecas[jogada].lado1) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
           {
           		mesa[livreDireita].status = '1';
                for(int i = 0;i<livreDireita;i++){
                 	
                 	tempE = mesa[i+1].ladoE;
                 	tempD = mesa[i+1].ladoD;
                 	if(i>0){
                 		mesa[i+1].ladoE = tempE;
                 		mesa[i+1].ladoD = tempD;
					}
					else{
						mesa[i+1].ladoE = mesa[i].ladoE;
                 		mesa[i+1].ladoD = mesa[i].ladoD;
					}
                 	
				 }
				 mesa[0].ladoD = pecas[jogada].lado1;
				 mesa[0].ladoE = pecas[jogada].lado2;
                 pecas[jogada].status = 'M';
           }
           else if(mesa[livreDireita-1].ladoD == pecas[jogada].lado1)
           {
           		mesa[livreDireita].status = '1';
                mesa[livreDireita].ladoD = pecas[jogada].lado2;
                mesa[livreDireita].ladoE = pecas[jogada].lado1;
                pecas[jogada].status = 'M';
           }
           else if(mesa[livreDireita-1].ladoD == pecas[jogada].lado2)
           {
           	    mesa[livreDireita].status = '1';
                mesa[livreDireita].ladoD = pecas[jogada].lado1;
                mesa[livreDireita].ladoE = pecas[jogada].lado2;
                pecas[jogada].status = 'M';
           }
           jogador = 1;
    }
}

/*
void jogadaComputador(){
	
}
*/

// for loop vendo at� quando o array mesa � diferente de 0
//o i que for 0 � a pr�xima jogada

int proximaJogada(){
	int i;
    for(i = 0; mesa[i].status != '0'; i++);
    return i;
}



