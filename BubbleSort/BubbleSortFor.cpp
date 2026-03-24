#include <stdio.h>
#include <locale.h>

void bubbleSort(int tam, int *arr);

int main()
{
    int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    int tam = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(tam, arr);

    for (int i = 0; i < tam; i++)
        printf("%d | ", arr[i]);

    return 0;
}

void bubbleSort(int tam, int *arr)
{
    int aux, swapped = 0;

    for (int i = 0; i < tam - 1; i++)
    {
        swapped = 0;

        for (int j = 0; j < tam - i - 1; j++)
        {
            if(arr[j] > arr[j + 1]) 
            {
                aux = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = aux;
                swapped = 1;
            }
        }

        if (!swapped) break;
    }
}