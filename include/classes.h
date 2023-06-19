#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
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
    ListaDuplamenteEncadeada<KanbanTask*> listaTarefas;

public:
    KanbanBoard(){};
    void addTask(KanbanTask* task);
    void removeTask(KanbanTask* task);
    void sortTasks(int prioridade);
    void moveTask(int taskId, const std::string& statusAtual, const std::string& statusDestino);
    void printBoard();

    //Método get
    ListaDuplamenteEncadeada<KanbanTask*> getTasks() const;
};


#endif