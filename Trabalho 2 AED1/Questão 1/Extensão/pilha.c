#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#define MAX 20

struct pilha{
    int numero[MAX];
    int topo;
};

/*
    Operação: cria_Pilha
    Entrada: nenhuma
    Pré-condições: nenhuma
    Processo: cria uma pilha e a coloca no estado de pilha vazia
    Saída: endereço da pilha criada
    Pós-condição: nenhuma
*/
Pilha cria_pilha(){

    Pilha p = (Pilha)malloc(sizeof(struct pilha));
    if(p != NULL)
        p -> topo = -1; //Coloca no estado de vazia
    return p;
}

/*
    Operação: pilha_vazia
    Entrada: endereço da Pilha
    Pré-condições: a pilha deve existir
    Processo: verifica se a pilha está vazia
    Saída: 1 caso esteja vazia ou 0 caso o contrário
    Pós-condição: nenhuma
*/

int pilha_vazia(Pilha p){

    if(p -> topo == -1)
        return 1;
    else
        return 0;
}

/*
    Operação: pilha_cheia
    Entrada: endereço da Pilha
    Pré-condições: a pilha de deve existir
    Processo: verifica se a pilha está cheia
    Saída: 1 caso esteja cheia ou 0 caso o contrário
    Pós-condição: nenhuma
*/

int pilha_cheia(Pilha li){

    if (li -> topo == MAX-1)
        return 1;
    else
        return 0;
}

/*
    Operação: push
    Entrada: endereço da pilha e o elemento a ser inserido
    Pré-condições: pilha não estar cheia
    Processo: inserir o elemento informado no topo da pilha
    Saída: 1 caso tenha inserido ou 0 caso o contrário
    Pós-condição: a pilha da entrada com um elemento a mais
*/

int push(Pilha p, int *elem){

    if (p == NULL || pilha_cheia(p) == 1)
        return 0;

    //insere o elemento no topo

    p -> topo++;
    p->numero[p->topo] = *elem;
    return 1;
}

/*
    Operação: pop
    Entrada: endereço da pilha e o endereço de retorno do elemento do topo da pilha
    Pré-condições: pilha não estar vazia
    Processo: remover o elemento que está no topo da pilha retorná-lo
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: a pilha de entrada com um elemento a menos e a variável de retorno com o elemento removido
*/

int pop(Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0; // Falha

    *elem = p->numero[p->topo]; //Retorna o elemento
    p->topo--; // Remove o elemento do topo

    return 1; // Sucesso
}

/*
    Operação: tamanho_Pilha
    Entrada: endereço da lista
    Pré-condições: lista não ser inválida
    Processo: verifica se está cheia
    Saída: tamanho da lista ou -1 caso não tenha tido sucesso
    Pós-condição: nenhuma
*/

int tamanho_Pilha(Pilha p){

    if(p == NULL)
        return -1;

    return p->topo + 1;
}

/*
    Operação: get_Topo
    Entrada: endereço da pilha e o endereço de retorno do elemento do topo da pilha
    Pré-condições: pilha não estar vazia
    Processo: retornar o valor do elemento que está no topo da pilha sem remove-lo
    Saída: 1 caso tenha tido sucesso ou 0 caso o contrário
    Pós-condição: variável de retorno com o elemento do topo
*/

int get_Topo(Pilha p, int elem){

    if(p == NULL || pilha_vazia(p) == 1)
        return 0;

    elem = p -> numero[p->topo]; //Retorna o elemento
    return 1;
}

/*
    Operação: apaga_Pilha
    Entrada: endereço da Pilha
    Pré-condições: Pilha ser válida
    Processo: Apaga a Pilha
    Saída: 1 caso tenha apagado ou 0 caso o contrário
    Pós-condição: Pilha apagada
*/
int apaga_Pilha(Pilha *p){

    if(*p == NULL)
        return 0;

    free(*p);
    *p = NULL;

    return 1;
}

/*
    Operação: esvazia_Pilha
    Entrada: endereço da Pilha
    Pré-condições: Pilha ser válida e não estar vazia
    Processo: Rsvazia a Pilha
    Saída: 1 caso tenha esvaziado ou 0 caso o contrário
    Pós-condição: Pilha vazia
*/
int esvazia_Pilha(Pilha p){

    if(p == NULL)
        return 0;

    p -> topo = -1;

    return 1;
}
