/**
 * @file kanbanboard.h
 * @brief Este arquivo contém a declaração da classe KanbanBoard, que representa o Quadro Kanban.
 * @author Isabela Gomes Mendes
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
 */
#ifndef KANBANBOARD_H
#define KANBANBOARD_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "kanbantask.h"
#include "estruturas_tads.hpp"
#include "templates.hpp"

// Definição de cores
#define ANSI_RESET "\033[0m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YELLOW "\033[33m"
#define ANSI_BLUE "\033[34m"

/**
 * @class KanbanBoard
 * @brief Classe KanbanBoard representa o Quadro Kanban que contém colunas e tarefas.
 * @code
 *    struct KanbanColumn{
 *      std::string name;
 *      ListaDuplamenteEncadeada<KanbanTask> tasks;
 *
 *     KanbanColumn(const std::string& columnName) : name(columnName) {}
 *
 *    // Método para obter a lista de tarefas da coluna
 *     ListaDuplamenteEncadeada<KanbanTask>& getTasks()
 *     {
 *         return tasks;
 *     }
 * };
 *   ListaDuplamenteEncadeada<KanbanColumn> columns;
 * @endcode
 * @details Essa classe possui dois atributos privados que merecem menção especial:
 * 1. Struct KanbanColumn
 *  Esse struct foi construído afim de definir uma coluna do Quadro Kanban, possui dois membros:
 *    - Uma string "nome" que armazena o nome da coluna
 *    - Uma lista duplamente encadeada do tipo "KanbanTask" que armazena as tarefas associadas a coluna
 * 2. Lista duplamente encadeada "columns"
 *  Essa é uma lista encadeada do tipo "KanbanColumn", ou seja, uma lista de colunas composta pelo struct KanbanColumn, que por sua vez contém uma lista de tarefas.
 * @details
 */
class KanbanBoard
{
private:
  /**
   * @brief Estrutura interna que representa uma coluna do quadro Kanban.
   * Cada coluna possui um nome e uma lista duplamente encadeada de tarefas.
   */
  struct KanbanColumn
  {
    std::string name;                           /*< Nome da coluna */
    ListaDuplamenteEncadeada<KanbanTask> tasks; /*< Lista de tarefas da coluna */

    /**
     * @brief Construtor da estrutura KanbanColumn.
     *
     * @param columnName Nome da coluna.
     */
    KanbanColumn(const std::string &columnName) : name(columnName) {}

    /**
     * @brief Obtém a lista de tarefas da coluna.
     *
     * @return Referência para a lista de tarefas da coluna.
     */
    ListaDuplamenteEncadeada<KanbanTask> &getTasks()
    {
      return tasks;
    }
  };

  ListaDuplamenteEncadeada<KanbanColumn> columns; /**< Lista duplamente encadeada de colunas do quadro Kanban */

public:
  /**
   * @brief Construtor padrão da classe KanbanBoard.
   */
  KanbanBoard();

  /**
   * @brief Destrutor padrão da classe KanbanBoard.
   */
  ~KanbanBoard();

  /**
   * @brief Método que adiciona uma nova coluna ao Quadro Kanban.
   *
   * @param columnName String de referência ao nome escolhido pelo usuário para a coluna.
   * @details Cria-se um novo struct KanbanColumn com o nome passado como parâmetro e adiciona-se o mesmo ao final da lista encadeada "columns" com o método pushback.
   */
  void addColumn(const std::string &columnName);

  /**
   * @brief Método que adiciona uma tarefa a uma coluna específica do Quadro Kanban.
   * @param columnIndex Índice da coluna em que deseja-se adicionar a tarefa.
   * @param task Variável do tipo KanbanTask, que contém a tarefa que será adicionada a uma coluna.
   * @details A lógica proposta é de através do índice informado descobrir a coluna de destino e adicionar a tarefa através do método push back.
   */
  void addTaskToColumn(int columnIndex, const KanbanTask &task);

  /**
   * @brief Método que imprime as tarefas em uma coluna específica do Quadro Kanban.
   * @param columnIndex Índice da coluna que deseja-se imprimir.
   * @details Após descobrir qual a coluna desejada pelo usuário através do índice, um 'for' percorre a lista de tarefas utilizando o método getTituloId para imprimir o título e id de cada tarefa.
   */
  void printColumn(int columnIndex) const;

