/*
	Name: Pilha.cpp
	Author: Marcos Vinicius
	Date: 03/03/26 10:57
	Description: Implementação do conceito de pilha (LIFO)
*/


#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <cstdlib>


//prototype
void menu(bool *isRunning);
void conversorBinario(int num);

void push(int num);
void printStack();
int pop();
bool isFull();
bool isEmpty();

//globals
int stack[5];
int conversorStack[25];
int tam = 5;
int topo = -1, conversorTop = -1;

int main()
{
	bool isRunning = true;
	
	while (isRunning) {
		menu(&isRunning);	
	}

    return 0;
}

void push(int num) {
    if (isFull()) printf("\n\nSTACK OVERFLOW - Pilha cheia");
    else {
        topo++;
        stack[topo] = num;

        printf("\n%d foi inserido na pilha", num);
    }
}

int pop() {
    if (isEmpty()) printf("\nA PILHA ESTA VAZIA");
    else {
        int numero = stack[topo];
        topo--;

        printf("\n%d foi removido da pilha", numero);

        return numero;
    }
}

bool isFull() {
    return topo == tam - 1;
}

bool isEmpty() {
    return topo == -1;
}

void printStack() {
	if (isEmpty()) printf("\n\n A PILHA ESTA VAZIA");
	else {
		printf("\n\nConteudo da pilha: ");
	
    	for (int i = topo; i >= 0; i--) printf("%d |", stack[i]);	
	}
}

void menu(bool *isRunning) {
	system("cls");

	int opt = 0;
    int numero = 0;

	printf("\n\n===============PILHA==============");
    printf("\n\n1 - Inserir elemento na pilha");
    printf("\n2 - Remover elemento da pilha");
    printf("\n3 - Mostrar elementos da pilha");
    printf("\n4 - Conversor Binario");
    printf("\n0 - Sair");
    printf("\n\n=================================");
    
    printf("\n\nDigite sua opcao: ");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        printf("Digite o numero que sera inserido na pilha: ");
        scanf("%d", &numero);

        push(numero);

        break;

    case 2:
        pop();
        break;

    case 3:
        printStack();
        break;

    case 4:
        printf("Digite o numero que sera convertido em binario: ");
        scanf("%d", &numero);

        conversorBinario(numero);
        break;

    case 0:
    	printf("Saindo...");
    	
        *isRunning = false;
        break;
    
    default:
        printf("Opcao invalida");
        break;
    }
    
    puts("");
    puts("");
    system("pause");
}

void conversorBinario(int num) {
    conversorTop = -1;

    while(num >= 1) {
        conversorTop++;
        conversorStack[conversorTop] = num % 2;

        num /= 2;
    }

    printf("Numero convertido: ");
    for (int i = conversorTop; i >= 0; i--) printf("%d", conversorStack[i]);
}