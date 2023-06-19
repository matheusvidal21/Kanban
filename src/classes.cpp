#include "../include/classes.h"

 // ------- IMPLEMENTANDO A CLASSE TASK --------
    //Métodos getters
        int Task::getId() const{ return id; }
        std::string Task::getTitulo() const{ return titulo; }
        std::string Task::getDescricao() const{ return descricao; }
        int Task::getPrioridade() const{ return prioridade; }
        std::string Task::getVencimento() const{ return dataVencimento; }

    //Métodos setters
        void Task::setId(int id) {this->id = id; }
        void Task::setTitulo(std::string titulo) { this->titulo = titulo; }
        void Task::setDescricao(std::string descricao) { this->descricao = descricao; }
        void Task::setPrioridade(int prioridade) { this->prioridade = prioridade; }
        void Task::setVencimento(std::string dataVencimento) { this->dataVencimento = dataVencimento; }


// --------- IMPLEMENTANDO A CLASSE KANBAN TASK ------

    //Método set e get
        void KanbanTask::setStatus(const std::string& status) { this->status = status; }
        std::string KanbanTask::getStatus() const { return status; }


    //Polimorfismo do método virtual
    /*    void KanbanTask::printTask() const override{
        std::cout << "ID: " << id << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Descrição: " << descricao << std::endl;
        std::cout << "Prioridade: " << prioridade << std::endl;
        std::cout << "Data de Vencimento: " << dataVencimento << std::endl;
        std::cout << "Status: " << status << std::endl;
    } */

// ---------- IMPLEMENTANDO A CLASSE KANBAN BOARD -----------

    void KanbanBoard::addTask(KanbanTask* task) { listaTarefas.pushBack(task); }
    void KanbanBoard::removeTask(KanbanTask* task) { listaTarefas.removeValue(task); }

    //void KanbanBoard::sortTasks(int prioridade){}
    //void KanbanBoard::moveTask(int taskId, const std::string& statusAtual, const std::string& statusDestino){}
    void KanbanBoard::printBoard(){
    std::cout << "+-----------------------------------------------+\n";
    std::cout << "|         GERENCIADOR DE TAREFAS KANBAN         |\n";
    std::cout << "+-----------+------------+-------+-------+------+\n";
    std::cout << "| Backlog   | Em Análise | To Do | Doing | Done |\n";
    std::cout << "+-----------+------------+-------+-------+------+\n";
    std::cout << "|           |            |       |       |      |\n";
    std::cout << "|           |            |       |       |      |\n";
    std::cout << "|           |            |       |       |      |\n";
    std::cout << "+-----------+------------+-------+-------+------+\n";
}

    //Método get
    ListaDuplamenteEncadeada<KanbanTask*> KanbanBoard::getTasks() const { return listaTarefas; }