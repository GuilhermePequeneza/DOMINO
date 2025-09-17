//DOM-GIPV - Projeto Domino - Etapa 5
//09/09/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida
#include "DOM_GIPV_CONTROLLER.h"
#include "DOM_GIPV_VIEW.cpp"

void jogar(){
	char op;

	finalizarJogo();
	op = menuGeral();
	limpaTela();
	switch(op)
	{
		case '1':
			embaralharPecas();
			prepararJogo();
			do{					
				op = menuJogador();
				switch(op)
				{
					case '1':
						COUNT_VEZ = 0;
						jogadaJogador();
						//printf("return: %d ",finalizarJogo() );
						break;
					case '2':
						comprarPecas();
						break;
					case '3':
						if(pecas[27].status == 'N'){
							printf("Ainda há peças a serem compradas.\n");
							system("pause");
						}
						else{	
							if(COUNT_VEZ == 1){
								COUNT_VEZ = 2;
							}
							else{
								COUNT_VEZ = 1;
							}
								passarVez();
						}
						limpaTela();
						break;
					case '4':
						mostrarRegras();
						break;
					case '5':
						salvarPartida("savegame.dat");
						break;
					case '6':
						carregarPartida("savegame.dat");
						break;
				}
			}while(op != '0' && finalizarJogo() == 0 && jogoTrancado() != 0);
			break;
		case '0':
			exit(0);
			break;
	}

}

void primeiraJogada() {
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
    
	mesa[0].ladoE = pecas[pecaMaior].lado1;
    sitjogo.mesaEJogo = pecas[pecaMaior].lado1;
    mesa[0].ladoD = pecas[pecaMaior].lado2;
    sitjogo.mesaDJogo = pecas[pecaMaior].lado2;
    pecas[pecaMaior].status = 'M';
    sitjogo.qtmesaJogo = 1;

    // Agora decide qual jogador tem a peca maior
    if(pecaMaior < 7) {
        sitjogo.jogadorJogo = '1';
    } else {
        sitjogo.jogadorJogo = '2';
    }
    
}


void prepararJogo(){
	for(int i = 0; i < 7; i++){
		maoJogador[0][i] = i;
		pecas[i].status = '1';
		maoJogador[1][i] = i+7;
		pecas[i + 7].status = '2';
		
	}
	primeiraJogada();
	printf("+----------------------------+\n");
	if(sitjogo.jogadorJogo == '1'){
		printf("%s comeï¿½ou\n", nome1);
	}
	else{
		printf("%s comeï¿½ou\n", nome2);
	}
	
	printf("+----------------------------+\n");
	passarVez();
	
	//if(sitjogo.jogadorJogo == '1')
	//	sitjogo.jogadorJogo = '2';
	//else{
	//	sitjogo.jogadorJogo = '1';
	//}
}

