#include "../include/functions.h"

// ==== Solicita ao usuários o número de colunas ====
int receiveNumColumns()
{
    int numColunas;
    std::cout << "===========" << ANSI_GREEN << " Bem vindo ao gerenciador de tarefas Kanban! " << ANSI_RESET << "===========\n";
    std::cout << "Quantas colunas você deseja adicionar no seu gerenciador?\n";
    std::cin >> numColunas;
    std::cin.ignore(); // Descarta o caractere de nova linha após a leitura do número
    return numColunas;
}

// ==== Solicita ao usuário o nome das colunas ====
void receiveColumns(KanbanBoard *kanbanBoard, int numColunas)
{
    std::cout << "===========" << ANSI_GREEN << " Informe os nomes das colunas " << ANSI_RESET << "===========\n";
    for (int i = 0; i < numColunas; i++)
    {
        std::string coluna;
        std::cout << (i + 1) << "ª coluna: ";
        std::getline(std::cin, coluna);
        stringMaiusculo(coluna);
        kanbanBoard->addColumn(coluna);
    }
}

// ==== Função que transforma toda a string em maiúsculo ====
void stringMaiusculo(std::string &texto)
{
    for (size_t i = 0; i < texto.length(); ++i)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = texto[i] - 'a' + 'A';
        }
    }
}

// ==== Limpa o terminal em diferentes sistemas operacionais ====
void clearTerminal()
{
#ifdef _WIN32 // Para Windows
    system("cls");
#else // Para sistemas Unix (Linux, macOS, etc.)
    system("clear");
#endif
}

// ==== Solicita ao usuário o número da coluna até que seja inserido um valor válido ====
int askForValidColumn(const KanbanBoard &kanbanBoard, int flag)
{
    int columnIndex;
    int numColumns = kanbanBoard.getNumColumns();

    switch (flag)
    {
    case 1:
        std::cout << "Tarefa criada. Informe agora o número da coluna que você deseja adicionar (1-" << numColumns << "): ";
        break;
    case 2:
        std::cout << "\nDigite o número da coluna de destino (1-" << numColumns << "): ";
        break;
    case 3:
        std::cout << "Digite o número da coluna que você deseja ordenar (ou digite -1 para sair): ";
        break;
    default:
        std::cout << "Digite o número da coluna (1-" << numColumns << "): ";
        break;
    }

    do
    {
        std::cin >> columnIndex;
        if (columnIndex == -1)
        { //"Digite -1 para sair"
            return -1;
        }
        if (columnIndex <= 0 || columnIndex > numColumns)
        {
            std::cout << ANSI_RED << "|!| Coluna inválida. Digite um número de coluna válido: " << ANSI_RESET;
        }
    } while (columnIndex <= 0 || columnIndex > numColumns);

    columnIndex -= 1;
    return columnIndex;
}

// ==== Pede para o usuário digitar uma operação ====
int getUserChoice()
{
    int operacao;
    std::cout << ANSI_GREEN << "Digite o número da operação: " << ANSI_RESET;
    std::cin >> operacao;
    return operacao;
}

