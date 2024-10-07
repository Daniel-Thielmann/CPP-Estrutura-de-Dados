#include <iostream>
#include <fstream>

#include <chrono>
#include "sort.h"
#include "Movie.h"

// Escolha do Método
void sort(Movie* movie, int n, int method, std::ofstream& outputFile) {
    long int comparisons = 0;
    long int swaps = 0;
    long long int time;

    static long long int sumComp = 0;
    static long long int sumSwap = 0;
    static long long int sumTime = 0;
    static long int M = 0;

    switch (method) {
        case 0: { // QuickSort
            auto start = std::chrono::steady_clock::now(); // Início da medição de tempo

            quickSort(movie, 0, n - 1, comparisons, swaps); // Chamada do QuickSort

            auto end = std::chrono::steady_clock::now(); // Fim da medição de tempo
            auto elapsed  = end - start; // Cálculo do tempo
            time = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
            sumTime += time; // Soma do tempo para cálculo posterior da média

            // Registro dos Resultados 
            outputFile << "Comparações: " << comparisons << "\n";
            outputFile << "Trocas: " << swaps << "\n";
            outputFile << "Tempo de processamento: " << time << "ms\n";
            break;
        }
        case 1: { // MergeSort
            auto start = std::chrono::steady_clock::now(); 

            mergeSort(movie, n, comparisons, swaps); // Chamada do MergeSort

            auto end = std::chrono::steady_clock::now(); 
            auto elapsed = end - start; 
            time = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
            sumTime += time; 

            // Registro dos Resultados no arquivo
            outputFile << "Comparações: " << comparisons << "\n";
            outputFile << "Trocas: " << swaps << "\n";
            outputFile << "Tempo de processamento: " << time << "ms\n";
            break;
        }

        case 2: { // HeapSort
            auto start = std::chrono::steady_clock::now(); 

            heapSort(movie, n, comparisons, swaps); // Chamada do HeapSort

            auto end = std::chrono::steady_clock::now(); 
            auto elapsed = end - start; 
            time = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
            sumTime += time; 

            // Registro dos Resultados no arquivo
            outputFile << "Comparações: " << comparisons << "\n";
            outputFile << "Trocas: " << swaps << "\n";
            outputFile << "Tempo de processamento: " << time << "ms\n";
            break;
        }
    }

    // Soma das Métricas
    sumComp += comparisons;
    sumSwap += swaps;
    M++;

    // Cálculo pós 3 execuções
    if (M != 0 && (M % 3 == 0)) {
        outputFile << "\n\nMÉDIA DE DESEMPENHO\n";
        outputFile << "Comparações: " << sumComp / 3 << "\n";
        outputFile << "Trocas: " << sumSwap / 3 << "\n";
        outputFile << "Tempo: " << sumTime / 3 << "ms\n";
        outputFile << "--------------------\n\n";

        // Reset das somas para novas execuções
        sumComp = 0;
        sumSwap = 0;
        sumTime = 0;
    }
}

void swap(Movie* a, Movie* b) {
    Movie temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort
int partition(Movie* movies, int low, int high, long int& comparisons, long int& swaps) {
    double pivot = movies[high].getPopularity();  // Pivô é o último
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        comparisons++;  
        if (movies[j].getPopularity() < pivot) {
            i++;
            swap(&movies[i], &movies[j]);
            swaps++;  
        }
    }
    swap(&movies[i + 1], &movies[high]);
    swaps++;  // (swap final)
    return (i + 1);
}

void quickSort(Movie* movies, int low, int high, long int& comparisons, long int& swaps) {
    if (low < high) {
        int pi = partition(movies, low, high, comparisons, swaps);

        quickSort(movies, low, pi - 1, comparisons, swaps);  // Ordena Esquerda
        quickSort(movies, pi + 1, high, comparisons, swaps);  // Ordena direita
    }
}

// MergeSort
void merge(Movie *v, Movie *vAux, int first, int middle, int last,
           long int& comparisons, long int& swaps){
    int i = first, j = middle + 1, k = 0;
    while(i <= middle && j <= last){
        if(v[i].getPopularity() <= v[j].getPopularity()){ // <= para estabilidade do algoritmo
            vAux[k] = v[i];
            i++;
        }
        else{
            vAux[k] = v[j];
            j++;
        }
        comparisons++;
        swaps++;
        k++;
    }
    while(i <= middle){ // preenche vetor auxiliar caso tenha sobrado valores na parte inferior do vetor
        vAux[k] = v[i];
        i++;
        k++;
        swaps++;
    }
    while(j <= last){ // preenche vetor auxiliar caso tenha sobrado valores na parte superior do vetor
        vAux[k] = v[j];
        j++;
        k++;
        swaps++;
    }

    for(k = 0; k < last-first+1; k++) // transfere o vetor auxiliar para o original
        v[first+k] = vAux[k];
}

void mergeSortRec(Movie *v, Movie *vAux, int first, int last,
                  long int& comparisons, long int& swaps){
    if(first < last){
        int middle = (first + last) / 2;
        mergeSortRec(v, vAux, first, middle, comparisons, swaps);
        mergeSortRec(v, vAux, middle+1, last, comparisons, swaps);
        merge(v, vAux, first, middle,last, comparisons, swaps);
    }
}
void mergeSort(Movie *v, int n, long int& comparisons, long int& swaps){
    auto* vAux = new Movie[n];
    mergeSortRec(v, vAux, 0, n-1, comparisons, swaps);
    delete [] vAux;
}


void heapify(Movie* movies, int n, int i, long int& comparisons, long int& swaps) {
    int largest = i;  // Inicializa o maior como raiz
    int left = 2 * i + 1;  // Filho esquerdo
    int right = 2 * i + 2;  // Filho direito

    // Se o filho esquerdo é maior que a raiz
    comparisons++;
    if (left < n && movies[left].getPopularity() > movies[largest].getPopularity()) {
        largest = left;
    }

    // Se o filho direito é maior que o maior atual
    comparisons++;
    if (right < n && movies[right].getPopularity() > movies[largest].getPopularity()) {
        largest = right;
    }

    // Se o maior não é a raiz
    if (largest != i) {
        swap(&movies[i], &movies[largest]);  // Troca
        swaps++;

        // Recursivamente reorganiza o subárvore afetado
        heapify(movies, n, largest, comparisons, swaps);
    }
}

void heapSort(Movie* movies, int n, long int& comparisons, long int& swaps) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(movies, n, i, comparisons, swaps);
    }

    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        swap(&movies[0], &movies[i]);
        swaps++;

        // Chama heapify no heap reduzido
        heapify(movies, i, 0, comparisons, swaps);
    }
}