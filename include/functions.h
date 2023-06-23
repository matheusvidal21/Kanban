#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include "classes.h"
#include "estruturas_tads.hpp"
#include "templates.hpp"


void stringMaiusculo(std::string& texto);
void clearTerminal();
void printMenu();
int getUserChoice();
void executarOperacao(int choice, KanbanBoard* kanbanBoard, int numColunas);

#endif