  /**
   * @brief Método que move uma tarefa de uma coluna para a outra.
   * @param taskId VID da tarefa a ser movida
   * @param idcolunaDestino ID da coluna de destino.
   * @details
   *  - A tarefa a ser movida é encontrada através da chamada da função findTask
   *  - Encontra-se a coluna de origem com a chamada da função findTaskColumn
   *  - Adiciona-se a tarefa a coluna de destino com o método pushback e deleta-se a tarefa da coluna de origem com o método removeValue.
   */
  void moveTask(int taskId, int idcolunaDestino);

  /**
   * @brief Método que ordena uma coluna escolhida com base na prioridade das taredas.
   * @param columnIndex Índice da coluna que deseja-se ordenar.
   * @param flag Flag para sinalizar se a ordenação deve ser por prioridade crescente ou decrescente.
   * @details
   *  - A tarefa a ser movida é encontrada através da chamada da função findTask
   *  - Encontra-se a coluna de origem com a chamada da função findTaskColumn
   *  - Adiciona-se a tarefa a coluna de destino com o método pushback e deleta-se a tarefa da coluna de origem com o método removeValue().
   */
  void sortColumn(int columnIndex, int flag);

  /**
   * @brief Método que retorna o número de colunas do Quadro Kanban.
   * @details O número de colunas é encontrado através do método getSize() da lista duplamente encadeada.
   * @return O número de colunas.
   */
  int getNumColumns() const;

  /**
   * @brief Método que exclui uma tarefa.
   * @param taskId ID da tarefa a ser excluída.
   * @details A tarefa é encontrada com a chamada do método findTask() e depois excluída com o método removeValue().
   * @return true ou false, dependendo se a tarefa foi removido com sucesso ou não.
   */
  bool removeTask(int taskId);

  /**
   * @brief Método que verifica se o Quadro Kanban possui tarefas.
   * @details Um laço 'for' percorre coluna por coluna verificando se estão vazias ou não.
   * @return true caso o quadro esteja vazio e false caso o quadro já possua tarefas.
   */
  bool isBoardEmpty() const;

  /**
   * @brief Método que verifica se uma coluna está vazia.
   * @param columnIndex Índice da coluna em que deseja-se realizar a verificação.
   * @details Após obter a coluna através do seu índice, usa-se o método de lista duplamente encadeada isEmpty().
   * @return true caso a coluna esteja vazia e false caso a coluna já possua tarefas.
   */
  bool columnEmpty(int columnIndex) const;

  /**
   * @brief Método que verifica se um ID recebido já existe.
   * @param id ID a ser verificado.
   * @details Percorre-se cada coluna comparando o ID passado como parâmetro com o ID de cada tarefa existente.
   * @return true caso o ID recebido já exista e false caso contrário.
   */
  bool existeIdDuplicado(int id) const;

  /**
   * @brief Imprime o quadro Kanban.
   *
   * Este método imprime o quadro Kanban com as colunas e tarefas associadas, formatando-o de acordo com a quantidade de colunas e tarefas presentes.
   * A formatação do quadro é ajustada automaticamente para melhorar a legibilidade.
   *
   * @note Este método assume que as colunas e tarefas já foram devidamente configuradas no objeto KanbanBoard.
   *
   * @details
   * O método utiliza técnicas de formatação para alinhar as colunas e tarefas na saída do console. Ele também ajusta a largura das colunas de acordo com o número de colunas presentes no quadro Kanban.
   *
   * A responsividade do quadro é implementada através de uma lógica que define a largura das colunas com base na quantidade de colunas existentes.
   * A quantidade máxima de tarefas em uma coluna é determinada para garantir a correta exibição das tarefas em todas as colunas.
   *
   * A saída do quadro Kanban inclui os títulos das colunas e as tarefas de cada coluna, organizadas em linhas.
   * Se uma coluna não possui uma tarefa em uma determinada linha, é exibido um espaço em branco para manter a formatação correta.
   */
  void printBoard() const;

