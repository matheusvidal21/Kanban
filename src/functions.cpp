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

// Solicitar ao usuário o número da coluna até que seja inserido um valor válido
int askForValidColumn(const KanbanBoard& kanbanBoard, int flag) {
    int columnIndex;
    int numColumns = kanbanBoard.getNumColumns();

    switch(flag){
    case 1:
        std::cout << "Tarefa criada. Informe agora o número da coluna que você deseja adicionar (1-" << numColumns << "): ";
        break;
    case 2:
        std::cout << "\nDigite o número da coluna de destino (1-" << numColumns << "): ";
        break;
    default:
        std::cout << "Digite o número da coluna (1-" << numColumns << "): ";
        break;
    }

    do{

        std::cin >> columnIndex;

        if (columnIndex <= 0 || columnIndex > numColumns) {
            std::cout << ANSI_RED << "|!| Coluna inválida. Por favor, insira um número de coluna válido. |!|\n" << ANSI_RESET;
        }
    }while (columnIndex <= 0 || columnIndex > numColumns);

    return (columnIndex - 1);
}

void printMenu(){
    std::cout << std::endl;
    std::cout << "*=========================================*" << std::endl;
    std::cout << "|         " << ANSI_BLUE << "MENU DE OPERAÇÕES KANBAN" << ANSI_RESET << "        |" << std::endl;
    std::cout << "*=========================================*" << std::endl;
    std::cout << "|  Escolha a operação desejada:           |" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "|  1. Adicionar nova tarefa               |" << std::endl;
    std::cout << "|  2. Editar tarefa existente             |" << std::endl;
    std::cout << "|  3. Ordernar tarefas por prioridade     |" << std::endl;
    std::cout << "|  4. Ver informações de uma tarefa       |" << std::endl;
    std::cout << "|  5. Exibir o quadro Kanban              |" << std::endl;
    std::cout << "|  6. Sair                                |" << std::endl;
    std::cout << "|                                         |" << std::endl;
    std::cout << "*=========================================*" << std::endl;
}

void printMenuEditar(){
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
    std::cout << "|                                   |" << std::endl;
    std::cout << "*===================================*" << std::endl;
}

void printMenuTarefa(){
        std::cout << std::endl << "\n"; 
        std::cout << "*========================================*        *=================================*" << std::endl;
        std::cout << "|        MENU DE OPERAÇÕES KANBAN        |        |          " << ANSI_BLUE << "EDITAR TAREFA" << ANSI_RESET << "          |" << std::endl;
        std::cout << "=========================================*        *=================================*" << std::endl;
        std::cout << "|  Escolha a operação desejada:          |        |  Escolha a alteração desejada:  |"<< std::endl;
        std::cout << "|                                        |        |                                 |" << std::endl;
        std::cout << "|  1. Adicionar nova tarefa              |        |  1. Editar informações          |" << std::endl;
        std::cout << "|  " << ANSI_BLUE << "2. Editar tarefa existente ------------------>" <<ANSI_RESET << " |  2. Mover tarefa                |" << std::endl;
        std::cout << "|  3. Ordernar tarefas por prioridade    |        |  3. Excluir tarefa              |" << std::endl;
        std::cout << "|  4. Ver informações de uma tarefa      |        |  4. Voltar                      |" << std::endl;
        std::cout << "|  5. Exibir o quadro Kanban             |        |                                 |" << std::endl;
        std::cout << "|  6. Sair                               |        *=================================*" << std::endl;
        std::cout << "|                                        |                                           " << std::endl;
        std::cout << "*========================================*                                           " << std::endl;
}

