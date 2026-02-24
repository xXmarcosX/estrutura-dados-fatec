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

//prototype
void enqueue(int num);
int dequeue();
bool isFull();
bool isEmpty();
void printQueue();

int main() 
{
    enqueue(100);
	enqueue(101);
	enqueue(102);
	enqueue(103);
	enqueue(104);
	
	puts("");
	enqueue(154);
	
	puts("");
	enqueue(154);
	
	printQueue();
	
	dequeue();
	dequeue();
	dequeue();
	
	printQueue();
	
	dequeue();
	dequeue();
	dequeue();
	
	printQueue();
	
	enqueue(114);
	enqueue(184);
	enqueue(174);
	
	printQueue();
	
    return 0;
}

void enqueue(int num)
{
	if (isFull()) printf("A fila esta cheia"); 
	else 
	{
		if (inicio == -1) inicio = 0;

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
	if (inicio == (fim + 1) % tam || (inicio == 0 && fim == tam - 1)) return true;
	else return false;
}

bool isEmpty()
{
	if (inicio == -1) return true;
	else return false;
}

 void printQueue()
 {
 	if (isEmpty()) printf("\n\nA FILA ESTA VAZIA");
 	else {
 		printf("\n\nConteudo da fila: ");
 		for (int i = inicio; i <= fim; i++) printf("%d |", itens[i]);	
	 }
 }