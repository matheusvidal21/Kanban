#ifndef CLASSES_H
#define CLASSES_H
#define MAX 100
#include <iostream>
#include "functions.h"
//#include "estruturas_tads.hpp"

class Tarefa{
    protected:
        std::string titulo;
        std::string descricao;
        std::string status;
        int prioridade;
        int dia, mes, ano; //data de vencimento
    public:
        Tarefa();
        Tarefa(const std::string& titulo, const std::string descricao, const std::string status, int prioridade, int dia, int mes, int ano);

};

class Coluna {
protected: 

public:
    void adicionarTarefa();
    void removerTarefa();
    void moverTarefa(const Tarefa& tarefa, Coluna& colunaDestino);
    
};

class Backlog : public Coluna {
private:
    Tarefa* listabacklog;
public:

};

class EmAnalise : public Coluna {
public:

};

class ParaFazer : public Coluna {
public:

};

class Fazendo : public Coluna {
public:

};

class Feito : public Coluna {
public:

};







#endif