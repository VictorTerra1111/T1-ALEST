#include <iostream>
#include "StringDoubleLinkedStack.hpp"

using namespace std;

StringDoubleLinkedStack::StringDoubleLinkedStack(int vmax){ // CONSTRUTOR INICIALIZA AS VARIAVEIS E RECEBE TAMANHO MAXIMO, CRIA STACK COM NEW 
    if(vmax < 1) maxElements = 10;
    maxElements = vmax;
    numElements = 0;
    stack = new string[maxElements];
}

StringDoubleLinkedStack::~StringDoubleLinkedStack(){ // DESTRUTOR CHAMA FUNCAO CLEAR QUE DA DELETE STACK
    clear();
}

bool StringDoubleLinkedStack::push(string e){ // PUSH COLOCA ELEMENTO NO STACK 
    if(numElements >= maxElements) return false; // VERIFICA SE AINDA PODE COLOCAR ELEMENTOS

    Node *aux = new Node(e); // CRIA UM AUXILIAR COM A INFORMACAO
    if(numElements == 0) head = tail = aux; numElements++; return true; // SE FOR VAZIO, OS PONTEIROS APONTAM PRO AUXILIAR E O NUMERO DE ELEMENTOS FICA +1 (1)
 
    aux->prev = tail; // SE NAO TIVER VAZIO, O ANTERIOR DELE APONTA PRA TAIL (BASE)
    tail->next = aux; // E O PROXIMO DE TAIL APONTA PRO AUX 
    tail = aux; // E MUDA TAIL DE LUGAR (AGORA A BASE EH O AUXILIAR NOVO), AGORA ESTAO ENCADEADOS 
    return true; //FUNCIONOU 
}

bool StringDoubleLinkedStack::top(string& e) const{ // VE O DE CIMA 
    if(numElements == 0) return false; // MESMA COISA QUE POP SÓ PASSA O VALOR POR REFERENCIA
    e = stack[numElements -1];
    return true;
}

bool StringDoubleLinkedStack::pop(string& e){
    if(numElements == 0) return false; //UNICA DIFERENCA EH QUE POP TIRA O ELEMENTO
    e = stack[numElements -1];
    numElements--;
    return true;
}

int StringDoubleLinkedStack::size() const{ // RETORNA NUMERO
    return numElements;
}

int StringDoubleLinkedStack::maxSize() const{ // RETORNA MAXIMO DE NUMERO
    return maxElements;
}

bool StringDoubleLinkedStack::isEmpty() const{ // VE SE TA VAZIO 
    if(numElements == 0) return true;
    return false;
}

bool StringDoubleLinkedStack::isFull() const{ // VE SE TA CHEIO
    if(numElements == maxElements) return true;
    return false;
}

void StringDoubleLinkedStack::clear(){ // DELETA STACK
    delete[] stack;
}