#include <iostream>

using namespace std;

void insertionSortDec(int *dados, int tam);

void imprimeVetor(int *dados, int tam);

int estaOrdenadoDec(int *dados, int tam);

void imprimeVetor(int *dados, int tam) {
	cout << dados[0];
	for (int i=1; i<tam; ++i) cout << " " << dados[i];
	cout << endl;
}

int estaOrdenadoDec(int *dados, int tam) {
	for (int i=0; i<tam-1; ++i) if (dados[i] < dados[i+1]) return 0;
	return 1;
}

int main() {
	int tam;
	cin >> tam;
	int *vet = new int[tam];
	for (int i=0; i<tam; ++i) cin >> vet[i];
	insertionSortDec(vet,tam);
	if (!estaOrdenadoDec(vet,tam)) cout << "> ERRO" << endl;
	delete[] vet;
	return 0;
}

void insertionSortDec(int *dados, int tam) {
  for (int i=1; i<tam; ++i) {
      int base = dados[i];
      int j = i-1;
      while ( j>=0 && base > dados[j] ) {
            dados[j+1] = dados[j];
            --j;
      }
      dados[j+1] = base;

      imprimeVetor(dados, tam);
  }
}

