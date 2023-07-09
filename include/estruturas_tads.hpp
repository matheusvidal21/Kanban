/**
 * @file estruturas_tads.hpp
 * @brief Implementação de templates dos Tipos Abstratos de Dados: Lista Duplamente Encadeada, Pilha e Fila
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/
#ifndef TADS_H
#define TADS_H
#include <iostream>
using namespace std;


/**
 * @class No
 * @brief Classe que representa um nó da lista duplamente encadeada.
 * @details A classe No possui um valor do tipo genérico T, e ponteiros para o nó anterior (prev) e próximo (next).
 * @tparam T O tipo de dado armazenado no nó.
 */
template <typename T>
class No{
  public:
    T valor; /*< O valor armazenado no nó. */
    No* prev; /*< Ponteiro para o nó anterior. */
    No* next; /*< Ponteiro para opróximo nó. */
    /**
    * @brief Construtor da classe No.
    * @param valor O valor a ser armazenado no nó.
    */
    No(T valor) : valor(valor), prev(NULL), next(NULL){}
    /**
    @brief Destrutor da classe No.
    */
    ~No(){};
};

/**
 * @class ListaDuplamenteEncadeada
 * @brief Classe que implementa uma lista duplamente encadeada.
 * @details A classe ListaDuplamenteEncadeada possui um ponteiro para o primeiro elemento (head) e um ponteiro para o último elemento (tail) da lista. 
 * Ela permite adicionar elementos no início (pushFront) e no final (pushBack), remover o primeiro elemento (removeFront) e o último elemento (removeBack),
 * verificar se a lista está vazia (isEmpty), imprimir os elementos da lista (print), obter o tamanho da lista (getSize), remover um valor específico (removeValue) e
 * limpar toda a lista (clear).
 * @tparam T O tipo de dado armazenado na lista.
 */
template <typename T>
class ListaDuplamenteEncadeada{
  private:
    No<T>* head; /*< Ponteiro para o primeiro elemento da lista. */
    No<T>* tail; /*< Ponteiro para o último elemento da lista. */

  public:

    /**
    * @brief Construtor da classe ListaDuplamenteEncadeada.
    */
    ListaDuplamenteEncadeada() : head(NULL), tail(NULL){}


    /**
     * @brief Destrutor da classe ListaDuplamenteEncadeada.
     * Remove todos os elementos da lista.
     */
    ~ListaDuplamenteEncadeada(){
      clear();
    }


    /**
     * @brief Método getter que retorna o ponteiro para o primeiro elemento da lista.
     * @return O ponteiro para o primeiro elemento da lista.
     */
    No<T>* getHead() const {
      return head;
    }


    /**
     * @brief Método para obter o elemento em um índice específico da lista
     * @param index O índice do elemento desejado.
     * @return Uma referência para o elemento do índice especificado.
     * @throw std::out_of_range caso o índice esteja fora dos limites da lista.
     */
    T& get(int index) const {
        if (index < 0 || index >= getSize()) {
            throw std::out_of_range("Index não encontrado.");
        }

        No<T>* current = head;
        int currentIndex = 0;

        while (current != NULL) {
            if (currentIndex == index) {
                return current->valor;
            }
            current = current->next;
            currentIndex++;
        }

        throw std::out_of_range("Index não encontrado.");
    }


    /**
     * @brief Método que adiciona um novo elemento no início da lista.
     * @param value O valor do novo elemento a ser adicionado.
     */
    void pushFront(T value){
      No<T>* newNo = new No<T>(value);
        if (isEmpty()){
          head = tail = newNo;
        }else{
          newNo->next = head;
          head->prev = newNo;
          head = newNo;
        }
    }  


    /**
     * @brief Método que adiciona um novo elemento no final da lista.
     * @param value O valor do novo elemento a ser adicionado.
     */
    void pushBack(T value){
      No<T>* newNo = new No<T>(value);
        if(isEmpty()){
          head = tail = newNo;
        }else{
          tail->next = newNo;
          newNo->prev = tail;
          tail = newNo;
        }
    }


