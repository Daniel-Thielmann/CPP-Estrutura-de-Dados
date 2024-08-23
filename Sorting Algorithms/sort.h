#ifndef SORT_H__
#define SORT_H__

#include <vector>
#include "filme.h"

void bubbleSort(std::vector<Filme>& filmes);
void mergeSort(std::vector<Filme>& filmes, int inicio, int fim);
void quickSort(std::vector<Filme>& filmes, int inicio, int fim);

#endif 