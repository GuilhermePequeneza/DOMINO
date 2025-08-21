#include "DOM_GIPV_CONTROLLER.h"
#include "DOM_GIPV_VIEW.cpp"

void jogar(){
	char op;
	do{
		
		op=menuGeral();
		switch(op)
		{
			case '1':
				prepararJogo();
				IniciaJogo();
				break;
			case '0':
				exit(0);
				break;
			default:
				printf("Ta errado"); //---:> acho melhor botar no view
		}
	}while(0)
	
	//bom dia, segue os arquivos zipados do grupo GIPV.

	
}


