/**
 * @file task.h
 * @brief Este arquivo contém a declaração da classe abstrata Task, que representa uma tarefa genérica.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/
#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>


/**
 * @class Task
 * @brief Classe abstrata Task representa uma tarefa.
 * 
 * Esta classe representa uma tarefa genérica.
 */
class Task
{
    protected: // Atributos da classe base
        std::string titulo; /**< Título da tarefa */
        std::string descricao; /**< Descrição da tarefa */
        int prioridade; /**< Prioridade da tarefa */
        std::string dataVencimento; /**< Data de vencimento da tarefa */


    public:
       /**
        * @brief Construtor padrão de Task.
        */
        Task();


       /**
        * @brief Construtor que cria um objeto Task com os atributos especificados.
        * @param titulo Título da tarefa.
        * @param descricao Descrição da tarefa.
        * @param prioridade Prioridade da tarefa.
        * @param dataVencimento Data de vencimento da tarefa.
        */
        Task(const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento);


       /**
        * @brief Construtor que cria um objeto Task com os atributos especificados, sem a data de vencimento.
        * @param titulo Título da tarefa.
        * @param descricao Descrição da tarefa.
        * @param prioridade Prioridade da tarefa.
        */
        Task(const std::string &titulo, const std::string &descricao, int prioridade);


       /**
        * @brief Construtor que cria um objeto Task com os atributos especificados, sem a prioridade e a data de vencimento.
        * @param titulo Título da tarefa.
        * @param descricao Descrição da tarefa.
        */
        Task(const std::string &titulo, const std::string &descricao);


       /**
        * @brief Construtor que cria um objeto Task com o título especificado, sem a descrição, a prioridade e a data de vencimento.
        * @param titulo Título da tarefa.
        */
        Task(const std::string &titulo);

        
       /**
        * @brief Construtor de cópia que cria um novo objeto Task com os mesmos atributos de outro objeto Task.
        * @param other Objeto Task a ser copiado.
        */
        Task(const Task& other)
        : titulo(other.titulo), descricao(other.descricao), prioridade(other.prioridade), dataVencimento(other.dataVencimento){}


       /**
        * @brief Destrutor virtual que permite a destruição adequada dos objetos derivados.
        */       
        virtual ~Task(){};

        
        
       /**
        * @brief Método getter que retorna o título da tarefa.
        * @return Título da tarefa.
        */
        std::string getTitulo() const;


       /**
        * @brief Método getter que retorna a descrição da tarefa.
        * @return Descrição da tarefa.
        */     
        std::string getDescricao() const;


       /**
        * @brief Método getter que retorna a prioridade da tarefa.
        * @return Prioridade da tarefa.
        */
        int getPrioridade() const;


       /**
        * @brief Método getter que retorna a data de vencimento da tarefa.
        * @return Data de vencimento da tarefa.
        */
        std::string getVencimento() const;


       /**
        * @brief Método setter que define o título da tarefa.
        * @param titulo Título da tarefa.
        */
        void setTitulo(std::string titulo);


       /**
        * @brief Método setter que define a descrição da tarefa.
        * @param descricao Descrição da tarefa.
        */
        void setDescricao(std::string descricao);


       /**
        * @brief Método setter que define a prioridade da tarefa.
        * @param prioridade Prioridade da tarefa.
        */     
        void setPrioridade(int prioridade);


       /**
        * @brief Método setter que define a data de vencimento da tarefa.
        * @param dataVencimento Data de vencimento da tarefa.
        */
        void setVencimento(std::string dataVencimento);


       /**
        * @brief Método virtual puro que deve ser implementado pelas classes derivadas para imprimir os detalhes da tarefa.
        */
        virtual void printTask() const = 0;
};

#endif