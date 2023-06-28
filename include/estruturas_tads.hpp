#ifndef TADS_H
#define TADS_H
#include <iostream>
using namespace std;

/*Lista duplamente encadeada*/
template <typename T>
class No{
  public:
    T valor;
    No* prev;
    No* next;
    No(T valor) : valor(valor), prev(NULL), next(NULL){}
    ~No(){};
};

template <typename T>
class ListaDuplamenteEncadeada{
  private:
    No<T>* head; //Primeiro elemento
    No<T>* tail; //Último elemento

  public:
    ListaDuplamenteEncadeada() : head(NULL), tail(NULL){}
    ~ListaDuplamenteEncadeada(){
      clear();
    }

    No<T>* getHead() const {
      return head;
    }

    // Obter o elemento em um índice específico da lista
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


  /*Método para adicionar um novo elemento no início da lista*/
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


  /*Método para adicionar um novo elemento no final da lista*/
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


  /*Método para remover o primeiro elemento da lista*/
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


  /*Método para remover o último elemento da lista*/
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

/*Método para verificar se a lista está vazia*/
    bool isEmpty() const {
      if(head == NULL){
        return true;
      }else{
        return false;
      }
    }


/*Método para imprimir os elementos da lista*/
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


/*Método que retorna o tamanho da lista*/
    int getSize() const{
      int size = 0;
      No<T>* current = head;

      while(current != NULL) {
        size++;
        current = current->next;
      }

      return size;
    }


  /*Método para remover um valor específico da lista*/
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

  /*Método para excluir toda a lista*/
    void clear(){
      No<T>* current = head;

      while(current != NULL) {
        No<T>* nextNo = current->next;
        delete current;
        current = nextNo;
      }

      head = tail = NULL;
    }
/*
     void swap(int index1, int index2) {
        int size = getSize();
        
        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
            throw std::out_of_range("Index out of range");
        }

        if (index1 == index2) {
            return;  // Não é necessário fazer trocas se os índices forem iguais
        }

        No<T>* node1 = getNode(index1);
        No<T>* node2 = getNode(index2);

        // Troca dos ponteiros prev e next para os nós adjacentes aos nós a serem trocados
        No<T>* prevNode1 = node1->prev;
        No<T>* nextNode1 = node1->next;
        No<T>* prevNode2 = node2->prev;
        No<T>* nextNode2 = node2->next;

        // Atualização dos ponteiros dos nós adjacentes
        if (prevNode1 != NULL) {
            prevNode1->next = node2;
        } else {
            head = node2;  // Atualiza o ponteiro head se node1 era o primeiro elemento
        }

        if (nextNode1 != NULL) {
            nextNode1->prev = node2;
        } else {
            tail = node2;  // Atualiza o ponteiro tail se node1 era o último elemento
        }

        if (prevNode2 != NULL) {
            prevNode2->next = node1;
        } else {
            head = node1;  // Atualiza o ponteiro head se node2 era o primeiro elemento
        }

        if (nextNode2 != NULL) {
            nextNode2->prev = node1;
        } else {
            tail = node1;  // Atualiza o ponteiro tail se node2 era o último elemento
        }

        // Troca dos ponteiros prev e next entre os nós a serem trocados
        node1->prev = prevNode2;
        node1->next = nextNode2;
        node2->prev = prevNode1;
        node2->next = nextNode1;
    }*/

/*
private:
    // ...

    // Método auxiliar para obter o nó em um determinado índice
    No<T>* getNode(int index) const {
        if (index < 0 || index >= getSize()) {
            throw std::out_of_range("Index out of range");
        }

        No<T>* current = head;
        int currentIndex = 0;

        while (current != NULL) {
            if (currentIndex == index) {
                return current;
            }
            current = current->next;
            currentIndex++;
        }

        throw std::out_of_range("Index out of range");
    }*/



};
/*==========================================================================================*/


/*Pilha*/
template <typename T>
class Pilha{
private:
    struct No{
        T valor;
        No* next;
        No(T value) : valor(value), next(NULL){}
    };

    No* top;

public:
    Pilha() : top(NULL){}

    ~Pilha(){
      while(!isEmpty()) {
        pop();
      }
    }

  /*Método para verificar se a pilha está vazia*/
    bool isEmpty() const {
      if(top == NULL){
        return true;
      }else{
        return false;
      }
    }

  /*Método para adicionar um elemento no topo da pilha*/
    void push(T value) {
        No* newNo = new No(value);
        newNo->next = top;
        top = newNo;
    }

  /*Método para remover o elemento do topo da pilha*/
    void pop() {
      if(isEmpty()){
        std::cout << "A pilha está vazia." << std::endl;
        return;
      }
      No* temp = top;
      top = top->next;
      delete temp;
    }

  /*Retorna o elemento do topo da pilha*/
    T& peek(){
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia.");
        }
        return top->valor;
    }
    
};
/*==========================================================================================*/


/*Fila*/
template <typename T>
class Fila{
private:
    struct No{
        T valor;
        No* next;
        No(T value) : valor(value), next(NULL){}
    };

    No* head;
    No* tail;

public:
    Fila() : head(NULL), tail(NULL){}

    ~Fila(){
      while(!isEmpty()) {
        dequeue();
      }
    }

  /*Método para verificar se a fila está vazia*/
    bool isEmpty() const {
      if(head == NULL){
        return true;
      }else{
        return false;
      }
    }

  /*Método para adicionar um elemento no final da fila*/
    void enqueue(T value){
      No* newNo = new No(value);
      if(isEmpty()){
        head = tail = newNo;
      }else{
        tail->next = newNo;
        tail = newNo;
      }
    }

  /*Método para remover o elemento na frente da fila*/
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

  /*Retorna o elemento da frente da fila*/
    T& peek(){
        if (isEmpty()) {
            throw std::runtime_error("A fila está vazia.");
        }
        return head->valor;
    }
};
/*==========================================================================================*/


#endif