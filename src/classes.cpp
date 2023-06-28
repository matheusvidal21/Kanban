#include "../include/classes.h"

 // =========== IMPLEMENTANDO A CLASSE TASK ===========

    // ==== Construtores ====
    Task::Task(){}

    Task::Task(const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento) 
    : titulo(titulo), descricao(descricao), prioridade(prioridade), dataVencimento(dataVencimento) {}

    Task::Task(const std::string& titulo, const std::string& descricao, int prioridade) 
    : titulo(titulo), descricao(descricao), prioridade(prioridade) {}

    Task::Task(const std::string& titulo, const std::string& descricao)
    : titulo(titulo), descricao(descricao) {}
 
    Task::Task(const std::string& titulo) 
    : titulo(titulo) {}


    // ==== Métodos getters ====
    std::string Task::getTitulo() const{ return titulo; }
    std::string Task::getDescricao() const{ return descricao; }
    int Task::getPrioridade() const{ return prioridade; }
    std::string Task::getVencimento() const{ return dataVencimento; }

    // ==== Métodos setters ====
    void Task::setTitulo(std::string titulo) { this->titulo = titulo; }
    void Task::setDescricao(std::string descricao) { this->descricao = descricao; }
    void Task::setPrioridade(int prioridade) { this->prioridade = prioridade; }
    void Task::setVencimento(std::string dataVencimento) { this->dataVencimento = dataVencimento; }



// =========== IMPLEMENTANDO A CLASSE KANBAN TASK ===========

    // ==== Construtores ====
    KanbanTask::KanbanTask(int id, const std::string& titulo) : Task(titulo), id(id) {}

    KanbanTask::KanbanTask(int id, const std::string& titulo, const std::string& descricao) 
    : Task(titulo, descricao), id(id)  {}

    KanbanTask::KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade)
    : Task(titulo, descricao, prioridade), id(id) {}

    KanbanTask::KanbanTask(int id, const std::string& titulo, const std::string& descricao, int prioridade, const std::string& dataVencimento)
    : Task(titulo, descricao, prioridade, dataVencimento), id(id)  {}

    // ==== Destrutor ====
    KanbanTask::~KanbanTask(){}


    // ==== Polimorfismo do método virtual ====
    void KanbanTask::printTask() const{
        std::cout << "ID: " << id << std::endl;
        std::cout << "Título: " << titulo << std::endl;
        std::cout << "Descrição: " << descricao << std::endl;
        std::cout << "Prioridade: ";
        /*Imprime uma cor de acordo com a prioridade
            Prioridade baixa: VERDE
            Prioridade média: AMARELO
            Prioridade alta: VERMELHO */
        switch (prioridade){
        case 1:
            std::cout << ANSI_GREEN << "1 - Baixa" << ANSI_RESET << std::endl;
            break;
        case 2:
            std::cout << ANSI_YELLOW << "2 - Média" << ANSI_RESET << std::endl;
            break;

        case 3:
            std::cout << ANSI_RED << "3 - Alta" << ANSI_RESET << std::endl;
            break;
        default:
            break;
        }
        std::cout << "Data de vencimento: " << dataVencimento << std::endl;
    }

    // ==== Sobrecarga de operador de comparação "==" ====
    bool KanbanTask::operator==(const KanbanTask& other) const{
        return this->id == other.id && this->titulo == other.titulo && this->descricao == other.descricao;
    } 

    // ==== Método getter e setter ====
    void KanbanTask::setId(int id){ this->id = id; }
    int KanbanTask::getId() const { return id; }
    
    // ==== Método para imprimir o título junto com o ID ====
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



