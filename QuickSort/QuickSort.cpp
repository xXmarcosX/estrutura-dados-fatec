/*
Nome: QuickSort.cpp
Autor: Marcos Vinicius
Data: 12/05/2026
Descrição: Programa para demonstrar a implementação do QuickSort
*/

#include <stdio.h>
#include <locale.h>

void swap(int *, int *);
int partition(int *, int, int);
void quickSort(int *, int, int);

int comp = 0;
int trocas = 0;

int main()
{
    int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    int i;
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    for (int j = 0; j < tam; j++)
        printf("%d | ", arr[j]);

    quickSort(arr, 0, tam - 1);

    printf("\n\nArray ordenado: \n");
    for (int j = 0; j < tam; j++)
        printf("%d | ", arr[j]);

    printf("\nQuantidade de comparacoes: %d", comp);
    printf("\nQuantidade de trocas: %d", trocas);

    return 0;
}

// Função que realiza a partição do conjunto de dados
int partition(int *arr, int inicio, int fim)
{
    int pivot = arr[inicio]; // primeiro elemento como pivot
    int i = (fim + 1);

    for (int j = fim; j >= inicio + 1; j--)
    {
        comp++;
        if (arr[j] >= pivot)
        {
            i--;
            swap(&arr[i], &arr[j]);
            trocas++;
        }
    }

    swap(&arr[i - 1], &arr[inicio]);
    trocas++;

    return (i - 1);
}

// Função principal do quickSort
void quickSort(int *arr, int inicio, int fim)
{
    if (inicio < fim)
    {
        int pivot = partition(arr, inicio, fim);

        quickSort(arr, inicio, pivot - 1); // partição do lado esquerdo
        quickSort(arr, pivot + 1, fim);    // partição do lado direito
    }
}

// Função para fazer a troca de elementos entre si
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}