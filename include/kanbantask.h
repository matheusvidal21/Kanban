#ifndef KANBANTASK_H
#define KANBANTASK_H
#include <iostream>
#include <string>
#include <sstream>
#include "task.h"

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"

// ==== CLASSE DERIVADA KANBANTASK ====
class KanbanTask : public Task
{
  private:
    int id; // Atributo da classe derivada

  public:
    // Contrutores
    KanbanTask() {}
    KanbanTask(int id, const std::string &titulo);
    KanbanTask(int id, const std::string &titulo, const std::string &descricao);
    KanbanTask(int id, const std::string &titulo, const std::string &descricao, int prioridade);
    KanbanTask(int id, const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento);
    
    //teste
    KanbanTask(const KanbanTask& other)
      : Task(other), id(other.id) {}

    // Destrutor
    ~KanbanTask();

    // Método getter e setter
    void setId(int id);
    int getId() const;

    // Método para imprimir o título junto com o ID
    std::string getTituloId() const;

    // Sobrecarga de operador de comparação "=="
    bool operator==(const KanbanTask &other) const;

    // Sobrecarga do operador de inserção 
    friend std::ostream& operator<<(std::ostream& os, const KanbanTask& task) {
        os << task.id << " " << task.titulo << " " << task.descricao << " " << task.prioridade << " " << task.dataVencimento;
        return os;
    }

    // Sobrecarga do operador de extração 
    friend std::istream& operator>>(std::istream& is, KanbanTask& task) {
        is >> task.id >> task.titulo >> task.descricao >> task.prioridade >> task.dataVencimento;
        return is;
    }

    // Polimorfismo do método virtual
    void printTask() const;

};

#endif