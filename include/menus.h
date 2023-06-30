#ifndef MENUS_H
#define MENUS_H
#include <iostream>

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"

// ==== MENU PRINCIPAL ====
void printMenu();
// ==== MENU PARA EDITAR INFORMAÇÕES DA TAREFA ====
void printMenuEditar();
// ==== SUBMENU PARA EDITAR TAREFA ====
void printMenuTarefa();
// ==== SUBMENU PARA ORDENAR TAREFAS
void printMenuOrdenar();

#endif