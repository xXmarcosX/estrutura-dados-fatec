/*
Nome: BubbleSort.cpp
Autor: Marcos Vinicius
Data: 24/03/2026
Descrição programa para demonstrar o funcionamento do método BubbleSort
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

int comp, trocas = 0;

// prototype
void bubbleSort(int tam, int *arr);

int main()
{
    int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");

    for (int i = 0; i < tam; i++)
        printf("%d | ", arr[i]);

    bubbleSort(tam, arr);

    printf("\n\nArray ordenado: \n");

    for (int i = 0; i < tam; i++)
        printf("%d | ", arr[i]);

    printf("\n\nQuantidade de comparacoes: %d", comp);
    printf("\nQuantidade de trocas: %d", trocas);

    return 0;
}

void bubbleSort(int tam, int *arr)
{
    int i = 0;
    int aux = 0;

    do
    {
        i = 0;

        while (i < tam - 1)
        {
            comp++;

            // > para crescente, < para decrescente
            if (arr[i] < arr[i + 1])
            {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                trocas++;
            }

            i++;
        }

        tam--;
    } while (tam > 0);
}