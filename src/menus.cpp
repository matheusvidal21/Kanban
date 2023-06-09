/**
 * @file menus.cpp
 * @brief Este arquivo contém a implementação das funções que imprimem os menus.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/

#include "../include/menus.h"

// ==== MENU PRINCIPAL ====
void printMenu()
{
  std::cout << std::endl;
  std::cout << "*=========================================*" << std::endl;
  std::cout << "|         " << ANSI_BLUE << "MENU DE OPERAÇÕES KANBAN" << ANSI_RESET << "        |" << std::endl;
  std::cout << "*=========================================*" << std::endl;
  std::cout << "|  Escolha a operação desejada:           |" << std::endl;
  std::cout << "|                                         |" << std::endl;
  std::cout << "|  1. Adicionar nova tarefa               |" << std::endl;
  std::cout << "|  2. Editar tarefa existente             |" << std::endl;
  std::cout << "|  3. Ver informações de uma tarefa       |" << std::endl;
  std::cout << "|  4. Ordernar tarefas por prioridade     |" << std::endl;
  std::cout << "|  5. Exibir o quadro Kanban              |" << std::endl;
  std::cout << "|  6. Salvar o quadro Kanban              |" << std::endl;
  std::cout << "|  7. Sair                                |" << std::endl;
  std::cout << "|                                         |" << std::endl;
  std::cout << "*=========================================*" << std::endl;
}

// ==== MENU PARA EDITAR INFORMAÇÕES DA TAREFA ====
void printMenuEditar()
{
  std::cout << std::endl;
  std::cout << "*===================================*" << std::endl;
  std::cout << "|           " << ANSI_BLUE << "EDITAR TAREFA" << ANSI_RESET << "           |" << std::endl;
  std::cout << "*===================================*" << std::endl;
  std::cout << "|  Escolha a alteração desejada:    |" << std::endl;
  std::cout << "|                                   |" << std::endl;
  std::cout << "|  1. Editar ID                     |" << std::endl;
  std::cout << "|  2. Editar título                 |" << std::endl;
  std::cout << "|  3. Editar descrição              |" << std::endl;
  std::cout << "|  4. Editar prioridade             |" << std::endl;
  std::cout << "|  5. Editar data de vencimento     |" << std::endl;
  std::cout << "|  6. Voltar                        |" << std::endl;
  std::cout << "|                                   |" << std::endl;
  std::cout << "*===================================*" << std::endl;
}

// ==== SUBMENU PARA EDITAR TAREFA ====
void printMenuTarefa()
{
  std::cout << std::endl
            << "\n";
  std::cout << "*========================================*        *=================================*" << std::endl;
  std::cout << "|        MENU DE OPERAÇÕES KANBAN        |        |          " << ANSI_BLUE << "EDITAR TAREFA" << ANSI_RESET << "          |" << std::endl;
  std::cout << "*========================================*        *=================================*" << std::endl;
  std::cout << "|  Escolha a operação desejada:          |        |  Escolha a alteração desejada:  |" << std::endl;
  std::cout << "|                                        |        |                                 |" << std::endl;
  std::cout << "|  1. Adicionar nova tarefa              |        |  1. Editar informações          |" << std::endl;
  std::cout << "|  " << ANSI_BLUE << "2. Editar tarefa existente ------------------>" << ANSI_RESET << " |  2. Mover tarefa                |" << std::endl;
  std::cout << "|  3. Ver informações de uma tarefa      |        |  3. Excluir tarefa              |" << std::endl;
  std::cout << "|  4. Ordernar tarefas por prioridade    |        |  4. Voltar                      |" << std::endl;
  std::cout << "|  5. Exibir o quadro Kanban             |        |                                 |" << std::endl;
  std::cout << "|  6. Salvar o quadro Kanban             |        *=================================*" << std::endl;
  std::cout << "|  7. Sair                               |" << std::endl;
  std::cout << "|                                        |                                           " << std::endl;
  std::cout << "*========================================*                                           " << std::endl;
}

// ==== SUBMENU PARA ORDENAR TAREFAS
void printMenuOrdenar()
{
  std::cout << std::endl
            << "\n";
  std::cout << "*========================================*        *=================================*" << std::endl;
  std::cout << "|        MENU DE OPERAÇÕES KANBAN        |        |         " << ANSI_BLUE << "ORDENAR TAREFAS" << ANSI_RESET << "         |" << std::endl;
  std::cout << "*========================================*        *=================================*" << std::endl;
  std::cout << "|  Escolha a operação desejada:          |        |  Escolha a ordenação desejada:  |" << std::endl;
  std::cout << "|                                        |        |                                 |" << std::endl;
  std::cout << "|  1. Adicionar nova tarefa              |        |  1. Ordenação crescente " << ANSI_GREEN << "(1-3)" << ANSI_RESET << "   |" << std::endl;
  std::cout << "|  2. Editar tarefa existente            |        |  2. Ordenação decrescente " << ANSI_RED << "(3-1)" << ANSI_RESET << " |" << std::endl;
  std::cout << "|  3. Ver informações de uma tarefa      |        |  3. Ordenar todas as colunas    |" << std::endl;
  std::cout << "|  " << ANSI_BLUE << "4. Ordernar tarefas por prioridade ---------->" << ANSI_RESET << " |  4. Voltar                      |" << std::endl;
  std::cout << "|  5. Exibir o quadro Kanban             |        |                                 |" << std::endl;
  std::cout << "|  6. Salvar o quadro Kanban             |        *=================================*" << std::endl;
  std::cout << "|  7. Sair                               |" << std::endl;
  std::cout << "|                                        |                                           " << std::endl;
  std::cout << "*========================================*                                           " << std::endl;
}

// ==== SUBMENU PARA SALVAR O QUADRO
void printMenuSalvar()
{
  std::cout << std::endl << "\n";
  std::cout << "*========================================*" << std::endl;
  std::cout << "|        MENU DE OPERAÇÕES KANBAN        |        *=================================*" << std::endl;
  std::cout << "*========================================*        |         " << ANSI_BLUE << "SALVAR O QUADRO" << ANSI_RESET << "         |" << std::endl;
  std::cout << "|  Escolha a operação desejada:          |        *=================================*" << std::endl;
  std::cout << "|                                        |        |  Escolha como deseja salvar:    |" << std::endl;
  std::cout << "|  1. Adicionar nova tarefa              |        |                                 |" << std::endl;
  std::cout << "|  2. Editar tarefa existente            |        |  1. Arquivo 'bin' existente     |" << std::endl;
  std::cout << "|  3. Ver informações de uma tarefa      |        |  2. Arquivo 'bin' novo          |" << std::endl;
  std::cout << "|  4. Ordernar tarefas por prioridade    |        |  3. Arquivo 'txt'               |" << std::endl;
  std::cout << "|  5. Exibir o quadro Kanban             |        |  4. Voltar                      |" << std::endl;
  std::cout << "|  " << ANSI_BLUE << "6. Salvar o quadro Kanban ------------------->" << ANSI_RESET << " |                                 |" << std::endl;
  std::cout << "|  7. Sair                               |        *=================================*" << std::endl;
  std::cout << "|                                        |" << std::endl;
  std::cout << "*========================================*                                            " << std::endl;

}