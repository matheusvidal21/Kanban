#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <cstdlib> // System("clear")
#include <dirent.h> // Manipulação de diretórios
#include "menus.h"
#include "kanbanboard.h"
#include "estruturas_tads.hpp"
#include "templates.hpp"

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"


// ==== Retorna uma lista dos arquivos em uma pasta ====
ListaDuplamenteEncadeada<std::string> listarArquivos(const std::string& pasta);
// ==== Solicita ao usuário o número de colunas ====
int receiveNumColumns();
// ==== Solicita ao usuário o nome das colunas ====
void receiveColumns(KanbanBoard *kanbanBoard, int numColunas);
// ==== Função que transforma toda a string em maiúsculo ====
void stringMaiusculo(std::string &texto);
// ==== Limpa o terminal em diferentes sistemas operacionais ====
void clearTerminal();
// ==== Solicita ao usuário o número da coluna até que seja inserido um valor válido ====
int askForValidColumn(const KanbanBoard &kanbanBoard, int flag);
// ==== Pede para o usuário digitar uma operação ====
int getUserChoice();
// ==== Grande switch case do programa ====
void executarOperacao(int choice, KanbanBoard *kanbanBoard, int numColunas);

#endif