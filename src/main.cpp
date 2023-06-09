#include <iostream>
#include "../include/classes.h"
#include "../include/functions.h"
#include "../include/templates.hpp"


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
    return 0;
}