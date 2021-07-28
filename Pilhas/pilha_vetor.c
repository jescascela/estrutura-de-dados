// Programa que contém algumas funções de Pilha utilizando versão com vetor

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct pilha
{
    int n; // Número de elementos da pilha
    int vet[MAX]; // Armazena os elementos da pilha
};

typedef struct pilha Pilha;

// Cria uma pilha vazia
Pilha* criaPilha()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha* p)
{
    if(p->n == 0)
    {
        return 1;
    }

    return 0;
}

// Insere um elemento no topo da pilha
void pilhaPush(Pilha* p, int v)
{
    if(p->n == MAX)
    {
        printf("Capacidade da pilha esta no limite\n");
        exit(1);
    }

    p->vet[p->n] = v; // Insere o elemento na próxima posição livre
    p->n++;
}

// Remove o elemento do topo da pilha
int pilhaPop(Pilha* p)
{
    int v;

    if(pilhaVazia(p) == 1)
    {
        printf("A pilha esta vazia!\n");
        exit(1);
    }

    v = p->vet[p->n - 1];
    p->n--;
    return v;
}

// Libera a memória alocada pela pilha
void liberaPilha(Pilha* p)
{
    free(p);
}

// Imprime elementos da pilha
void imprimePilha(Pilha* p)
{
    int i;

    for(i = p->n - 1; i >= 0; i--)
    {
        printf("%d\n", p->vet[i]);
    }
}

// Menu para testar as funções
void menu()
{
    Pilha* p;
    int opcao;
    int numero;

    p = criaPilha();

    printf("\nUma pilha vazia foi criada...\n\n");

    do
    {
        printf("Digite o numero da opcao desejada\n");
        printf("1- Inserir elemento no topo da pilha\n");
        printf("2- Remover elemento do topo da pilha.\n");
        printf("3- Verificar se a pilha esta vazia.\n");
        printf("4- Imprimir pilha.\n");
        printf("5- Sair.\n");
        
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um numemro inteiro: ");
            scanf("%d", &numero);
            pilhaPush(p, numero);
            break;
        case 2:
            printf("O numero %d foi removido do topo da pilha.\n", pilhaPop(p));
            break;
        case 3:
            if(pilhaVazia(p) == 1)
            {
                printf("A pilha esta vazia.\n");
            }
            else
            {
                printf("A pilha nao esta vazia.\n");
            }
            break;
        case 4:
            imprimePilha(p);
            break;
        case 5:
            liberaPilha(p);
            printf("Programa encerrado.\n");
            break;
        default:
            printf("Opcao invalida. Digite outro numero.\n\n");
            break;
        }
        
    } while (opcao != 5);
    
}

int main()
{
    menu();
    return 0;
}