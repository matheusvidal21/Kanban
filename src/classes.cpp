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
        if(prioridade == 1){
            return ANSI_GREEN + titulo + " (ID:" + ss.str() + ")" + ANSI_RESET;
        }else if(prioridade == 2){
            return ANSI_YELLOW + titulo + " (ID:" + ss.str() + ")" + ANSI_RESET;
        }else{
            return ANSI_RED + titulo + " (ID:" + ss.str() + ")" + ANSI_RESET;
        }
        
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
        KanbanColumn& column = columns.get(columnIndex); //Retorna a coluna desejada
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
    /// TEM QUE AJEITAR
    void KanbanBoard::printBoard() const {
        std::cout << "\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
        std::cout << "|                                            " << ANSI_BLUE << "GERENCIADOR DE TAREFAS KANBAN" << ANSI_RESET <<"                                            |\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";

        // RESPONSIVIDADE
        int numColumn = columns.getSize();
        int columnWidth = 0;
        switch (numColumn) {
            case 1: columnWidth = 58;
                    break;
            case 2: columnWidth = 38;
                    break;
            case 3: columnWidth = 28;
                    break;
            case 4: columnWidth = 22;
                    break;
            case 5: columnWidth = 18;
                    break;
            case 6: columnWidth = 16;
                    break;
            case 7: columnWidth = 14;
                    break;
            default: columnWidth = 25;
                    break;
        }

        std::cout << std::right << std::setw(columnWidth) << "";
        // Imprime os títulos das colunas lado a lado
        for (int i = 0; i < columns.getSize(); i++) {
            std::cout << std::left << std::setw(columnWidth) << std::setfill(' ') << columns.get(i).name;
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

        // Imprime as tarefas de cada linha em todas as colunas abaixo dos títulos
        for (int i = 0; i < maxTasks; ++i) {
            //std::cout << std::right<< std::setw(columnWidth) << "";
            std::cout << std::right << std::setw(columnWidth) << "";
            for (int j = 0; j < columns.getSize(); ++j) {
                
                    //std::cout << std::right << std::setw(columnWidth-8) << "";
                std::cout << std::left << std::setw(columnWidth+9) << std::setfill(' ');
                
                

                if (i < columns.get(j).tasks.getSize()) { // se i for menor que o número de tarefas de uma coluna
                    const KanbanTask& task = columns.get(j).tasks.get(i); // pegando a tarefa
                    std::string taskTitle = task.getTituloId();
                    std::cout << taskTitle ;
                } else {
                    std::cout << "";
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

    bool KanbanBoard::isBoardEmpty() const{
        for (int i = 0; i < columns.getSize(); ++i) {
            KanbanColumn& column = columns.get(i);
            if (!column.tasks.isEmpty()){
                return false;
            }
        }
        return true;
    }

    int KanbanBoard::getNumColumns() const {
        return columns.getSize();
    }




// ATENCAO: ISSO NAO FUNCIONA
/*
    void KanbanBoard::sortColumn(int idcoluna) {
        KanbanColumn& colunaOrdena = columns.get(idcoluna);
        int tamanhoColuna = colunaOrdena.tasks.getSize();

        for(int i = 0; i < tamanhoColuna - 1; i++) {
            for (int j = 0; j < tamanhoColuna - i - 1; j++) {
                    KanbanTask& task1 = colunaOrdena.tasks.get(j);
                    KanbanTask& task2 = colunaOrdena.tasks.get(j + 1);      
                    
                    if (task1.getPrioridade() > task2.getPrioridade()) {
                        colunaOrdena.tasks.swap(j, j + 1);
                    }
                          }
        }


    }*/