#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
};

/*
    Operação Cria_lista:

    -Entrada: nenhuma

    -Pré-condição: nenhuma

    -Processo: nenhuma

    -Saída: endereço nulo

    -Pós-condição: nenhuma
*/
Lista Cria_lista ()
{
    return NULL; // Retorna nulo
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
    if (lst == NULL) // Se a lista apontar para nulo
        return 1; // Sucesso
    else
        return 0; // Falha
}

/*
    Operação insere_final:

    -Entrada: endereço do endereço de uma lista, elemento a ser adicionado (inteiro)

    -Pré-condição: nenhuma

    -Processo: alocar um nó e alterar o valor do elemento pelo parâmetro passado, adicionar no final da lista esse nó

    -Saída: 1 caso inseriu ou 0 caso o contrário

    -Pós-condição: lista com mais um nó
*/
int insere_final (Lista *lst, int info)
{
    Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o nó

    if (n == NULL)
        return 0; // Falha caso não tenha tido sucesso a alocação

    n->info = info; // Copia para o nó o valor passado como parâmetro

    if (lista_vazia(*lst)) // Se a lista estiver vazia
    {
        n->prox = n;
        *lst = n; // Adiciona na lista o primeiro nó
    }
    else
    {
        n->prox = (*lst)->prox;
        (*lst)->prox = n;
        *lst = n; // Adiciona no final da lista o nó
    }

    return 1;
}

/*
    Operação insere_inicio:

    -Entrada: endereço do endereço de uma lista, elemento a ser adicionado (inteiro)

    -Pré-condição: nenhuma

    -Processo: alocar um nó e alterar o valor do elemento pelo parâmetro passado, adicionar no início da lista esse nó

    -Saída: 1 caso inseriu ou 0 caso o contrário

    -Pós-condição: lista com mais um nó
*/
int insere_inicio (Lista *lst, int info)
{
    Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o nó

    if (n == NULL)
        return 0; // Falha caso não tenha tido sucesso a alocação

    n->info = info; // Copia para o nó o valor passado como parâmetro

    if (lista_vazia(*lst)) // Se a lista estiver vazia
    {
        n->prox = n;
        *lst = n; // Adiciona na lista o primeiro nó
    }
    else
    {
        n->prox = (*lst)->prox;
        (*lst)->prox = n; // Adiciona no início da lista nó
    }

    return 1;
}

/*
    Operação insere_pos:

    -Entrada: endereço do endereço de uma lista, elemento a ser adicionado (inteiro), variável inteira com a posição desejada

    -Pré-condição: lista não estar vazia e a posição não ser menor que 1

    -Processo: percorre a lista até achar a posição desejada e aloca um novo nó para ocupar essa posição

    -Saída: 1 caso inseriu ou 0 caso o contrário

    -Pós-condição: lista com mais um nó
*/
int insere_pos (Lista *lst, int info, int pos)
{
    if(pos < 1) // Se a lista for vazia ou for uma posição menor que 1
        return 0; // Falha

    if(lista_vazia(*lst))
    {
        Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o nó

        if (n == NULL)
            return 0; // Falha caso não tenha tido sucesso a alocação

        n->info = info; // O nó alocado recebe o a informação a ser substituída
        n->prox = n;
        *lst = n;
        return 1;
    }

    int i = 1; // Começa na primeira posição
    Lista aux = *lst; // Recebe o último nó da lista

    while (aux->prox != *lst && i < pos) // Enquanto o nó próximo é diferente do último nó da lista e "i" é menor que a posição
    {
        aux = aux->prox; // Recebe o próximo nó
        i++; // Avança uma posição
    }

    if (i < pos)
    {
        if (i + 1 != pos)
            return 0;
        else
            aux = aux->prox;
    }

    Lista n = (Lista)malloc(sizeof(struct no)); // Aloca dinamicamente o nó

    if (n == NULL)
        return 0; // Falha caso não tenha tido sucesso a alocação

    n->info = info; // O nó alocado recebe o a informação a ser substituída
    n->prox = aux->prox;
    aux->prox = n;
    if (aux == *lst)
        *lst = n;

    return 1;
}

