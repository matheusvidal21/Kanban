/**
 * @file kanbantask.h
 * @brief Este arquivo contém a declaração da classe KanbanTask, que representa uma tarefa específica do Kanban.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/
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

/**
 * @class KanbanTask
 * @brief Classe KanbanTask representa uma tarefa específica para o Kanban.
 * 
 * Esta classe é uma classe derivada da classe Task e representa uma tarefa específica para o Kanban.
 */
class KanbanTask : public Task
{
  private:
    int id; /**< Identificação única da tarefa */


  public:
    /**
    * @brief Construtor padrão de KanbanTask.
    */
    KanbanTask() {}


    /**
    * @brief Construtor que cria um objeto KanbanTask com o ID e o título especificados.
    * @param id Identificação única da tarefa no Kanban.
    * @param titulo Título da tarefa.
    */
    KanbanTask(int id, const std::string &titulo);


    /**
    * @brief Construtor que cria um objeto KanbanTask com o ID, o título e a descrição especificados.
    * @param id Identificação única da tarefa no Kanban.
    * @param titulo Título da tarefa.
    * @param descricao Descrição da tarefa.
    */
    KanbanTask(int id, const std::string &titulo, const std::string &descricao);


    /**
    * @brief Construtor que cria um objeto KanbanTask com o ID, o título, a descrição e a prioridade especificados.
    * @param id Identificação única da tarefa no Kanban.
    * @param titulo Título da tarefa.
    * @param descricao Descrição da tarefa.
    * @param prioridade Prioridade da tarefa.
    */
    KanbanTask(int id, const std::string &titulo, const std::string &descricao, int prioridade);


    /**
    * @brief Construtor que cria um objeto KanbanTask com o ID, o título, a descrição, a prioridade e a data de vencimento especificados.
    * @param id Identificação única da tarefa no Kanban.
    * @param titulo Título da tarefa.
    * @param descricao Descrição da tarefa.
    * @param prioridade Prioridade da tarefa.
    * @param dataVencimento Data de vencimento da tarefa.
    */
    KanbanTask(int id, const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento);
    
    
    /**
    * @brief Construtor de cópia que cria um novo objeto KanbanTask com os mesmos atributos de outro objeto KanbanTask.
    * @param other Objeto KanbanTask a ser copiado.
    */    
    KanbanTask(const KanbanTask& other)
      : Task(other), id(other.id) {}


    /**
    * @brief Destrutor padrão de KanbanTask.
    */ 
    ~KanbanTask();


    /**
    * @brief Método setter que define o ID da tarefa.
    * @param id Identificação única da tarefa no Kanban.
    */   
    void setId(int id);


    /**
    * @brief Método getter que retorna o ID da tarefa.
    * @return Identificação única da tarefa no Kanban.
    */
    int getId() const;


    /**
    * @brief Método que retorna o título da tarefa junto com o ID.
    * @return Título da tarefa concatenado com o ID.
    */   
    std::string getTituloId() const;


    /**
    * @brief Sobrecarga do operador de comparação "==" para verificar igualdade entre duas KanbanTasks.
    * @param other KanbanTask a ser comparada.
    * @return true se as tasks forem iguais, false caso contrário.
    */   
    bool operator==(const KanbanTask &other) const;


    /**
    * @brief Sobrecarga do operador de inserção "<<" para imprimir os detalhes da KanbanTask em um fluxo de saída.
    * @param os Fluxo de saída.
    * @param task KanbanTask a ser impressa.
    * @return Fluxo de saída com os detalhes da KanbanTask impressos.
    */   
    friend std::ostream& operator<<(std::ostream& os, const KanbanTask& task) {
        os << task.id << " " << task.titulo << " " << task.descricao << " " << task.prioridade << " " << task.dataVencimento;
        return os;
    }


    /**
    * @brief Sobrecarga do operador de extração ">>" para ler os detalhes da KanbanTask de um fluxo de entrada.
    * @param is Fluxo de entrada.
    * @param task KanbanTask a ser preenchida com os detalhes lidos.
    * @return Fluxo de entrada após a leitura dos detalhes da KanbanTask.
    */  
    friend std::istream& operator>>(std::istream& is, KanbanTask& task) {
        is >> task.id >> task.titulo >> task.descricao >> task.prioridade >> task.dataVencimento;
        return is;
    }


    /**
    * @brief Implementação do método virtual puro printTask() da classe base Task para imprimir os detalhes da tarefa, adicionando o atributo ID.
    */    
    void printTask() const;

};

#endif