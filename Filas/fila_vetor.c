// Implementação de Fila com vetor

#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct fila
{
    int n; // Número de elementos da fila
    int ini; // Posição inicial
    int vet[MAX];
};

typedef struct fila Fila;

// Cria uma Fila vazia
Fila* criaFila()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->n = 0;
    f->ini = 0;

    return f;
}

// Insere um elemento no início da Fila
void insereFila(Fila* f, int v)
{
    int fim;

    if(f->n == MAX)
    {
        printf("A capacidade da fila estourou.\n");
        exit(1);
    }

    fim = (f->ini + f->n) % MAX; // Estratégia para trabalhar com a fila "circular"
    f->vet[fim] = v;
    f->n++;
}

// Verifica se a Fila está vazia
int filaVazia(Fila* f)
{
    if(f->n == 0)
    {
        return 1;
    }

    return 0;
}

// Retira um elemento do início da Fila
int retiraFila(Fila* f)
{
    int v;

    if(filaVazia(f) == 1)
    {
        printf("Fila vazia.\n");
        exit(1);
    }

    v = f->vet[f->ini];
    f->ini = (f->ini + 1) % MAX;
    f->n--;
    return v;
}

// Libera a memória alocada pela Fila
void liberaFila(Fila* f)
{
    free(f);
}

// Imprime os elementos da Fila
void imprimeFila(Fila* f)
{
    for(int i = 0; i < f->n; i++)
    {
        printf("%d ", f->vet[(f->ini + i) % MAX]);
    }
    printf("\n");
}

// Menu para testar as funções
void menu()
{
    Fila* f;
    int opcao;
    int numero;

    f = criaFila();

    printf("Uma Fila vazia foi criada...\n\n");

    do
    {
        printf("Digite o numero da opcao desejada\n");
        printf("1- Inserir elemento na fila\n");
        printf("2- Remover elemento do inicio da fila\n");
        printf("3- Imprimir Fila\n");
        printf("4- Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um numero inteiro: ");
            scanf("%d", &numero);
            insereFila(f, numero);
            printf("Elemento inserido com sucesso\n\n");
            break;
        case 2:
            printf("O numero %d foi removido do inicio da Fila.\n", retiraFila(f));
            break;
        case 3:
            imprimeFila(f);
            break;
        case 4:
            printf("Programa encerrado.\n");
            break;
        default:
            printf("Opcao invalida. Digite outro numero\n");
            break;
        }
    } while (opcao != 4);
    
}

int main()
{
    menu();
    return 0;
}