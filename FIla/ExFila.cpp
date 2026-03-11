#include <stdio.h>
#include <stdbool.h>

bool isEmpty();
bool isFull();
void enqueue(int num);
int dequeue();

int inicio = -1, fim = -1;
int tam = 5;
int fila[5];

int main()
{

    return 0;
}

bool isEmpty() {
    return inicio == -1;
}

bool isFull() {
    return inicio == (fim + 1) % tam || inicio == 0 && fim == tam - 1;
}

void enqueue(int num) {
    if (isFull()) printf("A FILA ESTA CHEIA");
    else {
        if (inicio == - 1) inicio = 0;

        fim = (fim + 1) % tam;
        fila[fim] = num;

        printf("%d foi adicionad a fila", num);
    }
}
