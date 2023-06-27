#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "estruturas_tads.hpp"
#include "templates.hpp"

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"

//CLASSE ABSTRATA
class Task{
    protected:
        std::string titulo;
        std::string descricao;
        int prioridade;
        std::string dataVencimento; 
    public:
        //Contrutores
        Task();
        Task(const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento);
        Task(const std::string& titulo, const std::string& descricao, int prioridade);
        Task(const std::string& titulo, const std::string& descricao);
        Task(const std::string& titulo);

        //Destrutor
        virtual ~Task(){};

        //Métodos getters
        std::string getTitulo() const;
        std::string getDescricao() const;
        int  getPrioridade() const;
        std::string getVencimento() const;

        //Métodos setters
        void setTitulo(std::string titulo);
        void setDescricao(std::string descricao);
        void setPrioridade(int prioridade);
        void setVencimento(std::string dataVencimento);

        //Método virtual puro
        virtual void printTask() const = 0;

};

class KanbanTask : public Task {
    private:
        int id;

    public:
        //Contrutores
        KanbanTask(){}
        KanbanTask(int id, const std::string& titulo);
        KanbanTask(int id, const std::string& titulo, const std::string& descricao);
        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade);
        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento);
        
        //Destrutor
        ~KanbanTask();

        //Método getter e setter
        void setId(int id);
        int getId() const;
        std::string getTituloId() const;

        //Sobrecarga de operador ==
        bool operator==(const KanbanTask& other) const;

        //Polimorfismo do método virtual
        void printTask() const;

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
    KanbanBoard();
    ~KanbanBoard();
 

 
   // Adicionar uma nova coluna ao quadro Kanban
    void addColumn(const std::string& columnName);

    // Adicionar uma tarefa a uma coluna específica do quadro Kanban
    void addTaskToColumn(int columnIndex, const KanbanTask& task);

    // Mover uma tarefa de uma coluna para outra coluna do quadro Kanban
    //void moveTask(int origemColumnIndex, int destinoColumnIndex, int taskIndex);

    void moveTask(int taskId, int idcolunaDestino);

    bool removeTask(int taskId);

    // Exibir as tarefas de uma coluna específica do quadro Kanban
    void printColumn(int columnIndex) const;

    // Exibir o quadro Kanban
    void printBoard() const;

    KanbanTask* findTask(int id);

    void sortColumn(int idcoluna);

    // Encontrar a coluna em que uma tarefa com o ID fornecido está localizada
    KanbanColumn* findTaskColumn(int taskId) const {
        for (int i = 0; i < columns.getSize(); i++) {
            KanbanColumn& column = columns.get(i);
            for (int j = 0; j < column.tasks.getSize(); j++) {
                if (column.tasks.get(j).getId() == taskId) {
                    return &column;
                }
            }
        }
        return NULL;
    }

    bool isBoardEmpty() const;

    int getNumColumns() const;

    //ListaDuplamenteEncadeada<KanbanColumn> getColumns(){ return columns; }

};


#endif
