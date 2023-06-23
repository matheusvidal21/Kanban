#include "../include/functions.h"

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
    std::cout << "               *=========================================*" << std::endl;
    std::cout << "               |         Menu de Operações Kanban        |" << std::endl;
    std::cout << "               *=========================================*" << std::endl;
    std::cout << "               |  Escolha a operação desejada:           |" << std::endl;
    std::cout << "               |                                         |" << std::endl;
    std::cout << "               |  1. Adicionar nova tarefa               |" << std::endl;
    std::cout << "               |  2. Editar tarefa existente             |" << std::endl;
    std::cout << "               |  3. Ordernar tarefas por prioridade     |" << std::endl;
    std::cout << "               |  4. Exibir o quadro Kanban              |" << std::endl;
    std::cout << "               |  5. Sair                                |" << std::endl;
    std::cout << "               |                                         |" << std::endl;
    std::cout << "               *=========================================*" << std::endl;
    std::cout << std::endl;
}

void printMenuTarefa(){
        std::cout << std::endl; 
        std::cout << "*========================================*        *=================================*" << std::endl;
        std::cout << "|         Menu de Operações Kanban       |        |         EDITAR TAREFAS          |" << std::endl;
        std::cout << "=========================================*        *=================================*" << std::endl;
        std::cout << "|  Escolha a operação desejada:          |        |  Escolha a alteração desejada:  |"<< std::endl;
        std::cout << "|                                        |        |                                 |" << std::endl;
        std::cout << "|  1. Adicionar nova tarefa              |        |  1. Editar informações          |" << std::endl;
        std::cout << "|  2. Editar tarefa existente ------------------> |  2. Mover tarefa                |" << std::endl;
        std::cout << "|  3. Ordernar tarefas por prioridade    |        |  3. Excluir tarefa              |" << std::endl;
        std::cout << "|  4. Exibir o quadro Kanban             |        |  4. Sair                        |" << std::endl;
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

    switch (choice){

    //===== CASO: ADICIONAR TAREFAS  =====   
    case 1:

        std::cout << "=========== Preencha os dados da tarefa ===========\n";
        std::cout << "ID (inteiro): ";
        std::cin >> id;
        task.setId(id);

        std::cout << "\nTítulo: ";
        cin.ignore(); // Limpar o buffer do teclado
        getline(cin, titulo);
        task.setTitulo(titulo);

        std::cout << "\nDescrição: ";
        getline(cin, descricao);
        task.setDescricao(descricao);

        std::cout << "\nPrioridade (1 - Baixo, 2 - Médio, 3 - Alto): ";
        std::cin >> prioridade;
        task.setPrioridade(prioridade);

        std::cout << "\nData de vencimento (dd/mm/aaaa): ";
        cin.ignore(); // Limpar o buffer do teclado
        getline(cin, dataVencimento);
        task.setVencimento(dataVencimento);

        clearTerminal();

        for (int i = 0; i < numColunas; i++){
            kanbanBoard->displayColumn(i);
        }
        std::cout << "Tarefa criada. Informe agora o index da coluna você deseja adicionar: \n";

        int indexColuna;
        std::cin >> indexColuna;
        indexColuna -= 1;
        kanbanBoard->addTaskToColumn(indexColuna, task);
        clearTerminal();
        std::cout << "===========  Tarefa adicionada na coluna =========== \n";
        kanbanBoard->displayColumn(indexColuna);

        break;

    //===== CASO: EDITAR TAREFAS EXISTENTES =====    
    case 2:

        printMenuTarefa();
        /*
        int escolha = getUserChoice();
        switch (escolha){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }*/

        break;



    //===== CASO: ORDERNAR TAREFAS POR PRIORIDADE =====   
    case 3:
        break;


    //===== CASO: EXIBIR QUADRO KANBAN =====   
    case 4:
        kanbanBoard->displayBoard();
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