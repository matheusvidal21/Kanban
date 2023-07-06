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

    KanbanColumn(const std::string &columnName) : name(columnName) {}
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

  void saveToFile(const std::string& fileName) const {
          std::ofstream file(fileName.c_str());
          //std::ofstream file(fileName);

          if (!file) {
              std::cout << "Erro ao abrir o arquivo " << fileName << std::endl;
              return;
          }

          int numTasks = 1;
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
  
};

#endif
