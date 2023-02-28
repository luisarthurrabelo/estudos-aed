/*
    Avaliativa: Lista Dinâmica/Encadeada

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no{
    int inteiro;
    struct no* prox;
};

/*
    Operação Cria_lista:

    -Entrada: nenhuma

    -Pré-condição: nenhuma

    -Processo: nenhum

    -Saída: endereço nulo

    -Pós-condição: nenhuma
*/

lista cria_lista (){
    return NULL;
}

/*
    Operação lista_vazia:

    -Entrada: endereço de uma lista

    -Pré-condição: nenhuma

    -Processo: verifica se a lista está vazia

    -Saída: 1 para vazia e 0 caso contrário

    -Pós-condição: nenhuma
*/

int lista_vazia (lista li){
    if (li == NULL)
        return 1;

    else
        return 0;
}

/*
    Operação insere_elem:

    -Entrada: endereço de um endereço de uma lista, elemento a ser adicionado (real)

    -Pré-condição: nenhuma

    -Processo: alocar um nó li2 e altera o valor do elemento pelo parâmetro passado, adicionar no início da lista esse nó

    -Saída: 1 caso inseriu ou 0 caso o contrário

    -Pós-condição: lista com um nó a mais
*/

int insere_elem(lista* li, int inteiro){

    lista li2 = (lista) malloc(sizeof(struct no));                                    //alocação para uma struct no_aluno

    if (li2 == NULL)
        return 0;

    li2 -> inteiro = inteiro;

    li2->prox = *li;

    *li = li2;


    return 1;
}

/*
    Operação remove_elem:

    -Entrada: endereço de um endereço de uma lista, uma variável real (inteiro)

    -Pré-condição: lista não estar vazia

    -Processo: percorre a lista até encontrar um valor da lista igual à info e depois remove o mesmo da lista

    -Saída: 1 caso removeu ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/

int remove_elem (lista* li, int inteiro){

    if (lista_vazia (*li) == 1)
        return 0;

    lista aux = *li;

    if (inteiro == (*li) -> inteiro){

        *li = aux -> prox;
        free (aux);

        return 1;
    }

    while (aux -> prox != NULL && aux -> prox -> inteiro != inteiro)
            aux = aux -> prox;

    if (aux -> prox == NULL)
        return 0;

    lista aux2 = aux -> prox;
    aux -> prox =  aux2 -> prox;
    free(aux2);

    return 1;
}

/*
    Operação esvazia_lista:

    -Entrada: endereço do endereço de uma lista

    -Pré-condição: lista não estar vazia

    -Processo: remover todos os elementos da lista, até a mesma ficar vazia

    -Saída: 1 caso tenha esvaziado a lista ou 0 caso o contrário

    -Pós-condição: lista vazia
*/

int esvazia_lista (lista* li){
    if (*li == NULL)
        return 0;

    while (*li != NULL){

        lista aux = *li;
        *li = aux -> prox;
        free(aux);

    }
    return 1;
}

/*
    Operação apaga_lista:

    -Entrada: endereço do endereço de uma lista

    -Pré-condição: nenhuma

    -Processo: retornar a função (esvazia_lista)

    -Saída: esvazia_lista

    -Pós-condição: nenhuma
*/

int apaga_lista (lista* li){

    return (esvazia_lista(li));
}

/*
    Operação get_elem_pos:

    -Entrada: endereço de uma lista, uma variável inteira pos (Posição desejada) e o endereço de um número real R

    -Pré-condição: A lista não estar vazia e a posição pos ser maior ou igual a 1

    -Processo: Percorre a lista até chegar na posição desejada e adiciona a informação do nó encontrado na variável R

    -Saída: 1 caso tenha tido sucesso ou 0 caso o contrário

    -Pós-condição: nenhuma
*/

int get_elem_pos(lista li, int pos, int* inteiro){               //li (não passa por referencia pois a lista não é alterada em momento nenhum, so estou pegando os elementos)

    if (lista_vazia (li) == 1 || pos <= 0)
        return 0;

    int cont = 1;                                                              //se a lista não é vazia começa-se o contador com 1
    lista aux = li;

     while (aux->prox != NULL && cont < pos)
    {
        aux = aux->prox;
        cont++;
    }

    if (cont < pos)
        return 0;

    *inteiro = aux -> inteiro;

    return 1;
}

