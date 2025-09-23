//DOM-GIPV - Projeto Domino - Etapa 5
//09/09/2025 - Grupo: GIPV
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
    
    // Pergunta se quer carregar partida salva
    partidaCarregada = querCarregar();
    
    if(partidaCarregada) {
        printf("Partida carregada! Continuando jogo...\n");
        system("pause");
    } else {
        // Só configura novo jogo se não carregou
        quantosJogadores();
        gerarPecas(); // SÓ gera peças para jogo novo
    }
    
    jogar();
}
