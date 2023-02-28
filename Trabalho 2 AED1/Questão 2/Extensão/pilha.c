#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"
#define MAX 30

struct no
{
    int tipo;
    Info uniao;
    struct no* prox;
};

/*
    Opera��o: cria_pilha
    Entrada: nenhuma
    Pr�-condi��es: nenhuma
    Processo: cria uma pilha e a coloca no estado de pilha vazia
    Sa�da: endere�o da pilha criada
    P�s-condi��o: nenhuma
*/

Pilha cria_pilha()
{
    return NULL;
}

/*
    Opera��o: pilha_vazia
    Entrada: endere�o da Pilha
    Pr�-condi��es: nenhuma
    Processo: verifica se a pilha est� vazia
    Sa�da: 1 caso esteja vazia ou 0 caso o contr�rio
    P�s-condi��o: nenhuma
*/

int pilha_vazia(Pilha p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}

/*
    Opera��o: push
    Entrada: endere�o do endere�o da pilha, um elemento do tipo Union Info e o inteiro represetando qual tipo ser� inserido
    Pr�-condi��es: nenhuma
    Processo: inserir o elemento informado no topo da pilha
    Sa�da: 1 caso tenha inserido ou 0 caso o contr�rio
    P�s-condi��o: a pilha de entrada ter� um elemento a mais sendo um caractere ou um numero real
*/

int push(Pilha *p, Info elem, int i)
{
    Pilha N;
    N=(Pilha) malloc(sizeof(struct no));

    if(N==NULL)
        return 0; //A alaco��o falhou.

    N->tipo =  i;

    if(i == 0)
    {
        N ->uniao.nro = elem.nro;
    }
    else
    {
        N->uniao.ch = elem.ch;
    }

    N->prox = *p;
    *p=N;
    return 1; //Sucesso
}

/*
    Opera��o: pop
    Entrada: endere�o do endere�o da pilha e o endere�o de um elemento do tipo Union Info
    Pr�-condi��es: pilha n�o estar vazia
    Processo: remover o elemento que est� no topo da pilha retorn�-lo
    Sa�da: 1 caso tenha removido ou 0 caso o contr�rio
    P�s-condi��o: A pilha de entrada com um elemento a menos e o elemento removido com o tipo Union Info
*/

int pop(Pilha *p, Info *elem)
{
    if(pilha_vazia(*p)==1)
        return 0; // A pilha esta vazia

    Pilha aux = *p;

    if((*p)->tipo == 0)
    {
        elem->nro = (*p)->uniao.nro;
    }
    else
    {
        elem->ch = (*p)->uniao.ch;
    }
    aux = *p;
    *p = (*p)->prox;

    free(aux);
    return 1; //Sucesso
}

/*
    Opera��o: le_Topo
    Entrada: endere�o da pilha e o endere�o de um elemento do tipo Union Info
    Pr�-condi��es: pilha n�o estar vazia
    Processo: retornar o valor do elemento que est� no topo da pilha sem remove-lo
    Sa�da: 1 caso tenha tido sucesso ou 0 caso o contr�rio
    P�s-condi��o: vari�vel de retorno com o elemento do topo
*/

int le_topo(Pilha p, Info* elem)
{
    if (pilha_vazia(p) == 1)
        return 0;

    if(p->tipo == 0)
    {
        elem->nro = p->uniao.nro;
    }
    else
    {
        elem->ch = p->uniao.ch;
    }

    return 1;
}

/*
    Opera��o: esvazia_Pilha
    Entrada: endere�o da Pilha
    Pr�-condi��es: Pilha ser v�lida e n�o estar vazia
    Processo: esvazia a Pilha
    Sa�da: 1 caso tenha esvaziado ou 0 caso o contr�rio
    P�s-condi��o: Pilha sem nenhum elemento
*/

int esvazia_Pilha(Pilha* p)
{
    if (*p == NULL)
        return 0;

    while(*p != NULL)
    {
        Pilha aux = *p;
        *p = aux -> prox;
        free(aux);
    }
    return 1;
}