/*
    Operação remove_maior:

    -Entrada: endereço de um endereço de uma lista, endereço de uma variável real (valor)

    -Pré-condição: lista não estar vazia

    -Processo: percorre a lista até achar o maior elemento, altera o valor da variavel valor para a informação presente nesse nó

    -Saída: 1 caso removeu ou 0 caso o contrário

    -Pós-condição: lista com menos um nó
*/

int remover_maior (lista* li, int* valor){

    if (lista_vazia (*li) == 1)
        return 0;

    lista aux = *li;
    *valor = aux -> inteiro;

    if (aux -> prox == NULL){

        free (aux);

        return 1;
    }

    while (aux -> prox != NULL){
        aux = aux -> prox;

        if (*valor < aux -> inteiro){
            *valor = aux -> inteiro;
        }

    }

    aux = *li;

    if (aux -> inteiro != *valor){

        while (aux -> prox -> inteiro != *valor){
            aux = aux -> prox;
        }

            lista aux2 = aux -> prox;
            aux -> prox = aux2 -> prox;
            free(aux2);
    }
    else
    {
        lista aux2 = *li;
        *li = aux2 -> prox;
        free(aux2);
    }

    return 1;
}

/*
    Operação inverter:

    -Entrada: endereço do endereço de uma lista (li)

    -Pré-condição: li não estar vazia

    -Processo: aloca uma nova lista (li2) com os elementos de li invertidos

    -Saída: uma lista com os elementos de li invertidos

    -Pós-condição: lista invertida li2
*/

lista inverter (lista *li){

    if (lista_vazia(*li) == 1)
        return NULL;

    lista li2 = (lista) malloc(sizeof(struct no));

    if (li2 == NULL){
        return NULL;
    }

    li2 -> inteiro = (*li) -> inteiro;
    li2 -> prox = NULL;

    lista aux = *li;
    lista aux2 = li2;

    while (aux -> prox != NULL){

        aux = aux -> prox;

        lista li3 = (lista) malloc(sizeof(struct no));
        if (li3 == NULL)
            return NULL;

        li3 -> inteiro = aux -> inteiro;

        li3 -> prox = aux2;
        li2 = li3;
        aux2 = li2;

    }

    if (aux -> prox == NULL){

        lista li4 = (lista) malloc(sizeof(struct no));
        if (li4 == NULL)
            return NULL;

        li4 -> inteiro = aux -> inteiro;
        li4 -> prox = aux2;

    }

    return li2;
}

/*
    Operação intercalar:

    -Entrada: endereço de duas lista (li e li2)

    -Pré-condição: li ou li2 não estar vazia

    -Processo: aloca uma nova lista (li3) com os elementos de li e li2 intercalados

    -Saída: uma lista com os elementos de li e li2 intercalados

    -Pós-condição: lista intercalada li3
*/

lista intercalar (lista li, lista li2){

    if (lista_vazia(li) == 1 || lista_vazia(li2) == 1)
        return NULL;

    lista li3 = (lista) malloc(sizeof(struct no));

    if (li3 == NULL){
        return NULL;
    }
    int inverte = 1;

    lista aux = li;
    lista aux2 = li2;

    lista aux3 = li3;

    aux3 -> inteiro = aux -> inteiro;
    aux3->prox = NULL;
    aux = aux->prox;
    while (1)
    {
        if(inverte == 0)
        {
            if (aux!= NULL)
            {
                lista li5 = (lista) malloc(sizeof(struct no));
                li5->inteiro = aux -> inteiro;
                aux3 -> prox = li5;
                aux3 = aux3->prox;
                aux3 -> prox = NULL;
                aux = aux -> prox;
            }
            if(aux2 != NULL)
                inverte = 1;

        }
        else if(inverte == 1)
        {
            if(aux2 != NULL)
            {
                lista li4 = (lista) malloc(sizeof(struct no));
                li4->inteiro = aux2 -> inteiro;
                aux3 -> prox = li4;
                aux3 = aux3->prox;
                aux3 -> prox = NULL;
                aux2 = aux2 -> prox;
            }
            if(aux != NULL)
                inverte = 0;
        }

        if(aux == NULL && aux2 == NULL)
            break;

    }

    return li3;
}
