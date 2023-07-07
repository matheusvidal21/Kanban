#include "../include/kanbanboard.h"

// =========== IMPLEMENTANDO A CLASSE KANBAN BOARD ===========

// ==== Construtor e destrutor ====
KanbanBoard::KanbanBoard() {}
KanbanBoard::~KanbanBoard() {}

// ==== Adiciona uma nova coluna ao quadro Kanban ====
void KanbanBoard::addColumn(const std::string &columnName)
{
  KanbanColumn column(columnName);
  columns.pushBack(column);
}

// ==== Adiciona uma tarefa a uma coluna específica do quadro Kanban ====
void KanbanBoard::addTaskToColumn(int columnIndex, const KanbanTask &task)
{
  KanbanColumn &column = columns.get(columnIndex); // Retorna a coluna desejada
  column.tasks.pushBack(task);
}

// ==== Imprime as tarefas de uma coluna específica do quadro Kanban ====
void KanbanBoard::printColumn(int columnIndex) const
{
  const KanbanColumn &column = columns.get(columnIndex);

  std::cout << "Coluna " << (columnIndex + 1) << " - " << column.name << ":\n";
  for (int i = 0; i < column.tasks.getSize(); ++i)
  {
    const KanbanTask &task = column.tasks.get(i);
    std::cout << task.getTituloId() << "\n";
  }
  std::cout << std::endl;
}

// ==== Move uma tarefa recebendo o ID da tarefa e da coluna de destino ====
void KanbanBoard::moveTask(int taskId, int idcolunaDestino)
{
  KanbanTask *tarefa = findTask(taskId); // ponteiro apontando para a tarefa

  if (tarefa == NULL)
  {
    std::cout << "Tarefa não encontrada." << std::endl;
    return;
  }

  KanbanColumn *colunaOrigem = findTaskColumn(taskId);
  if (colunaOrigem == NULL)
  {
    std::cout << "Coluna de origem não encontrada para a tarefa." << std::endl;
    return;
  }

  KanbanColumn &colunaDestino = columns.get(idcolunaDestino);

  colunaDestino.tasks.pushBack(*tarefa);
  colunaOrigem->tasks.removeValue(*tarefa);
}

