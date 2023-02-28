#include <stdlib.h>
#include "lista.h"

struct no
{
    double info;
    struct no *prox;
    struct no *ant;
};

/*
    Opera��o Cria_lista:

    -Entrada: nenhuma

    -Pr�-condi��o: nenhuma

    -Processo: nenhum

    -Sa�da: endere�o nulo

    -P�s-condi��o: nenhuma
*/
Lista Cria_lista ()
{
    return NULL; // Retorn nulo
}

/*
    Opera��o lista_vazia:

    -Entrada: endere�o de uma lista

    -Pr�-condi��o: nenhuma

    -Processo: verifica se a lista est� vazia

    -Sa�da: 1 se vazia ou 0 caso contr�rio

    -P�s-condi��o: nenhuma
*/
int lista_vazia (Lista lst)
{
    if (lst == NULL) // Lista apontar para nulo
        return 1; // Sucesso
    else
        return 0; // Falha
}

/*
    Opera��o insere_elem:

    -Entrada: endere�o de um endere�o de uma lista, elemento a ser adicionado (real)

    -Pr�-condi��o: nenhuma

    -Processo: alocar um n� n e alterar o valor do elemento pelo par�metro passado, adicionar no in�cio da lista esse n�

    -Sa�da: 1 caso inseriu ou 0 caso o contr�rio

    -P�s-condi��o: lista com mais um n�
*/
int insere_elem (Lista *lst, double info)
{
    Lista n = (Lista)malloc(sizeof(struct no)); // Faz a aloca��o de mem�ria do n� a ser adicionado na lista

    if (n == NULL) // Aloca��o n�o ter sucesso
        return 0; // Falha

    n->info = info; // O a informa��o do n� recebe o n�mero real passado como par�metro
    n->prox = *lst; // O pr�ximo n� depois de n, ser� o primeiro n� da lista
    n->ant = NULL; // o n� anterior de n � nulo

    if (!lista_vazia(*lst)) // Se a lista n�o estiver vazia
        (*lst)->ant = n; // O anterior do primeiro n� ser� o n

    *lst = n; // Lista aponta para n agora

    return 1;
}

/*
    Opera��o insere_pos:

    -Entrada: endere�o de um endere�o de uma lista, elemento a ser adicionado (real), vari�vel inteira com a posi��o desejada

    -Pr�-condi��o: lista n�o estar vazia e a posi��o n�o ser menor que 1

    -Processo: percorre a lista at� achar a posi��o desejada e insere um n� com o valor passado de par�metro

    -Sa�da: 1 caso inseriu ou 0 caso o contr�rio

    -P�s-condi��o: lista com mais um n�
*/
int insere_pos (Lista *lst, double info, int pos)
{
    if(pos < 1) // Lista estar vazia ou a posi��o ser menor que 1
        return 0; // Falha

    Lista aux = *lst; // N� auxiliar recebe o primeiro n� da lista

    if (!lista_vazia(*lst))
    {
        int i = 1; // Primeira posi��o
        while (aux->prox != NULL && i < pos) // Enquanto o pr�ximo n� n�o � nulo e a posi��o atual n�o � menor que a posi��o desejada
        {
            aux = aux->prox; // Recebe o pr�ximo n�
            i++; // Avan�a uma posi��o
        }

        if (i < pos)
        {
            if (i + 1 != pos)
                return 0;
            else // Adicionar na �ltima posi��o da lista
            {
                Lista n = (Lista)malloc(sizeof(struct no)); // Faz a aloca��o de mem�ria do n� a ser adicionado na lista

                if (n == NULL) // Aloca��o n�o ter sucesso
                    return 0; // Falha

                n->info = info; // Alterar o valor da posi��o desejada pelo passado como par�metro
                aux->prox = n;
                n->ant = aux;
                n->prox = NULL;
                return 1;
        }
    }
    }


    Lista n = (Lista)malloc(sizeof(struct no)); // Faz a aloca��o de mem�ria do n� a ser adicionado na lista

    if (n == NULL) // Aloca��o n�o ter sucesso
        return 0; // Falha

    n->info = info; // Alterar o valor da posi��o desejada pelo passado como par�metro

    n->prox = aux;

    if (*lst == NULL) // Se a lista estiver vazia
        n->ant = NULL;

    if (*lst != NULL) // Se a lista nao estiver vazia
    {
        n->ant = aux->ant;

        if (aux->ant != NULL)
            aux->ant->prox = n;

        aux->ant = n;
    }
    if (aux == *lst)
        *lst = n;

    return 1; // Sucesso
}

