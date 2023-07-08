#ifndef KANBANBOARD_H
#define KANBANBOARD_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "kanbantask.h"
#include "estruturas_tads.hpp"
#include "templates.hpp"

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"

// ==== CLASSE KANBANBOARD ====
class KanbanBoard
{
  private:
    struct KanbanColumn
  {
      std::string name;
      ListaDuplamenteEncadeada<KanbanTask> tasks;

      KanbanColumn(const std::string& columnName) : name(columnName) {}

      // Método para obter a lista de tarefas da coluna
      ListaDuplamenteEncadeada<KanbanTask>& getTasks() {
          return tasks;
      }
  };

    ListaDuplamenteEncadeada<KanbanColumn> columns; // Lista duplamente encadeada de colunas


  public:
    // Construtor e destrutor
    KanbanBoard();
    ~KanbanBoard();

    // Adiciona uma nova coluna ao quadro Kanban
    void addColumn(const std::string &columnName);

    // Adiciona uma tarefa a uma coluna específica do quadro Kanban
    void addTaskToColumn(int columnIndex, const KanbanTask &task);

    // Imprime as tarefas de uma coluna específica do quadro Kanban
    void printColumn(int columnIndex) const;

    // Move uma tarefa recebendo o ID da tarefa e da coluna de destino
    void moveTask(int taskId, int idcolunaDestino);

    // Ordena a coluna recebida como parâmetro com base nas prioridades das tarefas
    void sortColumn(int columnIndex, int flag);

    // Retorne o número de colunas do quadro kanban
    int getNumColumns() const;

    // Exclui uma tarefa recebendo o ID da tarefa desejada
    bool removeTask(int taskId);

    // Retorna true se o quadro não tiver nenhuma tarefa, e falso caso contrário
    bool isBoardEmpty() const;

    // Retorna true se a coluna recebida não tiver nenhuma tarefa, e falso caso contrário
    bool columnEmpty(int columnIndex) const;

    // Retorna true se o ID recebido já existe, e falso caso contrário
    bool existeIdDuplicado(int id) const;

    // Imprime todo o quadro Kanban
    void printBoard() const;

    // ==== Salva todo o quadro Kanban em um arquivo bin ====
    void saveToFile(const std::string& filename) const;

    // ==== Lê um quadro Kanban de um arquivo bin ====
    void loadFromFile(const std::string& filename);

    // ==== Salva o quadro Kanban em um arquivo txt para visualização ====
    void saveToFileTxt(const std::string& fileName) const;

    // ==== Procura e retorna a tarefa do ID recebido ====
    KanbanTask *findTask(int id);

    // Encontrar a coluna em que uma tarefa com o ID fornecido está localizada
    KanbanColumn *findTaskColumn(int taskId) const
    {
      for (int i = 0; i < columns.getSize(); i++)
      {
        KanbanColumn &column = columns.get(i);
        for (int j = 0; j < column.tasks.getSize(); j++)
        {
          if (column.tasks.get(j).getId() == taskId)
          {
            return &column;
          }
        }
      }
      return NULL;
    }

};

#endif