// ==== Ordena a coluna recebida como parâmetro com base nas prioridades das tarefas ====
void KanbanBoard::sortColumn(int columnIndex, int flag)
{
  if (columnIndex < 0 || columnIndex >= columns.getSize())
  {
    std::cout << "Coluna inválida." << std::endl;
    return;
  }

  KanbanColumn &column = columns.get(columnIndex);
  ListaDuplamenteEncadeada<KanbanTask> &tasks = column.tasks;
  int numTasks = tasks.getSize();

  // Array auxiliar para armazenar as prioridades das tarefas
  int *prioridades = new int[numTasks];

  // Preenche o array auxiliar com as prioridades das tarefas
  for (int i = 0; i < numTasks; i++)
  {
    KanbanTask &task = tasks.get(i);
    prioridades[i] = task.getPrioridade();
  }

  // Chama o algoritmo de ordenação apropriado com base na flag
  switch (flag)
  {
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
  for (int i = 0; i < numTasks; i++)
  {
    KanbanTask &task = tasks.get(i);
    task.setPrioridade(prioridades[i]);
  }

  delete[] prioridades;
}

// ==== Retorne o número de colunas do quadro kanban ====
int KanbanBoard::getNumColumns() const
{
  return columns.getSize();
}

// ==== Exclui uma tarefa recebendo o ID da tarefa desejada ====
bool KanbanBoard::removeTask(int taskId)
{
  KanbanTask *tarefa = findTask(taskId);

  if (tarefa == NULL)
    return false;

  KanbanColumn *coluna = findTaskColumn(taskId);
  coluna->tasks.removeValue(*tarefa);
  return true;
}

// ==== Retorna true se o quadro não tiver nenhuma tarefa, e falso caso contrário ====
bool KanbanBoard::isBoardEmpty() const
{
  for (int i = 0; i < columns.getSize(); ++i)
  {
    KanbanColumn &column = columns.get(i);
    if (!column.tasks.isEmpty())
    {
      return false;
    }
  }
  return true;
}

// ==== Retorna true se a coluna recebida não tiver nenhuma tarefa, e falso caso contrário ====
bool KanbanBoard::columnEmpty(int columnIndex) const
{
  const KanbanColumn &column = columns.get(columnIndex);
  if (column.tasks.isEmpty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

// ==== Retorna true se o ID recebido já existe, e falso caso contrário ====
bool KanbanBoard::existeIdDuplicado(int id) const
{
  for (int i = 0; i < columns.getSize(); ++i)
  {
    const KanbanColumn &column = columns.get(i);
    for (int j = 0; j < column.tasks.getSize(); ++j)
    {
      const KanbanTask &task = column.tasks.get(j);
      if (task.getId() == id)
      {
        return true;
      }
    }
  }
  return false;
}


// ==== Imprime todo o quadro Kanban ====
void KanbanBoard::printBoard() const
{
 
  // RESPONSIVIDADE
  int numColumn = columns.getSize();
  int columnWidth = 0;
  switch (numColumn)
  {
  case 1:
    columnWidth = 72;
    break;
  case 2:
    columnWidth = 48;
    break;
  case 3:
    columnWidth = 35;
    break;
  case 4:
    columnWidth = 32;
    break;
  case 5:
    columnWidth = 24;
    break;
  case 6:
    columnWidth = 21;
    break;
  case 7:
    columnWidth = 18;
    break;
  default:
    columnWidth = 25;
    break;
  }

  int firstColumnWidth = 0;
  if(numColumn <= 4){
    firstColumnWidth = columnWidth - 14;
  }else{
    firstColumnWidth = columnWidth - 7;
  }

  if(numColumn < 4){
     std::cout << "\n";
    std::cout << "+-------------------------------------------------------------------------------------------------------------------------+\n";
    std::cout << "|                                              " << ANSI_BLUE << "GERENCIADOR DE TAREFAS KANBAN" << ANSI_RESET << "                                              |\n";
    std::cout << "+-------------------------------------------------------------------------------------------------------------------------+\n";
  }else{
     std::cout << "\n";
    std::cout << "+-----------------------------------------------------------------------------------------------------------------------------------------+\n";
    std::cout << "|                                                      " << ANSI_BLUE << "GERENCIADOR DE TAREFAS KANBAN" << ANSI_RESET << "                                                      |\n";
    std::cout << "+-----------------------------------------------------------------------------------------------------------------------------------------+\n";
  }

  std::cout << std::right << std::setw(firstColumnWidth) << "";
  // Imprime os títulos das colunas lado a lado
  for (int i = 0; i < columns.getSize(); i++)
  {
    std::cout << std::left << std::setw(columnWidth) << std::setfill(' ') << columns.get(i).name;
  }
  std::cout << std::endl;

  // Encontra a maior quantidade de tarefas em uma coluna
  int maxTasks = 0;
  for (int i = 0; i < columns.getSize(); ++i)
  {
    int columnSize = columns.get(i).tasks.getSize();
    if (columnSize > maxTasks)
    {
      maxTasks = columnSize;
    }
  }

  // Imprime as tarefas de cada linha em todas as colunas abaixo dos títulos
  for (int i = 0; i < maxTasks; ++i)
  {
    std::cout << std::right << std::setw(firstColumnWidth) << "";
    for (int j = 0; j < columns.getSize(); ++j)
    {

      if (i < columns.get(j).tasks.getSize())
      { // se i for menor que o número de tarefas de uma coluna
        std::cout << std::left << std::setw(columnWidth + 9) << std::setfill(' ');
        const KanbanTask &task = columns.get(j).tasks.get(i); // pegando a tarefa
        std::string taskTitle = task.getTituloId();
        std::cout << taskTitle;
      }
      else
      {
        std::cout << std::left << std::setw(columnWidth) << std::setfill(' ');
        std::cout << "";
      }
    }
    std::cout << std::endl;
  }

  if(numColumn < 4){
    std::cout << "+-------------------------------------------------------------------------------------------------------------------------+\n";
  }else{
    std::cout << "+-----------------------------------------------------------------------------------------------------------------------------------------+\n";
  }
}


// ==== Salva todo o quadro Kanban em um arquivo bin ====
void KanbanBoard::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename.c_str(), std::ios::binary);
    if (!file) {
        std::cout << "Erro ao abrir o arquivo de salvamento." << std::endl;
        return;
    }

    int numColumns = columns.getSize();
    file.write(reinterpret_cast<const char*>(&numColumns), sizeof(numColumns));

    // Faz a gravação dos dados
    for (int i = 0; i < numColumns; i++)
    {
        const KanbanColumn& column = columns.get(i);
        int columnNameSize = column.name.size();
        file.write(reinterpret_cast<const char*>(&columnNameSize), sizeof(columnNameSize));
        file.write(column.name.c_str(), columnNameSize);

        const ListaDuplamenteEncadeada<KanbanTask>& tasks = column.tasks;
        int columnSize = tasks.getSize();
        file.write(reinterpret_cast<const char*>(&columnSize), sizeof(columnSize));

        for (int j = 0; j < columnSize; j++){
            const KanbanTask& task = tasks.get(j);

            // Escrever os dados da tarefa no arquivo
            int taskId = task.getId();
            file.write(reinterpret_cast<const char*>(&taskId), sizeof(taskId));

            std::string taskTitle = task.getTitulo();
            int taskTitleSize = taskTitle.size();
            file.write(reinterpret_cast<const char*>(&taskTitleSize), sizeof(taskTitleSize));
            file.write(taskTitle.c_str(), taskTitleSize);

            std::string taskDescription = task.getDescricao();
            int taskDescriptionSize = taskDescription.size();
            file.write(reinterpret_cast<const char*>(&taskDescriptionSize), sizeof(taskDescriptionSize));
            file.write(taskDescription.c_str(), taskDescriptionSize);

            int taskPriority = task.getPrioridade();
            file.write(reinterpret_cast<const char*>(&taskPriority), sizeof(taskPriority));

            std::string taskDueDate = task.getVencimento();
            int taskDueDateSize = taskDueDate.size();
            file.write(reinterpret_cast<const char*>(&taskDueDateSize), sizeof(taskDueDateSize));
            file.write(taskDueDate.c_str(), taskDueDateSize);
        }
    }

    file.close();

    std::cout << ANSI_GREEN << "Quadro Kanban salvo no arquivo " << filename << " com sucesso." << ANSI_RESET << std::endl;
}


// ==== Lê um quadro Kanban de um arquivo bin ====
void KanbanBoard::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename.c_str(), std::ios::binary);

    if (!file) {
        std::cout << "Erro ao abrir o arquivo de carregamento." << std::endl;
        return;
    }

    columns.clear(); // Limpa o quadro antes de carregar os dados

    int numColumns;
    file.read(reinterpret_cast<char*>(&numColumns), sizeof(numColumns));

    // Faz a leitura dos dados
    for (int i = 0; i < numColumns; i++) {
        int columnNameSize;
        file.read(reinterpret_cast<char*>(&columnNameSize), sizeof(columnNameSize));

        std::string columnName(columnNameSize, '\0');
        file.read(&columnName[0], columnNameSize);

        addColumn(columnName);

        int columnSize;
        file.read(reinterpret_cast<char*>(&columnSize), sizeof(columnSize));

        for (int j = 0; j < columnSize; j++) {
            KanbanTask task;

            // Ler os dados da tarefa do arquivo
            int taskId;
            file.read(reinterpret_cast<char*>(&taskId), sizeof(taskId));
            task.setId(taskId);

            int taskTitleSize;
            file.read(reinterpret_cast<char*>(&taskTitleSize), sizeof(taskTitleSize));
            std::string taskTitle(taskTitleSize, '\0');
            file.read(&taskTitle[0], taskTitleSize);
            task.setTitulo(taskTitle);

            int taskDescriptionSize;
            file.read(reinterpret_cast<char*>(&taskDescriptionSize), sizeof(taskDescriptionSize));
            std::string taskDescription(taskDescriptionSize, '\0');
            file.read(&taskDescription[0], taskDescriptionSize);
            task.setDescricao(taskDescription);

            int taskPriority;
            file.read(reinterpret_cast<char*>(&taskPriority), sizeof(taskPriority));
            task.setPrioridade(taskPriority);

            int taskDueDateSize;
            file.read(reinterpret_cast<char*>(&taskDueDateSize), sizeof(taskDueDateSize));
            std::string taskDueDate(taskDueDateSize, '\0');
            file.read(&taskDueDate[0], taskDueDateSize);
            task.setVencimento(taskDueDate);

            addTaskToColumn(i, task);
        }
    }

    file.close();

    std::cout << ANSI_GREEN << "Quadro Kanban carregado do arquivo " << filename << " com sucesso." << ANSI_RESET << std::endl;
}


