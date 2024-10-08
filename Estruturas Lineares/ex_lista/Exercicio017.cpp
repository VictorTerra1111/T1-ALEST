#include <iostream>

using namespace std;

struct Node {
    int info; 
    Node * next;

    Node ( int i) {
        info = i; next = nullptr;
        cout << "+ Node (" << info << ") criado ... " << endl;
    }

    ~Node() {
        cout << "- Node (" << info << ") destruido ... " << endl; 
    }
};

void reverse ( Node ** head , Node ** tail ) {
    Node * newHead = nullptr , * newTail = nullptr; // cria novos ponteiros

    while ( *head != nullptr ) { // laço ate o final da lista
        Node * aux = * head; // cria nodo auxiliar e faz apontar para head (que veio de parametro) 
        *head = (* head)->next; // atualiza o head para o proximo
        if(newHead == nullptr){ 
            newHead = newTail = aux;
            aux->next= nullptr; 
        }
        else{
            aux->next = newHead; // agora o proximo do auxiliar eh newHead (da lista nova) 
            newHead = aux; // agora aux vai pra frente
        }
    }

    *head = newHead; // ponteiros head e tail recebem os ponteiros da nova lista
    *tail = newTail;
}

int main () {
    Node * head = nullptr , * tail = nullptr ; // inicializa ponteiros para head e tail
    for ( int i =10; i <=50; i +=10) { // Insere 10 , 20 , 30 , 40 , 50 pelo final da lista
        Node * aux = new Node ( i );
        if ( tail == nullptr ) { head = tail = aux ; }
        else { tail -> next = aux ; tail = aux ; }
    }
    
    reverse (& head , & tail );
    
    cout << "head -- > "; // Exibi ção a partir do início : 50 , 40 , 30 , 20 , 10
    
    for ( Node * aux = head ; aux != nullptr ; aux = aux -> next )
        cout << "|" << aux -> info << ( aux -> next == nullptr ?"|X| ":"|| -> ");
    
    cout << " <--tail " << endl;
    
    while ( head != nullptr ) {
        Node * aux = head;
        head = head -> next;
         delete aux;
    } // Desaloca ção
    
    return 0;
}