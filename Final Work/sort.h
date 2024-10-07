#ifndef SORT_H__
#define SORT_H__

#include <fstream>
#include "Movie.h"

// Métodos Auxiliares
void sort(Movie* movie, int n, int method, std::ofstream& outputFile);
void swap(Movie* movies, int i, int j);

// QuickSort
void quickSort(Movie* movies, int low, int high, long int& comparisons, long int& swaps);
int partition(Movie* movies, int first, int last, long int& comparisons, long int& swaps);
// MergeSort
void merge(Movie *v, Movie *vAux, int first, int middle, int last,
           long int& comparisons, long int& swaps);
void mergeSortRec(Movie *v, Movie *vAux, int first, int last,
                  long int& comparisons, long int& swaps);
void mergeSort(Movie *v, int n, long int& comparisons, long int& swaps);

// HeapSort
void heapSort(Movie* movies, int n, long int& comparisons, long int& swaps);
void heapify(Movie* movies, int n, int i, long int& comparisons, long int& swaps);

#endif /* SORT_H__ */
