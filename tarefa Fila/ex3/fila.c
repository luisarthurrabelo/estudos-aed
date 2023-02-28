#include <stdlib.h>
#include "fila.h"
#include <string.h>

struct no{
    Produto info;
    struct no *prox;
};
typedef struct no No;

struct fila{
    struct no *ini;
    struct no *fim;
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

    if(f != NULL){
        f -> ini = NULL;
        f -> fim = NULL;
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

    if(f -> ini == NULL)
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

int insere_Fim(Fila f, Produto elem){

    No *N;
    N = (struct no *) malloc(sizeof(struct no));

    if(N == NULL){
        return 0;
    }

    N -> info = elem;
    N -> prox = NULL;

    if(fila_vazia(f) == 1)
        f -> ini = N;  //N é o 1º nó
    else
        (f -> fim) -> prox = N; //Último nó aponta N

    f -> fim = N;

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

int remove_ini(Fila f, Produto *elem){

    if(fila_vazia(f) == 1)
        return 0; // Falha

    struct no *aux = f -> ini; //Aux aponta para 1º nó
    *elem = aux -> info;       //Retorna valor do elemento 

    // Verifica se a fila tem um único nó
    if(f -> ini == f -> fim)
        f -> fim = NULL;

    f -> ini = aux -> prox; //Retira 1º nó da fila
    free(aux);

    return 1; // Sucesso
}

int tamanho_Fila(Fila f){

    int cont = 0;
    No *aux = f -> ini;

    while(aux != NULL){
        cont++;
        aux = aux -> prox;
    }

    return cont;
}

/*
    Operação: apaga_Fila
    Entrada: endereço do endereço de uma fila
    Pré-condições: nenhuma
    Processo: possui o mesmo processo que a função limpa_Fila
    Saída: 1 caso tenha apagado ou 0 caso o contrário
    Pós-condição: Fila apagada
*/

int apaga_Fila(Fila *f){

    return(esvazia_Fila(*f));
}

/*
    Operação: esvazia_Fila
    Entrada: endereço da Pilha
    Pré-condições: Pilha ser válida e não estar vazia
    Processo: esvazia a Pilha
    Saída: 1 caso tenha esvaziado ou 0 caso o contrário
    Pós-condição: Pilha sem nenhum elemento
*/

int esvazia_Fila(Fila f){

    if(f == NULL)
        return 0;

    if(f != NULL){
        No *no;

        while(f -> ini != NULL){
            no = f -> ini;
            f -> ini = f -> ini -> prox;
            free(no);
        }
    }
    free(f);

    return 1;
}