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
        Task();
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
        int getId() const { return id; }
        std::string getTitulo() const { return titulo; }
        std::string getDescricao() const { return descricao; }
        int  getPrioridade() const { return prioridade; }
        std::string getVencimento() const { return dataVencimento; }

    //Métodos setters
        void setId(int id) {this->id = id; }
        void setTitulo(std::string titulo) { this->titulo = titulo; }
        void setDescricao(std::string descricao) { this->descricao = descricao; }
        void setPrioridade(int prioridade) { this->prioridade = prioridade; }
        void setVencimento(std::string dataVencimento) { this->dataVencimento = dataVencimento; }

    //Método virtual puro
        virtual void printTask() const = 0;

            
};

class KanbanTask : public Task {
    private:
        std::string status;

    public:
    //Contrutores
        KanbanTask(int id, const std::string& titulo)
            : Task(id, titulo) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao)
            : Task(id, titulo, descricao) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade)
            : Task(id, titulo, descricao, prioridade) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento)
            : Task(id, titulo, descricao, prioridade, dataVencimento) {}

    //Destrutor
        ~KanbanTask(){}

    //Método set
        void setStatus(const std::string& status) { this->status = status; }
        std::string getStatus() const { return status; }


    //Polimorfismo do método virtual
        void printTask() const override {
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
    ListaDuplamenteEncadeada<KanbanTask*> tarefas;

public:
    void addTask(KanbanTask* task) { tarefas.pushBack(task); }
    void removeTask(KanbanTask* task) { tarefas.removeValue(task); }

    //Método get
    ListaDuplamenteEncadeada<KanbanTask*> getTarefas() const { return tarefas; }

    void sortTasks(int prioridade){}
    void moveTask(int taskId, const std::string& sourceStatus, const std::string& destinationStatus) {}


};


#endif