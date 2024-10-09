#include <iostream>
// código fila duplamente encadeada generica 

using namespace std;

struct Node { // nodo base
    Node *next;
    Node *prev; // antes e depois
    int data; 
    
    Node(int vdata) { 
        data = vdata;
        next = prev = nullptr; // inicializa os dois
    }
};

class IntQueue {
private:
    Node *head, *tail; // Usar Node<T>
    int num;
    int max;

public:
    IntQueue(int vmax = 10) {  // ver tamanho máximo
        max = vmax;
        head = tail = nullptr;
        num = 0;
    }

    ~IntQueue() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node *aux = head;
            head = head->next;
            delete aux;
        }
        tail = nullptr;
        num = 0;
    }

    int size() const { return num; }
    bool isEmpty() const { return num == 0; }
    bool isFull() const { return num == max; }

    bool addFirst(const int e) { 
        if (num == max) return false;
        
        Node *aux = new Node(e); 
        if (num == 0) head = tail = aux;
        else {
            aux->next = head;
            head->prev = aux;
            head = aux;
        }            
        ++num;
        return true;
    }
    
    bool addLast(const int e) { 
        if (num == max) return false;
        
        Node*aux = new Node(e);
        if (num == 0) head = tail = aux;
        else {
            aux->prev = tail;
            tail->next = aux;
            tail = aux;
        }            
        ++num;
        return true;
    }

    bool removeFirst(int &e) { 
        if (num == 0) return false;
        
        e = head->data; 
        
        Node *aux = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        else head->prev = nullptr;
        
        delete aux;

        --num;
        return true;
    }
    
    bool removeLast(int &e) { 
        if (num == 0) return false;
        
        e = tail->data; 
        Node *aux = tail;
        tail = tail->prev;
        if (tail == nullptr) head = nullptr;
        else tail->next = nullptr;
        
        delete aux;

        --num;
        return true;
    }

    bool first(int &e) { 
        if (num == 0) return false;

        e = head->data;
        return true;
    }

    bool last(int &e) { 
        if (num == 0) return false;

        e = tail->data;
        return true;
    }

    string str() const { // ver como o professor pedir
        return "";
    }
};
