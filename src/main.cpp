#include <iostream>
#include "../include/classes.h"
#include "../include/functions.h"
#include "../include/templates.hpp"
#include "../include/estruturas_tads.hpp"

using namespace std;

int main(){

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
    delete task;


    return 0;
}