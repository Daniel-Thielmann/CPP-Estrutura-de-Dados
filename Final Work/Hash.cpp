#include "Hash.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Movie.h"

void mergeHash(RegistroHash* products, int n);

// Função para comparar dois vote_average armazenados como strings
bool isEqual(const char* voteAverage1, const char* voteAverage2) {
    return strncmp(voteAverage1, voteAverage2, 3) == 0;
}

// Função de hash, usa pesos aleatórios para gerar um índice da tabela
int hash(const char* voteAverage, const int randomWeights[STRING_LENGTH], int tableSize) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += (int)voteAverage[i] * randomWeights[i];
    }
    return sum % tableSize;
}

// Função de rehash em caso de colisão
int rehash(int index, int tableSize) {
    return (index + 701) % tableSize;
}

void hashTable() {
    std::ifstream input;
    std::ofstream outputFile;
    outputFile.open("../vote_average.txt");
    if (!outputFile.is_open()) {
        std::cout << "Erro ao criar arquivo de saída" << std::endl;
    }

    input.open("../vote_average.dat");

    if(input.is_open()) {
        std::string line;
        while (getline(input, line)) {
            int N = stoi(line);
            RegistroHash* table = createTable(N);

            int P = 5;

            mergeHash(table, N*2);

            std::cout << "TABELA HASH PARA N = " << N << ":" << std::endl;
            outputFile << "TABELA HASH PARA N = " << N << ":" << std::endl;

            int i = 0;
            while(i < P) {
                if (table[i].qtdFilmes == 0)
                    break;

                std::cout << "VOTE_AVERAGE " << i + 1 << ": ";
                outputFile << "VOTE_AVERAGE " << i + 1 << ": ";
                for (int j = 0; j < STRING_LENGTH - 1; j++) {
                    std::cout << table[i].voteAverage[j];
                    outputFile << table[i].voteAverage[j];
                }
                std::cout << " " << "Quantidade de filmes: " << table[i].qtdFilmes << std::endl;
                outputFile << " " << "Quantidade de filmes: " << table[i].qtdFilmes << std::endl;

                i++;
            }
            std::cout << "--------------" <<  std::endl << std::endl;
            outputFile << "--------------" <<  std::endl << std::endl;
        }
    }
    else
        std::cout << "ERRO: arquivo de input nao encontrado" << std::endl;
}

// Função para criar a tabela hash e inserir os vote_average
RegistroHash* createTable(int n) {
    int M = n * 2; // Tamanho da tabela hash
    Movie* movies = Movie::import(n);
    RegistroHash* table = new RegistroHash[M];
    
    int colisoes = 0;
    int randomWeights[STRING_LENGTH];
    
    // Gerando pesos aleatórios para a função de hash
    std::cout << "Pesos aleatorios: ";
    for (int i = 0; i < STRING_LENGTH; i++) {
        randomWeights[i] = rand() % (n / 2);
        std::cout << randomWeights[i] << " ";
    }
    std::cout << std::endl;

    // Inserindo os vote_average na tabela hash
    for (int i = 0; i < n; i++) {
        char voteAverageStr[STRING_LENGTH];
        snprintf(voteAverageStr, sizeof(voteAverageStr), "%.1f", movies[i].getVoteAverage()); // Converter para string

        int index = hash(voteAverageStr, randomWeights, M);
        bool inserido = false;

        // Loop para rehash em caso de colisão
        while (!inserido && colisoes < M) {
            if (table[index].qtdFilmes == 0) {
                // Se o espaço está vazio, insere o novo vote_average
                table[index].setVoteAverage(movies[i].getVoteAverage());
                table[index].qtdFilmes++;
                inserido = true;
            } else if (isEqual(table[index].voteAverage, voteAverageStr)) {
                // Se já existe na tabela, incrementa a contagem
                table[index].qtdFilmes++;
                inserido = true;
            } else {
                // Rehash
                index = rehash(index, M);
                colisoes++;
            }
        }

        if (!inserido) {
            std::cout << "Colisoes excessivas ao inserir o vote_average " << movies[i].getVoteAverage() << std::endl;
        }
        colisoes = 0;
    }
    return table;
}

///MergeSort para Hash
bool isGreaterOrEqual(int x, int y){
    if(y == 0)
        return true;
    if(x != 0 && x >= y)
        return true;
    return false;
}

void mergeH(RegistroHash* products, RegistroHash* vAux, int first, int middle, int last){
    int i = first, j = middle + 1, k = 0;
    while(i <= middle && j <= last){
        if(isGreaterOrEqual(products[i].qtdFilmes, products[j].qtdFilmes)){
            vAux[k] = products[i];
            i++;
        }
        else{
            vAux[k] = products[j];
            j++;
        }
        k++;
    }
    while(i <= middle) { // preenche vetor auxiliar caso tenha sobrado valores na parte inferior do vetor
        vAux[k] = products[i];
        k++;
        i++;
    }
    while(j <= last){ // preenche vetor auxiliar caso tenha sobrado valores na parte superior do vetor
        vAux[k] = products[j];
        k++;
        j++;
    }

    for(k = 0; k < last-first+1; k++) // transfere o vetor auxiliar para o original
        products[first+k] = vAux[k];
}

void mergeHashRec(RegistroHash* products, RegistroHash* vAux, int first, int last){
    if(first < last){
        int middle = (first + last) / 2;
        mergeHashRec(products, vAux, first, middle);
        mergeHashRec(products, vAux, middle+1, last);
        mergeH(products, vAux, first, middle,last);
    }
}

void mergeHash(RegistroHash* products, int n){
    auto* vAux = new RegistroHash[n];
    mergeHashRec(products, vAux, 0, n-1);
    delete [] vAux;
}

