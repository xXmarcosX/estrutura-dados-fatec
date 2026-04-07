/*
Nome: selectionSort.cpp
Autor: Marcos Vinicius
Data: 31/03/2026
Descrição: Programa para comparar o desempenho de todos os métodos de ordenação
*/

#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

// prototype
void selectionSort(int *arr, int tam);
void bubbleSort(int *arr, int tam);
void insertionSort(int *arr, int tam);

long long comp = 0LL;
long long trocas = 0LL;

int main()
{
    // int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    // int arr2[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    int arr[100000];
    int arr2[100000];
    int arr3[100000];
    int tam = sizeof(arr) / sizeof(arr[0]);
    int el = 0;

    for (int i = 0; i < tam; i++)
    {
        el = rand() % 10000;

        arr[i] = el;
        arr2[i] = el;
        arr3[i] = el;
    }

    for (int i = 0; i < tam; i++)
    {
        arr2[i] = rand() % 10000;
    }

    // for (int i = 0; i < tam; i++)
    //     printf("%d | ", arr[i]);

    clock_t inicio = clock();
    bubbleSort(arr, tam);
    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.3lf segundos", tempo_gasto);
    printf("\nQuantidade de comparacoes com bubble: %lld", comp);
    printf("\nQuantidade de trocas com bubble: %lld", trocas);

    comp = 0;
    trocas = 0;

    inicio = clock();
    selectionSort(arr2, tam);
    fim = clock();

    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n\nTempo de execucao: %.3lf segundos", tempo_gasto);
    printf("\nQuantidade de comparacoes com selection: %lld", comp);
    printf("\nQuantidade de trocas com selection: %lld", trocas);

    comp = 0;
    trocas = 0;

    inicio = clock();
    insertionSort(arr3, tam);
    fim = clock();

    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n\nTempo de execucao: %.3lf segundos", tempo_gasto);
    printf("\nQuantidade de comparacoes com insertion: %lld", comp);
    printf("\nQuantidade de trocas com insertion: %lld", trocas);

    return 0;
}

void bubbleSort(int *arr, int tam)
{
    int aux, swapped = 0;

    for (int i = 0; i < tam - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < tam - i - 1; j++)
        {
            comp++;
            if (arr[j] > arr[j + 1])
            {
                trocas++;
                aux = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = aux;
                swapped = 1;
            }
        }

        if (!swapped)
            break;
    }
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