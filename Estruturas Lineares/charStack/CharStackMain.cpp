#include <iostream>
#include "CharStack.hpp"
using namespace std;

/* Usando a classe CharStack (do exercício anterior), escreva um programa em C++, que inverte as 
letras de cada palavra de um texto terminado por ponto (.), preservando a ordem das palavras.
Por exemplo, dado o texto: ETSE OICICREXE E OTIUM LICAF.
A saída deve ser:          ESTE EXERCICIO E MUITO FACIL.*/


string frasemod(string s);

int main(){

    char e;
    cout << "Digite as palavras para reorganiza-las" << endl;
    cin >> e;


    return 0;
}


string frasemod(string s){
    CharStack e(s.length());
    string res = " ";
    int pos = 0;
    while(s[pos] != '.' && s[pos] != ){
        if(s[pos] = ' '){
                
        }
        
        else{
            p.push(s[pos]);
        }
        res += s[pos];
        ++pos;
    }
}