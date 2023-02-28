#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define max 20 //Tamanho máximo da lista

typedef struct String{
    char str[20];
}
String;

struct lista{
    String string[max];
    int fim;
};
typedef struct lista *Lista;

/*
    Operação: cria_lista
        Entrada: nenhuma
        Pré-condições: nenhuma
        Processo: criar uma lista e deixá-la no estado de vazia
        Saída: endereço da lista criada
        Pós-condição: nenhuma
*/

Lista cria_lista(){

    Lista lst;
    lst = (Lista) malloc(sizeof(struct lista));

    if(lst != NULL)
        lst -> fim = 0; //Lista vazia - (*L).fim = 0

    return lst;
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

    if(lst == NULL) //Lista não existe
        return 0;

    if(lst -> fim == 0)
        return 1; //Lista vazia
    else   
        return 0; //Lista não vazia
}

/*
    Operação: lista_cheia
        Entrada: endereço de uma lista
        Pré-condições: lista ser válida
        Processo: verificar se a lista está na condição de cheia
        Saída: 1 se vazia ou 0 caso contrário
        Pós-condição: nenhuma
*/

int lista_cheia(Lista lst){

    if(lst == NULL) //Lista não existe
        return 0;

    if(lst -> fim == max)
        return 1; //Lista cheia
    else
        return 0; //Lista não cheia
}

/*
    Operação: insere_elemento
        Entrada: endereço de uma lista e o elemento(float) a ser inserido
        Pré-condições: lista ser válida e não estar cheia
        Processo: inserir o elemento no final da lista
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a lista de entrada com um elemento a mais
*/

int insere_elem(Lista lst, char *elem){

    if(lst == NULL || lista_cheia(lst) == 1)
        return 0; //Falha

    strcpy(lst -> string[lst -> fim].str, elem); //Insere elemento
    lst -> fim++;
    
    return 1;
}

/*
    Operação: remove_elem
        Entrada: endereço de uma lista e o elemento(float) a ser removido
        Pré-condições: lista ser válida e não estar vazia
        Processo: percorrer a lista até encontrar o elemento desejado ou chegar ao sue final. Se o elemento existe remove-lo
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a lista de entrada com 1 elemento a menos
*/

int remove_elem(Lista lst, char *elem){

    if(lst == NULL || lista_vazia(lst) == 1)
        return 0; //Falha

    int i = 0;
    int aux = 0;
 
    //Percorre até achar o elemento desejado ou o final da lista

    while(i < lst -> fim && strcmp(lst -> string[i].str, elem) != 0)
        i++;

    if(i == lst -> fim) 
        return 0; //Falha

    //Deslocamento à esquerda do sucessor até o final da lista

    for(aux = i + 1; aux < lst -> fim; aux++)
        lst -> string[aux - 1] = lst -> string[aux];

    lst -> fim--;

    return 1; //Sucesso
}

/*
    Operação: get_pos
        Entrada: endereço da lista, a posição a ser consultada, variável de retorno do elemento
        Pré-condições: lista tem que existir e não ser vazia e a posição deve existir
        Processo: pegar o valor do elemento que está na posição solicitada, caso ela exista e retorna-lo
        Saída: 1- sucesso ou 0- falha
        Pós-condição: nenhuma
*/

int get_pos(Lista lst, int n, char *elem){

    if(lst == NULL || lista_vazia(lst) == 1 || n > lst -> fim || n < 0)
        return 0; //Falha
    
    strcpy(elem, lst -> string[n - 1].str);

    return 1; //sucesso
}

/*
    Operação: limpar_lista
        Entrada: endereço de uma lista
        Pré-condições: lista ser válida
        Processo: apagar o espaço da lista da memória
        Saída: nenhuma
        Pós-condição: nenhuma
*/

int apaga_lista(Lista *end_lst){

    if(*end_lst == NULL) 
        return 0; //Falha

    free(*end_lst);
    *end_lst = NULL;

    return 1;
}

int limpa_lista(Lista end_lst){

    if(end_lst == NULL) 
        return 0; //Falha

    end_lst -> fim = 0;

    return 1;
}
