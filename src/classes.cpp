#include "../include/classes.h"

 // =========== IMPLEMENTANDO A CLASSE TASK ========

        //Construtores
    Task::Task(){}

    Task::Task(const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento) 
    : titulo(titulo), descricao(descricao), prioridade(prioridade), dataVencimento(dataVencimento) {}

    Task::Task(const std::string& titulo, const std::string& descricao, int prioridade) 
    : titulo(titulo), descricao(descricao), prioridade(prioridade) {}

    Task::Task(const std::string& titulo, const std::string& descricao)
    : titulo(titulo), descricao(descricao) {}
 
    Task::Task(const std::string& titulo) 
    : titulo(titulo) {}


    //Métodos getters
    std::string Task::getTitulo() const{ return titulo; }
    std::string Task::getDescricao() const{ return descricao; }
    int Task::getPrioridade() const{ return prioridade; }
    std::string Task::getVencimento() const{ return dataVencimento; }

    //Métodos setters
    void Task::setTitulo(std::string titulo) { this->titulo = titulo; }
    void Task::setDescricao(std::string descricao) { this->descricao = descricao; }
    void Task::setPrioridade(int prioridade) { this->prioridade = prioridade; }
    void Task::setVencimento(std::string dataVencimento) { this->dataVencimento = dataVencimento; }


// --------- IMPLEMENTANDO A CLASSE KANBAN TASK ------

    //Construtores
    KanbanTask::KanbanTask(int id, const std::string& titulo) : Task(titulo), id(id) {}

    KanbanTask::KanbanTask(int id, const std::string& titulo, const std::string& descricao) 
    : Task(titulo, descricao), id(id)  {}

    KanbanTask::KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade)
    : Task(titulo, descricao, prioridade), id(id) {}

    KanbanTask::KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento)
    : Task(titulo, descricao, prioridade, dataVencimento), id(id)  {}

    //Destrutor
    KanbanTask::~KanbanTask(){}


    //Polimorfismo do método virtual
    void KanbanTask::printTask() const{
        std::cout << "ID: " << id << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Descrição: " << descricao << std::endl;
        std::cout << "Prioridade: " << prioridade << std::endl;
        std::cout << "Data de Vencimento: " << dataVencimento << std::endl;
    }

    //Sobrecarga de operador ==
    bool KanbanTask::operator==(const KanbanTask& other) const{
        return this->id == other.id && this->titulo == other.titulo && this->descricao == other.descricao;
    } 

    //Método getter e setter
    void KanbanTask::setId(int id){ this->id = id; }
    int KanbanTask::getId() const { return id; }
    std::string KanbanTask::getTituloId() const {
        std::stringstream ss;
        ss << id;
        return titulo + " (ID:" + ss.str() + ")";
    }