void jogadaJogador(){
	
	int jogada = 0;
	int erro = 1; //se o erro for 1 ele repete o jogador para refazer a jogada, se for 0 passqa a vez para o proximo 
	char tentarDenovo = 'S';
	int livreDireita; // primeiro espaco livre na direita
	char lado;
	
	//limpaTela();
	//apresentarMesa();
 	livreDireita = proximaJogada();
 	
 	do{
 		limpaTela();
 		apresentarMesa();
		printf("Qual peï¿½a voce quer jogar?\n");
		apresentarPecasJogador();
		
		char escolha;
		scanf(" %c", &escolha);
		//fclear();
		
		// converte letra para ï¿½ndice
		int indiceLetra = tolower(escolha) - 'a';
		
		//encontrar a peï¿½a correspondente
		int contador = 0;
		jogada = -1;
		for(int i = 0; i < 28; i++){
		    if(pecas[i].status == sitjogo.jogadorJogo){
		        if(contador == indiceLetra){
		            jogada = i; // indice real da peï¿½a no vetor `pecas`
		            break;
		        }
		        contador++;
		    }
		}
	
		if(jogada == -1){
		    erro = 1;
		}
		
		fclear();
		
		if((pecas[jogada].status != sitjogo.jogadorJogo) || ((pecas[jogada].lado1 != mesa[0].ladoE && pecas[jogada].lado2 != mesa[0].ladoE) && (pecas[jogada].lado1 != mesa[livreDireita - 1].ladoD && pecas[jogada].lado2 != mesa[livreDireita - 1].ladoD))){
			//Ve se a peca ta na mï¿½o dele e se estiver se pode ser colocada em uma das extremidades da mesa(ta grande eu sei, nï¿½o gostou faz melhor :) )
			printf("Peça inválida. Gostaria de jogar outra peça?(S/N)\n");
			tentarDenovo = getchar();
		
		} 
		else
			erro = 0;		
		if(erro == 0){
			if(comparaLados(jogada, livreDireita) == 1){
				jogadaDupla(jogada, livreDireita);
			}
			else{
				jogadaSimples(jogada, livreDireita);
			}
			sitjogo.qtmesaJogo++;
			sitjogo.mesaDJogo = mesa[livreDireita - 1].ladoD;
			sitjogo.mesaEJogo = mesa[0].ladoE;
		}
	}while(erro == 1 && (tentarDenovo == 'S' || tentarDenovo == 's'));//Repete a escolha da peca enquanto digitar SIM(s ou S)
	
	if(erro == 0){
	passarVez();
	}
	limpaTela();
}


void jogadaComputador(){
	int pecajogavel = 0;
	
	for(int i = 0; i<27;i++){
		if(pecas[i].lado1 == sitjogo.mesaDJogo || pecas[i].lado1 == sitjogo.mesaEJogo || pecas[i].lado2 == sitjogo.mesaDJogo || pecas[i].lado2 == sitjogo.mesaEJogo){
			pecajogavel = 1;
		}
		
	}
	if(pecajogavel = 0){
		if (pecas[27].status != 'N'){
			passarVez();
		}
	}
	
}


// for loop vendo atï¿½ quando o array mesa ï¿½ diferente de 0
//o i que for 0 ï¿½ a prï¿½xima jogada

int proximaJogada(){
	int i;
    for(i = 0; mesa[i].status != '0'; i++);
    return i;
}

