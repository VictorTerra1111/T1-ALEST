#include <iostream>
#include <string>
// codigo para lista duplamente encadeada com menu no terminal (possivel questao t2)
using namespace std;

struct Node{
    string data;
    Node *next, *prev;
    //    Node * prev;
    Node(string i){
        data = i;
        next = nullptr;
    }
};


class List {
private: 
    int num;
    Node * head, * tail;

public:
    List() { // construtor
        num = 0;
        head = tail = nullptr;
    }

    ~List() { // so chama clear
        clear();
    }

    void clear() { 
        while (head != nullptr) {
            Node *aux = head;
            head = head->next;
            delete aux;
        }
        tail = nullptr;
        num = 0;
    }

    int size() const { return num; }
    bool isEmpty() const { return num == 0; }



    bool add(const string e) {
        Node *novo = new Node(e); // Cria Node com o valor 'e'.
        if (head == nullptr) {     // se tiver vazio
            head = tail = novo;
        } else {                   // se nao, adicional no final
            tail->next = novo;
            novo->prev = tail;
            tail = novo;
        }

        num++; 
        return true;
    }

    bool add(const int index, const string e) { 
        if (index < 0 || index > num) return false;

        Node *novo = new Node(e);

        if (index == 0) { // Inserção no início
            novo->next = head;
            if (head != nullptr) { // Se a lista não estiver vazia
                head->prev = novo;
            } else { 
                tail = novo; // Se a lista estava vazia
            }
            head = novo; // Atualiza o head para o novo node
        } 
        else {
            Node *auxPrev = head; // Ponteiro auxiliar para a posição anterior ao índice
            Node *auxNext = head->next; // Ponteiro auxiliar para a posição seguinte

            // Percorre a lista até encontrar a posição antes do índice desejado
            for (int i = 0; i < index - 1; i++) {
                auxPrev = auxPrev->next;
                auxNext = auxPrev->next;
            }

            // Insere o novo nó na posição correta
            novo->next = auxNext; 
            novo->prev = auxPrev;
            auxPrev->next = novo;

            if (auxNext != nullptr) { //se nao for no final
                auxNext->prev = novo;
            } else {
                tail = novo; // se for no final
            }
        }
        
        num++; 
        return true;
    }


    bool get(const int index, string &e) { 
        if (index < 0 || index >= num) return false; // Índice inválido

        Node *aux = head; //ponteiro auxiliar 
        for (int i = 0; i < index; i++) aux = aux->next; // Avança até o índice
        e = aux->data; //passa o valor do indice por referencia
        return true;
    }
    
    bool set(const int index, const string &e) { 
        if (index < 0 || index >= num) return false; // Índice inválido

        Node *aux = head;
        for (int i = 0; i < index; i++) aux = aux->next; // Avança até o índice
        aux->data = e;
        return true;
    }

    bool remove(int index) {
        if (index < 0 || index >= num) return false; 

        Node *aux; // Ponteiro auxiliar 
        
        if (index == 0) { // remove no início
            aux = head;
            head = head->next;
            if (head != nullptr) { // Se a lista não ficar vazia
                head->prev = nullptr;
            } else {
                tail = nullptr; // Se a lista ficar vazia
            }
        } 

        else if (index == num - 1) { // Remoção no final, ja vai para tail
            aux = tail;
            tail = tail->prev;
            tail->next = nullptr;
        }

        else { // Remoção no meio
            Node *prev = head;

            for (int i = 0; i < index - 1; i++) {
                prev = prev->next; // vai ate a posicao anterior da remocao
            }
            
            aux = prev->next; // atualiza aux pra posterior da remocao
            prev->next = aux->next; 
            if (aux->next != nullptr) {
                aux->next->prev = prev; // Atualiza o ponteiro `prev` do proximo nodo
            }
        }

        delete aux;
        num--; 
    return true;
}


    bool contains(const string e) {  // pesquisa linear na lista
        Node *aux = head; //cria um vetor auxiliar no head e modifica a posicao dele

        while (aux != nullptr) {
            if (aux->data == e) return true;
            aux = aux->next;
        }
        return false;
    }

    int indexOf(const int pos, const string e) {
        if (pos < 0 || pos >= num) return -1; // Índice inicial inválido

        Node *aux = head; //cria vetor auxiliar

        for (int i = 0; i < pos; i++) aux = aux->next; // Avança até a posição inicial
            
        int index = pos;

        while (aux != nullptr) { // procura na lista se o valor existe, se achar retorna index
            if (aux->data == e) return index;
            aux = aux->next;
            index++;
        }
        return -1; // se nao existe, retorna indice invalido 
    }

    int indexOf(const string e) { // retorna indice com pesquisa linear
        return indexOf(0, e);
    }

    void str(){
        Node *aux;
        aux = head; // Mostra a lista

        while (aux != nullptr){
            cout << "|" << aux->data;
            aux = aux->next;
        }
        cout << "|" << endl;

    }

};

int main(){
    List list;
    string c;
    bool fim = false;
    unsigned pos;
    int index,  c_int;
    cout << " '<' = PUSH_FRONT / '>' = PUSH_BACK / '{ ' = POP_FRONT / '}' = POP_BACK '+' = INSERT / '-' = REMOVE / '.' = QUIT " << endl;

    while (!fim){
        list.str();
        cin >> c;
        if(c == "<") c_int = 0;
        else if(c == ">") c_int = 1;
        else if(c == "+") c_int = 2;
        else if(c == "{") c_int = 3;
        else if(c == "}") c_int = 4;
        else if(c == "-") c_int = 5;
        else if(c == ".") c_int = 6;
        
        switch (c_int){
        case 0:
            cin >> c;
            list.add(0, c);
            break;
        case 1:
            cin >> c; 
            index = list.size();
            list.add(index, c);
            break;
        case 2:
            cin >> c >> pos; 
            list.add(pos, c);
            break;
        case 4:  // pop back
            if (list.size() > 0) list.remove(list.size() - 1);
            else cout << "ERRO" << endl;
            break;
        case 3: 
            if (list.size() > 0) list.remove(0);
            else cout << "ERRO" << endl;
            break;
        case 5:
            cin >> pos;
            if (list.size() > 0) list.remove(pos);
            else cout << "ERRO" << endl;
            break;
        case 6:
            fim = true;
            break;
        }
    }
    list.clear();
    return 0;
}