// =========== IMPLEMENTANDO A CLASSE KANBAN BOARD ===========

  
    // ==== Construtor e destrutor ====
    KanbanBoard::KanbanBoard(){}
    KanbanBoard::~KanbanBoard(){}
 

   // ==== Adiciona uma nova coluna ao quadro Kanban ====
    void KanbanBoard::addColumn(const std::string& columnName) {
        KanbanColumn column(columnName);
        columns.pushBack(column);
    }


    // ==== Adiciona uma tarefa a uma coluna específica do quadro Kanban ====
    void KanbanBoard::addTaskToColumn(int columnIndex, const KanbanTask& task) {    
        KanbanColumn& column = columns.get(columnIndex); //Retorna a coluna desejada
        column.tasks.pushBack(task);
    }
    

    // ==== Imprime as tarefas de uma coluna específica do quadro Kanban ====
    void KanbanBoard::printColumn(int columnIndex) const {
        const KanbanColumn& column = columns.get(columnIndex);

        std::cout << "Coluna " << (columnIndex+1) << " - " << column.name << ":\n";
        for (int i = 0; i < column.tasks.getSize(); ++i) {
            const KanbanTask& task = column.tasks.get(i);
            std::cout  << task.getTituloId() << "\n";
        }
        std::cout << std::endl;
    }


    // ==== Move uma tarefa recebendo o ID da tarefa e da coluna de destino ====
    void KanbanBoard::moveTask(int taskId, int idcolunaDestino) {
        KanbanTask* tarefa = findTask(taskId); // ponteiro apontando para a tarefa

        if(tarefa == NULL){
            std::cout << "Tarefa não encontrada." << std::endl;
            return;
        }
        
        KanbanColumn* colunaOrigem = findTaskColumn(taskId);
        if (colunaOrigem == NULL) {
            std::cout << "Coluna de origem não encontrada para a tarefa." << std::endl;
            return;
        }

        KanbanColumn& colunaDestino = columns.get(idcolunaDestino);

        colunaDestino.tasks.pushBack(*tarefa);
        colunaOrigem->tasks.removeValue(*tarefa);
    }

    
    // ==== Ordena a coluna recebida como parâmetro com base nas prioridades das tarefas ====
    void KanbanBoard::sortColumn(int columnIndex, int flag) {
        if (columnIndex < 0 || columnIndex >= columns.getSize()) {
            std::cout << "Coluna inválida." << std::endl;
            return;
        }

        KanbanColumn& column = columns.get(columnIndex);
        ListaDuplamenteEncadeada<KanbanTask>& tasks = column.tasks;
        int numTasks = tasks.getSize();

        // Array auxiliar para armazenar as prioridades das tarefas
        int* prioridades = new int[numTasks];

        // Preenche o array auxiliar com as prioridades das tarefas
        for (int i = 0; i < numTasks; i++) {
            KanbanTask& task = tasks.get(i);
            prioridades[i] = task.getPrioridade();
        }

        // Chama o algoritmo de ordenação apropriado com base na flag
        switch (flag) {
            case 1: // Ordenar da prioridade mais baixa para a mais alta (crescente)
                AlgoritmosDeOrdenacao<int>::bubbleSort(prioridades, numTasks);
                break;
            case 2: // Ordenar da prioridade mais alta para a mais baixa (decrescente)
                AlgoritmosDeOrdenacao<int>::selectionSort(prioridades, numTasks);
                break;
            default:
                delete[] prioridades;
                return;
        }

        // Atualiza a ordem das tarefas com base na ordenação das prioridades
        for (int i = 0; i < numTasks; i++) {
            KanbanTask& task = tasks.get(i);
            task.setPrioridade(prioridades[i]);
        }

        delete[] prioridades;
    } 


    // ==== Retorne o número de colunas do quadro kanban ====
    int KanbanBoard::getNumColumns() const {
        return columns.getSize();
    }


    // ==== Exclui uma tarefa recebendo o ID da tarefa desejada ====
    bool KanbanBoard::removeTask(int taskId) {
        KanbanTask* tarefa = findTask(taskId);

        if(tarefa ==  NULL) return false;
        
        KanbanColumn* coluna = findTaskColumn(taskId);
        coluna->tasks.removeValue(*tarefa);
        return true;    
    }


    // ==== Retorna true se o quadro não tiver nenhuma tarefa, e falso caso contrário ====
    bool KanbanBoard::isBoardEmpty() const{
        for (int i = 0; i < columns.getSize(); ++i) {
            KanbanColumn& column = columns.get(i);
            if (!column.tasks.isEmpty()){
                return false;
            }
        }
        return true;
    }


    // ==== Retorna true se a coluna recebida não tiver nenhuma tarefa, e falso caso contrário ====
    bool KanbanBoard::columnEmpty(int columnIndex) const{
        const KanbanColumn& column = columns.get(columnIndex);
        if(column.tasks.isEmpty()){
            return true;
        }else{
            return false;
        }
    }


    // ==== Retorna true se o ID recebido já existe, e falso caso contrário ====
    bool KanbanBoard::existeIdDuplicado(int id) const {
        for (int i = 0; i < columns.getSize(); ++i) {
            const KanbanColumn& column = columns.get(i);
            for (int j = 0; j < column.tasks.getSize(); ++j) {
                const KanbanTask& task = column.tasks.get(j);
                if (task.getId() == id) {
                    return true;
                }
            }
        }
        return false;
    }


    // ==== Procura e retorna a tarefa do ID recebido ====
    KanbanTask* KanbanBoard::findTask(int id) {
        for (int j = 0; j < columns.getSize(); ++j) {
            KanbanColumn& column = columns.get(j);
            for (int i = 0; i < column.tasks.getSize(); ++i) {
                if (id == column.tasks.get(i).getId() && column.tasks.isEmpty() == false) {
                    return &column.tasks.get(i);
                }
            }
        }
        return NULL;
    }



    // ==== Imprime todo o quadro Kanban ====
    void KanbanBoard::printBoard() const {
        std::cout << "\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
        std::cout << "|                                            " << ANSI_BLUE << "GERENCIADOR DE TAREFAS KANBAN" << ANSI_RESET <<"                                            |\n";
        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";

        // RESPONSIVIDADE
        int numColumn = columns.getSize();
        int columnWidth = 0;
        switch (numColumn) {
            case 1: columnWidth = 60;
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
            std::cout << std::left << std::setw(columnWidth) << "";
            for (int j = 0; j < columns.getSize(); ++j) {
                
                if (i < columns.get(j).tasks.getSize()) { // se i for menor que o número de tarefas de uma coluna
                    std::cout << std::left << std::setw(columnWidth+9) << std::setfill(' ');
                    const KanbanTask& task = columns.get(j).tasks.get(i); // pegando a tarefa
                    std::string taskTitle = task.getTituloId();
                    std::cout << taskTitle ;
                } else {
                   std::cout << std::left << std::setw(columnWidth) << std::setfill(' ');
                    std::cout << "";
                    
                }
            }
            std::cout << std::endl;
        }

        std::cout << "+---------------------------------------------------------------------------------------------------------------------+\n";
    }












    //Retorna a task que tem o id passado como parâmetro
    /*
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
    }*/