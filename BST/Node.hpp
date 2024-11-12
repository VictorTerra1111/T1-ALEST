#ifndef NODE_HPP
#define NODE_HPP


template <typename T>
struct Node
{
    T info;
    Node *right, *left, *parent;
    Node(T vinfo);
    ~Node();
};

#endif