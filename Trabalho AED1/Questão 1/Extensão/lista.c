#include <stdlib.h>
#include "lista.h"
#define MAX 20

struct TADlista
{
  char palavras[MAX];
  int fim;
};

/*
    Operação: Cria_lista
    Entrada: nenhuma
    Pré-condições: nenhuma
    Processo: aloca um espaço na memória para criar uma nova lista
    Saída: lista criada
    Pós-condição: lista criada
*/
Lista Cria_lista ()
{
    Lista elem = (Lista)malloc(sizeof(struct TADlista));
    if (elem != NULL)
        elem->fim = 0;
    return elem;
}

/*
    Operação: lista_vazia
    Entrada: endereço da lista
    Pré-condições: lista não ser inválida
    Processo: verifica se está vazia
    Saída: 1 caso esteja vazia ou 0 caso o contrário
    Pós-condição: nenhuma
*/
int lista_vazia (Lista elem)
{
    if (elem == NULL)
        return 0;

    if (elem->fim == 0)
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
int lista_cheia (Lista elem)
{
    if (elem == NULL)
        return 0;

    if (elem->fim == MAX)
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
int tamanho (Lista elem)
{
    if (elem == NULL)
        return -1;

    return elem->fim;
}

/*
    Operação: insere_ord
    Entrada: endereço da lista, variável do tipo char C
    Pré-condições: lista não ser inválida e a lista não estar cheia
    Processo: adiciona de forma ordenada C na lista
    Saída: 1 caso tenha inserido ou 0 caso o contrário
    Pós-condição: lista com mais um elemento
*/
int insere_ord (Lista elem, char palavra)
{
    if (elem == NULL || lista_cheia(elem) == 1)
        return 0;

    if (lista_vazia(elem) == 1 || palavra >= elem->palavras[elem->fim-1])
        elem->palavras[elem->fim] = palavra;
    else
    {
        int i, aux = 0;
        while (palavra >= elem->palavras[aux])
            aux++;

        for (i = elem->fim;i > aux;i--)
            elem->palavras[i] = elem->palavras[i-1];

        elem->palavras[aux] = palavra;
    }
    elem->fim++;
    return 1;
}

/*
    Operação: insere_ord
    Entrada: endereço da lista e um caracter C
    Pré-condições: lista não ser inválida e a lista não estar cheia
    Processo: remove de forma ordenada C na lista
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: lista com menos um elemento
*/
int remove_ord (Lista elem, char palavra)
{
    if (elem == NULL || lista_vazia(elem) || palavra > elem->palavras[elem->fim-1])
        return 0;


    int i;
    int aux = 0;

    while (aux < elem->fim && elem->palavras[aux] < palavra)
        aux++;

    if (aux == elem->fim || elem->palavras[aux] > palavra)
        return 0;

    for (i = aux+1;i < elem->fim;i++)
        elem->palavras[i-1] = elem->palavras[i];

    elem->fim--;
    return 1;
}

/*
    Operação: remover_pos
    Entrada: endereço da lista e variável do tipo inteira POS
    Pré-condições: lista não ser inválida, lista não estar vazia, posição não ser menor que 1 ou maior que o tamanho da lista
    Processo: remove o elemento presente na posição POS da lista
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: lista com menos um elemento
*/
int remover_pos (Lista elem, int pos)
{
    if (elem == NULL || lista_vazia(elem) || pos < 1 || pos > elem->fim)
        return 0;
    int i;
    for (i = pos;i < elem->fim;i++)
        elem->palavras[i-1] = elem->palavras[i];
    elem->fim--;
    return 1;
}

/*
    Operação: remover_vogais
    Entrada: endereço da lista
    Pré-condições: lista não ser inválida, lista não estar vazia
    Processo: remove todos os elementos que são vogais
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: lista sem os elementos que são vogais
*/
int remover_vogais (Lista elem)
{
    if (elem == NULL || lista_vazia(elem))
        return 0;
    int i, aux = 0;

    while (aux < elem->fim)
    {
        if (elem->palavras[aux] == 'A' || elem->palavras[aux] == 'E' || elem->palavras[aux] == 'I' || elem->palavras[aux] == 'O' || elem->palavras[aux] == 'U'
            || elem->palavras[aux] == 'a' || elem->palavras[aux] == 'e' || elem->palavras[aux] == 'i' || elem->palavras[aux] == 'o' || elem->palavras[aux] == 'u')
        {
                for (i = aux+1;i < elem->fim;i++)
                    elem->palavras[i-1] = elem->palavras[i];
                elem->fim--;
        }
        else
            aux++;
    }
    return 1;
}

/*
    Operação: intercala_listas
    Entrada: endereço de duas listas
    Pré-condições: as duas listas serem válidas e não estarem vazias
    Processo: cria uma lista que intercala os elementos de lst1 e lst2 mantendo os critérios de ordenação
    Saída: lista criada
    Pós-condição: uma nova lista criada de forma intercalada
*/
Lista intercala_listas(Lista lst1, Lista lst2)
{
    if (lst1 == NULL || lst2 == NULL ||lista_vazia(lst1) || lista_vazia(lst2))
        return NULL;

    int i1 = 0, i2 = 0, aux = 0;
    Lista elem = (Lista)malloc(sizeof(struct TADlista));

    if (elem == NULL)
        return NULL;

    elem->fim = 0;
    while (1)
    {
        if (i1 < lst1->fim && i2 < lst2->fim)
        {
            if (lst1->palavras[i1] <= lst2->palavras[i2])
            {
                    elem->palavras[aux] = lst1->palavras[i1];
                    i1++;
            }
            else
            {
                    elem->palavras[aux] = lst2->palavras[i2];
                    i2++;
            }

        }
        else if (i1 < lst1->fim)
        {
            elem->palavras[aux] = lst1->palavras[i1];
            i1++;
        }
        else if(i2 < lst2->fim)
        {
            elem->palavras[aux] = lst2->palavras[i2];
            i2++;
        }
        else
            break;
        aux++;
        elem->fim++;
    }

    return elem;
}

/*
    Operação: get_elem_pos
    Entrada: endereço da lista, variável inteira POS e o endereço de um caracter C
    Pré-condições: lista ser válida, não estar vazia e a posição estar entre o tamanho da lista e 1
    Processo: coloca na variável C o valor na posição POS da lista
    Saída: 1 caso tenha tido sucesso ou 0 caso o contrário
    Pós-condição: nenhuma
*/
int get_elem_pos (Lista elem, int pos, char *C)
{
    if (elem == NULL || lista_vazia(elem) || pos > elem->fim || pos < 1)
        return 0;

    *C = elem->palavras[pos - 1];
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
int esvazia_lista(Lista elem)
{
    if(elem == NULL || lista_vazia(elem))
        return 0;
    elem->fim = 0;
    return 1;
}

/*
    Operação: apaga_lista
    Entrada: endereço da lista
    Pré-condições: lista ser válida
    Processo: apaga a lista
    Saída: 1 caso tenha apagado ou 0 caso o contrário
    Pós-condição: lista apagada
*/
int apaga_lista(Lista *elem)
{
    if(*elem == NULL)
        return 0;
    free(*elem);
    *elem = NULL;
    return 1;
}
