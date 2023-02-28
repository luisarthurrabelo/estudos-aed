#include <stdlib.h>
#include "lista.h"

struct no
{
    double info;
    struct no *prox;
    struct no *ant;
};

/*
    Operação Cria_lista:

    -Entrada: nenhuma

    -Pré-condição: nenhuma

    -Processo: nenhum

    -Saída: endereço nulo

    -Pós-condição: nenhuma
*/
Lista Cria_lista ()
{
    return NULL; // Retorn nulo
}

/*
    Operação lista_vazia:

    -Entrada: endereço de uma lista

    -Pré-condição: nenhuma

    -Processo: verifica se a lista está vazia

    -Saída: 1 se vazia ou 0 caso contrário

    -Pós-condição: nenhuma
*/
int lista_vazia (Lista lst)
{
    if (lst == NULL) // Lista apontar para nulo
        return 1; // Sucesso
    else
        return 0; // Falha
}

/*
    Operação insere_elem:

    -Entrada: endereço de um endereço de uma lista, elemento a ser adicionado (real)

    -Pré-condição: nenhuma

    -Processo: alocar um nó n e alterar o valor do elemento pelo parâmetro passado, adicionar no início da lista esse nó

    -Saída: 1 caso inseriu ou 0 caso o contrário

    -Pós-condição: lista com mais um nó
*/
int insere_elem (Lista *lst, double info)
{
    Lista n = (Lista)malloc(sizeof(struct no)); // Faz a alocação de memória do nó a ser adicionado na lista

    if (n == NULL) // Alocação não ter sucesso
        return 0; // Falha

    n->info = info; // O a informação do nó recebe o número real passado como parâmetro
    n->prox = *lst; // O próximo nó depois de n, será o primeiro nó da lista
    n->ant = NULL; // o nó anterior de n é nulo

    if (!lista_vazia(*lst)) // Se a lista não estiver vazia
        (*lst)->ant = n; // O anterior do primeiro nó será o n

    *lst = n; // Lista aponta para n agora

    return 1;
}

/*
    Operação insere_pos:

    -Entrada: endereço de um endereço de uma lista, elemento a ser adicionado (real), variável inteira com a posição desejada

    -Pré-condição: lista não estar vazia e a posição não ser menor que 1

    -Processo: percorre a lista até achar a posição desejada e insere um nó com o valor passado de parâmetro

    -Saída: 1 caso inseriu ou 0 caso o contrário

    -Pós-condição: lista com mais um nó
*/
int insere_pos (Lista *lst, double info, int pos)
{
    if(pos < 1) // Lista estar vazia ou a posição ser menor que 1
        return 0; // Falha

    Lista aux = *lst; // Nó auxiliar recebe o primeiro nó da lista

    if (!lista_vazia(*lst))
    {
        int i = 1; // Primeira posição
        while (aux->prox != NULL && i < pos) // Enquanto o próximo nó não é nulo e a posição atual não é menor que a posição desejada
        {
            aux = aux->prox; // Recebe o próximo nó
            i++; // Avança uma posição
        }

        if (i < pos)
        {
            if (i + 1 != pos)
                return 0;
            else // Adicionar na última posição da lista
            {
                Lista n = (Lista)malloc(sizeof(struct no)); // Faz a alocação de memória do nó a ser adicionado na lista

                if (n == NULL) // Alocação não ter sucesso
                    return 0; // Falha

                n->info = info; // Alterar o valor da posição desejada pelo passado como parâmetro
                aux->prox = n;
                n->ant = aux;
                n->prox = NULL;
                return 1;
        }
    }
    }


    Lista n = (Lista)malloc(sizeof(struct no)); // Faz a alocação de memória do nó a ser adicionado na lista

    if (n == NULL) // Alocação não ter sucesso
        return 0; // Falha

    n->info = info; // Alterar o valor da posição desejada pelo passado como parâmetro

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
    Operação remove_elem:

    -Entrada: endereço de um endereço de uma lista, uma variável real (info)

    -Pré-condição: lista não estar vazia

    -Processo: percorre a lista até encontrar um valor da lista igual à info e depois remove o mesmo da lista

    -Saída: 1 caso removeu ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/
int remove_elem (Lista *lst, double info)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha
    Lista aux = *lst; // Nó auxiliar recebe o primeiro nó da lista

    while (aux->prox != NULL && aux->info != info) // Enquanto o próximo nó não é nulo e o elemento é diferente do desejado
        aux = aux->prox; // Avança para o próximo nó

    if (aux->info != info) // Se não tiver encontrado o elemento
        return 0; // Falha

    if (aux->prox != NULL)
        aux->prox->ant = aux->ant;

    if (aux->ant != NULL)
        aux->ant->prox = aux->prox;


    if (aux == *lst)
        *lst = aux->prox;

    free(aux); // Libera a memória desse nó

    return 1;
}

