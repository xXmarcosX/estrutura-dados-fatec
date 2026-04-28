/*
	Name: MergeSort.cpp
	Author: Marcos Vinicius
	Date: 28/04/26 11:17
	Description: Implementação do algoritmo MergeSort.cpp
*/

#include <stdio.h>

//prototype
void mergeSort(int *arr, int inicio, int fim); //Quebra tudo em uma unica unidade
void merge(int *arr, int inicio, int fim, int meio); //mescla tudo

int main() {
	int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
	int tam = sizeof(arr) / sizeof(arr[0]);
	
	for(int i = 0; i < tam; i++) {
		printf("%d | ", arr[i]);
	}
	
	mergeSort(arr, 0, tam - 1);
	
	//array ordenado
	for(int i = 0; i < tam; i++) {
		printf("%d | ", arr[i]);
	}
	
	
	return 0;
}

//Função recursiva para quebrar todo o conjunto em diversos arrays de um unico elemento
void mergeSort(int *arr, int inicio, int fim); {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, fim, meio);
    }
}

//Função que junta os subArrays divididos pela função recursiva mergeSort
void merge(int *arr, int inicio, int fim, int meio) {
    int i, j, k;
    int tamLeft, tamRight; // tamanho dos arrays temporários

    tamLeft = meio - inicio + 1;
	tamRight = fim - meio;

	int esquerda[tamLeft], direita[tamRight];

	//copia os dados do array original para os arrays
	//temporarios da esquerda[] e direita[]
	for(i = 0; i < tamLeft; i++) {
		esquerda[i] = arr[inicio + 1];
	}

	for(j = 0; j < tamRight; j++) {
		direita[j] = arr[meio + 1 + j];
	}

	//Mescla os arrays temporários de volta para o array original (arr)
	i = 0; //indice inicial do primeiro subarray (esquerdo)
	j = 0; //indice inicial do primeiro subarray (direito)
	k = inicio; //indice inicial do subarray mesclado

	while (i < tamLeft && j < tamRight) {
		if (esquerda[i] < direita[j]) {
			arr[k] = esquerda[i];
			i++;
		} else {
			arr[k] = direita[j];
			j++;
		}
		k++;
	}

	//copias os elementos restantes da esquerda[] se houver
	while(i < tamLeft) {
		arr[k] = esquerda[i];
		i++;
		k++;
	}

	//copias os elementos restantes da direita[] se houver
	while(j < tamRight) {
		arr[k] = direita[j];
		j++;
		k++;
	}
}