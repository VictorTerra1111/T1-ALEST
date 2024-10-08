#include <iostream> //nao possui .hpp
// codigo pilha duplamente encadeada do tipo inteiro, vou comentar onde precisa mudar para os tipos

using namespace std;

struct Node{ // nodo base

    Node * next;
    Node * prev;

    int data; // MUDAR AQUI PARA TIPO <------
    
    Node(int vdata){ // MUDAR AQUI PARA TIPO <------
        data = vdata;
        next = prev = nullptr;
    }
};

class IntStack{
    private:
        Node * head;
        int num;
        int max;

    public:
        IntStack(int vmax = 10){ // mudar aqui para tamanho minimo 
            max = vmax;
            head = nullptr;
            num = 0;
        }
        ~IntStack(){
            clear();
        }
        void clear(){
            while(head != nullptr){
                Node *aux = head;
                head = head->next;
                delete aux;
            }
            num = 0;
        }
        void push(const int e){ // MUDAR AQUI PARA TIPO <------
            Node *aux = new Node(e);
            aux->next = head;
            if(head != nullptr)
                head->prev = aux; // atualiza prev e next
            
            head = aux;
            ++num;
        }

        bool pop(int &e){ // MUDAR AQUI PARA TIPO <------
            if(!num) return false;
            e = head->data;
            --num;
            Node *aux = head;
            head = head->next;
            if(head != nullptr){
                head->prev = nullptr;
            }

            delete aux;

            return true;
        }

        bool top(int &e) const{ // MUDAR AQUI PARA TIPO <------
            if(!num) return false;
            e = head->data;
            return true;
        }

        int size() const{
            return num;
        }
        int maxSize() const{ return max;}
        
        bool isEmpty() const{
            if(num == 0) return true;
            return false;
        }
        bool isFull() const{
            if(num == max) return true;
            return false;
        }
        string str() const{ // depende do exercicio
            return "";
        }
};

int main(){ // para testar pilha
    int max;
    cin >> max;
    IntStack stack(max); // cria stack

 
    cout << "comecando looping para teste de metodos" << endl;

    int valor;
    for(int i = 0; i < max; i++){
        cout << "i = " << i << endl;
        
        cout << stack.isEmpty() << endl;

        stack.push(i);
        cout << "push" << endl;

        stack.top(valor);
        cout << valor << endl;
        cout << stack.size() << endl;
 
        cout << stack.maxSize() << endl;
        cout << stack.isEmpty() << endl;
        cout << stack.isFull() << endl;
    }
    return 0;
}
