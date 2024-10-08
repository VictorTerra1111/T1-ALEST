#include <iostream>

using namespace std;

/*
Usando como modelo o programa da lâmina anterior, construa em C++ a seguinte lista
duplamente encadeada. Percorra a lista, mostrando o conteúdo de seus nodos, tanto do
início para o fim, quanto do fim para o início.
*/

struct Node {
    char info;
    
    Node * next;
    Node * prev;

    Node(char i){
        info = i; next = nullptr ; prev = nullptr;
        cout << "+ Node (" << info << ") criado ... " << endl;
    }

    ~Node(){
        cout << "- Node (" << info << ") destruido ... " << endl;
    }
};

int main (){
    int tam;
    cout << "tamanho da pilha: " << endl;
    cin >> tam;
    
    Node * topo = nullptr;
    Node * base = nullptr;

    for(int i = 0; i < tam; i++ ){
        Node * novo = new Node('A' + i);
        
        if(topo != nullptr){
            topo->prev = novo;
            novo->next = topo;
        }
        else{
            base = novo;
        }
        topo = novo;
    }

    while ( topo != nullptr ){
        Node *aux = topo;
        topo = topo -> next;
        delete aux;
    }

    return 0;
}
