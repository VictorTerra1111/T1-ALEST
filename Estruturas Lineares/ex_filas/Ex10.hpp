#ifndef EX10_HPP
#define EX10_HPP

#include <string>

using namespace std;

class IntLinkedQueue{
    private:
        int numElements;
        struct Node{
            int data ;
            Node * next ;
            Node ( int d) { data = d; next = nullptr ; }
        };
        
        Node * queueHead , * queueTail ;
   
    public:
        IntLinkedQueue();
   
        ~ IntLinkedQueue();
   
        int size() const ;
   
        bool isEmpty() const ;
   
        void enqueue( const int e );
   
        bool dequeue( int & e );
   
        bool head( int & e) const ;
   
        void clear();
   
        string str() const ; // APENAS PARA DEPURACAO
};

# endif