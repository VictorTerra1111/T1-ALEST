#include <iostream>

using namespace std;

void selectionSort(int *dados, int tam);

void imprimeVetor(int *dados, int tam);

int main(){
	int tam;
	cin >> tam;

	int vetor[tam];
	
	for(int i = 0; i < tam; ++i){
		cin >> vetor[i];
	}

	selectionSort(vetor, tam);

	return 0;
}

void selectionSort(int *dados, int tam) {
  for (int i=0; i<tam-1; ++i) {
      int men = i;
      for (int j=i+1; j<tam; ++j)
          if ( dados[j] > dados[men] ) men = j;
      if ( men != i ) {
         int aux = dados[men];
         dados[men] = dados[i];
         dados[i] = aux;
      }
      imprimeVetor(dados,tam);
  }
}

void imprimeVetor(int *dados, int tam) {
        cout << dados[0];
        for (int i=1; i<tam; ++i) cout << " " << dados[i];
        cout << endl;
}