int getUserChoice()
{
    int operacao;
    std::cout << ANSI_GREEN << "Digite o número da operação: " << ANSI_RESET;
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
    int indexTask;// index;
    int novoid, novaprioridade, colunadestino;
    std::string novotitulo, novadescricao, novadata;
    KanbanTask* taskChoice;
    
    switch(choice){

    //===== CASO: ADICIONAR TAREFAS  =====   
    case 1:

        std::cout << "===========" << ANSI_GREEN << " Preencha os dados da tarefa " << ANSI_RESET << "===========\n";
        std::cout << "ID (inteiro): ";
        std::cin >> id;
        task.setId(id);
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
        std::cout << "\n(" << ANSI_GREEN << "1 - Baixa" << ANSI_RESET << "," << ANSI_YELLOW << " 2 - Média" << ANSI_RESET << "," << ANSI_RED << " 3 - Alta" << ANSI_RESET << "): ";
        std::cout << "\nPrioridade: ";
        while(true){
            std::cin >> prioridade;
            if(prioridade < 1 || prioridade > 3){
                std::cout << ANSI_RED << "|!| Digite uma prioridade válida. |!|" << ANSI_RESET << std::endl;
            }else{
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

        //Imprime todas as colunas
        for (int i = 0; i < numColunas; i++){
            kanbanBoard->printColumn(i);
        }

        //Pede o index da coluna para o usuário
        colunadestino = askForValidColumn(*kanbanBoard, 1);
        kanbanBoard->addTaskToColumn(colunadestino, task);
        clearTerminal();
        
        std::cout << "=======" << ANSI_GREEN << " Tarefa adicionada na coluna " << ANSI_RESET << "======= \n";
        kanbanBoard->printColumn(colunadestino);

        break;

    //===== CASO: EDITAR TAREFAS EXISTENTES =====    
    case 2:
        if(kanbanBoard->isBoardEmpty()){
            clearTerminal();
            std::cout << ANSI_RED << "|!| Seu quadro está vazio, adicione uma tarefa primeiro. |!|" << ANSI_RESET << std::endl;            
            break;
        }

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
                        std::cout << ANSI_RED << "|!| Informe uma opção válida. |!|" << ANSI_RESET << std::endl;
                        break;
                    }
            break;

        //========= CASO: MOVER TAREFA
        case 2:
                clearTerminal();
                while(true){
                     
                    for (int i = 0; i < numColunas; i++){
                        kanbanBoard->printColumn(i);
                    }

                    std::cout << "\nDigite o ID da tarefa que deseja mover (ou digite -1 para sair): ";
                    std::cin >> indexTask;

                    if (indexTask == -1) {
                        clearTerminal();
                        std::cout << ANSI_RED << "\nOperação cancelada.\n" << ANSI_RESET << std::endl;
                        break;  // Sai do loop
                    }

                    taskChoice = kanbanBoard->findTask(indexTask);
                    if(taskChoice == NULL){
                        clearTerminal();
                        std::cout << ANSI_RED << "|!| Tarefa não encontrada. Digite o ID novamente. |!|\n" << ANSI_RESET << std::endl;
                    }else{
                        std::cout << ANSI_GREEN << "==> Tarefa escolhida: " << taskChoice->getTituloId() << " <==" << ANSI_RESET << std::endl;

                        //Pede a coluna de destino para o usuário
                        colunadestino = askForValidColumn(*kanbanBoard, 2);
                        
                        kanbanBoard->moveTask(indexTask, (colunadestino));
                            
                        taskChoice = kanbanBoard->findTask(indexTask);

                        clearTerminal();
                        std::cout << ANSI_GREEN << "\nTarefa '" << taskChoice->getTitulo() << "' movida.\n" << ANSI_RESET;
                        kanbanBoard->printBoard();
                        std::cout << std::endl;
                    }
                }

            break;

        //========= CASO: EXCLUIR TAREFA    
        case 3:

                clearTerminal();
                
                while (true) {
                    kanbanBoard->printBoard();
                    std::cout << "\nDigite o ID da tarefa que deseja excluir (ou digite -1 para sair): ";
                    std::cin >> indexTask;

                    if (indexTask == -1) {
                        clearTerminal();
                        std::cout << ANSI_RED << "\nOperação cancelada.\n" << ANSI_RESET << std::endl;
                        break;  // Sai do loop
                    }
                    taskChoice = kanbanBoard->findTask(indexTask);

                    if(taskChoice == NULL){ //Verifica se o ID existe
                        clearTerminal();
                        std::cout << ANSI_RED << "\n|!| Tarefa não encontrada. Digite o ID novamente. |!|" << ANSI_GREEN << std::endl;
                    }else{
                        kanbanBoard->removeTask(indexTask);
                        clearTerminal();
                        std::cout << ANSI_GREEN << "\nTarefa excluída.\n" << ANSI_RESET << std::endl;
                        kanbanBoard->printBoard();
                        break;
                    }
                }

            break; 


        //========= CASO: VOLTAR
        case 4:
            clearTerminal();
            break;
        default:
            std::cout << ANSI_RED << "|!| Opção inválida. Por favor, escolha uma opção válida. |!|" << ANSI_RESET << std::endl;
            break;
        }

        break;



    //===== CASO: ORDERNAR TAREFAS POR PRIORIDADE =====   
    case 3: // NAO ESTA FUNCIONANDO
        if(kanbanBoard->isBoardEmpty()){
            clearTerminal();
            std::cout << ANSI_RED << "|!| Seu quadro está vazio, adicione uma tarefa primeiro. |!|" << ANSI_RESET << std::endl;            
            break;
        }
    /*
        clearTerminal();

        for (int i = 0; i < numColunas; i++){
                    kanbanBoard->printColumn(i);
        }

        std::cout << "Qual coluna deseja ordenar?";
        std::cin >> index;
        kanbanBoard->sortColumn(index-1);
        clearTerminal();
        std::cout << "Ótimo, sua coluna foi ordenada";
        kanbanBoard->printColumn(index-1);
        

*/


        break;


    //===== CASO: EXIBIR INFORMAÇÕES DA TAREFA
    case 4:
        if(kanbanBoard->isBoardEmpty()){
            clearTerminal();
            std::cout << ANSI_RED << "|!| Seu quadro está vazio, adicione uma tarefa primeiro. |!|" << ANSI_RESET << std::endl;            
            break;
        }
        clearTerminal();


        while (true) {
            kanbanBoard->printBoard();
            std::cout << "\nDigite o ID da tarefa que deseja ver as informações (ou digite -1 para sair): ";
            std::cin >> indexTask;

            if (indexTask == -1) {
                std::cout << ANSI_RED << "\nOperação cancelada.\n" << ANSI_RESET << std::endl;
                clearTerminal();
                break;  // Sai do loop
            }

            taskChoice = kanbanBoard->findTask(indexTask);

            if(taskChoice == NULL){ //Verifica se o ID existe
                clearTerminal();
                std::cout << ANSI_RED << "\n|!| Tarefa não encontrada. Digite o ID novamente. |!|" << ANSI_GREEN << std::endl;
            }else{
                clearTerminal();
                taskChoice->printTask();
            }
        }
    break;

    //===== CASO: EXIBIR QUADRO KANBAN =====   
    case 5:
        while (true){
            kanbanBoard->printBoard();
            std::cout << "\n\n\n\n\n\n\n\n\n\n\nDigite -1 para sair: ";
            std::cin >> indexTask;

            if (indexTask == -1) {
                break;  // Sai do loop
            }
            clearTerminal();
        }
        clearTerminal();
        
        break;

   //===== CASO: SAIR =====           
    case 6:
        std::cout << ANSI_RED << "Encerrando o programa..." << ANSI_RESET << std::endl;
        delete kanbanBoard; // Liberar a memória alocada
        kanbanBoard = NULL;
        std::exit(0);


   //===== CASO: OPÇÃO INVÁLIDA =====           
    default:
        std::cout << ANSI_RED << "|!| Opção inválida. Por favor, escolha uma opção válida. |!|" << ANSI_RESET << std::endl;
        break;
    }
    std::cout << "\n";
}