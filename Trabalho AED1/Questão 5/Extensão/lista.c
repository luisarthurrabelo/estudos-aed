#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
};

/*
    Opera��o Cria_lista:

    -Entrada: nenhuma

    -Pr�-condi��o: nenhuma

    -Processo: nenhuma

    -Sa�da: endere�o nulo

    -P�s-condi��o: nenhuma
*/
Lista Cria_lista ()
{
    return NULL; // Retorna nulo
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
    if (lst == NULL) // Se a lista apontar para nulo
        return 1; // Sucesso
    else
        return 0; // Falha
}

/*
    Opera��o insere_final:

    -Entrada: endere�o do endere�o de uma lista, elemento a ser adicionado (inteiro)

    -Pr�-condi��o: nenhuma

    -Processo: alocar um n� e alterar o valor do elemento pelo par�metro passado, adicionar no final da lista esse n�

    -Sa�da: 1 caso inseriu ou 0 caso o contr�rio

    -P�s-condi��o: lista com mais um n�
*/
int insere_final (Lista *lst, int info)
{
    Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o n�

    if (n == NULL)
        return 0; // Falha caso n�o tenha tido sucesso a aloca��o

    n->info = info; // Copia para o n� o valor passado como par�metro

    if (lista_vazia(*lst)) // Se a lista estiver vazia
    {
        n->prox = n;
        *lst = n; // Adiciona na lista o primeiro n�
    }
    else
    {
        n->prox = (*lst)->prox;
        (*lst)->prox = n;
        *lst = n; // Adiciona no final da lista o n�
    }

    return 1;
}

/*
    Opera��o insere_inicio:

    -Entrada: endere�o do endere�o de uma lista, elemento a ser adicionado (inteiro)

    -Pr�-condi��o: nenhuma

    -Processo: alocar um n� e alterar o valor do elemento pelo par�metro passado, adicionar no in�cio da lista esse n�

    -Sa�da: 1 caso inseriu ou 0 caso o contr�rio

    -P�s-condi��o: lista com mais um n�
*/
int insere_inicio (Lista *lst, int info)
{
    Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o n�

    if (n == NULL)
        return 0; // Falha caso n�o tenha tido sucesso a aloca��o

    n->info = info; // Copia para o n� o valor passado como par�metro

    if (lista_vazia(*lst)) // Se a lista estiver vazia
    {
        n->prox = n;
        *lst = n; // Adiciona na lista o primeiro n�
    }
    else
    {
        n->prox = (*lst)->prox;
        (*lst)->prox = n; // Adiciona no in�cio da lista n�
    }

    return 1;
}

/*
    Opera��o insere_pos:

    -Entrada: endere�o do endere�o de uma lista, elemento a ser adicionado (inteiro), vari�vel inteira com a posi��o desejada

    -Pr�-condi��o: lista n�o estar vazia e a posi��o n�o ser menor que 1

    -Processo: percorre a lista at� achar a posi��o desejada e aloca um novo n� para ocupar essa posi��o

    -Sa�da: 1 caso inseriu ou 0 caso o contr�rio

    -P�s-condi��o: lista com mais um n�
*/
int insere_pos (Lista *lst, int info, int pos)
{
    if(pos < 1) // Se a lista for vazia ou for uma posi��o menor que 1
        return 0; // Falha

    if(lista_vazia(*lst))
    {
        Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o n�

        if (n == NULL)
            return 0; // Falha caso n�o tenha tido sucesso a aloca��o

        n->info = info; // O n� alocado recebe o a informa��o a ser substitu�da
        n->prox = n;
        *lst = n;
        return 1;
    }

    int i = 1; // Come�a na primeira posi��o
    Lista aux = *lst; // Recebe o �ltimo n� da lista

    while (aux->prox != *lst && i < pos) // Enquanto o n� pr�ximo � diferente do �ltimo n� da lista e "i" � menor que a posi��o
    {
        aux = aux->prox; // Recebe o pr�ximo n�
        i++; // Avan�a uma posi��o
    }

    if (i < pos)
    {
        if (i + 1 != pos)
            return 0;
        else
            aux = aux->prox;
    }

    Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o n�

    if (n == NULL)
        return 0; // Falha caso n�o tenha tido sucesso a aloca��o

    n->info = info; // O n� alocado recebe o a informa��o a ser substitu�da
    n->prox = aux->prox;
    aux->prox = n;
    if (aux == *lst)
        *lst = n;

    return 1;
}

