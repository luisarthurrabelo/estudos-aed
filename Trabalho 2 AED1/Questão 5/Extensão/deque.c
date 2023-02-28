#include <stdlib.h>
#include <string.h>
#include "deque.h"
#define STR 21
#define MAX 11

struct deque
{
    char str[MAX][STR];
    int inicio, fim;
};

Deque cria_deque()
{
    Deque N = (Deque)malloc(sizeof(struct deque));
    if (N != NULL)
    {
        N->inicio = MAX - 1;
        N->fim = MAX - 1;
    }
    return N;
}

int deque_vazio(Deque deq)
{
    if (deq != NULL && deq->inicio == deq->fim)
        return 1;
    return 0;
}

int deque_cheio(Deque deq)
{
    if (deq != NULL && deq->inicio == (deq->fim + 1) % MAX)
        return 1;

    return 0;
}

int insere_fim(Deque deq, char *A)
{
    if (deque_cheio(deq))
        return 0;

    deq->fim = (deq->fim + 1) % MAX;
    strcpy(deq->str[deq->fim], A);
    return 1;
}

int insere_inicio(Deque deq, char *A)
{
    if (deque_cheio(deq))
        return 0;

    strcpy (deq->str[deq->inicio], A);
    deq->inicio = (deq->inicio - 1 + MAX) % MAX;
    return 1;
}

int remove_inicio(Deque deq, char *A)
{
    if (deque_vazio(deq))
        return 0;

    deq->inicio = (deq->inicio + 1) % MAX;
    strcpy (A, deq->str[deq->inicio]);

    return 1;
}

int remove_fim(Deque deq, char *A)
{
    if (deque_vazio(deq))
        return 0;

    strcpy (A, deq->str[deq->fim]);
    deq->fim = (deq->fim - 1 + MAX) % MAX;
    return 1;
}

int apaga_deque(Deque *deq)
{
    if(deq == NULL)
        return 0;

    free(*deq);
    *deq = NULL;
    return 1;
}

int esvazia_deque(Deque deq)
{
    if(deq == NULL || deque_vazio(deq))
        return 0;

    deq->inicio = MAX - 1;
    deq->fim = MAX - 1;
    return 1;
}
