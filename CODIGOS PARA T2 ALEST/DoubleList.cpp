#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
    Node(int i){
        data = i; next = prev = nullptr;
    }
};

template <typename T> // List<int> list(tamanho_maximo); gera um arraylist do tipo especificado

class DoubleList {
private: 
    int num;
    Node * head, * tail;
public:
    DoubleList() { // construtor
        num = 0;
        head = tail = nullptr;
    }

    ~DoubleList() { // so chama clear
        clear();
    }

    void clear() { 
        while(head != nullptr){
                Node *aux = head;
                head = head->next;
                delete aux;
                tail = nullptr;
        }
        num = 0;
    }

    int size() const { return num; }
    bool isEmpty() const { return num == 0; }

    bool add(const T e) {
        if (isFull()) return false;
      //alterar
        return true;
    }

    bool add(const int index, const T e) { 
        //alterar
        return true;
    }

    bool get(const int index, T &e) { 
        //alterar
        return true;
    }
    
    bool set(const int index, const T &e) { 
        //alterar
        return true;
    }

    bool remove(int index) {
        return true;
    }

    bool contains(const T e) {  // pesquisa linear na lista
        return false;
    }

    int indexOf(const int pos, const T e) { // pesquisa linear a partir da posicao fornecida 

        return 0; 
    }

    int indexOf(const T e) { // retorna indice com pesquisa linear
        return indexOf(0, e);
    }

    void reverse(Node ** head, Node ** tail ){
        
    }
};

