#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include "functions.h"
#include "estruturas_tads.hpp"

class Tarefa{
    protected:
        int id;
        std::string titulo;
        std::string descricao;
        int prioridade;
        std::string dataVencimento; 
    public:
    //Contrutores
        Tarefa();
        Tarefa(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento) 
        : id(id), titulo(titulo), descricao(descricao), prioridade(prioridade), dataVencimento(dataVencimento) {}

        Tarefa(int id, const std::string& titulo, const std::string& descricao, int prioridade) 
        : id(id), titulo(titulo), descricao(descricao), prioridade(prioridade) {}

        Tarefa(int id, const std::string& titulo, const std::string& descricao) 
        : id(id), titulo(titulo), descricao(descricao) {}

        Tarefa(int id, const std::string& titulo) 
        : id(id), titulo(titulo) {}

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
            
};

class KanbanTask : public Tarefa {
    private:
        std::string status;

    public:
    //Contrutores
        KanbanTask(int id, const std::string& titulo)
            : Tarefa(id, titulo) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao)
            : Tarefa(id, titulo, descricao) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade)
            : Tarefa(id, titulo, descricao, prioridade) {}

        KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento)
            : Tarefa(id, titulo, descricao, prioridade, dataVencimento) {}

    //Método set
        void setStatus(const std::string& status) { this->status = status; }
        std::string getStatus() const { return status; }
};

class TaskManagement {
private:
    ListaDuplamenteEncadeada<Tarefa*> tarefas;

public:
    void addTask(Tarefa* task) { tarefas.pushBack(task); }
    void removeTask(Tarefa* task) { tarefas.removeValue(task); }

    //Método get
    ListaDuplamenteEncadeada<Tarefa*> getTarefas() const { return tarefas; }

    void sortTarefas(){}
    void moveTask(int taskId, const std::string& sourceStatus, const std::string& destinationStatus) {}
};


#endif