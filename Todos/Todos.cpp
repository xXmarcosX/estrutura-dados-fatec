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

int comp = 0;
int trocas = 0;

int main()
{
    // int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    // int arr2[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    int arr[100000];
    int arr2[100000];
    int tam = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tam; i++)
    {
        arr[i] = rand() % 10000;
    }

    for (int i = 0; i < tam; i++)
    {
        arr2[i] = rand() % 10000;
    }

    // for (int i = 0; i < tam; i++)
    //     printf("%d | ", arr[i]);

    clock_t inicio = clock();
    bubbleSort(arr, tam);

    // 2. Marca o tempo final
    clock_t fim = clock();

    // 3. Calcula a diferença e converte para segundos
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %.3lf segundos\n", tempo_gasto);

    printf("\n\nQuantidade de comparacoes com bubble: %d", comp);
    printf("\nQuantidade de trocas com bubble: %d", trocas);

    comp = 0;
    trocas = 0;

    inicio = clock();
    selectionSort(arr2, tam);

    // 2. Marca o tempo final
    fim = clock();

    // 3. Calcula a diferença e converte para segundos
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\n\nTempo de execucao: %.3lf segundos\n", tempo_gasto);

    puts("");

    printf("\n\nQuantidade de comparacoes com selection: %d", comp);
    printf("\nQuantidade de trocas com selection: %d", trocas);

    // printf("\n\nArray ordenado: \n");

    // for (int i = 0; i < tam; i++)
    //     printf("%d | ", arr[i]);

    // printf("\n\nQuantidade de comparacoes: %d", comp);
    // printf("\nQuantidade de trocas: %d", trocas);

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