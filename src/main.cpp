#include <iostream>
#include <string>
#include "../include/kanbanboard.h"
#include "../include/functions.h"

using namespace std;

int main()
{

    // Alocando dinamicamnete um objeto de kanbanBoard na HEAP
    KanbanBoard *kanbanBoard = new KanbanBoard();

    int numColunas;

    std::cout << "Deseja ler um arquivo?" << std::endl;
    std::cout << "1. Sim" << std::endl;
    std::cout << "2. Não" << std::endl;
    int escolha;
    std::cin >> escolha;
    switch (escolha) {
    // Caso: ler arquivo
    case 1:
        kanbanBoard->loadFromFile("dados.bin");
        break;

    // Caso: não ler um arquivo
    case 2:
        // Recebendo o número de colunas
        numColunas = receiveNumColumns();
        clearTerminal();

        // Recebendo os nomes das colunas
        receiveColumns(kanbanBoard, numColunas);
        clearTerminal();
        break;
    
    default:
        std::cout << "Informe uma opção válida.";
        break;
    }

    numColunas = kanbanBoard->getNumColumns();

    // Imprime o quadro com as colunas inseridas
    std::cout << "Ótimo! Aqui está seu quadro:\n";
    kanbanBoard->printBoard();
    std::cout << std::endl
              << std::endl;

    // Loop principal do programa
    while (true)
    {
        printMenu();
        int choice = getUserChoice();
        clearTerminal();
        executarOperacao(choice, kanbanBoard, numColunas);
    }

    // Libera a memória alocada
    delete kanbanBoard;
    kanbanBoard = NULL;

    return 0;
}