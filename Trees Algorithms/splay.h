#ifndef SPLAY_H__
#define SPLAY_H__

#include "splay_node.h"
/**
 *  Tipo abstrato de dados para uma árvore Splay
 *  
 * 
 */
template <typename T>
class SplayTree
{   

    public:
        SplayTree();                     
        void           insert(T key);
        void           remove(T key);
        SplayNode<T>*  max();
        SplayNode<T>*  min();
        SplayNode<T>*  find(T key);
        void           print_tree();
        void           print_in_order();
        bool           is_empty(){return root == nullptr;};
        T              get_root_key(){ return root->key;}
        ~SplayTree();
    private:
        // Funções auxiliares
        void print_tree(SplayNode<T>* node, const std::string& prefix, bool isLeft, std::ostream& out);
        void print_in_order(SplayNode<T>* node, std::ostream& out);

        void rotateLeft(SplayNode<T> *node);
        void rotateRight(SplayNode<T> *node);
        void splay(SplayNode<T> *node);
        void clean(SplayNode<T> *node);
        //SplayNode<T>* remove_key(SplayNode<T> *r, T key);

        // Ponteiro para o no raiz da arvore
        SplayNode<T> *root;
};

/*
   Implement the SplayNode class
*/

// Cria um SplayTree vazia
template <typename T>
SplayTree<T>::SplayTree(): root(nullptr)
{ }

// Implementação da rotina de Rotação à Esquerda
/*
       Y                             X     
      / \        rotate left        / \    
     X   ^      <------------      ^   Y   
    / \ /C\                       /A\ / \  
   ^  ^                               ^  ^ 
  /A\/B\                             /B\/C\
  */
 
template <typename T>
void SplayTree<T>::rotateLeft(SplayNode<T> *x)
{
    SplayNode<T> *y = x->right;
    if(y == nullptr)
        return;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;   
   
}

/*
    Implementação da rotina de Rotação à Direita
       Y                             X     
      / \                           / \    
     X   ^                         ^   Y   
    / \ /C\                       /A\ / \  
   ^  ^         ------------>         ^  ^ 
  /A\/B\         rotate right        /B\/C\

*/ 
template <typename T>
void SplayTree<T>::rotateRight(SplayNode<T> *y) {
    SplayNode<T> *x = y->left;
    if(x == nullptr)
        return;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

// Implemente a rotina de splay. 
// O parâmetro node é o nó que deve ser splayado.
template <typename T>
void SplayTree<T>::splay(SplayNode<T> *x)
{
    while (x->parent != nullptr)
    {
        if (x->parent->parent == nullptr) // X é filho direto da raiz
        {
            if (x == x->parent->left)
                rotateRight(x->parent);
            else
                rotateLeft(x->parent);
        }
        else
        {
            SplayNode<T> *p = x->parent;
            SplayNode<T> *g = p->parent;
            
            if (x == p->left && p == g->left)
            {
                rotateRight(g);
                rotateRight(p);
            }
            else if (x == p->right && p == g->right)
            {
                rotateLeft(g);
                rotateLeft(p);
            }
            else if (x == p->right && p == g->left)
            {
                rotateLeft(p);
                rotateRight(g);
            }
            else if (x == p->left && p == g->right)
            {
                rotateRight(p);
                rotateLeft(g);
            }
        }
    }
}

// Implemente a rotina de busca
template <typename T>
SplayNode<T>* SplayTree<T>::find(T key)
{
    SplayNode<T> *node = root;
    SplayNode<T> *parent = nullptr;
    while (node != nullptr && node->key != key)
    {
        parent = node;
        if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }

    if(node == nullptr)
    {
        if(parent != nullptr)
            this->splay(parent);
    }
    else
        this->splay(node);
    return node;
}

// Implemente a rotina de inserção
template <typename T>
void SplayTree<T>::insert(T key)
{
    SplayNode<T> *node = new SplayNode<T>(key);
    SplayNode<T> *x    = root;
    SplayNode<T> *y    = nullptr;
    while(x != nullptr)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    node->parent = y;
    if (y == nullptr)
        root = node;
    else if (key < y->key)
        y->left = node;
    else
        y->right = node;
    this->splay(node);

}

// Retorna o nó que contem a maior chave
template <typename T>
SplayNode<T>* SplayTree<T>::max()
{
    SplayNode<T> *node = root;
    if(node == nullptr)
        return nullptr;
    while (node->right != nullptr)
        node = node->right;
    return node;
}

// Retorna o nó que contem a menor chave
template <typename T>
SplayNode<T>* SplayTree<T>::min()
{
    SplayNode<T> *node = root;
    if(node == nullptr)
        return nullptr;
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <typename T>
void SplayTree<T>::remove(T key)
{
    if (root == nullptr)
        return;

    // Splay the key to the root
    SplayNode<T> *node = find(key);

    if (node == nullptr || node->key != key)
        return; // Key não encontrada

    SplayNode<T> *leftSubtree = root->left;
    SplayNode<T> *rightSubtree = root->right;

    delete root;

    if (leftSubtree != nullptr)
    {
        leftSubtree->parent = nullptr;
        root = leftSubtree;

        SplayNode<T> *maxNode = max();
        splay(maxNode);
        root->right = rightSubtree;
        if (rightSubtree != nullptr)
            rightSubtree->parent = root;
    }
    else
    {
        root = rightSubtree;
        if (rightSubtree != nullptr)
            rightSubtree->parent = nullptr;
    }
}


template <typename T>
void SplayTree<T>::print_tree(SplayNode<T>* node, const std::string& prefix, bool isLeft, std::ostream& out)
{
    
    
    out << prefix;
    out << (isLeft ? "├──" : "└──" );

    // print the value of the node
    if(node == nullptr)
    {
        out << "[null]" << std::endl;
        return;
    }
    out <<"["<<node->getKey()<<"]" << std::endl;

    print_tree(node->getLeft() , prefix + (isLeft ? "│   " : "    "), true, out);
    print_tree(node->getRight(), prefix + (isLeft ? "│   " : "    "), false, out);
}

template <typename T>
void SplayTree<T>::print_in_order(SplayNode<T>* node, std::ostream& out)
{
    if(node == nullptr)
        return;
    print_in_order(node->left, out);
    out << node->key << " ";
    print_in_order(node->right, out);
}


template <typename T>
void SplayTree<T>::print_in_order()
{
    print_in_order(root, std::cout);
    std::cout << std::endl;
}

template <typename T>
void SplayTree<T>::print_tree()
{
    print_tree(root, "", false, std::cout);
    std::cout << std::endl;
}

template <typename T>
void SplayTree<T>::clean(SplayNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }
    clean(node->left);
    clean(node->right);
    delete node;
}

template <typename T>
SplayTree<T>::~SplayTree()
{
    clean(root);
    root = nullptr;
}



#endif /* SPLAY_H__ */
