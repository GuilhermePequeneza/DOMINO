//DOM-GIPV - Projeto Domino - Etapa 4
//02/09/2025 - Grupo: GIPV
//Guilherme Pequeneza
//Igor Dias da Silva
//Pedro Cione Barbosa
//Vitor Seiji Colombo Nishida

#include "DOM_GIPV_MODEL.cpp"
#include "DOM_GIPV_CONTROLLER.cpp"


main()
{	
	setlocale(LC_ALL,"");
	mostrarRegras();
	quantosJogadores(); //VIEW
	//system("pause");
	gerarPecas(); //--:> MODEL
	jogar(); //--:> CONTROLLER
	
}



