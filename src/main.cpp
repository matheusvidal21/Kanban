#include <iostream>
#include <string>
#include "../include/classes.h"
#include "../include/functions.h"
#include "../include/templates.hpp"
#include "../include/estruturas_tads.hpp"

using namespace std;

int main(){
/*
    KanbanBoard *tabela = new KanbanBoard;
    int operação;
    // Variáveis para criação de uma task (KanbanTask)
    int id, prioridade;
    std::string titulo, descricao, dataVencimento, status;
    KanbanTask *task = new KanbanTask;

    cout << "Bem vindo ao gerenciador de tarefas Kanban\n"
    << "Esta é sua tabela: " << endl;
    tabela->printBoard();

    cout << "Deseja realizar alguma operação?\n"
    << "1. Adicionar nova tarefa\n"
    << "2. Editar tarefa existente\n" << endl;
    cin >> operação;

    clearTerminal();

    switch (operação)
    {
    case 1:
    cout << "ID: ";
    cin >> id;
    task->setId(id);

    cout << "Título: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, titulo);
    task->setTitulo(titulo);

    cout << "Descrição: ";
    getline(cin, descricao);
    task->setDescricao(descricao);

    cout << "Prioridade: ";
    cin >> prioridade;
    task->setPrioridade(prioridade);

    cout << "Data de Vencimento: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, dataVencimento);
    task->setVencimento(dataVencimento);

    cout << "Status: ";
    getline(cin, status);
    task->setStatus(status);

    tabela->addTask(task); // ADICIONANDO UMA NOVA TAREFA A LISTA ENCADEADA
        break;  
    
    default:
        break;
    }

    delete tabela;
    tabela = NULL;
    delete task;
    task = NULL;*/

    KanbanBoard kanbanBoard;

    //Recebendo as colunas
    int numColunas;
    std::cout << "Quantas colunas você deseja adicionar?\n";
    std::cin >> numColunas;
    std::cin.ignore(); // Descarta o caractere de nova linha após a leitura do número
    clearTerminal();
    for(int i = 0; i < numColunas; i++){
        std::string coluna;
        std::cout << "Informe o nome da " << (i + 1) << "ª coluna: ";
        std::getline(std::cin, coluna);
        kanbanBoard.addColumn(coluna);
    }
    clearTerminal();


    std::cout << "Essa é sua tabela:\n";
    kanbanBoard.displayBoard();
            

    //fazer agora para adicionar tarefas em uma coluna

    // Adicionar tarefas às colunas
    KanbanTask task1(1, "Task 1");
    KanbanTask task2(2, "Task 2");
    KanbanTask task3(3, "Task 3");
    KanbanTask task4(4, "Task 4");/*


    kanbanBoard.addTaskToColumn(0, task1); // Adicionar à coluna "To Do"
    kanbanBoard.addTaskToColumn(1, task2); // Adicionar à coluna "In Progress"
    kanbanBoard.addTaskToColumn(1, task3); // Adicionar à coluna "In Progress"*/
    kanbanBoard.addTaskToColumn("fazendo", task4); // Adicionar à coluna "fazendo"

    // Exibir o quadro Kanban
    kanbanBoard.displayBoard();

    // Mover uma tarefa para outra coluna
    kanbanBoard.moveTask(0, 2, 0); // Mover a primeira tarefa da coluna "To Do" para a coluna "Done"


    cout << endl << "Depois de mover\n" << endl;

    // Exibir o quadro Kanban atualizado
    kanbanBoard.displayBoard();


    return 0;
}