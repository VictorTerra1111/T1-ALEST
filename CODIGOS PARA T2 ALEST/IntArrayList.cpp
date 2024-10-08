#include <iostream>

using namespace std;

template <typename T> //   IntArrayList<int> list(tamanho_maximo); gera um arraylist do tipo especificado
class IntArrayList {
public: 
    int max, num;
    T* list; 

    IntArrayList(int vmax) { // ver tamanho maximo caso sem parametro 
        max = vmax;
        num = 0;
        list = new T[max]; 
    }

    ~IntArrayList() {
        clear();
    }

    void clear() {
        delete[] list;
        num = 0;
    }

    int size() const { return num; }
    int maxSize() const { return max; }
    bool isFull() const { return num == max; }
    bool isEmpty() const { return num == 0; }

    bool add(const T e) {
        if (isFull()) return false;
        list[num] = e;
        ++num;
        return true;
    }

    bool add(const int index, const T e) { 
        if (isFull() || index < 0 || index > num) return false; 
        for (int i = num; i > index; --i) 
            list[i] = list[i - 1]; 
        list[index] = e;
        ++num;
        return true;
    }

    bool get(const int index, T &e) { 
        if (isEmpty() || index < 0 || index >= num) return false; 
        e = list[index];
        return true;
    }
    
    bool set(const int index, const T &e) { 
        if (index < 0 || index >= num) return false; 
        list[index] = e;
        return true;
    }

    bool remove(int index) {
        if (index < 0 || index >= num) return false;
        --num;
        for (int i = index; i < num; ++i) 
            list[i] = list[i + 1];
        return true;
    }

    bool contains(const T e) { 
        for (int i = 0; i < num; i++) {
            if (list[i] == e) return true;
        }
        return false;
    }

    int indexOf(const int pos, const T e) { 
        if (pos < 0 || pos >= num) return -1; 
        for (int i = pos; i < num; i++) {
            if (list[i] == e) return i;
        }
        return -1; 
    }

    int indexOf(const T e) {
        return indexOf(0, e);
    }
};