// ==== Grande switch case do programa ====
void executarOperacao(int choice, KanbanBoard *kanbanBoard, int numColunas)
{

    /*Dados utilizados*/
    int escolha, escolha2;
    int id, prioridade, indexTask;
    int novoid, novaprioridade, colunadestino = 0;
    std::string novotitulo, novadescricao, novadata;
    std::string titulo, descricao, dataVencimento;
    KanbanTask *taskChoice;
    KanbanTask task;

    // ==== SWITCH PRINCIPAL ====
    switch (choice)
    {

    // ==== CASO: ADICIONAR TAREFAS ====
    case 1:

        std::cout << "===========" << ANSI_GREEN << " Preencha os dados da tarefa " << ANSI_RESET << "===========\n";
        std::cout << "ID (inteiro): ";
        do
        {
            std::cin >> id;
            if (kanbanBoard->existeIdDuplicado(id))
            {
                std::cout << ANSI_RED << "|!| ID já existente. Digite um ID diferente: " << ANSI_RESET;
            }
            else
            {
                task.setId(id);
            }
        } while (kanbanBoard->existeIdDuplicado(id));

        std::cout << "*=====================*";
        std::cout << "\nTítulo: ";
        std::cin.ignore(); // Limpar o buffer do teclado
        getline(std::cin, titulo);
        task.setTitulo(titulo);

        std::cout << "*=====================*";
        std::cout << "\nDescrição: ";
        getline(std::cin, descricao);
        task.setDescricao(descricao);

        std::cout << "*=====================*";
        std::cout << "\n(" << ANSI_GREEN << "1: Baixa" << ANSI_RESET << "," << ANSI_YELLOW << " 2: Média" << ANSI_RESET << "," << ANSI_RED << " 3: Alta" << ANSI_RESET << ")";
        std::cout << "\nPrioridade: ";
        while (true)
        {
            std::cin >> prioridade;
            if (prioridade < 1 || prioridade > 3)
            {
                std::cout << ANSI_RED << "|!| Digite uma prioridade válida: " << ANSI_RESET;
            }
            else
            {
                task.setPrioridade(prioridade);
                break;
            }
        }

        std::cout << "*=====================*";
        std::cout << "\nData de vencimento (dd/mm/aaaa): ";
        std::cin.ignore(); // Limpar o buffer do teclado
        getline(std::cin, dataVencimento);
        task.setVencimento(dataVencimento);

        clearTerminal();

        // Imprime todas as colunas
        for (int i = 0; i < numColunas; i++)
        {
            kanbanBoard->printColumn(i);
        }

        // Pede o index da coluna para o usuário
        colunadestino = askForValidColumn(*kanbanBoard, 1);
        kanbanBoard->addTaskToColumn(colunadestino, task);
        clearTerminal();

        std::cout << "=======" << ANSI_GREEN << " Tarefa adicionada na coluna " << ANSI_RESET << "======= \n";
        kanbanBoard->printColumn(colunadestino);

        break;

    // ==== CASO: EDITAR TAREFAS EXISTENTES ====
    case 2:
        if (kanbanBoard->isBoardEmpty())
        {
            clearTerminal();
            std::cout << ANSI_RED << "|!| Seu quadro está vazio, adicione uma tarefa primeiro. |!|" << ANSI_RESET << std::endl;
            break;
        }

        printMenuTarefa();
        escolha = getUserChoice();

        switch (escolha)
        {

        // ==== CASO: EDITAR INFORMAÇÕES DA TAREFA ====
        case 1:

            clearTerminal();
            while (true)
            {

                kanbanBoard->printBoard();
                std::cout << "\nDigite o ID da tarefa que deseja editar (ou digite -1 para sair): ";
                std::cin >> indexTask;

                if (indexTask == -1)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "\nOperação cancelada.\n"
                              << ANSI_RESET << std::endl;
                    break; // Sai do loop
                }

                // Localizando a tarefa solicitada
                taskChoice = kanbanBoard->findTask(indexTask);
                if (taskChoice == NULL)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "|!| Tarefa não encontrada. Digite o ID novamente. |!|\n"
                              << ANSI_RESET << std::endl;
                }
                else
                {

                    clearTerminal();
                    taskChoice->printTask();
                    printMenuEditar();
                    escolha2 = getUserChoice();

                    clearTerminal();
                    taskChoice->printTask();
                    switch (escolha2)
                    {

                    case 1: // ==== CASO: EDITAR ID ====
                        std::cout << "\nInforme um novo ID: ";
                        while (true)
                        {
                            std::cin >> novoid;
                            if (kanbanBoard->existeIdDuplicado(novoid))
                            {
                                std::cout << ANSI_RED << "|!| ID já existente. Digite um ID diferente: " << ANSI_RESET;
                            }
                            else
                            {
                                taskChoice->setId(novoid);
                                break;
                            }
                        }

                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 2: // ==== CASO: EDITAR TÍTULO ====
                        std::cout << "\nInforme o novo título: ";
                        std::cin.ignore();
                        getline(std::cin, novotitulo);
                        taskChoice->setTitulo(novotitulo);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 3: // ==== CASO: EDITAR DESCRICAO ====
                        std::cout << "\nInforme a nova descrição: ";
                        std::cin.ignore();
                        getline(std::cin, novadescricao);
                        taskChoice->setDescricao(novadescricao);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 4: // ==== CASO: EDITAR PRIORIDADE ====
                        std::cout << "\n(" << ANSI_GREEN << "1: Baixa" << ANSI_RESET << "," << ANSI_YELLOW << " 2: Média" << ANSI_RESET << "," << ANSI_RED << " 3: Alta" << ANSI_RESET << ")";
                        std::cout << "\nInforme a nova prioridade: ";
                        while (true)
                        {
                            std::cin >> novaprioridade;
                            if (novaprioridade < 1 || novaprioridade > 3)
                            {
                                std::cout << ANSI_RED << "|!| Digite uma prioridade válida: " << ANSI_RESET;
                            }
                            else
                            {
                                taskChoice->setPrioridade(novaprioridade);
                                break;
                            }
                        }
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 5: // ==== CASO: EDITAR DATA DE VENCIMENTO ====
                        std::cout << "\nInforme a nova data de vencimento: ";
                        std::cin >> novadata;
                        taskChoice->setVencimento(novadata);
                        clearTerminal();
                        std::cout << "Aqui está sua tarefa atualizada:\n";
                        taskChoice->printTask();
                        break;

                    case 6: // ==== CASO: VOLTAR ====
                        clearTerminal();
                        break;
                    default:
                        std::cout << ANSI_RED << "|!| Informe uma opção válida. |!|" << ANSI_RESET << std::endl;
                        break;
                    }
                }
            }
            break;

        // ==== CASO: MOVER TAREFA ====
        case 2:
            clearTerminal();
            while (true)
            {
                indexTask = 0;

                for (int i = 0; i < numColunas; i++)
                {
                    kanbanBoard->printColumn(i);
                }

                std::cout << std::endl
                          << "Digite o ID da tarefa que deseja mover (ou digite -1 para sair): ";
                std::cin >> indexTask;

                if (indexTask == -1)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "\nOperação cancelada.\n"
                              << ANSI_RESET << std::endl;
                    break; // Sai do loop
                }

                taskChoice = kanbanBoard->findTask(indexTask);
                if (taskChoice == NULL)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "|!| Tarefa não encontrada. Digite o ID novamente. |!|\n"
                              << ANSI_RESET << std::endl;
                }
                else
                {

                    std::cout << ANSI_BLUE << "==> Tarefa escolhida: " << taskChoice->getTituloId() << ANSI_BLUE << " <==" << ANSI_RESET << std::endl;

                    // Pede a coluna de destino para o usuário
                    colunadestino = askForValidColumn(*kanbanBoard, 2);

                    kanbanBoard->moveTask(indexTask, colunadestino);

                    clearTerminal();

                    std::cout << ANSI_GREEN << "\nTarefa movida.\n"
                              << ANSI_RESET;
                    kanbanBoard->printBoard();
                    std::cout << std::endl;
                }
            }

            break;

        // ==== CASO: EXCLUIR TAREFA ====
        case 3:

            clearTerminal();

            while (true)
            {
                kanbanBoard->printBoard();
                std::cout << "\nDigite o ID da tarefa que deseja excluir (ou digite -1 para sair): ";
                std::cin >> indexTask;

                if (indexTask == -1)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "\nOperação cancelada.\n"
                              << ANSI_RESET << std::endl;
                    break; // Sai do loop
                }
                taskChoice = kanbanBoard->findTask(indexTask);

                if (taskChoice == NULL)
                { // Verifica se o ID existe
                    clearTerminal();
                    std::cout << ANSI_RED << "\n|!| Tarefa não encontrada. Digite o ID novamente. |!|" << ANSI_GREEN << std::endl;
                }
                else
                {
                    kanbanBoard->removeTask(indexTask);
                    clearTerminal();
                    std::cout << ANSI_GREEN << "\nTarefa excluída.\n"
                              << ANSI_RESET << std::endl;
                    kanbanBoard->printBoard();
                    break;
                }
            }

            break;

        //==== CASO: VOLTAR ====
        case 4:
            clearTerminal();
            break;
        default:
            std::cout << ANSI_RED << "|!| Opção inválida. Por favor, escolha uma opção válida. |!|" << ANSI_RESET << std::endl;
            break;
        }

        break;

    // ==== CASO: EXIBIR INFORMAÇÕES DA TAREFA ====
    case 3:
        if (kanbanBoard->isBoardEmpty())
        {
            clearTerminal();
            std::cout << ANSI_RED << "|!| Seu quadro está vazio, adicione uma tarefa primeiro. |!|" << ANSI_RESET << std::endl;
            break;
        }
        clearTerminal();

        while (true)
        {
            kanbanBoard->printBoard();
            std::cout << "\nDigite o ID da tarefa que deseja ver as informações (ou digite -1 para sair): ";
            std::cin >> indexTask;

            if (indexTask == -1)
            {
                clearTerminal();
                std::cout << ANSI_RED << "\nOperação cancelada.\n"
                          << ANSI_RESET << std::endl;
                break; // Sai do loop
            }

            taskChoice = kanbanBoard->findTask(indexTask);

            if (taskChoice == NULL)
            { // Verifica se o ID existe
                clearTerminal();
                std::cout << ANSI_RED << "\n|!| Tarefa não encontrada. Digite o ID novamente. |!|" << ANSI_RESET << std::endl;
            }
            else
            {
                clearTerminal();
                taskChoice->printTask();
            }
        }
        break;

    // ==== CASO: ORDERNAR TAREFAS POR PRIORIDADE ====
    case 4:
        if (kanbanBoard->isBoardEmpty())
        {
            clearTerminal();
            std::cout << ANSI_RED << "|!| Seu quadro está vazio, adicione uma tarefa primeiro. |!|" << ANSI_RESET << std::endl;
            break;
        }

        printMenuOrdenar();
        escolha = getUserChoice();
        clearTerminal();

        switch (escolha)
        {

        case 1: // ==== CASO: CRESCENTE ====
            while (true)
            {
                for (int i = 0; i < numColunas; i++)
                {
                    kanbanBoard->printColumn(i);
                }
                // Pede a coluna para o usuário
                colunadestino = askForValidColumn(*kanbanBoard, 3);

                if (colunadestino == -1)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "\nOperação cancelada.\n"
                              << ANSI_RESET << std::endl;
                    break; // Sai do loop
                }

                if (kanbanBoard->columnEmpty(colunadestino))
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "|!| A coluna está vazia. Não é possível realizar a ordenação. |!|\n"
                              << ANSI_RESET << std::endl;
                    continue; // Volta para o início do loop
                }

                kanbanBoard->sortColumn(colunadestino, 1);
                clearTerminal();
                std::cout << "Ótimo, a coluna " << (colunadestino + 1) << " foi ordenada de forma crescente.\n";
                std::cout << std::endl;
            }

            break;

        case 2: // ==== CASO: DECRESCENTE ====
            while (true)
            {
                for (int i = 0; i < numColunas; i++)
                {
                    kanbanBoard->printColumn(i);
                }
                // Pede a coluna para o usuário
                colunadestino = askForValidColumn(*kanbanBoard, 3);

                if (colunadestino == -1)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "\nOperação cancelada.\n"
                              << ANSI_RESET << std::endl;
                    break; // Sai do loop
                }

                if (kanbanBoard->columnEmpty(colunadestino))
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "|!| A coluna está vazia. Não é possível realizar a ordenação. |!|\n"
                              << ANSI_RESET << std::endl;
                    continue; // Volta para o início do loop
                }

                kanbanBoard->sortColumn(colunadestino, 2);
                clearTerminal();
                std::cout << "Ótimo, a coluna " << (colunadestino + 1) << " foi ordenada de forma decrescente.\n";
                std::cout << std::endl;
            }
            break;

        case 3: // ==== CASO: ORDENAR TODAS AS COLUNAS ====
            clearTerminal();
            kanbanBoard->printBoard();
            while (true)
            {

                std::cout << "\n\n\n1. Crescente (" << ANSI_GREEN << "1: Baixo" << ANSI_RESET << " - " << ANSI_RED << "3: Alto)" << ANSI_RESET;
                std::cout << "\n2. Decrescente (" << ANSI_RED << "3: Alto" << ANSI_RESET << " - " << ANSI_GREEN << "1: Baixo)" << ANSI_RESET;
                std::cout << "\nVocê deseja ordenar de qual forma (ou digite -1 para sair): ";
                std::cin >> escolha;

                if (escolha == -1)
                {
                    clearTerminal();
                    std::cout << ANSI_RED << "\nOperação cancelada.\n"
                              << ANSI_RESET << std::endl;
                    break; // Sai do loop
                }

                switch (escolha)
                {
                case 1:
                    for (int i = 0; i < numColunas; i++)
                    {
                        kanbanBoard->sortColumn(i, 1);
                    }
                    clearTerminal();
                    std::cout << "Ótimo, todas as colunas foram ordenadas de forma crescente.";
                    kanbanBoard->printBoard();
                    break;
                case 2:
                    for (int i = 0; i < numColunas; i++)
                    {
                        kanbanBoard->sortColumn(i, 2);
                    }
                    clearTerminal();
                    std::cout << "Ótimo, todas as colunas foram ordenadas de forma decrescente.";
                    kanbanBoard->printBoard();
                    break;
                default:
                    clearTerminal();
                    std::cout << ANSI_RED << "|!| Opção inválida |!|" << ANSI_RESET << std::endl;
                    kanbanBoard->printBoard();
                    break;
                }
            }
            break;

        case 4: // ==== CASO: VOLTAR ====
            clearTerminal();
            break;
        default:
            clearTerminal();
            std::cout << ANSI_RED << "|!| Opção inválida. Por favor, escolha uma opção válida. |!|" << ANSI_RESET << std::endl;
            break;
        }

        break;


    // ==== CASO: SALVAR EM UM ARQUIVO 'TXT' ====
    case 5:/*
        clearTerminal();
        //std::cout << "Informe o nome do arquivo: ";
        //getline(std::cin, titulo);
        kanbanBoard->saveToFile("titulo.txt");*/


        kanbanBoard->saveToFile("dados.bin");
        std::cout << "Dados salvos no arquivo 'dados.bin'";




        break;  


    // ==== CASO: EXIBIR QUADRO KANBAN ====
    case 6:
        while (true)
        {
            kanbanBoard->printBoard();
            std::cout << "\n\n\n\n\n\n\n\n\n\nDigite -1 para sair: ";
            std::cin >> indexTask;

            if (indexTask == -1)
            {
                break; // Sai do loop
            }
            clearTerminal();
        }
        clearTerminal();

        break;


    // ==== CASO: SAIR ====
    case 7:
        std::cout << ANSI_RED << "Encerrando o programa..." << ANSI_RESET << std::endl;
        delete kanbanBoard; // Libera a memória alocada
        kanbanBoard = NULL;
        std::exit(0);
        break;

    // ==== CASO: OPÇÃO INVÁLIDA ====
    default:
        std::cout << ANSI_RED << "|!| Opção inválida. Por favor, escolha uma opção válida. |!|\n"
                  << ANSI_RESET << std::endl;
        break;
    }

    // ==== FIM DO SWITCH PRINCIPAL ====
    std::cout << "\n";
}