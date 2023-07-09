/**
 * @file menus.h
 * @brief Este arquivo contém funções para imprimir os menus de operações do Quadro Kanban.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/
#ifndef MENUS_H
#define MENUS_H
#include <iostream>

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"

/**
 * @brief Imprime o menu principal do sistema Kanban.
*/
void printMenu();

/**
 * @brief Imprime o menu para editar informações de uma tarefa.
*/
void printMenuEditar();

/**
 * @brief Imprime o submenu para editar uma tarefa.
*/
void printMenuTarefa();

/**
 * @brief Imprime o submenu para ordenar as tarefas.
*/
void printMenuOrdenar();

/**
 * @brief Imprime o submenu para salvar o quadro Kanban.
*/
void printMenuSalvar();

#endif