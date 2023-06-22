#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <iomanip>
#include "functions.h"
#include "estruturas_tads.hpp"

//CLASSE ABSTRATA
class Task{
    protected:
        int id;
        std::string titulo;
        std::string descricao;
        int prioridade;
        std::string dataVencimento; 
    public:
    //Contrutores
        Task(){}
        Task(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento) 
        : id(id), titulo(titulo), descricao(descricao), prioridade(prioridade), dataVencimento(dataVencimento) {}

        Task(int id, const std::string& titulo, const std::string& descricao, int prioridade) 
        : id(id), titulo(titulo), descricao(descricao), prioridade(prioridade) {}

        Task(int id, const std::string& titulo, const std::string& descricao) 
        : id(id), titulo(titulo), descricao(descricao) {}

        Task(int id, const std::string& titulo) 
        : id(id), titulo(titulo) {}

        
    //Destrutor
        ~Task(){};

    //Métodos getters
        int getId() const;
        std::string getTitulo() const;
        std::string getDescricao() const;
        int  getPrioridade() const;
        std::string getVencimento() const;

    //Métodos setters
        void setId(int id);
        void setTitulo(std::string titulo);
        void setDescricao(std::string descricao);
        void setPrioridade(int prioridade);
        void setVencimento(std::string dataVencimento);

    //Método virtual puro
        virtual void printTask() const = 0;

            
};

class KanbanTask : public Task {
    private:
        std::string status;

    public:
    //Contrutores
        KanbanTask(){}
        KanbanTask(int id, const std::string& titulo)
            : Task(id, titulo) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao)
            : Task(id, titulo, descricao) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade)
            : Task(id, titulo, descricao, prioridade) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento)
            : Task(id, titulo, descricao, prioridade, dataVencimento) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento, const std::string& status)
            : Task(id, titulo, descricao, prioridade, dataVencimento), status(status) {}   

    //Destrutor
        virtual ~KanbanTask(){}

    //Método set
        void setStatus(const std::string& status);
        std::string getStatus() const;

    bool operator==(const KanbanTask& other) const {
        return this->id == other.id && this->titulo == other.titulo && this->descricao == other.descricao;
    } 

    //Polimorfismo do método virtual
    void printTask() const{
        std::cout << "ID: " << id << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Descrição: " << descricao << std::endl;
        std::cout << "Prioridade: " << prioridade << std::endl;
        std::cout << "Data de Vencimento: " << dataVencimento << std::endl;
        std::cout << "Status: " << status << std::endl;
    }
};

class KanbanBoard {
private:
struct KanbanColumn {
        std::string name;
        ListaDuplamenteEncadeada<KanbanTask> tasks;

        KanbanColumn(const std::string& columnName) : name(columnName) {}
    };

    ListaDuplamenteEncadeada<KanbanColumn> columns; // Lista duplamente encadeada de colunas

public:
    KanbanBoard(){};
    ~KanbanBoard(){};
 

 
   // Adicionar uma nova coluna ao quadro Kanban
    void addColumn(const std::string& columnName) {
        KanbanColumn column(columnName);
        columns.pushBack(column);
    }

    // Adicionar uma tarefa a uma coluna específica do quadro Kanban
    /*void addTaskToColumn(int columnIndex, const KanbanTask& task) {
        KanbanColumn& column = columns.get(columnIndex);
        column.tasks.pushBack(task);
    }*/

    // Adicionar uma tarefa a uma coluna específica do quadro Kanban
    void addTaskToColumn(const std::string& columnName, const KanbanTask& task) {
    for (int i = 0; i < columns.getSize(); i++) {
        if (columns.get(i).name == columnName) {
            columns.get(i).tasks.pushBack(task);
            return;
        }
    }
   // Caso a coluna não seja encontrada, você pode lançar uma exceção, retornar um código de erro, ou tratar de outra forma, de acordo com a sua necessidade.
    // Aqui, por exemplo, lançamos uma exceção std::runtime_error.
        throw std::runtime_error("Coluna não encontrada: " + columnName);
    }

    // Mover uma tarefa de uma coluna para outra coluna do quadro Kanban
    void moveTask(int origemColumnIndex, int destinoColumnIndex, int taskIndex) {
        KanbanColumn& origemColumn = columns.get(origemColumnIndex);
        KanbanColumn& destinoColumn = columns.get(destinoColumnIndex);

        KanbanTask task = origemColumn.tasks.get(taskIndex);
        destinoColumn.tasks.pushBack(task);
        origemColumn.tasks.removeValue(task);
    }