// ---------- IMPLEMENTANDO A CLASSE KANBAN BOARD -----------

  
    //Construtor e destrutor
    KanbanBoard::KanbanBoard(){}
    KanbanBoard::~KanbanBoard(){}
 

 
   // Adicionar uma nova coluna ao quadro Kanban
    void KanbanBoard::addColumn(const std::string& columnName) {
        KanbanColumn column(columnName);
        columns.pushBack(column);
    }

    // Adicionar uma tarefa a uma coluna específica do quadro Kanban
    void KanbanBoard::addTaskToColumn(int columnIndex, const KanbanTask& task) {
        KanbanColumn& column = columns.get(columnIndex); // COLUNA TEMPORÁRIA
        column.tasks.pushBack(task);
    }
    
    // Exibir as tarefas de uma coluna específica do quadro Kanban
    void KanbanBoard::printColumn(int columnIndex) const {
        const KanbanColumn& column = columns.get(columnIndex);

        std::cout << "Coluna " << (columnIndex+1) << " - " << column.name << ":\n";
        for (int i = 0; i < column.tasks.getSize(); ++i) {
            const KanbanTask& task = column.tasks.get(i);
            std::cout  << task.getTituloId() << "\n";
        }
        std::cout << std::endl;
    }


    //Exibir o quadro Kanban
    void KanbanBoard::printBoard() const {
        std::cout << "\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
        std::cout << "|                                            GERENCIADOR DE TAREFAS KANBAN                                            |\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
        
        //RESPONSIVIDADE
        int numColumn = columns.getSize();
        int columnWidth = 0;
        switch (numColumn){
        case 1: columnWidth = 60;
            break;
        case 2: columnWidth = 40;
            break;
        case 3: columnWidth = 30;
            break;
        case 4: columnWidth = 25;
            break;
        case 5: columnWidth = 20;
            break;
        case 6: columnWidth = 19;
            break;
        case 7: columnWidth = 15;
            break;
        case 8: columnWidth = 14;
            break;
        case 9: columnWidth = 13;
            break;
        default: columnWidth = 25;
            break;
        }

        // Imprime os títulos das colunas lado a lado
        for(int i = 0; i < columns.getSize(); i++) {
            std::cout << std::left << std::setw(columnWidth) << columns.get(i).name;
        }
        std::cout << std::endl;


        // Encontra a maior quantidade de tarefas em uma coluna
        int maxTasks = 0;
        for (int i = 0; i < columns.getSize(); ++i) {
            int columnSize = columns.get(i).tasks.getSize();
            if (columnSize > maxTasks) {
                maxTasks = columnSize;
            }
        }



        // Imprime as tarefas de cada coluna abaixo dos títulos
        for (int i = 0; i < maxTasks; ++i) {
            for(int j = 0; j < columns.getSize(); ++j) {
                if (i < columns.get(j).tasks.getSize()) { // se i for menor que o numero de tasks de uma coluna
                    const KanbanTask& task = columns.get(j).tasks.get(i); // pegando a tarefa
                    std::cout << std::left << std::setw(columnWidth) << task.getTituloId();
                } else {
                    std::cout << std::setw(columnWidth) << "";
                }
            }
            std::cout << std::endl;
        }

        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
    }

    //Retorna a task que tem o id passado como parâmetro
    KanbanTask* KanbanBoard::findTask(int id){
        // Encontra a maior quantidade de tarefas em uma coluna
        int maxTasks = 0;
        for (int i = 0; i < columns.getSize(); ++i) {
            int columnSize = columns.get(i).tasks.getSize();
            if (columnSize > maxTasks) {
                maxTasks = columnSize;
            }
        }

        for (int i = 0; i < maxTasks; ++i) {
            for(int j = 0; j < columns.getSize(); ++j) {
                if ( !columns.get(j).tasks.isEmpty() && id == columns.get(j).tasks.get(i).getId()) { 
                    KanbanTask* task = &columns.get(j).tasks.get(i); // pegando a tarefa
                    return task;
                }
            }
        }
        return NULL;
    }

    
    void KanbanBoard::moveTask(int taskId, int idcolunaDestino) {
        KanbanTask* tarefa = findTask(taskId); // ponteiro apontando para a tarefa

        if(tarefa ==  NULL) return;
        
        KanbanColumn* colunaOrigem = findTaskColumn(taskId);
        KanbanColumn& colunaDestino = columns.get(idcolunaDestino);

        colunaDestino.tasks.pushBack(*tarefa);
        colunaOrigem->tasks.removeValue(*tarefa);

    } 


    bool KanbanBoard::removeTask(int taskId) {
        KanbanTask* tarefa = findTask(taskId);

        if(tarefa ==  NULL) return false;
        
        KanbanColumn* coluna = findTaskColumn(taskId);
        coluna->tasks.removeValue(*tarefa);
        return true;
    }

    






    


    // =========== ANOTAÇÕES

        /*
    // Adicionar uma tarefa a uma coluna específica do quadro Kanban
    void addTaskToColumn(const std::string& columnName, const KanbanTask& task) {
    for (int i = 0; i < columns.getSize(); i++) {
        if (columns.get(i).name == columnName) {
            columns.get(i).tasks.pushBack(task);
            return;
        }
    }
        // Caso a coluna não seja encontrada, você pode lançar uma exceção, retornar um código de erro, ou tratar de outra forma, de acordo com a sua necessidade.
        // Aqui, por exemplo, lançamos uma exceção std::runtime_error.
        throw std::runtime_error("Coluna não encontrada: " + columnName);
    }*/


    /*
    // Mover uma tarefa de uma coluna para outra coluna do quadro Kanban
    void KanbanBoard::moveTask(int origemColumnIndex, int destinoColumnIndex, int taskIndex) {
        KanbanColumn& origemColumn = columns.get(origemColumnIndex);
        KanbanColumn& destinoColumn = columns.get(destinoColumnIndex);

        KanbanTask task = origemColumn.tasks.get(taskIndex);
        destinoColumn.tasks.pushBack(task);
        origemColumn.tasks.removeValue(task);
    }*/

    
  /*  // Mover uma tarefa de uma coluna para outra coluna do quadro Kanban
    void KanbanBoard::moveTask(int destinoColumnIndex, int taskIndex) {
        KanbanTask *task = findTask(taskIndex); // ponteiro apontando para tarefa que quero mover
        KanbanColumn& destinoColumn = columns.get(destinoColumnIndex); // referencia coluna destino

// Encontrando o máximo de tarefas que uma coluna possui
        int maxTasks = 0;
        for (int i = 0; i < columns.getSize(); ++i) {
            int columnSize = columns.get(i).tasks.getSize();
            if (columnSize > maxTasks) {
                maxTasks = columnSize;
            }
        }


        for (int i = 0; i < maxTasks; ++i) {
            for(int j = 0; j < columns.getSize(); ++j) {




                if ( !columns.get(j).tasks.isEmpty() && task->getId() == columns.get(j).tasks.get(i).getId()) { 



                   const KanbanTask& task = columns.get(j).tasks.get(i); // pegando a tarefa
                   columns.get(j).tasks.removeValue(task);
                }
            }
        }
        destinoColumn.tasks.pushBack(*task);

    */

