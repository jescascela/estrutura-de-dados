// Programa que contém algumas funções de Pilha utilizando versão com listas encadeadas

include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

struct pilha
{
    Lista* prim; // Ponteiro para o primeiro nó da pilha
};

typedef struct pilha Pilha;

// Cria uma pilha vazia
Pilha* criaPilha()
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    
    p->prim = NULL;
    
    return p;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha* p)
{
    if(p->prim == NULL)
    {
        return 1;
    }

    return 0;
}

// Insere um elemento no topo da pilha
void pilhaPush(Pilha* p, int v)
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->info = v;
    l->prox = p->prim;
    p->prim = l;
}

// Retira o elemento do topo da pilha
int pilhaPop(Pilha* p)
{
    Lista* t; // Ponteiro auxiliar temporário
    int v;

    if(pilhaVazia(p) == 1)
    {
        printf("Pilha vazia.\n");
        exit(1);
    }

    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);

    return v;
}

// Imprime os elementos da pilha
void imprimePilha(Pilha* p)
{
    Lista* l;

    for(l = p->prim; l != NULL; l = l->prox)
    {
        printf("%d\n", l->info);
    }
}

// Libera a memória alocada pela pilha
void liberaPilha(Pilha* p)
{
    Lista* l = p->prim;

    while(l != NULL)
    {
        Lista* t = l->prox;
        free(l);
        l = t;
    }

    free(p);
}

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