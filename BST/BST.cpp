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
}

template <typename T>
bool contains(const T &e)
{
    bool achou = false;
    Node<T> aux = root;
    while (aux->info != e)
    {
        if (aux->info > e)
            aux = aux->left;
        else
            aux = aux->right;
        if (aux == nullptr)
            break;
    }
    return true;
}
