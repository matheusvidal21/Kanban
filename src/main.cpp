/**
 * @file main.cpp
 * @brief Arquivo principal que inicia e maneja todo programa do gerenciador de tarefas Kanban.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/

#include <iostream>
#include <string>
#include "../include/kanbanboard.h"
#include "../include/functions.h"
#include "../include/estruturas_tads.hpp" 

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"

using namespace std;


/**
 * @brief Função principal que inicia o programa do gerenciador de tarefas Kanban.
 * @return 0 em caso de sucesso.
 */
int main()
{

    // Alocando dinamicamnete um objeto de kanbanBoard na HEAP
    KanbanBoard *kanbanBoard = new KanbanBoard();

    int numColunas;
    std::string nameFile, caminhoFile;
    bool arquivoExiste = false;
    std::string pasta = "data/bin";

    // Primeira parte do programa, antes do menu
    while(true){

        std::cout << "===========" << ANSI_GREEN << " Bem vindo ao gerenciador de tarefas Kanban! " << ANSI_RESET << "===========\n";
        std::cout << "Deseja ler um arquivo?" << std::endl;
        std::cout << "1. Sim" << std::endl;
        std::cout << "2. Não" << std::endl;
 
        int escolha;
        std::cin >> escolha;

        // Caso: ler arquivo
        if(escolha == 1) {
            
            // Lista dos arquivos da pasta /data
            ListaDuplamenteEncadeada<std::string> arquivos = listarArquivos(pasta);

            clearTerminal();

            // Verificar se há arquivos na pasta
            if (arquivos.isEmpty()){
                std::cout << ANSI_RED << "Nenhum arquivo encontrado na pasta '" << pasta << "'" << ANSI_RESET << std::endl;
        
            }else{

                while(!arquivoExiste) {

                    // Exibir os arquivos disponíveis
                    std::cout << "Arquivos disponíveis na pasta '" << pasta << "':" << std::endl;
                    for (int i = 0; i < arquivos.getSize(); i++) {
                        std::cout << ANSI_GREEN << i + 1 << ". " << arquivos.get(i) << ANSI_RESET << std::endl;
                    }
                    
                    std::cout << "\nInsira o nome do arquivo com os dados (exemplo.bin): ";
                    std::cin >> nameFile;
                    caminhoFile = "data/bin/" + nameFile;

                    // Verifique se o arquivo existe
                    std::ifstream arquivo(caminhoFile.c_str());
                    if (arquivo.is_open()) {
                        arquivoExiste = true;
                        arquivo.close();
                    } else {
                        clearTerminal();
                        std::cout << ANSI_RED << "|!| Arquivo não encontrado |!|" << ANSI_RESET << std::endl;
                    }
                }
                
                clearTerminal();
                kanbanBoard->loadFromFile(caminhoFile);
                kanbanBoard->printBoard();
                
                break;

            }

        // Caso: não ler um arquivo
       }else if(escolha == 2){

            clearTerminal();

            // Recebendo o número de colunas
            numColunas = receiveNumColumns();
            clearTerminal();

            // Recebendo os nomes das colunas
            receiveColumns(kanbanBoard, numColunas);
            clearTerminal();
            
            // Imprime o quadro com as colunas inseridas
            std::cout << "Ótimo! Aqui está seu quadro:\n";
            kanbanBoard->printBoard();
            std::cout << std::endl << std::endl;

            break;

        }else{
            clearTerminal();
            std::cout << ANSI_RED << "|!| Informe uma opção válida |!|" << ANSI_RESET << std::endl;
        }

    }

    numColunas = kanbanBoard->getNumColumns();

    // Loop principal do programa (menu)
    while (true) {
        printMenu();
        int choice = getUserChoice();
        clearTerminal();
        executarOperacao(choice, kanbanBoard);
        
    }

    // Libera a memória alocada
    delete kanbanBoard;
    kanbanBoard = NULL;

    return 0;
}