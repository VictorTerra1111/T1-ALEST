#include <iostream>
#include "BST.hpp"
#include <string>

using namespace std;

template <typename T>
BST()
{
    root = nullptr;
}

template <typename T>
~BST()
{
    if (root != nullptr)
        delete root;
}

template <typename T>
string strGraphViz() const
{
    if (root == nullptr)
        return "";
    return root->strGraphViz();
}

template <typename T>
void add(const T &e)
{
    Node<T> aux = root;
    while (aux->info < e){
        // terminar - tem que ser recursivo
    }
}

template <typename T>
bool contains(const T &e)
{
    Node<T> aux = root;
    while (aux->info != e)
    {
        if (aux->info > e)
            aux = aux->left;
        else if (aux->info < e)
            aux = aux->right;
        else if(root == nullptr)
            return false;
    }

    return true;
}
