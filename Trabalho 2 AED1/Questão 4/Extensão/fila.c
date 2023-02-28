#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no
{
    Pessoa paciente;
    struct no *prox;
};

/*
    Opera��o cria_fila:

    - Entrada: Nenhuma

    - Pr�-condi��o: Nenhuma

    - Processo: Retorna NULL

    - Sa�da: NULL

    - P�s-condi��o: Nenhuma
*/

Fila cria_fila ()
{
    return NULL;
}

/*
    Opera��o fila_vazia:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila ser v�lida

    - Processo: Verifica se a fila � NULL

    - Sa�da: Retorna 1 se ela for NULL 0 caso n�o

    - P�s-condi��o: Nenhuma
*/

int fila_vazia (Fila f)
{
    if (f == NULL)
        return 1;
    else
        return 0;
}

/*
    - Opera��o: insere_ord

    - Entrada: endere�o da fila, vari�vel do tipo Pessoa

    - Pr�-condi��es: fila n�o ser inv�lida

    - Processo: adiciona de forma ordenada na fila

    - Sa�da: 1 caso tenha inserido ou 0 caso o contr�rio

    - P�s-condi��o: fila com mais um elemento
*/

int insere_ord (Fila *f, Pessoa elem)
{

    Fila N = (Fila)malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N -> paciente = elem;

    if (fila_vazia(*f))
    {
        N -> prox = N;
        *f = N;
    }
    else
    {
        Fila aux = *f;
        while (aux->prox != *f && aux->prox->paciente.gravidade < elem.gravidade)
            aux = aux->prox;


        if (aux->prox == *f && aux->prox->paciente.gravidade < elem.gravidade)
        {
            aux = aux->prox;
            N->prox = aux->prox;
            aux->prox = N;
            *f = N;
        }
        else
        {
            N->prox = aux->prox;
            aux->prox = N;
        }
    }


    return 1;
}

/*
    Opera��o remove_inicio:

    - Entrada: Endere�o da fila e endere�o de elem

    - Pr�-condi��o: Fila n�o estar vazia

    - Processo: Remove do in�cio da fila

    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o

    - P�s-condi��o: Fila com menos um elemento
*/

int remove_ini (Fila *f, Pessoa *elem)
{
    if (fila_vazia(*f))
        return 0;

    Fila aux = (*f) -> prox;
    *elem = aux -> paciente;

    if (*f ==  (*f) -> prox)
        *f = NULL;
    else
        (*f) -> prox = aux -> prox;

    free (aux);

    return 1;
}

/*
    Opera��o esvazia_fila:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Nenhuma

    - Processo: processo do apaga_fila(f)

    - Sa�da: retorna apaga_fila(f)

    - P�s-condi��o: Nenhuma
*/

int esvazia_fila (Fila *f)
{
    return apaga_fila(f);
}

/*
    Opera��o apaga_fila:

    - Entrada: Endere�o da fila

    - Pr�-condi��o: Fila ser vazia

    - Processo: Apaga a Fila

    - Sa�da: Retorna 1 caso tenha dado certo e 0 caso n�o

    - P�s-condi��o: Fila apagada
*/

int apaga_fila (Fila *f)
{
    if (fila_vazia(*f))
        return 0; //Falha

    while (*f != (*f)->prox) // Enquanto n�o tem apenas um elemento na lista
    {
        Fila aux = (*f)->prox;
        (*f)->prox = aux->prox;
        free(aux);

    }
    Fila aux = *f;
    *f = NULL;
    free(aux);

    return 1; //Sucesso
}

