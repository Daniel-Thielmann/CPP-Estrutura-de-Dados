#ifndef EDII_ARVOREVP_H
#define EDII_ARVOREVP_H

#include <iostream>
#include <cstring>
#include <chrono>

enum Color : bool {
    RED = true,
    BLACK = false
};

struct NodeVP {
    int movieId;  
    int binIndex;  // Localização no arquivo binário

    Color color;
    NodeVP *left, *right, *parent;

    NodeVP(int id, int binaryIndex = -1) : movieId(id), binIndex(binaryIndex), color(RED) {
        left = right = parent = nullptr;
    }

    ~NodeVP() {
        left = right = parent = nullptr;
    }

    int getId() const {
        return movieId;
    }

    void print() const {
        std::cout << "Movie ID: " << movieId;
        if (color)
            std::cout << " (VERMELHO)" << std::endl;
        else
            std::cout << " (PRETO)" << std::endl;
    }

    bool operator<(const NodeVP& n) const {
        return movieId < n.movieId;
    }

    bool operator<=(const NodeVP& n) const {
        return movieId <= n.movieId;
    }

    bool operator>(const NodeVP& n) const {
        return movieId > n.movieId;
    }
};

class ArvoreVP {

private:
    NodeVP *root;

    // Busca e Inserção
    NodeVP* auxInsere(NodeVP* p, NodeVP *newNode, long int& comparisons);
    NodeVP* auxBusca(NodeVP* p, int movieId, long int& comparisons);
    
    // Balanceamento da árvore
    void rotateLeft(NodeVP* P);
    void rotateRight(NodeVP* P);
    void fixViolation(NodeVP* node);
    
    // Liberação de memória
    NodeVP* free(NodeVP* node);
    // Auxiliar Percurso
    void inOrder(NodeVP* root);

public:
    ArvoreVP() : root(nullptr) {}
    ~ArvoreVP();

    void insere(int movieId, int binIndex, long int& comparisons);
    NodeVP* busca(int movieId, long int& comparisons);
    void print();
};

#endif EDII_ARVOREVP_H
