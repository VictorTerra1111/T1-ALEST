#ifndef _INTLINKEDSTACK_HPP
#define _INTLINKEDSTACK_HPP
#include <string>

using namespace std;

class IntLinkedStack {
    private:

        int numElements;
        struct Node{
            int data;
            Node * next;
            Node(int d){data = d; next = nullptr;}
        };

        Node * stack;

    public :

        IntLinkedStack();
        ~ IntLinkedStack();
        void push(const int e);
        bool pop(int &e);
        bool top(int &e)const;
        int size()const;
        bool isEmpty()const;
        void clear();
        string str()const; // APENAS PARA DEPURACAO
};

# endif