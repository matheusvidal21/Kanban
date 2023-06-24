#include "../include/functions.h"

// Convertendo a string em caixa
void stringMaiusculo(std::string& texto) {
    for (size_t i = 0; i < texto.length(); ++i) {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = texto[i] - 'a' + 'A';
        }
    }
}

void clearTerminal(){
// Limpa o terminal em diferentes sistemas operacionais
#ifdef _WIN32 // Para Windows
    system("cls");
#else // Para sistemas Unix (Linux, macOS, etc.)
    system("clear");
#endif
}

void printMenu(){
    std::cout << std::endl;
    std::cout << "*=========================================*" << std::endl;
    std::cout << "|         MENU DE OPERAÇÕES KANBAN        |" << std::endl;
    std::cout << "*=========================================*" << std::endl;
    std::cout << "|  Escolha a operação desejada:           |" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "|  1. Adicionar nova tarefa               |" << std::endl;
    std::cout << "|  2. Editar tarefa existente             |" << std::endl;
    std::cout << "|  3. Ordernar tarefas por prioridade     |" << std::endl;
    std::cout << "|  4. Exibir o quadro Kanban              |" << std::endl;
    std::cout << "|  5. Sair                                |" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "*=========================================*" << std::endl;
    std::cout << std::endl;
}

void printMenuEditar(){
    std::cout << std::endl;
    std::cout << "*===================================*" << std::endl;
    std::cout << "|           EDITAR TAREFA           |" << std::endl;
    std::cout << "*===================================*" << std::endl;
    std::cout << "|  Escolha a alteração desejada:    |" << std::endl;
    std::cout << "|                                   |" << std::endl;
    std::cout << "|  1. Editar ID                     |" << std::endl;
    std::cout << "|  2. Editar título                 |" << std::endl;
    std::cout << "|  3. Editar descrição              |" << std::endl;
    std::cout << "|  4. Editar prioridade             |" << std::endl;
    std::cout << "|  5. Editar data de vencimento     |" << std::endl;
    std::cout << "|                                   |" << std::endl;
    std::cout << "*===================================*" << std::endl;
    std::cout << std::endl;
}

void printMenuTarefa(){
        std::cout << std::endl << "\n"; 
        std::cout << "*========================================*        *=================================*" << std::endl;
        std::cout << "|        MENU DE OPERAÇÕES KANBAN        |        |          EDITAR TAREFA          |" << std::endl;
        std::cout << "=========================================*        *=================================*" << std::endl;
        std::cout << "|  Escolha a operação desejada:          |        |  Escolha a alteração desejada:  |"<< std::endl;
        std::cout << "|                                        |        |                                 |" << std::endl;
        std::cout << "|  1. Adicionar nova tarefa              |        |  1. Editar informações          |" << std::endl;
        std::cout << "|  2. Editar tarefa existente ------------------> |  2. Mover tarefa                |" << std::endl;
        std::cout << "|  3. Ordernar tarefas por prioridade    |        |  3. Excluir tarefa              |" << std::endl;
        std::cout << "|  4. Exibir o quadro Kanban             |        |  4. Voltar                      |" << std::endl;
        std::cout << "|  5. Sair                               |        |                                 |" << std::endl;
        std::cout << "|                                        |        *=================================*" << std::endl;
        std::cout << "*========================================*                                           " << std::endl;
        std::cout << std::endl;
}

int getUserChoice()
{
    int operacao;
    std::cout << "Digite o número da operação: ";
    std::cin >> operacao;
    return operacao;
}

