#include "ArvoreVP.h"
#include <iostream>
#include <chrono>

// Percurso in-order
void ArvoreVP::inOrder(NodeVP* root) {
    if (root == nullptr)
        return;
    
    inOrder(root->left);
    root->print();  
    inOrder(root->right);
}

// Imprimir a árvore in-order
void ArvoreVP::print() {
    inOrder(root);  
}

// Auxiliar de Inserção
NodeVP* ArvoreVP::auxInsere(NodeVP* root, NodeVP* novoNo, long int& comparisons) {
    if (root == nullptr) {
        return novoNo;  // Caso base, onde o nó será inserido
    }

    comparisons++;  
    if (novoNo->getId() < root->getId()) {
        root->left = auxInsere(root->left, novoNo, comparisons);
        root->left->parent = root;
    } else if (novoNo->getId() > root->getId()) {
        root->right = auxInsere(root->right, novoNo, comparisons);
        root->right->parent = root;
    }

    return root;
}

// Inserção
void ArvoreVP::insere(int movieId, int binIndex, long int& comparisons) {
    NodeVP* novoNo = new NodeVP(movieId, binIndex);  // Criação de um novo nó
    root = auxInsere(root, novoNo, comparisons);
    fixViolation(novoNo);  // Corrige violações
}

// Auxiliar de busca
NodeVP* ArvoreVP::auxBusca(NodeVP* root, int movieId, long int& comparisons) {
    if (root == nullptr || root->getId() == movieId) {
        return root;
    }

    comparisons++;  
    if (movieId < root->getId()) {
        return auxBusca(root->left, movieId, comparisons);
    }
    return auxBusca(root->right, movieId, comparisons);
}

// Busca
NodeVP* ArvoreVP::busca(int movieId, long int& comparisons) {
    return auxBusca(root, movieId, comparisons);
}

// Corrige violações das propriedades VP após a inserção
void ArvoreVP::fixViolation(NodeVP* node) {
    NodeVP* parent = nullptr;
    NodeVP* grandparent = nullptr;

    while (node != root && node->color == RED && node->parent != nullptr && node->parent->color == RED) {
        parent = node->parent;
        grandparent = node->parent->parent;
        if (grandparent == nullptr) break;  // Verifique se grandparent não é nullptr

        if (parent == grandparent->left) {
            NodeVP* tio = grandparent->right;

            if (tio != nullptr && tio->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                tio->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        } else {
            NodeVP* tio = grandparent->left;

            if (tio != nullptr && tio->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                tio->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

void ArvoreVP::rotateLeft(NodeVP* node) {
    NodeVP* rightChild = node->right;
    node->right = rightChild->left;

    if (node->right != nullptr) {
        node->right->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void ArvoreVP::rotateRight(NodeVP* node) {
    NodeVP* leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != nullptr) {
        node->left->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    } else if (node == node->parent->left) {
        node->parent->left = leftChild;
    } else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

// Destrutor 
ArvoreVP::~ArvoreVP() {
    root = free(root);  // Libera todos os nós da árvore
}

// Liberar memória
NodeVP* ArvoreVP::free(NodeVP* node) {
    if (node == nullptr)
        return nullptr;

    free(node->left);
    free(node->right);
    delete node;

    return nullptr;
}