    // Exibir as tarefas de uma coluna específica do quadro Kanban
    void displayColumn(int columnIndex) const {
        const KanbanColumn& column = columns.get(columnIndex);

        std::cout << "Column " << columnIndex << " - " << column.name << ":\n";
        for (int i = 0; i < column.tasks.getSize(); ++i) {
            const KanbanTask& task = column.tasks.get(i);
            std::cout << "Task " << i << ": " << task.getTitulo() << "\n";
        }
        std::cout << std::endl;
    }

void displayBoard() const {
    std::cout << "\n";
    std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
    std::cout << "|                                            GERENCIADOR DE TAREFAS KANBAN                                            |\n";
    std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
    
    //RESPONSIVIDADE
    int numColumn = columns.getSize();
    int columnWidth = 0;
    switch (numColumn){
    case 1: columnWidth = 60;
        break;
    case 2: columnWidth = 40;
        break;
    case 3: columnWidth = 30;
        break;
    case 4: columnWidth = 25;
        break;
    case 5: columnWidth = 20;
        break;
    case 6: columnWidth = 19;
        break;
    case 7: columnWidth = 15;
        break;
    case 8: columnWidth = 14;
        break;
    case 9: columnWidth = 13;
        break;
    default: columnWidth = 25;
        break;
    }



    //std::cout << "          ";
    // Imprime os títulos das colunas lado a lado
    for(int i = 0; i < columns.getSize(); i++) {
        std::cout << std::left << std::setw(columnWidth) << columns.get(i).name;
    }
    std::cout << std::endl;


    // Encontra o número máximo de tarefas em uma coluna
    int maxTasks = 0;
    for (int i = 0; i < columns.getSize(); ++i) {
        int columnSize = columns.get(i).tasks.getSize();
        if (columnSize > maxTasks) {
            maxTasks = columnSize;
        }
    }



    // Imprime as tarefas de cada coluna abaixo dos títulos
    for (int i = 0; i < maxTasks; ++i) {

        for(int j = 0; j < columns.getSize(); ++j) {
            if (i < columns.get(j).tasks.getSize()) {
                const KanbanTask& task = columns.get(j).tasks.get(i);
                std::cout << std::left << std::setw(columnWidth) << task.getTitulo();
            } else {
                std::cout << std::setw(columnWidth) << "";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
}



/*
    // Exibir as tarefas de uma coluna específica do quadro Kanban
    void displayColumn(int columnIndex) const {
        const KanbanColumn& column = columns.get(columnIndex);

        std::cout << "Column " << columnIndex << " - " << column.name << ":\n";
        for (int i = 0; i < column.tasks.getSize(); ++i) {
            const KanbanTask& task = column.tasks.get(i);
            std::cout << "Task " << i << ": " << task.getTitulo() << "\n";
        }
        std::cout << std::endl;
    }

    void displayBoard() const {


    std::cout << "+";
    for (int i = 0; i < columns.getSize(); ++i) {
        std::cout << "------------";
    }
    std::cout << "+\n";
    std::cout << "|         GERENCIADOR DE TAREFAS KANBAN          |\n";
    std::cout << "+";
    for (int i = 0; i < columns.getSize(); ++i) {
        std::cout << "------------";
    }
    std::cout << "+\n";

    //std::cout << "|";
    std::cout << std::setw(10);
    for (int i = 0; i < columns.getSize(); ++i) {
            std::cout << columns.get(i).name << std::setw(10);
    }
    std::cout << std::endl;


    // Get the maximum number of tasks in any column
    int maxTasks = 0;
    for (int i = 0; i < columns.getSize(); ++i) {
        int columnSize = columns.get(i).tasks.getSize();
        if (columnSize > maxTasks) {
            maxTasks = columnSize;
        }
    }

    // Iterate over the rows
    for (int row = 0; row < maxTasks; ++row) {


        // Print tasks for each column
        for (int i = 0; i < columns.getSize(); ++i) {
            if (row < columns.get(i).tasks.getSize()) {
                const KanbanTask& task = columns.get(i).tasks.get(row);
                std::cout << std::setw(10) << task.getTitulo();
            } else {
                std::cout << std::setw(10);
            }
        }

        std::cout << "\n";
    }


    std::cout << "+";
    for (int i = 0; i < columns.getSize(); ++i) {
        std::cout << "------------";
    }
    std::cout << "+\n";
}
*/



/*
    void addTask(KanbanTask* task);
    void removeTask(KanbanTask* task);
    void sortTasks(int prioridade);
    void moveTask(int taskId, const std::string& statusAtual, const std::string& statusDestino);
    void printTasks(const std::string& status);
    void printBoard();

    //Método get
    ListaDuplamenteEncadeada<KanbanTask*> getTasks() const;*/
};


#endif