/*
    Opera��o remove_elem:

    -Entrada: endere�o de um endere�o de uma lista, uma vari�vel real (info)

    -Pr�-condi��o: lista n�o estar vazia

    -Processo: percorre a lista at� encontrar um valor da lista igual � info e depois remove o mesmo da lista

    -Sa�da: 1 caso removeu ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
*/
int remove_elem (Lista *lst, double info)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha
    Lista aux = *lst; // N� auxiliar recebe o primeiro n� da lista

    while (aux->prox != NULL && aux->info != info) // Enquanto o pr�ximo n� n�o � nulo e o elemento � diferente do desejado
        aux = aux->prox; // Avan�a para o pr�ximo n�

    if (aux->info != info) // Se n�o tiver encontrado o elemento
        return 0; // Falha

    if (aux->prox != NULL)
        aux->prox->ant = aux->ant;

    if (aux->ant != NULL)
        aux->ant->prox = aux->prox;


    if (aux == *lst)
        *lst = aux->prox;

    free(aux); // Libera a mem�ria desse n�

    return 1;
}

/*
    Opera��o remove_todos:

    -Entrada: endere�o de um endere�o de uma lista, uma vari�vel real (info)

    -Pr�-condi��o: lista n�o estar vazia

    -Processo:  percorre a lista at� encontrar valores da lista igual � info e depois remov�-los da lista

    -Sa�da: 1 caso removeu ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
*/
int remove_todos (Lista *lst, double info)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha
    Lista aux = *lst; // N� auxiliar recebe o primeiro n� da lista

    while (aux != NULL) // Enquanto o n� atual � diferente de nulo
    {
        if (aux->info == info) // Se for igual ao valor passado por par�metro
        {
            Lista aux2 = aux;

            if (aux2->prox != NULL)
                aux2->prox->ant = aux2->ant;

            if (aux2->ant != NULL)
                aux2->ant->prox = aux2->prox;

            if (aux2 == *lst)
                *lst = aux2->prox;

            aux = aux2->prox;
            free(aux2); // Remove o n�
        }
        else
            aux = aux->prox; // Passa para o pr�ximo n�
    }

    return 1; // Sucesso
}

/*
    Opera��o remove_menor:

    -Entrada: endere�o de um endere�o de uma lista, endere�o de uma vari�vel real (info)

    -Pr�-condi��o: lista n�o estar vazia

    -Processo: percorre a lista at� achar o menor elemento, altera o valor de info para a informa��o presente nesse n�

    -Sa�da: 1 caso removeu ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
*/
int remove_menor (Lista *lst, double *menor)
{
    if (lista_vazia(*lst)) // Lista vazia
        return 0; // Falha

    Lista aux2 = *lst;
    Lista aux = aux2;
    int i = 1;
    *menor = aux2->info;

    while (aux2->prox != NULL) // Percorre a lista at� achar o menor valor
    {
        aux2 = aux2->prox;
        i++;

        if (aux2->info < *menor)
        {
            *menor = aux2->info;
            aux = aux2;
        }

    }
    aux2 = aux;
    if (aux2->prox != NULL)
        aux2->prox->ant = aux2->ant;

    if (aux2->ant != NULL)
            aux2->ant->prox = aux2->prox;

    if (aux2 == *lst)
        *lst = aux2->prox;

    aux = aux2->prox;

    free(aux2); // Libera a mem�rio do menor valor

    return 1; // Sucesso
}

