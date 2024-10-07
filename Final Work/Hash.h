#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Movie.h"

const static int STRING_LENGTH = 4;
struct RegistroHash{
    char voteAverage[STRING_LENGTH]; // Guardamos o vote_average como string para aplicar o hash
    int qtdFilmes = 0; 

    void setVoteAverage(double vote) {
        snprintf(voteAverage, sizeof(voteAverage), "%.1f", vote); // Converter para string
    }
};

RegistroHash* createTable(int n);
int hash(const char* productId, const int randomWeight[STRING_LENGTH], int tableSize);
int rehash(int index, int tableSize);
void hashTable();

#endif //HASH_H