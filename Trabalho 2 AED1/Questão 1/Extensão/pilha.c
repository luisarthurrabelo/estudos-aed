#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#define MAX 20

struct pilha{
    int numero[MAX];
    int topo;
};

/*
    Opera��o: cria_Pilha
    Entrada: nenhuma
    Pr�-condi��es: nenhuma
    Processo: cria uma pilha e a coloca no estado de pilha vazia
    Sa�da: endere�o da pilha criada
    P�s-condi��o: nenhuma
*/
Pilha cria_pilha(){

    Pilha p = (Pilha)malloc(sizeof(struct pilha));
    if(p != NULL)
        p -> topo = -1; //Coloca no estado de vazia
    return p;
}

/*
    Opera��o: pilha_vazia
    Entrada: endere�o da Pilha
    Pr�-condi��es: a pilha deve existir
    Processo: verifica se a pilha est� vazia
    Sa�da: 1 caso esteja vazia ou 0 caso o contr�rio
    P�s-condi��o: nenhuma
*/

int pilha_vazia(Pilha p){

    if(p -> topo == -1)
        return 1;
    else
        return 0;
}

/*
    Opera��o: pilha_cheia
    Entrada: endere�o da Pilha
    Pr�-condi��es: a pilha de deve existir
    Processo: verifica se a pilha est� cheia
    Sa�da: 1 caso esteja cheia ou 0 caso o contr�rio
    P�s-condi��o: nenhuma
*/

int pilha_cheia(Pilha li){

    if (li -> topo == MAX-1)
        return 1;
    else
        return 0;
}

/*
    Opera��o: push
    Entrada: endere�o da pilha e o elemento a ser inserido
    Pr�-condi��es: pilha n�o estar cheia
    Processo: inserir o elemento informado no topo da pilha
    Sa�da: 1 caso tenha inserido ou 0 caso o contr�rio
    P�s-condi��o: a pilha da entrada com um elemento a mais
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
    Opera��o: pop
    Entrada: endere�o da pilha e o endere�o de retorno do elemento do topo da pilha
    Pr�-condi��es: pilha n�o estar vazia
    Processo: remover o elemento que est� no topo da pilha retorn�-lo
    Sa�da: 1 caso tenha removido ou 0 caso o contr�rio
    P�s-condi��o: a pilha de entrada com um elemento a menos e a vari�vel de retorno com o elemento removido
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
    Opera��o: tamanho_Pilha
    Entrada: endere�o da lista
    Pr�-condi��es: lista n�o ser inv�lida
    Processo: verifica se est� cheia
    Sa�da: tamanho da lista ou -1 caso n�o tenha tido sucesso
    P�s-condi��o: nenhuma
*/

int tamanho_Pilha(Pilha p){

    if(p == NULL)
        return -1;

    return p->topo + 1;
}

/*
    Opera��o: get_Topo
    Entrada: endere�o da pilha e o endere�o de retorno do elemento do topo da pilha
    Pr�-condi��es: pilha n�o estar vazia
    Processo: retornar o valor do elemento que est� no topo da pilha sem remove-lo
    Sa�da: 1 caso tenha tido sucesso ou 0 caso o contr�rio
    P�s-condi��o: vari�vel de retorno com o elemento do topo
*/

int get_Topo(Pilha p, int elem){

    if(p == NULL || pilha_vazia(p) == 1)
        return 0;

    elem = p -> numero[p->topo]; //Retorna o elemento
    return 1;
}

/*
    Opera��o: apaga_Pilha
    Entrada: endere�o da Pilha
    Pr�-condi��es: Pilha ser v�lida
    Processo: Apaga a Pilha
    Sa�da: 1 caso tenha apagado ou 0 caso o contr�rio
    P�s-condi��o: Pilha apagada
*/
int apaga_Pilha(Pilha *p){

    if(*p == NULL)
        return 0;

    free(*p);
    *p = NULL;

    return 1;
}

/*
    Opera��o: esvazia_Pilha
    Entrada: endere�o da Pilha
    Pr�-condi��es: Pilha ser v�lida e n�o estar vazia
    Processo: Rsvazia a Pilha
    Sa�da: 1 caso tenha esvaziado ou 0 caso o contr�rio
    P�s-condi��o: Pilha vazia
*/
int esvazia_Pilha(Pilha p){

    if(p == NULL)
        return 0;

    p -> topo = -1;

    return 1;
}
