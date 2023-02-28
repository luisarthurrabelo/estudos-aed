#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no{
    char string[10];
    Lista prox;
};

/*
    Operação: cria_lista
        Entrada: nenhuma
        Pré-condições: nenhuma
        Processo: criar uma lista e deixá-la no estado de vazia, criando o primeiro nó como cabeçalho
        Saída: nenhuma
        Pós-condição: nenhuma
*/

Lista cria_lista(){

    //Aloca nó cabeçalho
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));

    //Coloca lista no estado de vazia

    if(cab != NULL)          //Se a alocação falhar
        cab -> prox = NULL;

    return cab;
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

    if(lst -> prox == NULL)
        return 1; //Lista vazia   
    else   
        return 0; //Lista não vazia
}

/*
    Operação: insere_elem
        Entrada: endereço de uma lista e uma string
        Pré-condições: lista ser válida
        Processo: insere o elemento percorrendo a lista para achar a posição correta
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a string é armazenada no nó da lista
*/

int insere_ord(Lista *lst, char *elem){

    //Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0; //Falha: nó não alocado

    //Preenche os campos do novo nó

    strcpy(N -> string, elem); //Insere o conteúdo(valor do elem)

    //Percorrimento da lista

    Lista aux = *lst; //Faz aux apontar para 1° nó

    while(aux -> prox != NULL && strcmp(aux -> prox -> string, elem) < 0)      
        aux = aux -> prox; //Avança

    //Insere o novo nó na lista
    N -> prox = aux -> prox;
    aux -> prox = N;

    return 1;
}

/*
    Operação: remove_elem
        Entrada: endereço de uma lista e o inteiro a ser removido
        Pré-condições: lista ser válida e não estar vazia
        Processo: percorrer a lista até encontrar o elemento desejado ou chegar ao sue final. Se o elemento existe remove a string
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a lista de entrada com 1 elemento a menos
*/

int remove_ord(Lista *lst, char *elem){

    if(lista_vazia(*lst) == 1 || strcmp(elem, (*lst) -> string) < 0)
        return 0; //Falha

    Lista aux = *lst; //Ponteiro auxiliar para o 1º nó
 
    //Trata matento = 1º nó da lista

    if(strcmp(elem, (*lst) -> string) == 0){

        *lst = aux -> prox;  //Lista aponta para o 2º nó
        free(aux);          //Libera memória alocada
        return 1;
    }

    while(aux -> prox != NULL && strcmp(aux -> prox -> string, elem) < 0)
        aux = aux -> prox;

    if(aux -> prox == NULL || strcmp(aux -> prox -> string, elem) > 0)
        return 0; //Falha

    //Remove elemento =/= 1° nó da lista

    Lista aux2 = aux -> prox; //Aponta nó a ser removido 
    aux -> prox = aux2 -> prox; //Retira nó da lista
    free(aux2); //Libera memória alocada

    return 1;
}

/*
    Operação: get_pos
        Entrada: endereço da lista, a posição a ser consultada, variável de retorno do elemento
        Pré-condições: lista tem que existir e não ser vazia e a posição deve existir
        Processo: pegar a string está na posição solicitada, caso ela exista retorna os dados
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a string da posição é alocada
*/

int get_pos(Lista lst, int pos, char *elem){

    if(lista_vazia(lst) || pos <= 0)
        return 0; //Falha

    int cont = 1;
    Lista Aux = lst -> prox;

    while(Aux -> prox != NULL && cont < pos){
        
        Aux = Aux -> prox;
        cont++;
    }

    if(cont != pos) //Nao existe a posição solicitada na lista
        return 0;   //Falha

    strcpy(elem, Aux -> string); //Retorna o valor do elemento da posição desejada
    return 1;                    //sucesso
}

/*
    Operação: apagar_lista
        Entrada: endereço de uma lista
        Pré-condições: lista ser válida
        Processo: apagar o espaço da lista da memória
        Saída: nenhuma
        Pós-condição: nenhuma
*/

int limpa_lista(Lista *lst){

    if(lst == NULL)
        return 0;

    while(*lst != NULL){

        Lista Aux = *lst;
        *lst = Aux -> prox;
        free(Aux);
    }
    
    return 1;
}

int apaga_lista(Lista *lst){

    return(limpa_lista(lst));
}
