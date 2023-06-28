#include <iostream>
#include <string>
#include "../include/classes.h"
#include "../include/functions.h"
#include "../include/templates.hpp"
#include "../include/estruturas_tads.hpp"

using namespace std;

int main(){

    // Alocando dinamicamnete um objeto de kanbanBoard na HEAP
    KanbanBoard* kanbanBoard = new KanbanBoard();

    // Recebendo as colunas
    int numColunas;
    std::cout << "===========" << ANSI_GREEN << " Bem vindo ao gerenciador de tarefas Kanban! "  << ANSI_RESET << "===========\n";
    std::cout << "Quantas colunas você deseja adicionar no seu gerenciador?\n";
    std::cin >> numColunas;
    std::cin.ignore(); // Descarta o caractere de nova linha após a leitura do número
    clearTerminal();

    std::cout << "===========" << ANSI_GREEN << " Informe os nomes das colunas " << ANSI_RESET << "===========\n";
    for(int i = 0; i < numColunas; i++){
        std::string coluna;
        std::cout << (i + 1) << "ª coluna: ";
        std::getline(std::cin, coluna);
        stringMaiusculo(coluna);
        kanbanBoard->addColumn(coluna);
    }

    clearTerminal();

    // Imprime o quadro com as colunas inseridas
    std::cout << "Ótimo! Aqui está seu quadro:\n";
    kanbanBoard->printBoard();
    std::cout << "\n" << std::endl;

    // Loop principal do programa
    while(true){
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