// ==== Salva o quadro Kanban em um arquivo txt para visualização ====
void KanbanBoard::saveToFileTxt(const std::string& fileName) const
{
          std::ofstream file(fileName.c_str());
          //std::ofstream file(fileName);

          if (!file) {
              std::cout << "Erro ao abrir o arquivo " << fileName << std::endl;
              return;
          }

          int numTasks = 1;
          // Imprime no arquivo txt
          for (int i = 0; i < columns.getSize(); i++) {
              const KanbanColumn& column = columns.get(i);
              file << "*======================================*\n";
              file << "           Coluna " << (i + 1) << ": " << column.name << std::endl;
              file << "\n" << std::endl;
              const ListaDuplamenteEncadeada<KanbanTask>& tasks = column.tasks;
              for (int j = 0; j < tasks.getSize(); j++) {
                  const KanbanTask& task = tasks.get(j);
                  /*file << "  - Tarefa " << (j + 1) << ": " << task.getDescricao() << std::endl;
                  file << "  - Tarefa " << (numTasks) << ": " << task.getTitulo() << std::endl;
                  file << "          " << task.getDescricao() << std::endl;*/
                  file << "+-------------------------------------+\n";
                  file << "|              Tarefa " << numTasks << "               |\n"; 
                  file << "+-------------------------------------+\n";
                  file << " Título: " << task.getTitulo() << "\n";
                  file << " Descrição: " << task.getDescricao() << "\n";
                  file << "+-------------------------------------+\n\n";
                  numTasks++; 
              }
              file << std::endl;
              file << "*======================================*\n";
              file << "\n" << std::endl;
          }

          file.close();

          std::cout << ANSI_GREEN << "Tabela salva no arquivo " << fileName << " com sucesso." << ANSI_RESET << std::endl;
}


// ==== Procura e retorna a tarefa do ID recebido ====
KanbanTask *KanbanBoard::findTask(int id)
{
  for (int j = 0; j < columns.getSize(); ++j)
  {
    KanbanColumn &column = columns.get(j);
    for (int i = 0; i < column.tasks.getSize(); ++i)
    {
      if (id == column.tasks.get(i).getId() && column.tasks.isEmpty() == false)
      {
        return &column.tasks.get(i);
      }
    }
  }
  return NULL;
}