/*
    Opera��o inverte:

    -Entrada: endere�o do endere�o de duas listas (L1 e L2)

    -Pr�-condi��o: L1 n�o estar vazia e L2 estar vazia

    -Processo: Coloca na lista L2 a lista L1 de forma invertida

    -Sa�da: 1 caso a inver��o tenha tido sucesso ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
*/
int inverte (Lista lst, Lista *lst2)
{
    if (lista_vazia(lst) || !lista_vazia(*lst2)) // L1 n�o estar vazia e L2 estar vazia
        return 0; // Falha

    Lista aux = lst; // Recebe o primeiro n� de L1
    Lista n = (Lista)malloc(sizeof(struct no)); // Faz a aloca��o de mem�ria do n� a ser adicionado em L2

    if (n == NULL)
        return 0;

    n->info = aux->info; // Adiciona na informa��o do n� de L2 as informa��es do primeiro n� de L1
    n->ant = NULL;
    n->prox = NULL;
    *lst2 = n; // L2 aponta para o primeiro n� igual a n

    while (aux->prox != NULL) // Enquanto o pr�ximo n� de L1 � diferente de nulo
    {

        aux = aux->prox; // Avan�a um n�
        Lista n = (Lista)malloc(sizeof(struct no)); // Faz a aloca��o de mem�ria do n� a ser adicionado em L2
        n->info = aux->info; // Adiciona na informa��o do n� de L2 as informa��es do primeiro n� de L1

        if (n == NULL)
            return 0;

        (*lst2)->ant = n; // O anterior do primeiro n� de L2 ser� n
        n->prox = *lst2; // O pr�ximo n� de n ser� o primeiro n� de L2
        n->ant = NULL; // O anterior de n ser� nulo

        *lst2 = n; // A lista agora aponta para n
    }

    return 1;
}

/*
    Opera��o get_elem_pos:

    -Entrada: endere�o de uma lista, uma vari�vel inteira P (Posi��o desejada) e o endere�o de um n�mero real R

    -Pr�-condi��o: A lista n�o estar vazia e a posi��o P ser maior ou igual a 1

    -Processo: Percorre a lista at� chegar na posi��o desejada e adiciona a informa��o do n� encontrado na vari�vel R

    -Sa�da: 1 caso tenha tido sucesso ou 0 caso o contr�rio

    -P�s-condi��o: nenhuma
*/
int get_elem_pos (Lista lst, int pos, double *info)
{
    if (lista_vazia(lst) || pos < 1) // Se a lista for vazia ou for uma posi��o menor que 1
        return 0; // Falha

    int i = 1;
    i = 1;
    Lista aux = lst;

    while (aux->prox != NULL && i < pos) // Percorre a lista at� o i ser igual posi��o, enquanto o pr�ximo n� n�o � nulo
    {
        aux = aux->prox; // Recebe o pr�ximo n�
        i++; // Avan�a para o pr�ximo n�
    }

    if (i < pos)  // Se i for menor que a posi��o desejada quer dizer que n�o foi poss�vel encontrar o elemento
        return 0; // Falha

    *info = aux->info; // Copia o valor desejado da lista para a vari�vel passada como refer�ncia
    return 1; // Sucesso
}

/*
    Opera��o apaga_lista:

    -Entrada: endere�o do endere�o de uma lista

    -Pr�-condi��o: lista n�o estar vazia

    -Processo: remover todos os elementos da lista, at� a mesma ficar vazia

    -Sa�da: 1 caso tenha apagado a lista ou 0 caso o contr�rio

    -P�s-condi��o: lista apagada
*/
int apaga_lista (Lista *lst)
{
    if (lst == NULL)
        return 0; //Falha

    while (*lst != NULL) // Enquanto a lista n�o � vazia
    {
        Lista aux = *lst; // Vai removendo o �ltimo elemento da lista at� ela ficar vazia
        *lst = aux->prox;
        free(aux); // Libera a mem�ria do n� atual
    }
    return 1; //Sucesso
}


