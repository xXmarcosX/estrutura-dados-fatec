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
        int opt = 1;

        while (opt)
        {
            opt = menu();
            tratarOpcao(Lista, opt);

            puts("");

            system("pause");
            system("cls");
        }
    }

    return 0;
}

int menu()
{
    int opt = 0;

    puts("Escolha sua opcao: ");

    printf("==================MENU DA LISTA====================");
    printf("\n(1) - Zerar a lista");
    printf("\n(2) - Exibir a lista");
    printf("\n(3) - Inserir um elemento no FIM da lista");
    printf("\n(4) - Inserir elemento no INICIO da lista");
    printf("\n(5) - Excluir um elemento do FIM da lista");
    printf("\n(6) - Excluir um elemento do INICIO da lista");
    printf("\n(0) - Sair");
    puts("\n==================================================");

    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void tratarOpcao(Node *List, int opt)
{
    Node *temp;

    switch (opt)
    {
    case 1:
        iniciarLista(List);
        break;
    case 2:
        exibirLista(List);
        break;
    case 3:
        insereNoFim(List);
        break;

    case 4:
        insereInicio(List);
        break;

    case 5:
        retirarDoFim(List);
        break;

    case 6:
        retirarInicio(List);
        break;

    case 0:
        printf("Saindo...");
        exit(0);
        break;

    default:
        puts("Opcao invalida");
        break;
    }
}

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

void insereInicio(Node *List)
{
    Node *novo = alocaMemoria();
    Node *head = List->prox;

    List->prox = novo;
    novo->prox = head;

    puts("No inserido no inicio da lista");

    tam++;
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
    puts("Novo elemento inserido com sucesso!\n\n");
}

Node *retirarInicio(Node *List)
{
    if (List->prox == NULL)
    {
        puts("\nA lista esta vazia");

        return NULL;
    }
    else
    {
        Node *temp = List->prox;
        List->prox = temp->prox;

        tam--;

        printf("Elemento excluido do inicio da lista");

        return temp;
    }
}

Node *retirarDoFim(Node *List)
{
    if (List->prox == NULL)
    {
        puts("\nA lista ja esta vazia");

        return NULL;
    }
    else
    {
        Node *ultimo = List->prox;
        Node *penultimo = List;

        while (ultimo->prox != NULL)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }

        penultimo->prox = NULL;

        puts("Elemento excluido com sucesso do fim da lista");

        tam--;

        return ultimo;
    }
}

// Função para exibir todo o conteúdo da Lista
void exibirLista(Node *Lista)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // COR ORIGINAL
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_Attributes;

    // salvar os atributos das cores
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_Attributes = consoleInfo.wAttributes; // Salva a cor original

    if (vazia(Lista))
        puts("\nA lista esta vazia");
    else
    {
        Node *temp = Lista->prox;

        printf("Lista: \n");

        while (temp != NULL)
        {
            printf("Nome: %s", temp->nome);
            printf(" | Idade: %d", temp->idade);

            SetConsoleTextAttribute(hConsole, 6); // MUDA COR P Q EU QUERO
            printf(" ==> ");
            SetConsoleTextAttribute(hConsole, saved_Attributes); // RESETA

            temp = temp->prox;
        }

        printf("NULL");
    }
}