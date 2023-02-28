#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{

    int info;
    Lista prox;
    Lista ant;
};

/*
    Operação: cria_lista
        Entrada: nenhuma
        Pré-condições: nenhuma
        Processo: criar uma lista e deixá-la no estado de vazia
        Saída: endereço da lista criada
        Pós-condição: nenhuma
*/

Lista cria_lista(){
    return NULL;
}

/*
    Operação: lista_vazia
        Entrada: endereço de uma lista
        Pré-condições: lista ser válida
        Processo: verificar se a lista está na condição de vazia
        Saída: 1 se vazia ou 0 caso contrário
        Pós-condição: nenhuma
*/

int lista_vazia(Lista lst){

    if(lst == NULL) //Lista vazia
        return 1;
    else  
        return 0; //Lista não vazia
}

/*
    Operação: insere_elem
        Entrada: endereço de uma lista e o elemento(float) a ser inserido
        Pré-condições: lista ser válida e não estar cheia
        Processo: inserir o elemento no final da lista
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a lista de entrada com um elemento a mais
*/

int insere_ord(Lista *lst, int elem){

    Lista N = (Lista) malloc(sizeof(struct no)); // Aloca um novo nó

    if(N == NULL)
        return 0; //Falha: nó não alocado

    if(lst == NULL)
        return 0;

    N -> info = elem;

    if(lista_vazia(*lst)){

        N -> prox = NULL;
        N -> ant = NULL;
        *lst = N;

        return 1;
    }
    else{

        Lista ante, aux = *lst;

        while(aux != NULL && aux -> info > elem){

            ante = aux;
            aux = aux -> prox;
        }
        if(aux == *lst){

            N -> ant = NULL;
            (*lst) -> ant = N;
            N -> prox = (*lst);
            *lst = N;
        }
        else{

            N -> prox = ante -> prox;
            N -> ant = ante;
            ante -> prox = N;

            if(aux != NULL)
                aux -> ant = N;
        }

        return 1;
    }
}

/*
    Operação: remove_elem
        Entrada: endereço de uma lista e o elemento(float) a ser removido
        Pré-condições: lista ser válida e não estar vazia
        Processo: percorrer a lista até encontrar o elemento desejado ou chegar ao sue final. Se o elemento existe remove-lo
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a lista de entrada com 1 elemento a menos
*/

int remove_ord(Lista *lst, int elem){

    if(lista_vazia(*lst) == 1 || elem > (*lst) -> info)
        return 0; //Falha

    Lista N = *lst;

    while(N != NULL && N -> info != elem)
        N = N -> prox;

    if(N == NULL) //Não encontrado
        return 0;

    if(N -> ant == NULL) //Remover o primeiro
        *lst = N -> prox;

    else
        N -> ant -> prox = N -> prox;

    //Caso não for o último
    if(N -> prox != NULL)
        N -> prox -> ant = N -> ant;

    free(N);
    return 1;
}

/*
    Operação: get_pos
        Entrada: endereço da lista, a posição a ser consultada, variável de retorno do elemento
        Pré-condições: lista tem que existir e não ser vazia e a posição deve existir
        Processo: pegar o valor do elemento que está na posição solicitada, caso ela exista e retorna-lo
        Saída: 1- sucesso ou 0- falha
        Pós-condição: nenhuma
*/

int get_pos(Lista lst, int pos, int *elem){

    if(lista_vazia(lst) || pos <= 0)
        return 0; //Falha

    int cont = 1;
    Lista Aux = lst;

    while(Aux -> prox != NULL && cont < pos){

        Aux = Aux -> prox;
        cont++;
    }

    if(cont != pos) //Nao existe a posição solicitada na lista
        return 0;   //Falha

    *elem = Aux -> info; //Retorna o valor do elemento da posição desejada
    
    return 1;            //sucesso
}

/*
    Operação: apagar_lista
        Entrada: endereço de uma lista
        Pré-condições: lista ser válida
        Processo: apagar o espaço da lista da memória
        Saída: nenhuma
        Pós-condição: nenhuma
*/

int apaga_lista(Lista *lst){

    if(lst == NULL)
        return 0;

    while(*lst != NULL){

        Lista Aux = *lst;
        *lst = Aux -> prox;
        free(Aux);
    }
    
    return 1;
}
