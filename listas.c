// Programa que contém algumas funções de Listas Encadeadas

#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info; // Garda informação da lista
    struct lista* prox; // Ponteiro para próxima lista
};

typedef struct lista Lista;

// Cria uma lista vazia
Lista* criaLista()
{
    return NULL;
}

// Insere um novo elemento no início da lista
Lista* insereInicio(Lista* l, int i)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

// Insere um novo elemento no final da lista
Lista* insereFinal(Lista* l, int i)
{
    Lista* p = l;

    // Percorre até chegar no último elemento da lista
    while(p->prox != NULL)
    {
        p = p->prox;
    }

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = NULL;
    p->prox = novo;

    return l;
}

// Verifica se a lista está vazia
int listaVazia(Lista* l)
{
    if(l == NULL)
    {
        return 1; // A lista está vazia
    }
    return 0; // A lista não está vazia
}

// Imprime os elementos da lista
void imprimeLista(Lista* l)
{
    Lista* p; // Variável auxiliar para percorrer a lista

    for(p = l; p != NULL; p = p->prox)
    {
        printf("Info = %d\n", p->info);
    }
}

// Busca um determinado elemento na lista
Lista* buscaElementoLista(Lista* l, int v)
{
    Lista* p;

    for(p = l; p != NULL; p = p->prox)
    {
        if(p->info == v)
        {
            return p;
        }
    }

    return NULL; // Elemento não encontrado na lista
}

// Retira uma elemento da lista
Lista* retiraLista(Lista* l, int v)
{
    Lista* anterior = NULL; // Guarda o elemento anterior
    Lista* p = l; // Ponteiro para percorrer a lista

    while(p != NULL && p->info != v)
    {
        anterior = p;
        p = p->prox;
    }

    /* 
        Se p == NULL então a lista foi toda percorrida
        e o elemento não foi encontrado. Então a própria
        lista é retornada e a função é encerrada
    */
    if(p == NULL)
    {
        return l;
    }

    // Retira elemento do início
    if(anterior == NULL)
    {
        l = p->prox;
    }
    else
    {
        // Retira elemento do meio da lista
        anterior->prox = p->prox;
    }

    free(p);
    return l;
}

void liberaLista(Lista* l)
{
    Lista* p = l;
    while(p != NULL)
    {
        Lista* t = p->prox; // Guarda referência para o próximo elemento da lista
        free(p); // Libera a memória apontada por p
        p = t; // t aponta para o próximo elemento da lista
    }
}

// Menu para testar as funções
void menu()
{
    Lista* l;
    int opcao;
    int numero;

    l = criaLista();

    printf("\nUma lista vazia foi criada...\n\n");

    do
    {
        printf("Digite o numero da opcao desejada\n");
        printf("1- Inserir elemento no inicio da lista\n");
        printf("2- Imprimir lista\n");
        printf("3- Buscar elemento\n");
        printf("4- Verificar se a lista esta vazia\n");
        printf("5- Remover elemento da lista\n");
        printf("6- Inserir elemento no fim da lista\n");
        printf("7- Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um numero inteiro: ");
            scanf("%d", &numero);
            l = insereInicio(l, numero);
            printf("Elemento inserido com sucesso!\n\n");
            break;
        case 2:
            imprimeLista(l);
            printf("\n");
            break;
        case 3:
            printf("Digite o numero do elemento que deseja buscar: ");
            scanf("%d",&numero);
            if(buscaElementoLista(l, numero) != NULL)
            {
                printf("O numero %d esta na lista\n", numero);
            }
            else
            {
                printf("O numero %d nao esta na lista\n", numero);
            }
            break;
        case 4:
            if(listaVazia(l) == 1)
            {
                printf("A lista esta vazia.\n");
            }
            else
            {
                printf("A lista nao esta vazia.\n");
            }
            break;
        case 5:
            printf("Digite o numero que deseja remover: ");
            scanf("%d", &numero);
            l = retiraLista(l, numero);
            break;
        case 6:
            printf("Digite um numero inteiro: ");
            scanf("%d", &numero);
            l = insereFinal(l, numero);
            break;
        case 7:
            liberaLista(l); 
            printf("Programa ecerrado.\n");
            break;
        default:
            printf("Opcao invalida. Digite outro numero\n\n");
            break;
        }
    }while(opcao != 7);
}

int main()
{
    menu();
    return 0;
}