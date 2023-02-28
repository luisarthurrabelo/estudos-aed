#include <stdlib.h>
#include "lista.h"
#define MAX 20

struct TADlista
{
  char palavras[MAX];
  int fim;
};

/*
    Opera��o: Cria_lista
    Entrada: nenhuma
    Pr�-condi��es: nenhuma
    Processo: aloca um espa�o na mem�ria para criar uma nova lista
    Sa�da: lista criada
    P�s-condi��o: lista criada
*/
Lista Cria_lista ()
{
    Lista elem = (Lista)malloc(sizeof(struct TADlista));
    if (elem != NULL)
        elem->fim = 0;
    return elem;
}

/*
    Opera��o: lista_vazia
    Entrada: endere�o da lista
    Pr�-condi��es: lista n�o ser inv�lida
    Processo: verifica se est� vazia
    Sa�da: 1 caso esteja vazia ou 0 caso o contr�rio
    P�s-condi��o: nenhuma
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
    Opera��o: lista_cheia
    Entrada: endere�o da lista
    Pr�-condi��es: lista n�o ser inv�lida
    Processo: verifica se est� cheia
    Sa�da: 1 caso esteja cheia ou 0 caso o contr�rio
    P�s-condi��o: nenhuma
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
    Opera��o: tamanho
    Entrada: endere�o da lista
    Pr�-condi��es: lista n�o ser inv�lida
    Processo: verifica se est� cheia
    Sa�da: tamanho da lista ou -1 caso n�o tenha tido sucesso
    P�s-condi��o: nenhuma
*/
int tamanho (Lista elem)
{
    if (elem == NULL)
        return -1;

    return elem->fim;
}

/*
    Opera��o: insere_ord
    Entrada: endere�o da lista, vari�vel do tipo char C
    Pr�-condi��es: lista n�o ser inv�lida e a lista n�o estar cheia
    Processo: adiciona de forma ordenada C na lista
    Sa�da: 1 caso tenha inserido ou 0 caso o contr�rio
    P�s-condi��o: lista com mais um elemento
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
    Opera��o: insere_ord
    Entrada: endere�o da lista e um caracter C
    Pr�-condi��es: lista n�o ser inv�lida e a lista n�o estar cheia
    Processo: remove de forma ordenada C na lista
    Sa�da: 1 caso tenha removido ou 0 caso o contr�rio
    P�s-condi��o: lista com menos um elemento
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
    Opera��o: remover_pos
    Entrada: endere�o da lista e vari�vel do tipo inteira POS
    Pr�-condi��es: lista n�o ser inv�lida, lista n�o estar vazia, posi��o n�o ser menor que 1 ou maior que o tamanho da lista
    Processo: remove o elemento presente na posi��o POS da lista
    Sa�da: 1 caso tenha removido ou 0 caso o contr�rio
    P�s-condi��o: lista com menos um elemento
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
    Opera��o: remover_vogais
    Entrada: endere�o da lista
    Pr�-condi��es: lista n�o ser inv�lida, lista n�o estar vazia
    Processo: remove todos os elementos que s�o vogais
    Sa�da: 1 caso tenha removido ou 0 caso o contr�rio
    P�s-condi��o: lista sem os elementos que s�o vogais
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
    Opera��o: intercala_listas
    Entrada: endere�o de duas listas
    Pr�-condi��es: as duas listas serem v�lidas e n�o estarem vazias
    Processo: cria uma lista que intercala os elementos de lst1 e lst2 mantendo os crit�rios de ordena��o
    Sa�da: lista criada
    P�s-condi��o: uma nova lista criada de forma intercalada
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
    Opera��o: get_elem_pos
    Entrada: endere�o da lista, vari�vel inteira POS e o endere�o de um caracter C
    Pr�-condi��es: lista ser v�lida, n�o estar vazia e a posi��o estar entre o tamanho da lista e 1
    Processo: coloca na vari�vel C o valor na posi��o POS da lista
    Sa�da: 1 caso tenha tido sucesso ou 0 caso o contr�rio
    P�s-condi��o: nenhuma
*/
int get_elem_pos (Lista elem, int pos, char *C)
{
    if (elem == NULL || lista_vazia(elem) || pos > elem->fim || pos < 1)
        return 0;

    *C = elem->palavras[pos - 1];
    return 1;
}

/*
    Opera��o: esvazia_lista
    Entrada: endere�o da lista
    Pr�-condi��es: lista ser v�lida e n�o estar vazia
    Processo: esvazia a lista
    Sa�da: 1 caso tenha esvaziado ou 0 caso o contr�rio
    P�s-condi��o: lista sem nenhum elemento
*/
int esvazia_lista(Lista elem)
{
    if(elem == NULL || lista_vazia(elem))
        return 0;
    elem->fim = 0;
    return 1;
}

/*
    Opera��o: apaga_lista
    Entrada: endere�o da lista
    Pr�-condi��es: lista ser v�lida
    Processo: apaga a lista
    Sa�da: 1 caso tenha apagado ou 0 caso o contr�rio
    P�s-condi��o: lista apagada
*/
int apaga_lista(Lista *elem)
{
    if(*elem == NULL)
        return 0;
    free(*elem);
    *elem = NULL;
    return 1;
}