void executarOperacao(int choice, KanbanBoard* kanbanBoard, int numColunas)
{
    /*Dados da tarefa*/
    int id, prioridade;
    std::string titulo, descricao, dataVencimento;
    KanbanTask task;
    /*Editar tarefa*/
    int escolha, escolha2;
    int indexTask;
    int novoid, novaprioridade;
    std::string novotitulo, novadescricao, novadata;
    KanbanTask* taskChoice;
    switch(choice){

    //===== CASO: ADICIONAR TAREFAS  =====   
    case 1:

        std::cout << "=========== Preencha os dados da tarefa ===========\n";
        std::cout << "ID (inteiro): ";
        std::cin >> id;
        task.setId(id);

        std::cout << "\nTítulo: ";
        std::cin.ignore(); // Limpar o buffer do teclado
        getline(std::cin, titulo);
        task.setTitulo(titulo);

        std::cout << "\nDescrição: ";
        getline(std::cin, descricao);
        task.setDescricao(descricao);

        std::cout << "\nPrioridade (1 - Baixo, 2 - Médio, 3 - Alto): ";
        std::cin >> prioridade;
        task.setPrioridade(prioridade);

        std::cout << "\nData de vencimento (dd/mm/aaaa): ";
        std::cin.ignore(); // Limpar o buffer do teclado
        getline(std::cin, dataVencimento);
        task.setVencimento(dataVencimento);

        clearTerminal();

        for (int i = 0; i < numColunas; i++){
            kanbanBoard->printColumn(i);
        }
        std::cout << "Tarefa criada. Informe agora o número da coluna que você deseja adicionar: \n";

        int indexColuna;
        std::cin >> indexColuna;
        indexColuna -= 1;
        kanbanBoard->addTaskToColumn(indexColuna, task);
        clearTerminal();
        std::cout << "===========  Tarefa adicionada na coluna =========== \n";
        kanbanBoard->printColumn(indexColuna);

        break;

    //===== CASO: EDITAR TAREFAS EXISTENTES =====    
    case 2:

        printMenuTarefa();
        escolha = getUserChoice();

        switch(escolha){

            // ========= CASO: EDITAR INFORMAÇÕES DA TAREFA 
            case 1: 
                clearTerminal();
                kanbanBoard->printBoard();
                std::cout << "\nDigite o ID da tarefa que deseja editar: ";
                std::cin >> indexTask;

                // Localizando a tarefa solicitada
                taskChoice = kanbanBoard->findTask(indexTask);
                clearTerminal();
                taskChoice->printTask();
                printMenuEditar();
                escolha2 = getUserChoice();
                clearTerminal();
                    switch (escolha2)
                    {
                    case 1: // ======== CASO: EDITAR ID
                        std::cout << "Informe o novo ID: ";
                        std::cin >> novoid;
                        taskChoice->setId(novoid);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;
                    
                    case 2: // ======== CASO: EDITAR TÍTULO
                        std::cout << "Informe o novo título: ";
                        std::cin.ignore();
                        getline(std::cin, novotitulo);
                        taskChoice->setTitulo(novotitulo);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 3: // ======== CASO: EDITAR DESCRICAO
                        std::cout << "Informe a nova descrição: ";
                        std::cin.ignore();
                        getline(std::cin, novadescricao);
                        taskChoice->setDescricao(novadescricao);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 4: // ======== CASO: EDITAR TÍTULO
                        std::cout << "Informe a nova prioridade (1 - Baixa 2 - Média 3 - Alta): ";
                        std::cin >> novaprioridade;
                        taskChoice->setPrioridade(novaprioridade);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 5: // ======== CASO: EDITAR TÍTULO
                        std::cout << "Informe a nova data de vencimento: ";
                        std::cin >> novadata;
                        taskChoice->setVencimento(novadata);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;
                    default:
                        std::cout << "Informe uma opção válida." << std::endl;
                        break;
                    }
            break;

        //========= CASO: MOVER TAREFA
        case 2:/*
                clearTerminal();
                for (int i = 0; i < numColunas; i++){
                    kanbanBoard->printColumn(i);
                }
                std::cout << "\nDigite o ID da tarefa que deseja mover: ";
                std::cin >> indexTask;
                std::cout << "\nDigite o número da coluna que você deseja mover: ";
                std::cin >> columnDestino;
                kanbanBoard->moveTask((columnDestino-1), indexTask);
                // Localizando a tarefa solicitada
                
                clearTerminal();
                std::cout << "\n Tarefa movida!";
                kanbanBoard->printBoard();
*/


            break;

        //========= CASO: EXCLUIR TAREFA    
        case 3:



            break; 


        //========= CASO: VOLTAR
        case 4:
            clearTerminal();
            break;
        default:
            break;
        }

        break;



    //===== CASO: ORDERNAR TAREFAS POR PRIORIDADE =====   
    case 3:
        break;


    //===== CASO: EXIBIR QUADRO KANBAN =====   
    case 4:
        kanbanBoard->printBoard();
        break;


   //===== CASO: SAIR =====           
    case 5:
        std::cout << "Encerrando o programa..." << std::endl;
        delete kanbanBoard; // Liberar a memória alocada
        kanbanBoard = NULL;
        std::exit(0);


   //===== CASO: OPÇÃO INVÁLIDA =====           
    default:
        std::cout << "Opção inválida. Por favor, escolha uma opção válida." << std::endl;
        break;
    }
    std::cout << "\n";
}