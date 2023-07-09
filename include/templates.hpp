/**
 * @file templates.hpp
 * @brief Código-fonte auxiliar com templates genéricos de algoritmos de ordenação e busca.
 * @author Isabela Gomes Mendes 
 * @author Matheus Costa Vidal
 * @since 14/06/2023
 * @date 08/07/2023
*/
#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <iostream>
#include "estruturas_tads.hpp"


/**
 * @class AlgoritmosDeOrdenacao
 * @brief Template de classe para algoritmos de ordenação.
 * @tparam T O tipo de dado a ser ordenado.
 * @details Esta classe contém implementações de algoritmos de ordenação como Bubble Sort (crescente), Selection Sort (decrescente) e Merge Sort (crescente).
 */
template<typename T>
class AlgoritmosDeOrdenacao {
public:


   /**
    * @brief Ordena a lista de forma crescente usando o Bubble Sort.
    * @param list A lista a ser ordenada.
    * @param size O tamanho da lista.
    *
    * A complexidade do Bubble Sort é O(n^2), onde "n" é o tamanho da lista a ser ordenada.
    * Essa é uma complexidade quadrática, o que significa que o tempo de execução aumenta
    * rapidamente à medida que o tamanho da lista aumenta. A complexidade quadrática do Bubble Sort
    * ocorre porque, em cada passagem, são feitas comparações entre pares de elementos adjacentes
    * e, se necessário, são feitas trocas.
    */
    static void bubbleSort(ListaDuplamenteEncadeada<T>& list, int size) {

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {

                T& task1 = list.get(j);
                T& task2 = list.get(j + 1);
                if (task1.getPrioridade() > task2.getPrioridade()) {
                    swapTasks(task1, task2);
                }

            }
        }
    }



   /**
    * @brief Ordena a lista de forma decrescente usando o Selection Sort.
    * @param list A lista a ser ordenada.
    * @param size O tamanho da lista.
    *
    * A complexidade do Selection Sort também é O(n^2), onde "n" é o tamanho da lista a ser ordenada.
    * Assim como o Bubble Sort, o Selection Sort possui uma complexidade quadrática. A complexidade
    * quadrática do Selection Sort ocorre porque, em cada iteração, é necessário percorrer a parte não
    * ordenada para encontrar o menor elemento.
    */
    static void selectionSort(ListaDuplamenteEncadeada<T>& list, int size) {

        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < size; j++) {

                T& task1 = list.get(j);
                T& task2 = list.get(minIndex);
                if (task1.getPrioridade() > task2.getPrioridade()){
                    minIndex = j;
                }

            }

            if (minIndex != i) {
                T& task1 = list.get(i);
                T& task2 = list.get(minIndex);
                swapTasks(task1, task2);
            }
        }
    }



   /**
    * @brief Ordena a lista usando o Merge Sort.
    * @param arr A lista a ser ordenada.
    * @param left O índice de início da sublista.
    * @param right O índice de fim da sublista.
    *
    * A complexidade do Merge Sort é O(n log n), onde "n" é o tamanho da lista a ser ordenada.
    * Essa é uma complexidade assintótica eficiente e torna o Merge Sort adequado para lidar com
    * grandes conjuntos de dados. O Merge Sort possui essa complexidade porque o algoritmo divide
    * repetidamente a lista em duas metades, até que sejam formadas sublistas com apenas um elemento.
    */
    static void mergeSort(ListaDuplamenteEncadeada<T>& arr, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

private:

   /**
    * @brief Realiza a troca de duas tarefas.
    * @param task1 A primeira tarefa.
    * @param task2 A segunda tarefa.
    */
    static void swapTasks(T& task1, T& task2) {
        T temp = task1;
        task1 = task2;
        task2 = temp;
    }


   /**
    * @brief Combina duas sublistas em uma única lista ordenada.
    * @param arr A lista a ser combinada.
    * @param left O índice de início da primeira sublista.
    * @param mid O índice de fim da primeira sublista e início da segunda sublista.
    * @param right O índice de fim da segunda sublista.
    */
    static void merge(ListaDuplamenteEncadeada<T>& arr, int left, int mid, int right) {
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



/**
 * @class AlgoritmosDeBuscaBinaria
 * @brief Template de classe para algoritmo de busca binária genérico.
 * @tparam T O tipo de dado a ser buscado.
 */
template<typename T>
class AlgoritmosDeBuscaBinaria {
public:

   /**
    * @brief Realiza uma busca binária iterativa em uma lista ordenada.
    * @param arr A lista ordenada.
    * @param tamanho O tamanho da lista.
    * @param chave O valor a ser buscado.
    * @return O índice do valor encontrado ou -1 se não for encontrado.
    */
    static int BuscaBinariaIterativa(ListaDuplamenteEncadeada<T>& arr, int tamanho, T chave){
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



   /**
    * @brief Realiza uma busca binária recursiva em uma lista ordenada.
    * @param arr A lista ordenada.
    * @param inicio O índice de início da sublista.
    * @param fim O índice de fim da sublista.
    * @param chave O valor a ser buscado.
    * @return O índice do valor encontrado ou -1 se não for encontrado.
    */
    static int BuscaBinariaRecursiva(ListaDuplamenteEncadeada<T>& arr, int inicio, int fim, T chave){
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