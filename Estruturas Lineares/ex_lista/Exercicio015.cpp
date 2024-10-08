#include <iostream>

using namespace std ;

struct Node {
    char info ; Node * next ;
    Node ( char i) { info = i ; next = nullptr ; cout << "+ Node (" << info << ") criado ... " << endl ; }
    ~ Node () { cout << "- Node (" << info << ") destruido ... " << endl ; }
};
int main () {
    string s = " ADCBE "; Node * head = nullptr , * tail = nullptr ; // Criação
    for ( int i =0; i <s . length (); ++ i) {
        Node * aux = new Node ( s[ i] );
        
        if ( tail == nullptr ) { head = tail = aux ; }
        
        else { tail -> next = aux ; tail = aux ; }
    }

    // Coloque a solu ção aqui !
    /* 
    pesquisa linear (primeiro com o segundo)
    crio um ponteiro aux que aponta pro head
    comparo a informacao de aux < aux->next
        se for 
            cria um nodo para salvar informacao
            copia a informacao do nodo
            
        se nao for:
            aux = aux->next (aux aponta pro proximo)
    
    */
    // fim da solucao

    cout << "head -- > "; // Exibição
    for ( Node * aux = head ; aux != nullptr ; aux = aux -> next )
    cout << "|" << aux -> info << ( aux -> next == nullptr ?"|X| ":"|| -> ");
    cout << " <--tail " << endl ;
    while ( head != nullptr ) { Node * aux = head ; head = head -> next ; delete aux ; } // Desaloca ção
    return 0;
}