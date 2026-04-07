/*
Nome: InsertionSort.cpp
Autor: Marcos Vinicius
Data: 07/04/2026
Descrição: Programa para demonstrar a implementação do InsertionSort
*/

#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

// prototype
void insertionSort(int *arr, int tam);

// globals
long long trocas = 0LL, comp = 0LL;

int main()
{
    // int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    int arr[100000];
    int i = 0;
    int tam = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tam; i++)
    {
        arr[i] = rand() % 10000;
    }

    printf("Array ORIGINAL:\n");
    for (i = 0; i < tam; i++)
        printf("%d | ", arr[i]);

    clock_t inicio = clock();
    insertionSort(arr, tam);
    clock_t fim = clock();
    
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n\nArray ORDENADO:\n");
    for (i = 0; i < tam; i++)
        printf("%d | ", arr[i]);

    printf("\n\nQuantidade de comparacoes: %lld", comp);
    printf("\nQuantidade de trocas: %lld", trocas);
    printf("\nTempo de execucao do InsertionSort: %.3lf", tempo_gasto);

    return 0;
}

void insertionSort(int *arr, int tam)
{
    int i = 0, j = 0, atual = 0;

    for (i = 1; i < tam; i++)
    {
        atual = arr[i];
        j = i - 1;

        while (j >= 0 && atual < arr[j])
        {
            comp++;
            arr[j + 1] = arr[j];
            trocas++;
            j--;
        }

        arr[j + 1] = atual;
        trocas++;
    }
}