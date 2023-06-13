#include <iostream>
#include "../include/classes.h"
#include "../include/functions.h"
#include "../include/templates.hpp"
#include "../include/estruturas_tads.hpp"


int main(){
    int arr[] = {3, 6, 5, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Array original: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //AlgoritmosDeOrdenacao<char>::selectionSort(arr, size);
    AlgoritmosDeOrdenacao<int>::bubbleSort(arr, size);
    // AlgoritmosDeOrdenacao<int>::mergeSort(arr, 0, size - 1);

    std::cout << "Array ordenado: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;


    std::cout << "Valor 5 encontrado na posição: " << AlgoritmosDeBuscaBinaria<int>::BuscaBinariaRecursiva(arr, 0, size - 1, 5) << std::endl;
    std::cout << "Valor 3 encontrado na posição: " << AlgoritmosDeBuscaBinaria<int>::BuscaBinariaIterativa(arr, size, 3) << std::endl;

    std::cout << "\n\n\n\n";

    ListaDuplamenteEncadeada<int> list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushFront(5);
    std::cout<< "Tamanho: " << list.getSize() << std::endl;
    list.print();  // Saída: 5 10 20 30

    list.removeFront();
    list.removeBack();

    list.print();  // Saída: 10 20
    list.removeValue(10);
    list.print();  // Saída: 20
    list.removeValue(20);
    list.print();  
    list.clear();

    std::cout << "\n\n\n\n";
    Pilha<char> pilha;

    pilha.push('b');
    pilha.push('c');
    pilha.push('g');

    std::cout << "Elemento no topo: " << pilha.peek() << std::endl;

    pilha.pop();

    std::cout << "Elemento no topo após pop: " << pilha.peek() << std::endl;

    std::cout << "\n\n\n\n";




    Fila<int> fila;

    fila.enqueue(10);
    fila.enqueue(20);
    fila.enqueue(30);

    std::cout << "Elemento na frente: " << fila.peek() << std::endl;

    fila.dequeue();

    std::cout << "Elemento na frente após dequeue: " << fila.peek() << std::endl;

    return 0;


    return 0;
}