#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"

template <typename T>
class BST
{
private:
    Node<T> *root;
public:
    BST();
    ~BST();
    string strGraphViz() const;
    void add(const T &e);
    bool contains(const T &e);
};

#endif