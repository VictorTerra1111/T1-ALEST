#include <iostream>
#include <sstream>

#include "Exercicio013.hpp"

using namespace std;

StringArrayList::StringArrayList(int mxSz){
    maxElements = mxSz;
    list = new string[maxElements];
    numElements = 0;
}

StringArrayList::~StringArrayList(){
    clear();
}

void StringArrayList::clear(){
    numElements = 0;
}

int StringArrayList::size() const{
    return numElements;
}

int StringArrayList::maxSize() const{
    return maxElements;
}

bool StringArrayList::isEmpty() const{
    if(numElements == 0) return true;

    return false;
}

bool StringArrayList::isFull() const{
    if(numElements == maxElements) return true;
    
    return false;
}

bool StringArrayList::add(const string &s){
    if(numElements == maxElements) return false;

    list[numElements++] = s;

    return true;
}

bool StringArrayList::add(const int index, const string &s){
    if(isFull()) return false;
    if(index < 0 || index > numElements) return false;
    
    for(int i = numElements; i > index; i--){
        list[i] = list[i - 1];
    }
    
    list[index] = s;
    ++numElements;

    return true;
}

bool StringArrayList::remove(const int index){
    if(numElements == 0 || index < 0 || index >= numElements) return false;
    --numElements;

    for(int i = numElements; i < numElements; i++){
        list[i] = list[i + 1];
    }
    

    return true;
}

bool StringArrayList::get(const int index, string &s){
    if(index < 0 || index >= numElements) return false;

    s = list[index];
    return true;
}

bool StringArrayList::set(const int index, const string &s){
    if(index < 0 || index >= numElements) return false;

    list[index] = s;
    return true;
}

bool StringArrayList::contains(const string &s){
    for(int i  =0; i < numElements; i++){
        if(list[i] == s) return true;
    }
    return false;
}

int StringArrayList::indexOf(const string &s){
    for(int i = 0; i < numElements; i++) if(list[i] == s) return i;
    return -1;
}

int StringArrayList::indexOf(int index, const string &s){
    if(index < 0 || index > maxElements) return -1;
    for(int i = index; i < numElements; i++) if(list[i] == s) return i;
    return -1;
}

string StringArrayList::str() const{
    stringstream ss;

    for(int i = 0; i < numElements; i++){
        ss << list[i];
    }

    return ss.str();
}