void comprarPecas()
  {
  int i=14;
  while(i<28)
    {
    if(pecas[i].status=='N')
      {
      pecas[i].status=sitjogo.jogadorJogo;
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
		printf("%s Venceu :() xd", nome1);
		return 1;
		
	}
	if(count2 == 0){
		printf("%s Venceu :() xd", nome2);
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
	else{
		return 0;
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
			printf("Carï¿½cter invï¿½lido. Tente novamente");
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
			pecas[pecca].status = 'M';
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
		{														//lado esquerdo da mesa em comparaï¿½ï¿½o com o lado esquerdo da peca
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
		{														  //lado esquerdo da mesa em comparaï¿½ï¿½o com o lado direito da peca
			mesa[livee].status = '1';
			for (int i = livee; i > 0; i--) {
				mesa[i].ladoD = mesa[i - 1].ladoD;
				mesa[i].ladoE = mesa[i - 1].ladoE;
			}
			mesa[0].ladoE = pecas[pecca].lado2;
			mesa[0].ladoD = pecas[pecca].lado1;
			pecas[pecca].status = 'M';
	
		}
		else if(mesa[livee-1].ladoD == pecas[pecca].lado1)//lado direito da mesa em comparaï¿½ï¿½o com o lado direito da peca
		{
			mesa[livee].status = '1';
			mesa[livee].ladoD = pecas[pecca].lado2;
			mesa[livee].ladoE = pecas[pecca].lado1;
			pecas[pecca].status = 'M';
		}
		else if(mesa[livee-1].ladoD == pecas[pecca].lado2)//lado direito da mesa em comparaï¿½ï¿½o com o lado esquerdo da peca
		{
			mesa[livee].status = '1';
			mesa[livee].ladoD = pecas[pecca].lado1;
			mesa[livee].ladoE = pecas[pecca].lado2;
			pecas[pecca].status = 'M';
		}
}

int jogoTrancado(){ //Caso onde o jogo tranca
	
	int count1=0;
	int count2=0;
	int soma1=0;
	int soma2=0;
	

	if(COUNT_VEZ>1){ //Condicao que antecede a "finalizarJogo()" para ver se o jogo trancou

		for(int i = 0; i < 28; i++){ //verifica a quantidade de pecas na mao de cada jogador em - count1 e 2
			if(pecas[i].status == '1'){
				count1++;
				soma1 += pecas[i].lado1 + pecas[i].lado2; 

			}
			if(pecas[i].status == '2'){
				count2++;
				soma2 += pecas[i].lado1 + pecas[i].lado2; 
			}
			if(count1 > 0 && count2 > 0){
				break;
			}
		}
	
		if (soma1 > soma2){ //mensagem de saï¿½da
			printf("%s perdeu com %d total de pontos\n",nome1, soma1);
			printf("%s ganhou com %d total de pontos\n",nome2, soma2);
			return 0;
		if(soma2 > soma1){
			printf("%s ganhou com %d total de pontos\n",nome1, soma1);
			printf("%s perdeu com %d total de pontos\n",nome2, soma2);
			return 0;
		}
		else 
			printf("Os jogadores empataram na quantidade de pontos: j1 %d = j2 %d",soma1,soma2);
			return 0;
		}
	}
	else{
		return 1;
	}
}

void passarVez(){
	if(sitjogo.jogadorJogo == '1')
		sitjogo.jogadorJogo = '2';
	else
		sitjogo.jogadorJogo = '1';
}

void salvarPartida(const char *arquivo) {
    FILE *fp = fopen(arquivo, "wb");
    if (!fp) {
        printf("Erro ao abrir arquivo para salvar!\n");
        return;
    }

    // Salva nomes
    fwrite(nome1, sizeof(nome1), 1, fp);
    fwrite(nome2, sizeof(nome2), 1, fp);

    // Salva variï¿½veis globais
    fwrite(&JOGADOR_ATUAL, sizeof(JOGADOR_ATUAL), 1, fp);
    fwrite(&COUNT_VEZ, sizeof(COUNT_VEZ), 1, fp);

    // Salva peï¿½as
    fwrite(pecas, sizeof(pecas), 1, fp);

    // Salva mesa
    fwrite(mesa, sizeof(mesa), 1, fp);

    // Salva estado do jogo
    fwrite(&sitjogo, sizeof(sitjogo), 1, fp);

    fclose(fp);
    printf("Partida salva em %s!\n", arquivo);
    system("pause");
    limpaTela();
}

void carregarPartida(const char *arquivo) {
    FILE *fp = fopen(arquivo, "rb");
    if (!fp) {
        printf("Nenhum save encontrado!\n");
        //return;
    }

    // Carrega nomes
    fread(nome1, sizeof(nome1), 1, fp);
    fread(nome2, sizeof(nome2), 1, fp);

    // Carrega variï¿½veis globais
    fread(&JOGADOR_ATUAL, sizeof(JOGADOR_ATUAL), 1, fp);
    fread(&COUNT_VEZ, sizeof(COUNT_VEZ), 1, fp);

    // Carrega peï¿½as
    fread(pecas, sizeof(pecas), 1, fp);

    // Carrega mesa
    fread(mesa, sizeof(mesa), 1, fp);

    // Carrega estado do jogo
    fread(&sitjogo, sizeof(sitjogo), 1, fp);

    fclose(fp);
    printf("Partida carregada de %s!\n", arquivo);
    system("pause");
    limpaTela();
}


