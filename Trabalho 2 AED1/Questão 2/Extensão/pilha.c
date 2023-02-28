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
    Operação: cria_pilha
    Entrada: nenhuma
    Pré-condições: nenhuma
    Processo: cria uma pilha e a coloca no estado de pilha vazia
    Saída: endereço da pilha criada
    Pós-condição: nenhuma
*/

Pilha cria_pilha()
{
    return NULL;
}

/*
    Operação: pilha_vazia
    Entrada: endereço da Pilha
    Pré-condições: nenhuma
    Processo: verifica se a pilha está vazia
    Saída: 1 caso esteja vazia ou 0 caso o contrário
    Pós-condição: nenhuma
*/

int pilha_vazia(Pilha p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}

/*
    Operação: push
    Entrada: endereço do endereço da pilha, um elemento do tipo Union Info e o inteiro represetando qual tipo será inserido
    Pré-condições: nenhuma
    Processo: inserir o elemento informado no topo da pilha
    Saída: 1 caso tenha inserido ou 0 caso o contrário
    Pós-condição: a pilha de entrada terá um elemento a mais sendo um caractere ou um numero real
*/

int push(Pilha *p, Info elem, int i)
{
    Pilha N;
    N=(Pilha) malloc(sizeof(struct no));

    if(N==NULL)
        return 0; //A alacoção falhou.

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
    Operação: pop
    Entrada: endereço do endereço da pilha e o endereço de um elemento do tipo Union Info
    Pré-condições: pilha não estar vazia
    Processo: remover o elemento que está no topo da pilha retorná-lo
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: A pilha de entrada com um elemento a menos e o elemento removido com o tipo Union Info
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
    Operação: le_Topo
    Entrada: endereço da pilha e o endereço de um elemento do tipo Union Info
    Pré-condições: pilha não estar vazia
    Processo: retornar o valor do elemento que está no topo da pilha sem remove-lo
    Saída: 1 caso tenha tido sucesso ou 0 caso o contrário
    Pós-condição: variável de retorno com o elemento do topo
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
    Operação: esvazia_Pilha
    Entrada: endereço da Pilha
    Pré-condições: Pilha ser válida e não estar vazia
    Processo: esvazia a Pilha
    Saída: 1 caso tenha esvaziado ou 0 caso o contrário
    Pós-condição: Pilha sem nenhum elemento
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



