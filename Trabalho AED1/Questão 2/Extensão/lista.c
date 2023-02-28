#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define MAX 10
#define STR 16

struct lista{
    char nome[MAX][STR];
    int qtd;
};

/*
    Operação: Cria_lista
    Entrada: nenhuma
    Pré-condições: nenhuma
    Processo: aloca um espaço na memória para criar uma nova lista
    Saída: lista criada
    Pós-condição: lista criada
*/
Lista cria_lista()
{
    Lista li = (Lista)malloc(sizeof(struct lista));
    if(li != NULL)
        li -> qtd = 0;
    return li;
}

/*
    Operação: lista_vazia
    Entrada: endereço da lista
    Pré-condições: lista não ser inválida
    Processo: verifica se está vazia
    Saída: 1 caso esteja vazia ou 0 caso o contrário
    Pós-condição: nenhuma
*/
int lista_vazia(Lista li)
{

    if(li == NULL)
        return 0;
    else if(li->qtd == 0)
        return 1;
    else
        return 0;
}

/*
    Operação: lista_cheia
    Entrada: endereço da lista
    Pré-condições: lista não ser inválida
    Processo: verifica se está cheia
    Saída: 1 caso esteja cheia ou 0 caso o contrário
    Pós-condição: nenhuma
*/
int lista_cheia(Lista li)
{
    if (li == NULL)
        return 0;

    if (li->qtd == MAX)
        return 1;
    else
        return 0;
}

/*
    Operação: tamanho
    Entrada: endereço da lista
    Pré-condições: lista não ser inválida
    Processo: verifica se está cheia
    Saída: tamanho da lista ou -1 caso não tenha tido sucesso
    Pós-condição: nenhuma
*/
int tamanho(Lista li)
{
    if(li == NULL)
        return -1;
    return li->qtd;
}

/*
    Operação: insere_elem
    Entrada: endereço da lista, uma string S
    Pré-condições: lista não ser inválida e a lista não estar cheia
    Processo: adiciona na última posição a string
    Saída: 1 caso tenha inserido ou 0 caso o contrário
    Pós-condição: lista com mais um elemento
*/
int insere_elem(Lista li, char *elem)
{
    if (li == NULL || lista_cheia(li) == 1)
        return 0;
    strcpy(li->nome[li->qtd], elem);                               // Insere elemento
    li->qtd++;
    return 1;
}

/*
    Operação: inserir_string_pos
    Entrada: endereço da lista,  uma string S e um inteiro POS
    Pré-condições: lista não ser inválida e a lista não estar cheia e POS ser uma posição válida
    Processo: adiciona na posição POS da lista S
    Saída: 1 caso tenha inserido ou 0 caso o contrário
    Pós-condição: lista com mais um elemento
*/
int inserir_string_pos(Lista li, char *x, int y)
{
    if(li == NULL || lista_cheia(li) == 1 || y < 1 || y > li->qtd+1)
        return 0;
    int aux = li->qtd++;

    while(aux >= y)
    {
        strcpy(li->nome[aux], li->nome[aux-1]);
        aux--;
    }
    strcpy(li->nome[y - 1], x);
    return 1;
}

/*
    Operação: remove_elem
    Entrada: endereço da lista, endereço de uma string S
    Pré-condições: lista não ser inválida e a lista não estar cheia
    Processo: adiciona na última posição a string
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: lista com menos um elemento
*/
int remove_elem(Lista li, char *elem)
{
    if (li == NULL || lista_vazia(li) == 1)
        return 0; // Falha
    int i = 0, Aux = 0;
    while (Aux < li->qtd && strcmp(li -> nome[Aux], elem) != 0)
        Aux++;
    if (Aux == li->qtd) // Final de lista (∄elem)
        return 0; // Falha
    // Deslocamento à esq. do sucessor até o final da lista
    for (i = Aux+1; i < li->qtd; i++)
    {
        strcpy(li->nome[i-1], li->nome[i]);
        li->qtd--; // Decremento do campo Fim
    }
    return 1; // Sucesso
}

/*
    Operação: remov_menor
    Entrada: endereço da lista, endereço de uma string S
    Pré-condições: lista não ser inválida e a lista não estar vazia
    Processo: remove o menor elemento da lista
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: lista com menos um elemento
*/
int remov_menor(Lista li)
{
    if (li == NULL || lista_vazia(li) == 1)
        return 0;
    int aux, i = 0;
    for(aux=1;aux<li->qtd;aux++)
    {
            if(strcmp(li->nome[aux], li->nome[i]) < 0)              //string 1 menor que string 2
                i = aux;
    }
    for(i = i+1; i < li->qtd; i++)
        strcpy(li->nome[i-1], li->nome[i]);
    li->qtd--;
    return 1; //Sucesso
}


/*
    Operação: get_elem
    Entrada: endereço da lista o endereço de um a string S e uma variável inteira POS
    Pré-condições: lista ser válida, não estar vazia e a posição estar entre o tamanho da lista e 1
    Processo: coloca na variável S o valor na posição POS da lista
    Saída: 1 caso tenha tido sucesso ou 0 caso o contrário
    Pós-condição: nenhuma
*/
int get_elem(Lista li, char *elem, int x)
{
    if(li == NULL || x > li -> qtd || x < 1 || lista_vazia(li) == 1)
        return 0;
    strcpy(elem, li -> nome[x - 1]);
    return 1;
}

/*
    Operação: concatenar_lista

    Entrada: endereço de duas listas L1 e L2
    Pré-condições: as listas serem válidas e não estarem vazias
    Processo: gera uma nova lista que é a concatenação de L1 e L2
    Saída: a lista criada
    Pós-condição: lista concatenada criada
*/
Lista concatenar_lista(Lista l1, Lista l2)
{
    if(l1 == NULL || l2 == NULL || lista_vazia(l1) || lista_vazia(l2))
        return 0;
    Lista l3 = cria_lista();

    if(l3 == NULL)
        return 0;
    int i;
    for(i = 0;i < l1->qtd; i++)
    {
        strcpy(l3->nome[i] ,l1->nome[i]);
        l3->qtd++;
    }
    for(i = 0;i < l2->qtd; i++)
    {
        strcpy(l3->nome[l3->qtd] ,l2->nome[i]);
        l3->qtd++;
    }

    return l3;

}

/*
    Operação: apaga_lista
    Entrada: endereço da lista
    Pré-condições: lista ser válida
    Processo: apaga a lista
    Saída: 1 caso tenha apagado ou 0 caso o contrário
    Pós-condição: lista apagada
*/
int apaga_lista(Lista *li)
{
    if(*li == NULL)
        return 0;
    free(*li);
    *li = NULL;
    return 1;
}

/*
    Operação: esvazia_lista
    Entrada: endereço da lista
    Pré-condições: lista ser válida e não estar vazia
    Processo: esvazia a lista
    Saída: 1 caso tenha esvaziado ou 0 caso o contrário
    Pós-condição: lista sem nenhum elemento
*/
int esvazia_lista(Lista li)
{
    if(li == NULL)
        return 0;
    li -> qtd = 0;
    return 1;
}