  /**
   * @brief Salva as informações do Quadro Kanban em um arquivo '.bin'.
   * @param filename Nome do arquivo em que deseja-se salvar o quadro.
   * @details
   * - O método cria um arquivo de saída com o nome fornecido e o abre em modo binário para gravação dos dados do quadro Kanban.
   * - Em seguida, o número de colunas do quadro é gravado no arquivo como um valor inteiro.
   * - O método percorre cada coluna do quadro e grava os dados da coluna e suas tarefas associadas no arquivo.
   * - Em seguida, cada tarefa é percorrida e seus dados, como ID, título, descrição, prioridade e data de vencimento, são gravados no arquivo.
   * - Após a gravação de todos os dados, o arquivo é fechado.
   */
  void saveToFile(const std::string &filename) const;

  /**
   * @brief Lê um Quadro Kanban a partir de um arquivo '.bin'
   * @param filename Nome do arquivo a ser lido.
   * @details
   * @note Este método substituirá o estado atual do quadro Kanban com os dados lidos do arquivo.
   *
   * @details
   * - O método abre o arquivo especificado em modo binário para leitura dos dados do quadro Kanban.
   * - Antes de carregar os dados, o método limpa o quadro atual utilizando o método `clear()` para garantir que o quadro esteja vazio antes do carregamento.
   * - O método percorre cada coluna e lê os dados da coluna e suas tarefas associadas do arquivo.
   * - Para cada coluna, o tamanho do nome da coluna é lido, seguido pela leitura do nome da coluna em si.
   * - Uma nova coluna é adicionada ao quadro Kanban utilizando o método `addColumn()` com o nome da coluna lido.
   * - Em seguida, o número de tarefas na coluna é lido e, para cada tarefa, são lidos os dados da tarefa do arquivo e a tarefa é adicionada à coluna utilizando o método `addTaskToColumn()`.
   */
  void loadFromFile(const std::string &filename);

  /**
   * @brief Método que salva o Quadro Kanban em um arquivo '.txt' para a visualizaçao.
   * @param fileName O nome do arquivo no qual será gravado o quadro.
   * @details
   * - O método cria um arquivo de saída com o nome fornecido e o abre em modo de texto para gravação dos dados do quadro Kanban.
   * - O método percorre cada coluna do quadro e grava as informações da coluna e suas tarefas associadas no arquivo de texto.
   * - Para cada coluna, é gravado um cabeçalho indicando o número da coluna e o nome da coluna.
   * - Em seguida, cada tarefa é percorrida e suas informações, como título e descrição, são gravadas no arquivo de texto.
   * - Cada tarefa é delimitada por uma linha horizontal para melhorar a legibilidade.
   */
  void saveToFileTxt(const std::string &fileName) const;

  /**
   * @brief Método que encontra uma tarefa com base em seu ID.
   * @param id ID da tarefa a ser encontrada
   * @return Ponteiro de KanbanTask
   * @details
   * - O método percorre todas as colunas do quadro Kanban e, para cada coluna, verifica se existem tarefas nessa coluna.
   * - Se a coluna não estiver vazia, o método percorre todas as tarefas da coluna em busca da tarefa com o ID fornecido.
   * - Se a tarefa for encontrada, um ponteiro para essa tarefa é retornado.
   */
  KanbanTask *findTask(int id);

  /**
   * @brief Método que encontra a coluna de uma tarefa com base em seu ID.
   * @param taskId ID da tarefa a qual será encontrada a coluna
   * @return Ponteiro de KanbanColumn
   * @details
   * - Percorre todas as colunas do quadro Kanban e, para cada coluna, verifica se existem tarefas nessa coluna.
   * - Se a coluna não estiver vazia, o método percorre todas as tarefas da coluna em busca da tarefa com o ID fornecido.
   * - Se a tarefa for encontrada, um ponteiro para a coluna correspondente é retornado.
   */
  KanbanColumn *findTaskColumn(int taskId) const
  {
    for (int i = 0; i < columns.getSize(); i++)
    {
      KanbanColumn &column = columns.get(i);
      for (int j = 0; j < column.tasks.getSize(); j++)
      {
        if (column.tasks.get(j).getId() == taskId)
        {
          return &column;
        }
      }
    }
    return NULL;
  }
};

#endif