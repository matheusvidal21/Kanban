#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>

// ==== CLASSE ABSTRATA TASK ====
class Task
{
protected: // Atributos da classe base
    std::string titulo;
    std::string descricao;
    int prioridade;
    std::string dataVencimento;

public:
    // Contrutores
    Task();
    Task(const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento);
    Task(const std::string &titulo, const std::string &descricao, int prioridade);
    Task(const std::string &titulo, const std::string &descricao);
    Task(const std::string &titulo);

    // Destrutor
    virtual ~Task(){};

    // Métodos getters
    std::string getTitulo() const;
    std::string getDescricao() const;
    int getPrioridade() const;
    std::string getVencimento() const;

    // Métodos setters
    void setTitulo(std::string titulo);
    void setDescricao(std::string descricao);
    void setPrioridade(int prioridade);
    void setVencimento(std::string dataVencimento);

    // Método virtual puro
    virtual void printTask() const = 0;
};

#endif
