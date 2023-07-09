/**
 * @file functions.h
 * @brief Funções desenvolvidas a fim de modularizar a função Main, em sua maioria se tratam de interações com o usuário.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include <cstdlib> 
#include <dirent.h> 
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


/**
 * @brief Função que retorna uma lista dos arquivos em uma pasta.
 * Utilizado para listar os nomes dos arquivos (.bin) salvos com informações para preenchimento do quadro.
 * @param pasta Diretório que contém os arquivos onde o programa fará a leitura 
 * @details A lógica proposta é uma vez aberto o diretório passado como parâmetro, lê-se o nome de cada arquivo, o atribui a uma string e no final adiciona-se a string ao final da lista duplamente encadeada chamada "arquivos"
 * @return Uma lista duplamente encadeada de nomes de arquivos presentes no diretório passado como parâmetro
*/  
ListaDuplamenteEncadeada<std::string> listarArquivos(const std::string& pasta);


/**
 * @brief Solicita ao usuário qual número de colunas do Quadro Kanban que o mesmo deseja
 * @details Função utilizada no início do programa para definir o número de colunas que o Quadro Kanban deve ter, escolhido pelo usuário.
 * @return O número de colunas.
*/  
int receiveNumColumns();


/**
 * @brief Solicita ao usuário os nomes das colunas do quadro Kanban
 * @param kanbanBoard Ponteiro do tipo "KanbanBoard" que será usado para adicionar colunas ao Quadro Kanban.
 * @param numColunas Variável do tipo inteiro contendo o número de colunas escolhido pelo usuário, foi obtido previamente pela função "receiveNumColumns"
 * @details Função utilizada no início do programa, logo após a função "receiveNumColumns", pede-se que o usuário nomeie as colunas uma a uma e conforme isso vai acontecendo, uma nova coluna é adicionada ao objeto "kanbanBoard"
*/  
void receiveColumns(KanbanBoard *kanbanBoard, int numColunas);


/**
 * @brief Função que converte uma string em letras maiúsculas
 * @param texto String que deseja-se converter 
 * @details Essa função foi criada para fins estéticos da exibição do Quadro Kanban, para que tudo fique padronizado em letras maiúsculas e mais agradável de ser exibido.
*/
void stringMaiusculo(std::string &texto);


/**
 * @brief Função que limpa o terminal em diferentes sistemas operacionais.
 * @details Essa função foi criada com fins estéticos e compatibilidade, para que tanto em sistemas Windows como em sistemas Linux, o terminal possa ser limpado periodicamente tornando-se mais agradável aos olhos do usuário.
 * - Para sistemas Windows, o comando "cls" é utilizado para limpar o terminal.
 * - Para sistemas Unix (Linux, macOS, etc.), o comando "clear" é utilizado
*/
void clearTerminal();


/**
 * @brief Função que solicita ao usuário o número da coluna em que se deseja realizar alguma operação
 * @param kanbanBoard Referência a um objeto do tipo KanbanBoard, utilizado para obter o número de colunas 
 * @param flag Variável que será utilizada no switch case para indicar de qual operação a função vai se tratar no momento em que foi chamada
 * @details Essa função foi amplamente utilizada durante o programa para solicitar ao usuário uma coluna.
 * - Inicialmente, descobre-se o número de colunas no objeto kanbanBoard
 * - Utiliza-se a flag passada como parâmetro em um switch case para descobrir de qual operação se trata
 * - Lê-se o número da coluna digitado pelo usuário e o atribui a uma variável do tipo int chamada "columnIndex". Caso o número digitado seja inválido pede por um novo número até que o mesmo seja válido
 * - Diminui-se -1 do número digitado pelo usuário pois os índices começam em 0.
 * @return Indíce da coluna em que deve ser realizada alguma operação.
*/
int askForValidColumn(const KanbanBoard &kanbanBoard, int flag);


/**
 * @brief Função que solicita ao usuário a escolha de uma operação
 * @details Essa função solicita e lê o número de uma operação escolhido pelo usuário. É utlizada posteriormente a impressão de um menu de opções.
 * @return O número da operação que o usuário deseja realizar
 * 
*/
int getUserChoice();


/**
 * @brief Essa função é um grande switch case utilizado para manejar as operações no Quadro Kanban.
 * @param choice Variável utilizada como parametro para a escolha do caso no primeiro switch case.
 * @param kanbanBoard Ponteiro de um objeto do tipo KanbanBoard, será utilizado para realizar manipulações no Quadro Kanban.
 * @details 
 * - No switch case principal, realizadas 6 tipos de operações diferentes:
 * 1. Adicionar uma tarefa
 * 2. Editar uma tarefa existente 
 *      Neste caso é aberto outro switch case com novas opções:
 *          A. Editar informações de uma tarefa (Um novo switch case é aberto com os atributos editáveis: id, título, descrição, prioridade, data de vencimento e "voltar")
 *          B. Mover tarefa
 *          C. Excluir tarefa
 *          D. Voltar
 * 3. Ver informações de uma tarefa
 * 4. Ordenar tarefas por prioridade (utiliza os algoritmos de ordenação Bubble Sort e Selection Sort)
 * 5. Exibir o Quadro Kanban
 * 6. Salvar o Quadro Kanban 
 *      Neste caso é aberto um novo switch case com opções de salvamento:
 *          A. Arquivo 'bin' existente
 *          B. Arquivo 'bin' novo
 *          C. Arquivo 'txt'
 *          D. Voltar
 * 7. Sair
 * 8. Caso uma opção inválida seja digitada, é solicitado uma nova opção ao usuário até que seja digitada uma das existentes.
 * 
*/
void executarOperacao(int choice, KanbanBoard *kanbanBoard);

#endif