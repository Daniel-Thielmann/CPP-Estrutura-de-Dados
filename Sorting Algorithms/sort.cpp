#include "filme.h"
#include "sort.h"
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<Filme>& filmes) {
    int n = filmes.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (filmes[j].nome > filmes[j + 1].nome) {
                std::swap(filmes[j], filmes[j + 1]);
            }
        }
    }
}

void merge(std::vector<Filme>& filmes, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    std::vector<Filme> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = filmes[inicio + i];
    for (int j = 0; j < n2; j++)
        right[j] = filmes[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (left[i].nome <= right[j].nome) {
            filmes[k] = left[i];
            i++;
        } else {
            filmes[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        filmes[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        filmes[k] = right[j];
        j++;
        k++;
    }
}

void mergeSortHelper(std::vector<Filme>& filmes, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSortHelper(filmes, inicio, meio);
        mergeSortHelper(filmes, meio + 1, fim);

        merge(filmes, inicio, meio, fim);
    }
}

void mergeSort(std::vector<Filme>& filmes) {
    mergeSortHelper(filmes, 0, filmes.size() - 1);
}

int partition(std::vector<Filme>& filmes, int inicio, int fim) {
    Filme pivot = filmes[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (filmes[j].nome <= pivot.nome) {
            i++;
            std::swap(filmes[i], filmes[j]);
        }
    }

    std::swap(filmes[i + 1], filmes[fim]);
    return i + 1;
}

void quickSortHelper(std::vector<Filme>& filmes, int inicio, int fim) {
    if (inicio < fim) {
        int pi = partition(filmes, inicio, fim);

        quickSortHelper(filmes, inicio, pi - 1);
        quickSortHelper(filmes, pi + 1, fim);
    }
}

void quickSort(std::vector<Filme>& filmes) {
    quickSortHelper(filmes, 0, filmes.size() - 1);
}
