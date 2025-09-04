#include "DOM_GIPV_CONTROLLER.h"
#include "DOM_GIPV_VIEW.cpp"

void jogar(){
	char op;
	do{
		finalizarJogo();
		op = menuGeral();
		limpaTela();
		switch(op)
		{
			case '1':
				embaralharPecas();
				prepararJogo();
				do{
					op = menuJogador(JOGADOR_ATUAL);
					switch(op)
					{
						case '1':
							jogadaJogador(JOGADOR_ATUAL);
							
							//printf("return: %d ",finalizarJogo() );
							
							break;
						case '2':
							comprarPecas(JOGADOR_ATUAL);
							break;
						case '3':
							if(JOGADOR_ATUAL == '1')
								JOGADOR_ATUAL = '2';
							else
								JOGADOR_ATUAL = '1';
								limpaTela();
							break;
					}
				}while(op != '0' && finalizarJogo() == 0);
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
        pecas[pecaMaior].status = 'M';
        return '1'; // Jogador 1
    } else {
        mesa[0].ladoE = pecas[pecaMaior].lado1;
        mesa[0].ladoD = pecas[pecaMaior].lado2;
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
	JOGADOR_ATUAL = primeiraJogada();
	printf("Jogador %c comecou\n\n", JOGADOR_ATUAL);
	if(JOGADOR_ATUAL == '1')
		JOGADOR_ATUAL = '2';
	else{
		JOGADOR_ATUAL = '1';}
}

void jogadaJogador(char jogador){
	system("pause");
	
	
	char lado;
	limpaTela();
	apresentarMesa();
 	int jogada = 0;
	int erro = 0; //se o erro for 1 ele repete o jogador para refazer a jogada, se for 0 passqa a vez para o proximo 
	int livreDireita; // primeiro espaco livre na direita
	livreDireita = proximaJogada();
	printf("Qual peca voce quer jogar?\n");
	apresentarPecasJogador(jogador);
	scanf("%d", &jogada);
	fclear();
	if(pecas[jogada].status != JOGADOR_ATUAL)
		erro = 1;
	if(erro == 0){
		if(comparaLados(jogada, livreDireita) == 1){
			jogadaDupla(jogada, livreDireita);
		}
		else{
			jogadaSimples(jogada, livreDireita);
		else if(mesa[0].ladoE == pecas[jogada].lado2) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
		{														//lado esquerdo da mesa em compara��o com o lado esquerdo da peca
			mesa[livreDireita].status = '1';
			for (int i = livreDireita; i > 0; i--) {
				mesa[i].ladoD = mesa[i - 1].ladoD;
				mesa[i].ladoE = mesa[i - 1].ladoE;
			}
			mesa[0].ladoD = pecas[jogada].lado2;
			mesa[0].ladoE = pecas[jogada].lado1;
			pecas[jogada].status = 'M';
		}
		else if(mesa[0].ladoE == pecas[jogada].lado1) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
		{														  //lado esquerdo da mesa em compara��o com o lado direito da peca
			mesa[livreDireita].status = '1';
			for (int i = livreDireita; i > 0; i--) {
				mesa[i].ladoD = mesa[i - 1].ladoD;
				mesa[i].ladoE = mesa[i - 1].ladoE;
			}
			mesa[0].ladoE = pecas[jogada].lado2;
			mesa[0].ladoD = pecas[jogada].lado1;
			pecas[jogada].status = 'M';
	
		}
		else if(mesa[livreDireita-1].ladoD == pecas[jogada].lado1)//lado direito da mesa em compara��o com o lado direito da peca
		{
			mesa[livreDireita].status = '1';
			mesa[livreDireita].ladoD = pecas[jogada].lado2;
			mesa[livreDireita].ladoE = pecas[jogada].lado1;
			pecas[jogada].status = 'M';
		}
		else if(mesa[livreDireita-1].ladoD == pecas[jogada].lado2)//lado direito da mesa em compara��o com o lado esquerdo da peca
		{
			mesa[livreDireita].status = '1';
			mesa[livreDireita].ladoD = pecas[jogada].lado1;
			mesa[livreDireita].ladoE = pecas[jogada].lado2;
			pecas[jogada].status = 'M';
		}
	}
	else{
		printf("Peca invalida.Tente novamente\n");
		system("pause");
	}
	if(erro == 0){
	if(JOGADOR_ATUAL == '1')
		JOGADOR_ATUAL = '2';
	else
		JOGADOR_ATUAL = '1';
	}
	limpaTela();
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

void comprarPecas(char jogador)
  {
  int i=14;
  while(i<28)
    {
    if(pecas[i].status=='N')
      {
      pecas[i].status=jogador;
      break;
	  }
	i++;
	}
  if(i>=28)
    printf("Nada a comprar");
    system("pause");
    limpaTela();
  }

 /// 12, 14, 15
 
int finalizarJogo(){
	int count1 = 0;
	int count2 = 0;
	for(int i = 0; i < 28; i++){
		if(pecas[i].status == '1'){
			count1++;

		}
			if(pecas[i].status == '2'){
			count2++;
		}
		if(count1 > 0 && count2 > 0){
			break;
		}
	}
	if(count1 == 0){
		printf("Jogador 1 Venceu :() xd");
		return 1;
		
	}
	if(count2 == 0){
		printf("Jogador 2 Venceu :() xd");
		return 2;
	}
	else{
		return 0;
	}
}

int comparaLados(int peka, int livre){ //Ve se a jogada pode ser feita em ambas as extremidades da mesa
										// recebe o id da peca jogada e o o indice da mesa 
	if((mesa[0].ladoE == pecas[peka].lado1 || mesa[0].ladoE == pecas[peka].lado2) && (mesa[livre - 1].ladoD == pecas[peka].lado1 || mesa[livre - 1].ladoD == pecas[peka].lado2)){
		return 1;
	}
}

void jogadaDupla(int pecca, int livree){
	char lado;
	do{
		
		printf("Qual lado deseja jogar(E/D)?\n");
		//fclear();
		lado = getchar();
		fclear();
		if(lado != 'E' && lado != 'e' && lado != 'D' && lado != 'd'){
			printf("Caracter invalido. Tente novamente");
			system("pause");
			limpaTela();
		}
		if(lado == 'E' || lado == 'e'){
			mesa[livree].status = '1';
			
			for(int i = livree; i > 0; i--) {
				mesa[i].ladoD = mesa[i - 1].ladoD;
				mesa[i].ladoE = mesa[i - 1].ladoE;
				}
			if(mesa[0].ladoE == pecas[pecca].lado1){
				mesa[0].ladoD = pecas[pecca].lado1;
				mesa[0].ladoE = pecas[pecca].lado2;	
			
			}
			else{
				mesa[0].ladoD = pecas[pecca].lado2;
				mesa[0].ladoE = pecas[pecca].lado1;
					
			}
			pecas[livree].status = 'M';
		}
		if(lado == 'D' || lado == 'd'){
			mesa[livree].status = '1';
			if(mesa[livree - 1].ladoD == pecas[pecca].lado1){
				mesa[livree].ladoE = pecas[pecca].lado1;
				mesa[livree].ladoD = pecas[pecca].lado2;
					
			}
			else{
				mesa[livree].ladoD = pecas[pecca].lado1;
				mesa[livree].ladoE = pecas[pecca].lado2;	
					
			}
			pecas[pecca].status = 'M';
		}
		
	}while(lado != 'E' && lado != 'e' && lado != 'D' && lado != 'd');
}


void jogadaSimples(int pecca, int livee){
	if(mesa[0].ladoE == pecas[pecca].lado2) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
		{														//lado esquerdo da mesa em compara��o com o lado esquerdo da peca
			mesa[livee].status = '1';
			for (int i = livee; i > 0; i--) {
				mesa[i].ladoD = mesa[i - 1].ladoD;
				mesa[i].ladoE = mesa[i - 1].ladoE;
			}
			mesa[0].ladoD = pecas[pecca].lado2;
			mesa[0].ladoE = pecas[pecca].lado1;
			pecas[pecca].status = 'M';
		}
		else if(mesa[0].ladoE == pecas[pecca].lado1) //indice 1 pq vai tudo pra direita       //PARTE DE JOGAR FAZER DEPOIS.
		{														  //lado esquerdo da mesa em compara��o com o lado direito da peca
			mesa[livee].status = '1';
			for (int i = livee; i > 0; i--) {
				mesa[i].ladoD = mesa[i - 1].ladoD;
				mesa[i].ladoE = mesa[i - 1].ladoE;
			}
			mesa[0].ladoE = pecas[pecca].lado2;
			mesa[0].ladoD = pecas[pecca].lado1;
			pecas[pecca].status = 'M';
	
		}
		else if(mesa[livee-1].ladoD == pecas[pecca].lado1)//lado direito da mesa em compara��o com o lado direito da peca
		{
			mesa[livee].status = '1';
			mesa[livee].ladoD = pecas[pecca].lado2;
			mesa[livee].ladoE = pecas[pecca].lado1;
			pecas[pecca].status = 'M';
		}
		else if(mesa[livee-1].ladoD == pecas[pecca].lado2)//lado direito da mesa em compara��o com o lado esquerdo da peca
		{
			mesa[livee].status = '1';
			mesa[livee].ladoD = pecas[pecca].lado1;
			mesa[livee].ladoE = pecas[pecca].lado2;
			pecas[pecca].status = 'M';
		}
int JogoTrancado(){ //Caso onde o jogo tranca
	int count1=0;
	int count2=0;
	int soma1=0;
	int soma2=0;
	

	if(COUNT_VEZ>1){ //Condicao que antecede a "finalizarJogo()" para ver se o jogo trancou

		for(int i = 0; i < 28; i++){ //verifica a quantidade de pecas na mao de cada jogador em - count1 e 2
			if(pecas[i].status == '1'){
				count1++;
				soma1 = pecas[i].lado1 + pecas[i].lado2 

			}
				if(pecas[i].status == '2'){
				count2++;
				soma2 = pecas[i].lado1 + pecas[i].lado2 
			}
			if(count1 > 0 && count2 > 0){
				break;
			}
		}
	
		if (soma1 > soma2){ //mensagem de saída
			printf("Jogador 1 venceu com %d total de pontos\n",soma1);
			printf("Jogador 2 perdeu com %d total de pontos\n",soma2);

		
		if(soma2 > soma1) {
		printf("Jogador 2 venceu com %d total de pontos\n",soma2);
		printf("Jogador 1 perdeu com %d total de pontos\n",soma1);
		}
		else 
		printf("Os jogadores empataram na quantidade de pontos: j1 %d = j2 %d",soma1,soma2);

		}
	}
}