/*
    Operação remove_inicio:

    -Entrada: endereço do endereço de uma lista, endereço de uma variável inteira (info)

    -Pré-condição: lista não estar vazia

    -Processo:  altera o valor de info para a informação presente no primeiro nó da lista e depois remove o mesmo

    -Saída: 1 caso removeu ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/
int remove_inicio (Lista *lst, int *info)
{
    if (lista_vazia(*lst)) // Se a lista estiver vazia
        return 0; // Falha

    Lista aux = (*lst)->prox; // Aponta para o início da lista
    *info = aux->info; // O valor a ser removido, copiado para a variável passada como parâmetro

    if (*lst == (*lst)->prox) // Se a lista tem só um elemento
        *lst = NULL;
    else
       (*lst)->prox = aux->prox; // O último nó aponta para o segundo nó da lista

    free(aux); // Libera a memória do primeiro nó da lista

    return 1; // Sucesso
}

/*
    Operação remove_final:

    -Entrada: endereço do endereço de uma lista, endereço de uma variável inteira (info)

    -Pré-condição: lista não estar vazia

    -Processo:  altera o valor de info para a informação presente no último nó da lista e depois remove o mesmo

    -Saída: 1 caso removeu ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/
int remove_final (Lista *lst, int *info)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha

    Lista aux = *lst; // Aponta para o fim da lista

    *info = aux->info; // O valor a ser removido, copiado para a variável passada como parâmetro

    if (*lst == (*lst)->prox) // Se a lista tem só um elemento
    {
        *lst = NULL; // Remove o elemento
        free(aux);
    }
    else
    {
        while (aux->prox != (*lst)) // Percorre a lista até o penúltimo elemento da lista
        {
            aux = aux->prox;
        }

        Lista aux2 = aux->prox;
        aux->prox = aux2->prox; // Faz o penúltimo elemento apontar para o primeiro elemento da lista
        *lst = aux; // Faz a lista apontar para penúltimo elemento
        free(aux2); // Libera a memória do último elemento
    }

    return 1;
}

/*
    Operação remove_pares:

    -Entrada: endereço do endereço de uma lista

    -Pré-condição: a lista não estar vazia

    -Processo: remove todos os números pares da lista

    -Saída: 1 caso forem removidos ou 0 caso o contrário

    -Pós-condição: lista sem os elementos pares
*/
int remove_pares (Lista *lst)
{
    if (lista_vazia(*lst)) // Lista estar vazia
        return 0; // Falha

    Lista aux = (*lst); // Aponta para o último nó da lista

    while (aux->prox != (*lst)) // Enquanto o próximo nó é diferente do último nó
    {

        if (aux->prox->info % 2 == 0) // Se o próximo nó for um número par
        {
            Lista aux2 = aux->prox; // Recebe o valor do próximo nó
            aux->prox = aux2->prox; // O próximo do nó atual será o próximo do próximo nó
            free(aux2); // Libera o próximo nó
        }
        else
            aux = aux->prox; // Recebe o valor do próximo nó
    }

    if((*lst)->info % 2 == 0) // Verifica se o último nó é par
    {
        if ((*lst) == (*lst)->prox) // Se tiver só um elemento na lista
        {
            aux = (*lst);
            *lst = NULL;
            free(aux); // Libera a memória desse elemento
        }
        else
        {
            Lista aux2 = *lst; // Recebe o último nó da lista
            aux->prox = (*lst)->prox; // O próximo do penúltimo nó apontará para o primeiro nó da lista
            *lst = aux; // A lista agora aponta para o penúltimo nó
            free(aux2); // Libera o último nó
        }

    }

    return 1;
}

/*
    Operação get_elem_pos:

    -Entrada: endereço de uma lista, uma variável inteira P (Posição desejada) e o endereço de um número inteiro I

    -Pré-condição: A lista não estar vazia e a posição P ser maior ou igual a 1

    -Processo: Percorre a lista até chegar na posição desejada e adiciona a informação do nó encontrado na variável I

    -Saída: 1 caso tenha tido sucesso ou 0 caso o contrário

    -Pós-condição: nenhuma
*/
int get_elem_pos (Lista lst, int pos, int *info)
{
    if (lista_vazia(lst) || pos < 1) // Se a lista for vazia ou for uma posição menor que 1
        return 0; // Falha

    int i = 1;
    i = 1;
    Lista aux = lst->prox;

    while (aux != lst && i < pos) // Percorre a lista até o i ser igual posição, enquanto o nó não é igual o último nó
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
    if (lista_vazia(*lst))
        return 0; //Falha

    while (*lst != (*lst)->prox) // Enquanto não tem apenas um elemento na lista
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


