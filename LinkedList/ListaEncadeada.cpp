/*
    Name: LinkedList.cpp
    Author: Marcos Vinicius
    Date: 10/03/26 11:19
    Description: Implementação de LinkedList
*/

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

// definição da estrutura de um nó (node)
typedef struct Node
{
    char nome[20];
    int idade;
    Node *prox;
};

// globals
int tam;

// prototype
int vazia(Node *);
int menu();
Node *alocaMemoria();
Node *retirarDoFim(Node *);
Node *retirarInicio(Node *);
void insereNoFim(Node *);
void insereInicio(Node *);
void exibirLista(Node *);
void iniciarLista(Node *);
void tratarOpcao(Node *, int);

int main()
{
    Node *Lista = (Node *)malloc(sizeof(Node));

    if (!Lista)
    {
        puts("Sem memoria para criar a lista");
        exit(1);
    }
    else
    {
        insereNoFim(Lista);
    }

    exibirLista(Lista);

    return 0;
}

// int menu() {

// }

// void tratarOpcao(Node *List, int opt) {

// }

void iniciarLista(Node *List)
{
    List->prox = NULL;
    tam = 0;
}

int vazia(Node *Lista)
{
    if (Lista->prox == NULL)
        return 1;
    else
        return false;
}

Node *alocaMemoria()
{
    Node *novo = (Node *)malloc(sizeof(Node));

    if (!novo)
    {
        puts("Sem memoria disponivel para criar um novo no");
        exit(1);
    }
    else
    {
        printf("Nome: ");
        scanf("%s", &novo->nome);

        printf("Idade: ");
        scanf("%d", &novo->idade);

        return novo;
    }
}

void insereNoFim(Node *Lista)
{
    Node *novo = alocaMemoria();
    novo->prox = NULL;

    if (vazia(Lista))
        Lista->prox = novo;
    else
    {
        Node *temp = Lista->prox;

        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }

        temp->prox = novo;
    }

    tam++;
    puts("Novo elemento inserido com sucesso!");
}

// Função para exibir todo o conteúdo da Lista
void exibirLista(Node *Lista)
{
    if (vazia(Lista))
        puts("\nA lista esta vazia");
    else
    {
        Node *temp = Lista->prox;

        printf("Lista: ");

        while (temp->prox != NULL)
        {
            printf("Nome: %s", temp->nome);
            printf("Idade %d", temp->idade);
            printf(" ==> ");

            temp = temp->prox;
        }
    }
}