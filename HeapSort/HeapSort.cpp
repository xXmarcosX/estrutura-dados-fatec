/*
Nome: HeapSort.cpp
Autor: Marcos Vinicius
Data: 05/05/2026
Descrição: Programa para a implementação do HeapSort
*/

#include <stdio.h>
#include <locale.h>

// prototype
void heapfy(int *arr, int n, int i);
void heapSort(int *arr, int tam);
void swap(int *a, int *b);
void printArray(int *arr);

int tam;

int main()
{
    int arr[] = {17, 38, 12, 2, 44, 25, 19, -4, 30, 10};
    tam = sizeof(arr) / sizeof(arr[0]);

    puts("Array original: ");
    printArray(arr);

    heapSort(arr, tam);

    puts("Array ordenado: ");
    printArray(arr);

    return 0;
}

// Função para troca de posições (swap)
void swap(int *a, int *b)
{
    int aux = *a;

    *a = *b;
    *b = aux;
}

// Função que faz heapfy, ou seja, testa se o pai é maior
//  que os filhos (MAXHEAP)
//  ou se o pai é menor que os filhos (MINHEAP)
//  Chama o swap para fazer a troca
void heapfy(int *arr, int n, int i)
{
    int maior = i; // inicializa o maior como raiz
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    // se o filho da esquerda é maior que o pai
    if (left < n && arr[left] > arr[maior])
    {
        maior = left;
    }

    // se o filho da direita é maior que o pai
    if (right < n && arr[right] > arr[maior])
    {
        maior = right;
    }

    if (maior != i)
    {
        swap(&arr[i], &arr[maior]);

        // Chama recursivamente heapfy na sub-árvore afetada
        heapfy(arr, n, maior);
    }
}

// Função principal que monta a árvore
// e submete à função recursiva heapfy
// para verificar as regras de MAXHEAP ou MINHEAP
void heapSort(int *arr, int tam)
{
    // 1. Constrói um MAXHEAP
    for (int i = tam / 2 - 1; i >= 0; i--)
    {
        heapfy(arr, tam, i);
    }

    // 2. Troca a raiz com o último elemento e reduz a árvore (heap)
    for (int i = tam - 1; i > 0; i--)
    {
        // Move o elemento atual (raiz) para o fim do array
        swap(&arr[0], &arr[i]);

        // Chama a função heapfy na raiz para restaurar a propriedade do heap (MAXHEAP ou MINHEAP)
        // Verifica se o pai é maior/menor que os dois filhos
        heapfy(arr, i, 0);
    }
}

void printArray(int *arr)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d | ", arr[i]);
    }
    puts("");
}