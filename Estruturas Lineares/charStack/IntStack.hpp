#ifndef _INTSTACK_HPP
#define _INTSTACK_HPP

#include <string>

using namespace std;

class IntStack {
private:
  int numElements;
  int maxElements;
  char *stack;
public:
  IntStack(int mxSz = 10);
  ~IntStack();
  int size() const;
  int maxSize() const;
  bool isEmpty() const;
  bool isFull() const;
  void clear();
  bool push(const char e);
  bool pop(char &e);
  bool top(char &e) const;
  string str() const; // APENAS PARA DEPURACAO
};
#endif
