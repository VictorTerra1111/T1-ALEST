#ifndef STRING_DOUBLE_LINKED_STACK_HPP
#define STRING_DOUBLE_LINKED_STACK_HPP
#include <string>
using namespace std;

struct Node{
    string data;
    Node *next;
    Node *prev;

    Node(string vdata){
        data = vdata;

        prev = nullptr;
        next = nullptr;
    }

};

class StringDoubleLinkedStack{
    private:
        int numElements;
        int maxElements;
        Node *head, *tail;


        string *stack;

    public:
        StringDoubleLinkedStack(int vmax = 10);
        ~StringDoubleLinkedStack();

        bool push(string e);
        bool top(string& e) const;
        bool pop(string& e);
        int size () const;
        int maxSize() const;
        bool isEmpty() const;
        bool isFull() const;
        void clear();
};

#endif