/*
    Opera��o remove_inicio:

    -Entrada: endere�o do endere�o de uma lista, endere�o de uma vari�vel inteira (info)

    -Pr�-condi��o: lista n�o estar vazia

    -Processo:  altera o valor de info para a informa��o presente no primeiro n� da lista e depois remove o mesmo

    -Sa�da: 1 caso removeu ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
*/
int remove_inicio (Lista *lst, int *info)
{
    if (lista_vazia(*lst)) // Se a lista estiver vazia
        return 0; // Falha

    Lista aux = (*lst)->prox; // Aponta para o in�cio da lista
    *info = aux->info; // O valor a ser removido, copiado para a vari�vel passada como par�metro

    if (*lst == (*lst)->prox) // Se a lista tem s� um elemento
        *lst = NULL;
    else
       (*lst)->prox = aux->prox; // O �ltimo n� aponta para o segundo n� da lista

    free(aux); // Libera a mem�ria do primeiro n� da lista

    return 1; // Sucesso
}

/*
    Opera��o remove_final:

    -Entrada: endere�o do endere�o de uma lista, endere�o de uma vari�vel inteira (info)

    -Pr�-condi��o: lista n�o estar vazia

    -Processo:  altera o valor de info para a informa��o presente no �ltimo n� da lista e depois remove o mesmo

    -Sa�da: 1 caso removeu ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
*/
int remove_final (Lista *lst, int *info)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha

    Lista aux = *lst; // Aponta para o fim da lista

    *info = aux->info; // O valor a ser removido, copiado para a vari�vel passada como par�metro

    if (*lst == (*lst)->prox) // Se a lista tem s� um elemento
    {
        *lst = NULL; // Remove o elemento
        free(aux);
    }
    else
    {
        while (aux->prox != (*lst)) // Percorre a lista at� o pen�ltimo elemento da lista
        {
            aux = aux->prox;
        }

        Lista aux2 = aux->prox;
        aux->prox = aux2->prox; // Faz o pen�ltimo elemento apontar para o primeiro elemento da lista
        *lst = aux; // Faz a lista apontar para pen�ltimo elemento
        free(aux2); // Libera a mem�ria do �ltimo elemento
    }

    return 1;
}

/*
    Opera��o remove_pares:

    -Entrada: endere�o do endere�o de uma lista

    -Pr�-condi��o: a lista n�o estar vazia

    -Processo: remove todos os n�meros pares da lista

    -Sa�da: 1 caso forem removidos ou 0 caso o contr�rio

    -P�s-condi��o: lista sem os elementos pares
*/
int remove_pares (Lista *lst)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha

    Lista aux = (*lst); // Aponta para o �ltimo n� da lista

    while (aux->prox != (*lst)) // Enquanto o pr�ximo n� � diferente do �ltimo n�
    {

        if (aux->prox->info % 2 == 0) // Se o pr�ximo n� for um n�mero par
        {
            Lista aux2 = aux->prox; // Recebe o valor do pr�ximo n�
            aux->prox = aux2->prox; // O pr�ximo do n� atual ser� o pr�ximo do pr�ximo n�
            free(aux2); // Libera o pr�ximo n�
        }
        else
            aux = aux->prox; // Recebe o valor do pr�ximo n�
    }

    if((*lst)->info % 2 == 0) // Verifica se o �ltimo n� � par
    {
        if ((*lst) == (*lst)->prox) // Se tiver s� um elemento na lista
        {
            aux = (*lst);
            *lst = NULL;
            free(aux); // Libera a mem�ria desse elemento
        }
        else
        {
            Lista aux2 = *lst; // Recebe o �ltimo n� da lista
            aux->prox = (*lst)->prox; // O pr�ximo do pen�ltimo n� apontar� para o primeiro n� da lista
            *lst = aux; // A lista agora aponta para o pen�ltimo n�
            free(aux2); // Libera o �ltimo n�
        }

    }

    return 1;
}

/*
    Opera��o get_elem_pos:

    -Entrada: endere�o de uma lista, uma vari�vel inteira P (Posi��o desejada) e o endere�o de um n�mero inteiro I

    -Pr�-condi��o: A lista n�o estar vazia e a posi��o P ser maior ou igual a 1

    -Processo: Percorre a lista at� chegar na posi��o desejada e adiciona a informa��o do n� encontrado na vari�vel I

    -Sa�da: 1 caso tenha tido sucesso ou 0 caso o contr�rio

    -P�s-condi��o: nenhuma
*/
int get_elem_pos (Lista lst, int pos, int *info)
{
    if (lista_vazia(lst) || pos < 1) // Se a lista for vazia ou for uma posi��o menor que 1
        return 0; // Falha

    int i = 1;
    i = 1;
    Lista aux = lst->prox;

    while (aux != lst && i < pos) // Percorre a lista at� o i ser igual posi��o, enquanto o n� n�o � igual o �ltimo n�
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
    if (lista_vazia(*lst))
        return 0; //Falha

    while (*lst != (*lst)->prox) // Enquanto n�o tem apenas um elemento na lista
    {
        Lista aux = (*lst)->prox;
        (*lst)->prox = aux->prox;
        free(aux);

    }
    Lista aux = *lst;
    *lst = NULL;
    free(aux);
    return 1; //Sucesso
}


