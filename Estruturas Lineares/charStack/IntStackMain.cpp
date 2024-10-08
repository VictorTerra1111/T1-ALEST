#include <iostream>
#include "IntStack.hpp"

using namespace std;

void print(IntStack &stack) {
  cout << "  " << stack.str() << "  size=" << stack.size() << "/" << stack.maxSize() << "  top=";
  char t;   bool res = stack.top(t);
  if (res) cout << t; else cout << "X";
  cout << "  isEmpty=" << stack.isEmpty() << "  isFull=" << stack.isFull() << endl;
}

int main() {
  char e;
  bool res;
  cout << "IntStack(4): ";  IntStack stack(4);  print(stack);
  e = 'a';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
 e = 'b';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 'c';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 'd';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = 'e';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = 'f';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(X):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 'g';  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  cout << "clear(): OK  ";  stack.clear();  print(stack);
  return 0;
}

