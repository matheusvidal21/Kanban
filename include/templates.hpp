#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <iostream>

/*Código auxiliar com template genérico com algoritimos de ordenação:
  Bubble Sort, Selection Sort e Merge Sort.*/
template<typename T>
class AlgoritmosDeOrdenacao {
public:

    /*A complexidade do Bubble Sort é O(n^2), onde "n" é 
    o tamanho da lista a ser ordenada. Essa é uma complexidade
    quadrática, o que significa que o tempo de execução aumenta 
    rapidamente à medida que o tamanho da lista aumenta. A complexidade
    quadrática do Bubble Sort ocorre porque, em cada passagem, são feitas comparações
    entre pares de elementos adjacentes e, se necessário, são feitas trocas. 
    */
    //Ordena de forma crescente
    static void bubbleSort(T arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    /*A complexidade do Selection Sort também é
    O(n^2), onde "n" é o tamanho da lista a ser ordenada.
    Assim como o Bubble Sort, o Selection Sort possui uma 
    complexidade quadrática. A complexidade quadrática do 
    Selection Sort ocorre porque, em cada iteração, é necessário
    percorrer a parte não ordenada para encontrar o menor elemento. 
    */
   //Ordena de forma decrescente
    static void selectionSort(T arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            int indice_minimo = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] > arr[indice_minimo]) {
                    indice_minimo = j;
                }
            }
            std::swap(arr[i], arr[indice_minimo]);
        }
    }

    /*A complexidade do Merge Sort é O(n log n), onde "n" é o 
    tamanho da lista a ser ordenada. Essa é uma complexidade assintótica 
    eficiente e torna o Merge Sort adequado para lidar com grandes 
    conjuntos de dados. O Merge Sort possui essa complexidade porque o
    algoritmo divide repetidamente a lista em duas metades, até que sejam
    formadas sublistas com apenas um elemento. 
    */
    static void mergeSort(T arr[], int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

private:
    static void merge(T arr[], int left, int mid, int right) {
        int left_size = mid - left + 1;
        int right_size = right - mid;
        
        T* left_arr = new T[left_size];
        T* right_arr = new T[right_size];


        for (int i = 0; i < left_size; i++) {
            left_arr[i] = arr[left + i];
        }

        for (int j = 0; j < right_size; j++) {
            right_arr[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < left_size && j < right_size) {
            if (left_arr[i] <= right_arr[j]) {
                arr[k] = left_arr[i];
                i++;
            } else {
                arr[k] = right_arr[j];
                j++;
            }
            k++;
        }

        while (i < left_size) {
            arr[k] = left_arr[i];
            i++;
            k++;
        }

        while (j < right_size) {
            arr[k] = right_arr[j];
            j++;
            k++;
        }
        delete[] left_arr;
        delete[] right_arr;
    }  
};

template<typename T>
class AlgoritmosDeBuscaBinaria {
public:

    // Busca binária iterativa
    static int BuscaBinariaIterativa(T arr[], int tamanho, T chave){
        int inicio = 0;
        int fim = tamanho - 1;

        while(inicio <= fim){
            int meio = (inicio + fim)/2;
            if(arr[meio] == chave){
                return meio;
            }else if(arr[meio] > chave){
                fim = meio - 1;
            }else{
                inicio = meio + 1;
            }
        }
        return -1; // Retorna -1 se a chave não for encontrada
    }

    // Busca binária recursiva
    static int BuscaBinariaRecursiva(T arr[], int inicio, int fim, T chave){
        if(inicio > fim) return -1;// Retorna -1 se a chave não for encontrada

        int meio = (inicio+fim)/2;

        if(arr[meio] == chave){
            return meio;
        }else if(arr[meio] > chave){
            return BuscaBinariaRecursiva(arr, inicio, (meio - 1), chave);
        }else{
            return BuscaBinariaRecursiva(arr, (meio + 1), fim, chave);
        }
    }
};

#endif