/*
    Operação remove_todos:

    -Entrada: endereço de um endereço de uma lista, uma variável real (info)

    -Pré-condição: lista não estar vazia

    -Processo:  percorre a lista até encontrar valores da lista igual à info e depois removê-los da lista

    -Saída: 1 caso removeu ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/
int remove_todos (Lista *lst, double info)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha
    Lista aux = *lst; // Nó auxiliar recebe o primeiro nó da lista

    while (aux != NULL) // Enquanto o nó atual é diferente de nulo
    {
        if (aux->info == info) // Se for igual ao valor passado por parâmetro
        {
            Lista aux2 = aux;

            if (aux2->prox != NULL)
                aux2->prox->ant = aux2->ant;

            if (aux2->ant != NULL)
                aux2->ant->prox = aux2->prox;

            if (aux2 == *lst)
                *lst = aux2->prox;

            aux = aux2->prox;
            free(aux2); // Remove o nó
        }
        else
            aux = aux->prox; // Passa para o próximo nó
    }

    return 1; // Sucesso
}

/*
    Operação remove_menor:

    -Entrada: endereço de um endereço de uma lista, endereço de uma variável real (info)

    -Pré-condição: lista não estar vazia

    -Processo: percorre a lista até achar o menor elemento, altera o valor de info para a informação presente nesse nó

    -Saída: 1 caso removeu ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/
int remove_menor (Lista *lst, double *menor)
{
    if (lista_vazia(*lst)) // Lista vazia
        return 0; // Falha

    Lista aux2 = *lst;
    Lista aux = aux2;
    int i = 1;
    *menor = aux2->info;

    while (aux2->prox != NULL) // Percorre a lista até achar o menor valor
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

    free(aux2); // Libera a memório do menor valor

    return 1; // Sucesso
}

/*
    Operação inverte:

    -Entrada: endereço do endereço de duas listas (L1 e L2)

    -Pré-condição: L1 não estar vazia e L2 estar vazia

    -Processo: Coloca na lista L2 a lista L1 de forma invertida

    -Saída: 1 caso a inverção tenha tido sucesso ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/
int inverte (Lista lst, Lista *lst2)
{
    if (lista_vazia(lst) || !lista_vazia(*lst2)) // L1 não estar vazia e L2 estar vazia
        return 0; // Falha

    Lista aux = lst; // Recebe o primeiro nó de L1
    Lista n = (Lista)malloc(sizeof(struct no)); // Faz a alocação de memória do nó a ser adicionado em L2

    if (n == NULL)
        return 0;

    n->info = aux->info; // Adiciona na informação do nó de L2 as informações do primeiro nó de L1
    n->ant = NULL;
    n->prox = NULL;
    *lst2 = n; // L2 aponta para o primeiro nó igual a n

    while (aux->prox != NULL) // Enquanto o próximo nó de L1 é diferente de nulo
    {

        aux = aux->prox; // Avança um nó
        Lista n = (Lista)malloc(sizeof(struct no)); // Faz a alocação de memória do nó a ser adicionado em L2
        n->info = aux->info; // Adiciona na informação do nó de L2 as informações do primeiro nó de L1

        if (n == NULL)
            return 0;

        (*lst2)->ant = n; // O anterior do primeiro nó de L2 será n
        n->prox = *lst2; // O próximo nó de n será o primeiro nó de L2
        n->ant = NULL; // O anterior de n será nulo

        *lst2 = n; // A lista agora aponta para n
    }

    return 1;
}

/*
    Operação get_elem_pos:

    -Entrada: endereço de uma lista, uma variável inteira P (Posição desejada) e o endereço de um número real R

    -Pré-condição: A lista não estar vazia e a posição P ser maior ou igual a 1

    -Processo: Percorre a lista até chegar na posição desejada e adiciona a informação do nó encontrado na variável R

    -Saída: 1 caso tenha tido sucesso ou 0 caso o contrário

    -Pós-condição: nenhuma
*/
int get_elem_pos (Lista lst, int pos, double *info)
{
    if (lista_vazia(lst) || pos < 1) // Se a lista for vazia ou for uma posição menor que 1
        return 0; // Falha

    int i = 1;
    i = 1;
    Lista aux = lst;

    while (aux->prox != NULL && i < pos) // Percorre a lista até o i ser igual posição, enquanto o próximo nó não é nulo
    {
        aux = aux->prox; // Recebe o próximo nó
        i++; // Avança para o próximo nó
    }

    if (i < pos)  // Se i for menor que a posição desejada quer dizer que não foi possível encontrar o elemento
        return 0; // Falha

    *info = aux->info; // Copia o valor desejado da lista para a variável passada como referência
    return 1; // Sucesso
}

/*
    Operação apaga_lista:

    -Entrada: endereço do endereço de uma lista

    -Pré-condição: lista não estar vazia

    -Processo: remover todos os elementos da lista, até a mesma ficar vazia

    -Saída: 1 caso tenha apagado a lista ou 0 caso o contrário

    -Pós-condição: lista apagada
*/
int apaga_lista (Lista *lst)
{
    if (lst == NULL)
        return 0; //Falha

    while (*lst != NULL) // Enquanto a lista não é vazia
    {
        Lista aux = *lst; // Vai removendo o último elemento da lista até ela ficar vazia
        *lst = aux->prox;
        free(aux); // Libera a memória do nó atual
    }
    return 1; //Sucesso
}


