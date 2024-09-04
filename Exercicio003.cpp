#include <iostream>
#include <string>

using namespace std;

struct registro_t{
	std::string nome;
	int numero;
};

void imprimeVetor(registro_t *dados, int tam) {
        cout << dados[0].nome << "/" << dados[0].numero;
        for (int i=1; i<tam; ++i) cout << " " << dados[i].nome << "/" << dados[i].numero;
        cout << endl;
}

void bubbleSort(registro_t *dados, int tam) {
        int trocou;
        do {
                trocou = 0;
                for (int i=0; i<tam-1; ++i){
                        if (dados[i].nome > dados[i+1].nome || (dados[i].nome == dados[i+1].nome && dados[i].numero > dados[i+1].numero)) {
				registro_t aux = dados[i];
	                        dados[i]= dados[i+1];
                                dados[i+1] = aux;
				trocou = 1;
			}
	
	        }
		imprimeVetor(dados, tam);
	}  while (trocou);
}

int main(){
	int tam;
	cin >> tam;

	registro_t vetor[tam];
	
	for(int i = 0; i < tam; ++i){
		cin >> vetor[i].nome;
		cin >> vetor[i].numero;
	}
	
	bubbleSort(vetor, tam);

	return 0;
}






