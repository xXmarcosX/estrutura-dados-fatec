/*
Nome: selectionSort.cpp
Autor: Marcos Vinicius
Data: 31/03/2026
Descrição programa para demonstrar o funcionamento do método SelectionSort
*/

#include <stdio.h>
#include <ctime>
#include <cstdlib>

// prototype
void selectionSort(int *arr, int tam);

int comp = 0, trocas = 0;

int main()
{
    // int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    int arr[100000];
    int tam = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tam; i++) {
        arr[i] = rand() % 10000;
    }

    printf("Array original: \n");

    for (int i = 0; i < tam; i++)
        printf("%d | ", arr[i]);

    selectionSort(arr, tam);

    printf("\n\nArray ordenado: \n");

    for (int i = 0; i < tam; i++)
        printf("%d | ", arr[i]);

    printf("\n\nQuantidade de comparacoes: %d", comp);
    printf("\nQuantidade de trocas: %d", trocas);

    return 0;
}

void selectionSort(int *arr, int tam)
{
    int menor, atual, aux;

    for (int i = 0; i < tam - 1; i++)
    {
        atual = i;
        menor = i + 1;

        for (int j = i + 1; j < tam; j++)
        {
            comp++;

            if (arr[j] < arr[menor])
            {
                menor = j;
            }
        }

        comp++;
        if (arr[menor] < arr[atual])
        {
            aux = arr[atual];

            arr[atual] = arr[menor];
            arr[menor] = aux;

            trocas++;
        }
    }
}

