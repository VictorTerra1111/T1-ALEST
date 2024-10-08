#include <iostream>
// codigo fila simplesmente encadeada do tipo inteiro, vou comentar onde precisa mudar para os tipos

using namespace std;

struct Node{ // nodo base

    Node * next;

    int data; // MUDAR AQUI PARA TIPO <------
    
    Node(int vdata){ // MUDAR AQUI PARA TIPO <------
        data = vdata;
        next = nullptr;
    }
};

class IntQueue{
    private:
        Node * head, * tail;
        int num;

    public:
        IntQueue(){ 
            head = tail = nullptr;
            num = 0;
        }

        ~IntQueue(){
            clear();
        }

        void clear(){
            while(head != nullptr){
                Node *aux = head;
                head = head->next;
                delete aux;
            }
            tail = nullptr;
            num = 0;
        }

        int size() const{ return num; }
        bool isEmpty() const{ if(num == 0) return true; return false; }

        void enqueue(const int e){ // MUDAR AQUI PARA TIPO <------
            Node * aux = new Node(e);
            if(num == 0) head = tail = aux;

            else{
                tail->next = aux;
                tail = aux;
            }
            ++num;
        }

        bool dequeue(int &e){ // MUDAR AQUI PARA TIPO <------
            if(num == 0) return false;

            e = head->data; 
            Node *aux = head;
            head = head->next;
            delete aux;
            --num;
            if(head == nullptr) tail = nullptr;

            return true;
        }

        bool head(int &e){ // MUDAR AQUI PARA TIPO <------
            if(num == 0) return false;

            e = head->data;
            return true;
        }

        string str() const{ // depende do exercicio
            return "";
        }
};