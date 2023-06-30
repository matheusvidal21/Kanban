#include <iostream>
#include <string>
#include "../include/kanbanboard.h"
#include "../include/functions.h"

using namespace std;

int main()
{

    // Alocando dinamicamnete um objeto de kanbanBoard na HEAP
    KanbanBoard *kanbanBoard = new KanbanBoard();

    // Recebendo o número de colunas
    int numColunas = receiveNumColumns();
    clearTerminal();

    // Recebendo os nomes das colunas
    receiveColumns(kanbanBoard, numColunas);
    clearTerminal();

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