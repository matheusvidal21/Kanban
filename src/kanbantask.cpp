#include "../include/kanbantask.h"

// =========== IMPLEMENTANDO A CLASSE KANBAN TASK ===========

// ==== Construtores ====
KanbanTask::KanbanTask(int id, const std::string &titulo) : Task(titulo), id(id) {}

KanbanTask::KanbanTask(int id, const std::string &titulo, const std::string &descricao)
    : Task(titulo, descricao), id(id) {}

KanbanTask::KanbanTask(int id, const std::string &titulo, const std::string &descricao, int prioridade)
    : Task(titulo, descricao, prioridade), id(id) {}

KanbanTask::KanbanTask(int id, const std::string &titulo, const std::string &descricao, int prioridade, const std::string &dataVencimento)
    : Task(titulo, descricao, prioridade, dataVencimento), id(id) {}

// ==== Destrutor ====
KanbanTask::~KanbanTask() {}

// ==== Polimorfismo do método virtual ====
void KanbanTask::printTask() const
{
  std::cout << "ID: " << id << std::endl;
  std::cout << "Título: " << titulo << std::endl;
  std::cout << "Descrição: " << descricao << std::endl;
  std::cout << "Prioridade: ";
  /*Imprime uma cor de acordo com a prioridade
      Prioridade baixa: VERDE
      Prioridade média: AMARELO
      Prioridade alta: VERMELHO */
  switch (prioridade)
  {
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
bool KanbanTask::operator==(const KanbanTask &other) const
{
  return this->id == other.id && this->titulo == other.titulo && this->descricao == other.descricao;
}

// ==== Método getter e setter ====
void KanbanTask::setId(int id) { this->id = id; }
int KanbanTask::getId() const { return id; }

// ==== Método para imprimir o título junto com o ID ====
std::string KanbanTask::getTituloId() const
{
  std::stringstream ss;
  ss << id;
  if (prioridade == 1)
  {
    return ANSI_GREEN + titulo + " (ID:" + ss.str() + ")" + ANSI_RESET;
  }
  else if (prioridade == 2)
  {
    return ANSI_YELLOW + titulo + " (ID:" + ss.str() + ")" + ANSI_RESET;
  }
  else
  {
    return ANSI_RED + titulo + " (ID:" + ss.str() + ")" + ANSI_RESET;
  }
}
