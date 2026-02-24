/*
	Name: Fila.cpp
	Author: Marcos Vinicius
	Date: 24/02/26 10:57
	Description: Programa para implementar uma fila do tipo FIFO
*/

#include <stdio.h>
#include <stdbool.h>

int itens[5];
int inicio = 0;
int tam = 5;

//prototype
void enqueue(int num);
int dequeue();
bool isFull();
bool isEmpty();
void printQueue();

int main() 
{
    printf("shauhsua");

    return 0;
}

void enqueue(int num)
{
	if (isFull()) printf("A fila esta cheia"); 
	else 
	{
		if (inicio = -1) inicio = 0;
	}
}


int dequeue()
{
	...
}

bool isFull()
{
	if (fim + 1 == tam) return true;
	else return false;
}

bool isEmpty()
{
	if (inicio = -1) return true;
	else return false;
}

void printQueue()
{
	...
}