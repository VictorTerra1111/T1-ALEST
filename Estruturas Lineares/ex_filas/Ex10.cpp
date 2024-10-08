#include <iostream>
#include <string>
#include <sstream>

#include "Ex10.hpp"

using namespace std;

/* 
Usando como ponto de partida a classe IntQueue, apresentada anteriormente e
implementada usando alocação sequencial ou contígua, implemente a classe
IntLinkedQueue, que funciona da mesma forma, porém usando alocação encadeada.
Observações:
A versão usando alocação encadeada eliminará a necessidade de se trabalhar com um limite
máximo de elementos, consequentemente, os métodos maxSize() e isFull() NÃO farão
parte da nova implementação.
A definição da classe (arquivo IntLinkedQueue.hpp) e um programa de teste (arquivo
IntLinkedQueueMain.cpp) estão listados nas lâminas a seguir.
*/

IntLinkedQueue::IntLinkedQueue(){
    int numElements = 0;
    queueHead = queueTail = nullptr;
}
   
IntLinkedQueue::~IntLinkedQueue(){
    clear();
}
   
int IntLinkedQueue::size()const{
    return numElements;
}
   
bool IntLinkedQueue::isEmpty()const {
    if (numElements == 0) return true;
    else return false;
}
   
void IntLinkedQueue::enqueue(const int e){
    Node *aux = new Node(e);
    
    if( queueHead == nullptr){
            queueHead = queueHead = aux;
    }  
    
    else { 
        queueTail->next = aux; 
        queueTail = aux;
    }
    numElements++;
}

bool IntLinkedQueue::dequeue(int &e){
    if(numElements == 0) return false;

    e = queueHead->data;
    Node *aux = queueHead;
    queueHead = queueHead->next;
    delete aux;
    --numElements;
    
    if(queueHead == nullptr) queueTail = nullptr;
    
    return true;
}

bool IntLinkedQueue::head( int & e) const{
    return false;
}
   
void IntLinkedQueue::clear(){
    while ( queueHead != nullptr ){
        Node *aux = queueHead;
        queueHead = queueHead -> next;
        delete aux;
    }
    numElements = 0;
}
   
string IntLinkedQueue::str() const {
    Node *aux = queueHead;
    stringstream ss;
    ss << "|";

    while(aux != nullptr){
        ss << aux->data << "|";
        aux = aux->next;
    }
  
    return ss.str();
}