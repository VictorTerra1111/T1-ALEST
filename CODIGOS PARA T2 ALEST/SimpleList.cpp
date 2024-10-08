#include <iostream>
using namespace std;
// PARA ZIPAR PASTA:  zip -r <zip file name> <directory name>
struct Node{
    int data;
    Node *next;
    Node(int i){
        data = i; next = nullptr;
    }
};

template <typename T> // List<int> list; gera uma lista do tipo especificado
class List {
private: 
    int num;
    Node * head, * tail;
public:
    List() { // construtor
        num = 0;
        head = tail = nullptr;
    }

    ~List() { clear();}

    void clear() { 
        while(head != nullptr){
                Node *aux = head;
                head = head->next;
                delete aux;
        }
        num = 0;
    }

    int size() const { return num; }
    bool isEmpty() const { return num == 0; }

    bool add(const T e) {
        Node *novo = new Node(e); // Cria Node com o valor 'e'.
        if (head == nullptr) {     // se tiver vazio
            head = tail = novo;
        } else {                   // se nao, adicional no final
            tail->next = novo;
            tail = novo;
        }
        num++; 
        return true;
    }

    bool add(const int index, const T e) { 
        if (index < 0 || index > num) return false; // Verifica se o índice é válido
        Node *novo = new Node(e); //novo nodo

        if (index == 0) { // Inserção no início
            novo->next = head;
            head = novo;
            if (tail == nullptr) tail = novo; // Se a lista estava vazia
        }
        else {
            Node *aux = head; //ponteiro auxiliar
            for (int i = 0; i < index - 1; i++) aux = aux->next; //percorre ate o anterior do index onde vai ser encaixado o nodo
            
            novo->next = aux->next;
            aux->next = novo;
            
            if (novo->next == nullptr) tail = novo; // Atualiza a cauda se inserido no fim.
        }
        num++;
        return true;
    }

    bool get(const int index, T &e) { 
        if (index < 0 || index >= num) return false; // Índice inválido

        Node *aux = head; //ponteiro auxiliar 
        for (int i = 0; i < index; i++) aux = aux->next; // Avança até o índice
        e = aux->data; //passa o valor do indice por referencia
        return true;
    }
    
    bool set(const int index, const T &e) { 
        if (index < 0 || index >= num) return false; // Índice inválido

        Node *aux = head;
        for (int i = 0; i < index; i++) aux = aux->next; // Avança até o índice
        aux->data = e;
        return true;
    }

    bool remove(int index) {
        if (index < 0 || index >= num) return false; // Índice inválido

        Node *aux; //por ser simplesmente, precisa de um ponteiro auxiliar
        
        if (index == 0) { // Remoção no início.
            aux = head;
            head = head->next;
            if (head == nullptr) tail = nullptr; // Lista ficou vazia
        } else {
            Node *prev = head;
            for (int i = 0; i < index-1; i++) prev = prev->next;
            
            aux = prev->next;
            prev->next = aux->next;
            
            if (aux == tail) tail = prev; // Atualiza tail se necessário
        }
        delete aux;
        num--;
        return true;
    }

    bool contains(const T e) {  // pesquisa linear na lista
        Node *aux = head; //cria um vetor auxiliar no head e modifica a posicao dele

        while (aux != nullptr) {
            if (aux->data == e) return true;
            aux = aux->next;
        }
        return false;
    }

    int indexOf(const int pos, const T e) { // pesquisa linear a partir da posicao fornecida 
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

    int indexOf(const T e) { // retorna indice com pesquisa linear
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