    /**
     * @brief Método que remove o primeiro elemento da lista.
     * Se a lista estiver vazia, uma mensagem de erro é exibida.
     */
    void removeFront() {
      if(isEmpty()){
        std::cout << "A lista está vazia." << std::endl;
        return;
      }

      No<T>* temp = head;
      head = head->next;

      if (head == NULL){ //Caso só tenha um elemento
        tail = NULL;
      }else{
        head->prev = NULL;
      }
      delete temp;
    }


    /**
     * @brief Método que remove o último elemento da lista.
     * Se a lista estiver vazia, uma mensagem de erro é exibida.
     */
    void removeBack() {
      if(isEmpty()){
        std::cout << "A lista está vazia." << std::endl;
        return;
      }

      No<T>* temp = tail;
      tail = tail->prev;

      if(tail == NULL){ //Caso só tenha um elemento
        head = NULL;
      }else{
        tail->next = NULL;
      }

      delete temp;
    }


    /**
     * @brief Método que verifica se a lista está vazia.
     * @return true se a lista estiver vazia, false caso contrário.
     */
    bool isEmpty() const {
      if(head == NULL){
        return true;
      }else{
        return false;
      }
    }


    /**
     * @brief Método que imprime os elementos da lista.
     * Se a lista estiver vazia, uma mensagem informando isso é exibida.
     */
    void print() const{
      if(isEmpty()){
        std::cout << "A lista está vazia." << std::endl;
        return;
      }

      No<T>* current = head;
      while (current != NULL) {
        std::cout << current->valor << " ";
        current = current->next;
      }
      std::cout << std::endl;
    }


   /**
     * @brief Método que retorna o tamanho da lista.
     * @return O tamanho da lista.
     */
    int getSize() const{
      int size = 0;
      No<T>* current = head;

      while(current != NULL) {
        size++;
        current = current->next;
      }

      return size;
    }


   /**
     * @brief Método que remove um valor específico da lista.
     * @param value O valor a ser removido.
     * @return true se o valor foi removido com sucesso, false caso contrário.
     */
    bool removeValue(const T& value){
      if(isEmpty()){
        return false;
      }

      No<T>* current = head;

      // Caso o valor a ser removido esteja na cabeça da lista
      if(current->valor == value){
        head = current->next;

        if(head != NULL){
          head->prev = NULL;
        }else{
          tail = NULL;
        }

        delete current;
        return true;
      }

      while(current != NULL) {
        if(current->valor == value) {
          No<T>* prevNo = current->prev;
          No<T>* nextNo = current->next;

          if(prevNo != NULL) {
            prevNo->next = nextNo;
          }

          if(nextNo != NULL) {
            nextNo->prev = prevNo;
          }else{
            tail = prevNo;
          }

          delete current;
          return true;
        }
        current = current->next;
      }
      return false;
    }


    /**
     * @brief Método que remove todos os elementos da lista.
     * @details Remove todos os elementos da lista, liberando a memória alocada por cada nó.
     */
    void clear(){
      No<T>* current = head;

      while(current != NULL) {
        No<T>* nextNo = current->next;
        delete current;
        current = nextNo;
      }

      head = tail = NULL;
    }

};



/*==========================================================================================*/


/**
 * @class Pilha
 * @brief Classe que implementa uma pilha utilizando a estrutura de lista encadeada.
 * @tparam T O tipo de dado armazenado na pilha.
 * 
 */
template <typename T>
class Pilha{
private:
   /**
    * @brief Classe que representa um nó da pilha.
    */
    struct No{
        T valor; /*< O valor armazenado no nó. */
        No* next; /*< Ponteiro para o próximo nó. */

        /**
         * @brief Construtor da classe No.
         * @param value O valor a ser armazenado no nó.
         */
        No(T value) : valor(value), next(NULL){}
    };

