#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "classes.h"
#include "estruturas_tads.hpp"
#include "templates.hpp"

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"


void stringMaiusculo(std::string& texto);
void clearTerminal();
void printMenu();
int getUserChoice();
void executarOperacao(int choice, KanbanBoard* kanbanBoard, int numColunas);

#endif