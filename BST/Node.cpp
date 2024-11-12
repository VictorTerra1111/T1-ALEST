#include <iostream>
#include "Node.hpp"

using namespace std;

template <typename T>
Node::Node(T vinfo)
{
    right = left = parent = nullptr;
    info = vinfo;
}

Node::~Node()
{
    cout << "deletando nodo..." << endl;
}