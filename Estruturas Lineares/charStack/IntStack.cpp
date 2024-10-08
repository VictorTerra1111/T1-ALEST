#include <iostream>
#include "IntStack.hpp"

IntStack::IntStack(int mxSz) {
  numElements = 0;   maxElements =  ( mxSz < 1 ) ? 10 : mxSz;
  stack = new char[maxElements];
}

IntStack::~IntStack() {  delete[] stack;  }

int IntStack::size() const { return numElements; }

int IntStack::maxSize() const { return maxElements; }

bool IntStack::isEmpty() const { return numElements == 0; }

bool IntStack::isFull() const { return numElements == maxElements; }

void IntStack::clear() { numElements = 0; }

bool IntStack::push(const char e) {
  if ( numElements == maxElements ) return false;
  else { stack[ numElements++ ] = e;  return true; }
}

bool IntStack::pop(char &e) {
  if ( numElements == 0 ) return false;
  else { e = stack[ --numElements ];  return true; }
}

bool IntStack::top(char &e) const {
  if ( numElements < 1 ) return false;
  else { e = stack[ numElements-1 ];  return true; }
}

string IntStack::str() const {
 int i;  stringstream ss;
  ss << "|";
  for (i=0; i<numElements; ++i) ss << stack[i] << "|";
  for (; i<maxElements; ++i) ss << " |";
  return ss.str();
}
