#include <stdlib.h>
#include "fila.h"
#include <string.h>
#define MAX 11
#define STR 30

struct fila{
    char no[STR][MAX];
    int ini, cont;
};

/*
    Operação: Cria_Fila
    Entrada: nenhuma
    Pré-condições: nenhuma
    Processo: cria uma fila e a coloca no estado de vazia
    Saída: endereço da pilha criada
    Pós-condição: nenhuma
*/

Fila cria_Fila(){

    Fila f = (Fila)malloc(sizeof(struct fila));

    if(f != NULL){    //Coloca no estado de vazia
        f -> ini = 0;
        f -> cont = 0;
    }

    return f;
}

/*
    Operação: fila_vazia
    Entrada: endereço da fila
    Pré-condições: nenhuma
    Processo: verifica se a fila está vazia
    Saída: 1 caso esteja vazia ou 0 caso o contrário
    Pós-condição: nenhuma
*/

int fila_vazia(Fila f){

    if(f -> cont == 0)
        return 1;
        
    else
        return 0;
}

/*
    Operação: fila_cheia
    Entrada: endereço da Pilha
    Pré-condições: a pilha de deve existir
    Processo: verifica se a pilha está cheia
    Saída: 1 caso esteja cheia ou 0 caso o contrário
    Pós-condição: nenhuma
*/
int fila_cheia(Fila f){

    if(f -> cont == MAX)
        return 1;
    else
        return 0;
}

/*
    Operação: insere_Fim
    Entrada: endereço da fila e o elemento a ser inserido
    Pré-condições: fila ser válida e não estar cheia
    Processo: inserir o elemento informado no final da pilha
    Saída: 1 caso tenha inserido ou 0 caso o contrário
    Pós-condição: a fila da entrada com um elemento a mais
*/

int insere_Fim(Fila f, char *elem){

    if(f == NULL){
        return 0;
    }

    if(fila_cheia(f) == 1)
        return 0;
    
    //insere o elemento no fim

    strcpy(f -> no[(f -> ini+f -> cont) % MAX], elem);  //insere no final
    f -> cont++;                                        //incremento circular

    return 1;
}

/*
    Operação: remove_ini
    Entrada: endereço da fila e o endereço de retorno do elemento removido
    Pré-condições: fila deve ser válida e não estar vazia
    Processo: remover o elemento que está no início da fila e retornar seu valor
    Saída: 1 caso tenha removido ou 0 caso o contrário
    Pós-condição: a pilha de entrada com um elemento a menos
*/

int remove_ini(Fila f, char *elem){

    if(f == NULL){
        return 0;
    }

    if(fila_vazia(f) == 1)
        return 0; // Falha

    strcpy(elem, f -> no[f -> ini]);   // Remove do inicio
    f -> ini = (f -> ini+1) % MAX;      // Incremento circular
    f -> cont--;                        //Decremento não circular

    return 1; // Sucesso
}

/*
    Operação: tamanho_Fila
    Entrada: endereço da fila
    Pré-condições: fila não ser inválida
    Processo: verifica se está vazia
    Saída: tamanho da fila ou -1 caso não tenha tido sucesso
    Pós-condição: nenhuma
*/

int tamanho_Fila(Fila f)
{
    if(f == NULL)
        return -1;

    return f -> cont;
}

/*
    Operação: apaga_Fila
    Entrada: endereço do endereço da Fila
    Pré-condições: Fila ser válida
    Processo: apaga a Fila
    Saída: 1 caso tenha apagado ou 0 caso o contrário
    Pós-condição: Fila apagada
*/

int apaga_Fila(Fila *f){

    if(*f == NULL)
        return 0;

    free(*f);
    *f = NULL;
    
    return 1;
}

/*
    Operação: esvazia_Fila
    Entrada: endereço da Fila
    Pré-condições: Fila ser válida e não estar vazia
    Processo: esvazia a Fila
    Saída: 1 caso tenha esvaziado ou 0 caso o contrário
    Pós-condição: Fila sem nenhum elemento
*/

int esvazia_Fila(Fila f){

    if(f == NULL)
        return 0;

    f -> cont = 0;
    f -> ini = 0;
    return 1;
}


