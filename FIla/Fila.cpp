/*
	Name: Fila.cpp
	Author: Marcos Vinicius
	Date: 24/02/26 10:57
	Description: Programa para implementar uma fila do tipo FIFO
*/

#include <stdio.h>
#include <stdbool.h>

int itens[5];
int inicio = -1, fim = -1;
int tam = 5;

// prototype
void enqueue(int num);
int dequeue();
bool isFull();
bool isEmpty();
void printQueue();

int main()
{
	int opt = 0, num = 0;
	int isRunning = true;

	printf("\n\n1 - enqueue");
	printf("\n2 - dequeue");
	printf("\n3 - exibir fila");
	printf("\n0 - sair");

	while (isRunning)
	{
		printf("\n\nDigite a parada: ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			printf("\nDigite o numero que sera adicionado a fila: ");
			scanf("%d", &num);

			enqueue(num);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			printQueue();
			break;

		case 0:
			printf("Saindo...");
			isRunning = false;
			break;

		default:
			printf("\nOpcao invalida");
			break;
		}
	}

	return 0;
}

void enqueue(int num)
{
	if (isFull())
		printf("A fila esta cheia");
	else
	{
		if (inicio == -1)
			inicio = 0;

		fim = (fim + 1) % tam;
		itens[fim] = num;

		printf("\nElemento %d inserido na fila", num);
	}
}

int dequeue()
{
	int num;

	if (isEmpty())
	{
		printf("\nA Fila esta vazia");

		return -1;
	}
	else
	{
		num = itens[inicio];

		if (inicio == fim)
		{
			inicio = -1;
			fim = -1;
		}
		else
		{
			inicio = (inicio + 1) % tam;
		}

		printf("\n%d Foi excluido da fila", num);

		return num;
	}
}

bool isFull()
{
	if (inicio == (fim + 1) % tam || (inicio == 0 && fim == tam - 1))
		return true;
	else
		return false;
}

bool isEmpty()
{
	if (inicio == -1)
		return true;
	else
		return false;
}

void printQueue()
{
	if (isEmpty())
		printf("\n\nA FILA ESTA VAZIA");
	else
	{
		printf("\n\nConteudo da fila: ");
		for (int i = inicio; i <= fim; i++)
			printf("%d |", itens[i]);
	}
}