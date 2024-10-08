#include <iostream>
using namespace std;
struct Node {
  char info;  Node *next;
  Node(char i) {  info = i;  next = nullptr;  cout << "+ Node(" << info << ") criado..." << endl;  }
  ~Node() {  cout << "- Node(" << info << ") destruido..." << endl;  }
};

int main() {
  Node *head = nullptr, *tail = nullptr;  // Criação
  for (char l='B'; l<='F'; l++) {
      if (l == 'D') continue; // Evita que o Node com a info 'D' seja inserido na lista...
      
      Node *aux = new Node(l);
      
      if ( tail == nullptr ) {  head = tail = aux;  }
      else {  tail->next = aux;  tail = aux;  }
  }

  // Coloque a solução aqui!
  
  Node *nodeA = new Node('A'); //insercao no inicio
  nodeA->next = head; // faz o nodeA agora ser head (inicio)
  head = nodeA; // faz o ponteiro head apontar para nodeA
  
  Node *nodeG = new Node('G'); //insercao no final
  tail->next = nodeG; // faz o nodeG agora ser tail (fim)
  tail = nodeG; // faz o ponteiro tail apontar para nodeG
  
  Node *nodeD = new Node('D'); //insercao no meio
  Node *aux = head, *ant = nullptr;
  while(aux != nullptr && nodeD->info > aux->info){
    ant = aux;
    aux = aux->next;
  }
  ant->next = nodeD;
  nodeD->next = aux;

  // Fim da solução

  cout << "head--> ";  // Exibição
  for (Node *aux = head; aux != nullptr; aux = aux->next)
      cout << "|" << aux->info << (aux->next==nullptr?"|X| ":"|| -> ");
  cout << " <--tail" << endl;
  while ( head != nullptr ) {  Node *aux = head;  head = head->next;  delete aux;  }  // Desalocação
  return 0;	
}
