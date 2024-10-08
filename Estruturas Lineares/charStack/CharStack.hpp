#ifndef _CHARSTACK_HPP
#define _CHARSTACK_HPP

#include <string>

using namespace std;

class CharStack {
private:
  int numElements;
  int maxElements;
  char *stack;
public:
  CharStack(int mxSz = 10);
  ~CharStack();
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