    No* top; /*< Ponteiro para o topo da pilha. */

public:
    /**
      * @brief Construtor da classe Pilha.
      */
    Pilha() : top(NULL){}


    /**
     * @brief Destrutor da classe Pilha.
     * Remove todos os elementos da pilha.
     */
    ~Pilha(){
      while(!isEmpty()) {
        pop();
      }
    }


    /**
     * @brief Verifica se a pilha está vazia.
     * @return true se a pilha estiver vazia, false caso contrário.
     */    
    bool isEmpty() const {
      if(top == NULL){
        return true;
      }else{
        return false;
      }
    }


    /**
     * @brief Adiciona um elemento no topo da pilha.
     * @param value O valor do elemento a ser adicionado.
     */
    void push(T value) {
        No* newNo = new No(value);
        newNo->next = top;
        top = newNo;
    }


    /**
     * @brief Remove o elemento do topo da pilha.
     * Se a pilha estiver vazia, uma mensagem de erro é exibida.
     */
    void pop() {
      if(isEmpty()){
        std::cout << "A pilha está vazia." << std::endl;
        return;
      }
      No* temp = top;
      top = top->next;
      delete temp;
    }


    /**
     * @brief Retorna o elemento do topo da pilha.
     *
     * @return Uma referência para o elemento do topo.
     * @throw std::runtime_error Se a pilha estiver vazia.
     */
    T& peek(){
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia.");
        }
        return top->valor;
    }
    
};



/*==========================================================================================*/



/**
 * @class Fila
 * @brief Classe que implementa uma fila utilizando a estrutura de lista encadeada.
 * @tparam T O tipo de dado armazenado na fila.
 */
template <typename T>
class Fila{
private:
   /**
    * @brief Classe que representa um nó da fila.
    */
    struct No{
        T valor;  /*< O valor armazenado no nó. */
        No* next;  /*< Ponteiro para o próximo nó. */

         /**
          * @brief Construtor da classe No.
          *
          * @param value O valor a ser armazenado no nó.
          */
        No(T value) : valor(value), next(NULL){}
    };

    No* head; /*< Ponteiro para o primeiro elemento da fila. */
    No* tail; /*< Ponteiro para o último elemento da fila. */


public:
    /**
     * @brief Construtor da classe Fila.
     */
    Fila() : head(NULL), tail(NULL){}


    /**
     * @brief Destrutor da classe Fila.
     * Remove todos os elementos da fila.
     */
    ~Fila(){
      while(!isEmpty()) {
        dequeue();
      }
    }


    /**
     * @brief Verifica se a fila está vazia.
     *
     * @return true se a fila estiver vazia, false caso contrário.
     */
    bool isEmpty() const {
      if(head == NULL){
        return true;
      }else{
        return false;
      }
    }


    /**
     * @brief Adiciona um elemento no final da fila.
     *
     * @param value O valor do elemento a ser adicionado.
     */
    void enqueue(T value){
      No* newNo = new No(value);
      if(isEmpty()){
        head = tail = newNo;
      }else{
        tail->next = newNo;
        tail = newNo;
      }
    }


    /**
     * @brief Remove o elemento na frente da fila.
     * Se a fila estiver vazia, uma mensagem de erro é exibida.
     */
    void dequeue(){
      if(isEmpty()){
        std::cout << "A fila está vazia." << std::endl;
        return;
      }
      No* temp = head;
      head = head->next;
      if(head == NULL){
        tail = NULL;
      }
      delete temp;
    }


    /**
     * @brief Retorna o elemento da frente da fila.
     *
     * @return Uma referência para o elemento da frente.
     * @throw std::runtime_error Se a fila estiver vazia.
     */
    T& peek(){
        if (isEmpty()) {
            throw std::runtime_error("A fila está vazia.");
        }
        return head->valor;
    }
};

/*==========================================================================================*/

#endif