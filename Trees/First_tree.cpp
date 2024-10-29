#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    char info;
    Node *child1, *child2, *child3;

    Node(char i, Node *c1 = nullptr, Node *c2 = nullptr, Node *c3 = nullptr){
        info = i;
        child1 = c1;
        child2 = c2;
        child3 = c3;
        cout << "+ Node (" << info << ") criado ... " << endl;
    }
    
    ~Node() { cout << "- Node (" << info << ") destruido ... " << endl; }
};

string strGraphViz ( Node * root ) {
    stringstream ss; 
    ss << "graph \"Arvore\" \{" << endl;
    ss << " node [shape = circle ]" << endl;

    if(root->child1 != nullptr) ss << root->info << " -- {" << root->child1->info << " ";
    if(root ->child2 != nullptr) ss << root->child2->info << " ";
    if(root ->child3 != nullptr) ss << root->child3->info << "}";
    ss << strGraphViz(root->child1);
    ss << "}" << endl;
    
    return ss.str();
}

int main(){
    Node *b = new Node('B'), *e = new Node('E'),
         *f = new Node('F'), *g = new Node('G');          // Cria folhas
    Node *c = new Node('C', e, f), *d = new Node('D', g); // Cria intermediarios
    Node *root = new Node('A', b, c, d);                  // Cria raiz
    
    cout << strGraphViz(root) << endl;
    delete b; delete e; delete f; delete g ; // Desaloca folhas
    delete c; delete d; // Desaloca intermediarios
    delete root ;
    return 0;
}
