#include <iostream>
#include "IntLinkedStack.hpp"

using namespace std;

void print ( IntLinkedStack & stack ) {
  cout << " " << stack . str () << " size =" << stack . size () << " top =";
  int t; bool res = stack . top ( t );
  if ( res ) cout << t; else cout << "X";
  cout << " isEmpty =" << stack . isEmpty () << endl ;
}

int main () {
  int vet [] = {0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
  int numElements = sizeof ( vet )/ sizeof ( int );
  IntLinkedStack stack ;
  cout << " "; print ( stack );

  for ( int i =0; i < numElements ; ++ i) {
    cout << " push (" << vet [i ] << "): ";
    stack . push ( vet [i ] );
    print ( stack );
  }

  for ( int i =0; i < numElements +1; ++ i ) {
    int e;
    bool res = stack . pop ( e );
    if ( ! res ) cout << " pop (X): ";
    else cout << " pop(" << e << "): ";
    print ( stack );
  }

  return 0;
}