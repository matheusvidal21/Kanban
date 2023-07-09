/**
 * @file task.cpp
 * @brief Este arquivo contém a implementação da classe abstrata Task.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/

#include "../include/task.h"

// =========== IMPLEMENTANDO A CLASSE TASK ===========

// ==== Construtores ====
Task::Task() {}

Task::Task(const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento)
    : titulo(titulo), descricao(descricao), prioridade(prioridade), dataVencimento(dataVencimento) {}

Task::Task(const std::string &titulo, const std::string &descricao, int prioridade)
    : titulo(titulo), descricao(descricao), prioridade(prioridade) {}

Task::Task(const std::string &titulo, const std::string &descricao)
    : titulo(titulo), descricao(descricao) {}

Task::Task(const std::string &titulo)
    : titulo(titulo) {}

// ==== Métodos getters ====
std::string Task::getTitulo() const { return titulo; }
std::string Task::getDescricao() const { return descricao; }
int Task::getPrioridade() const { return prioridade; }
std::string Task::getVencimento() const { return dataVencimento; }

// ==== Métodos setters ====
void Task::setTitulo(std::string titulo) { this->titulo = titulo; }
void Task::setDescricao(std::string descricao) { this->descricao = descricao; }
void Task::setPrioridade(int prioridade) { this->prioridade = prioridade; }
void Task::setVencimento(std::string dataVencimento) { this->dataVencimento = dataVencimento; }