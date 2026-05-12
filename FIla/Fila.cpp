#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool isFull();
bool isEmpty();
void enqueue(int num);
int dequeue();

int fila[10];
int tam = 10;
int inicio = -1, fim = -1;

int main()
{

	for (size_t i = 0; i < 10; i++)
	{
		printf("%d | ", fila[i]);
	}

	return 0;
}

bool isFull()
{
	return inicio == (fim + 1) % tam || inicio == 0 && fim == tam - 1;
}

bool isEmpty()
{
	return inicio == -1;
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
		fila[fim] = num;
	}
}

int dequeue()
{
	int num = 0;

	if (isEmpty())
	{
		printf("A fila esta vazia");
		return -1;
	}
	else
	{
		num = fila[inicio];

		if (inicio == fim)
		{
			inicio = -1;
			fim = -1;
		}
		else
		{
			inicio = (inicio + 1) % tam;
		}
	}

	return num;
}