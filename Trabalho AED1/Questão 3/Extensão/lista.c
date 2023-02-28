#include <stdlib.h>
#include "lista.h"

struct no{

    float info;
    Lista prox;
};

/*
    Operação: cria_lista

        Entrada: nenhuma
        Pré-condições: nenhuma
        Processo: cria uma lista e deixa no estado de vazia, criando o primeiro nó como cabeçalho
        Saída: endereço de uma lista
        Pós-condição: nenhuma
*/
Lista cria_lista(){

    //Aloca nó cabeçalho
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));

    //Coloca lista no estado de vazia

    if(cab != NULL){       //Se a alocação nao falhar
        cab -> prox = NULL;
    }

    return cab;
}

/*
    Operação: lista_vazia
        Entrada: endereço de uma lista
        Pré-condições: Nenhuma
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
    Operação: insere_ord
        Entrada: endereço do endereço de uma lista e um real do tipo float
        Pré-condições: lista deve ser válida
        Processo: percorre a lista até encontrar a posicao correta a ser inserido, de forma decrescente
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a numero é armazenado no respectivo nó da lista que foi criado
*/
int insere_ord(Lista *lst, float elem){

    //Aloca um novo nó
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0; //Falha: nó não alocado

    //Preenche os campos do novo nó

    N -> info = elem;  //Insere o conteúdo(valor do elem)

    //Percorrimento da lista

    Lista aux = *lst; //Faz aux apontar para 1° nó

    while(aux -> prox != NULL && aux -> prox -> info > elem)
        aux = aux -> prox; //Avança

    //Insere o novo nó na lista
    N -> prox = aux -> prox;
    aux -> prox = N;

    return 1;
}

/*
    Operação: remove_ord
        Entrada: endereço do endereço de uma lista e um real do tipo float
        Pré-condições: lista não estar vazia e o elemento ser maior que o primeiro elemento da lista
        Processo: percorrer a lista até encontrar o elemento desejado ou chegar ao sue final.
        Saída: 1- sucesso ou 0- falha
        Pós-condição: Se o elemento existir remove da lista
*/
int remove_ord(Lista *lst, float elem){

    if(lista_vazia(*lst) == 1 || elem > (*lst)->prox->info)
        return 0; //Falha

    Lista aux = *lst; //Ponteiro auxiliar para o 1º nó

    //1º nó da lista

    if(elem == (*lst) -> info){

        *lst = aux -> prox;  //Lista aponta para o 2º nó
        free(aux);           //Libera memória alocada
        return 1;
    }

    while(aux -> prox != NULL && aux -> prox -> info > elem)
        aux = aux -> prox;

    if(aux -> prox == NULL || aux -> prox -> info < elem)
        return 0; //Falha

    //Remove elemento =/= 1° nó da lista

    Lista aux2 = aux -> prox;   //Aponta nó a ser removido
    aux -> prox = aux2 -> prox; //Retira nó da lista
    free(aux2);                 //Libera memória alocada

    return 1;
}

/*
    Operação: get_pos
        Entrada: endereço de uma lista, a posição a ser consultada e o endereço do elemento a ser retornado
        Pré-condições: lista não pode ser vazia e a posição deve ser maior que zero
        Processo: pegar o elemento que está na posição solicitada, caso ela exista aloca no parametro do elemento
        Saída: 1- sucesso ou 0- falha
        Pós-condição: o valor da posição é alocada no elemento a ser retornado
*/
int get_pos(Lista lst, int pos, float *elem){

    if(lista_vazia(lst) || pos <= 0)
        return 0; //Falha

    int cont = 1;
    Lista Aux = lst -> prox;

    while(Aux -> prox != NULL && cont < pos){

        Aux = Aux -> prox;
        cont++;
    }

    if(cont < pos)  //Nao existe a posição solicitada na lista
        return 0;    //Falha

    *elem = Aux -> info;  //Retorna o valor do elemento da posição desejada
    return 1;             //sucesso
}

/*
    Operação: remover_pos
        Entrada: endereço do endereço da lista e a posição a ser consultada
        Pré-condições: lista tem que existir e não ser vazia e a posição deve ser maior ou igual a zero
        Processo: percorre a lista até a posição solicitada e limpa a posição
        Saída: 1- sucesso ou 0- falha
        Pós-condição: a lista termina com 1 elemento a menos
*/
int remover_pos(Lista *lst, int pos){

    if(lista_vazia(*lst) || pos <= 0)
        return 0; //Falha

    Lista Aux1 = *lst;
    Lista Aux = (*lst) -> prox;
    int cont = 1;

    while(Aux -> prox != NULL && cont < pos){

        Aux1 = Aux;
        Aux = Aux -> prox;
        cont++;
    }

    if(cont < pos)          //Nao existe a posição solicitada na lista
        return 0;            //Falha

    Aux1 -> prox = Aux -> prox;
    free(Aux);

    return 1;                //sucesso
}

/*
    Operação: lista_tamanho
        Entrada: endereço de uma lista
        Pré-condições: lista tem que existir
        Processo: percorre a lista até chegar no final contanto a quantidade de nós
        Saída: quantidade de elementos em caso de sucesso ou -1- falha
        Pós-condição: nenhuma
*/
int lista_tamanho(Lista lst){

    if(lst == NULL)
        return -1;

    int cont = 0;
    Lista aux = lst;
    while(aux->prox != NULL){
        aux = aux->prox;
        cont++;
    }

    cont--;

    return cont;
}

/*
    Operação: lista_igauis
        Entrada: o endereço do endereço de duas listas
        Pré-condições:as lista não podem ser vazias
        Processo: percorre as duas listas comparando se os dois elementos de cada nó são iguais
        Saída: -1- Lista vazia 0- Falha 1- Sucesso
        Pós-condição: nenhuma
*/
int lista_iguais(Lista *lst, Lista *lst2){

    if(lista_vazia(*lst) || lista_vazia(*lst2))
        return -1; //Falha

    Lista atual = *lst;
    Lista atual2 = *lst2;

    while(atual != NULL && atual2 != NULL){

        if(atual -> info != atual2 -> info)
            return 0;

        atual = atual -> prox;
        atual2 = atual2 -> prox;
    }

    return 1;
}

/*
    Operação: lista intercalar
        Entrada: endereço de duas lista
        Pré-condições: as duas não podem estar vazias
        Processo: intercala as duas listas mantendo o critério de ordenação
        Saída: a lista criada
        Pós-condição: lista intercalada criada
*/
Lista lista_intercalar(Lista lst, Lista lst2){

    if(lista_vazia(lst) || lista_vazia(lst2))
        return NULL;

    Lista lst3 = cria_lista();

    Lista aux1 = lst->prox;
    Lista aux2 = lst2->prox;
    Lista aux3 = lst3;

    while(1)
    {
        Lista lixo;
        if(aux1 != NULL && aux2 != NULL)
        {
            if(aux1->info > aux2->info)
            {
                lixo = (Lista) malloc(sizeof(struct no));
                if(lixo == NULL)
                    return 0;
                lixo->info = aux1->info;
                aux1 = aux1->prox;
            }
            else
            {
                lixo = (Lista) malloc(sizeof(struct no));
                if(lixo == NULL)
                    return 0;
                lixo->info = aux2->info;
                aux2 = aux2->prox;
            }

        }
        else if(aux1 != NULL && aux2 == NULL)
        {
            lixo = (Lista) malloc(sizeof(struct no));
            if(lixo == NULL)
                return 0;
            lixo->info = aux1->info;
            aux1 = aux1->prox;
        }


        else if(aux2 != NULL && aux1 == NULL)
        {
            lixo = (Lista) malloc(sizeof(struct no));
            if(lixo == NULL)
                return 0;
            lixo->info = aux2->info;
            aux2 = aux2->prox;

        }
        else
            break;
        aux3->prox = lixo;
        aux3 = aux3->prox;
        aux3->prox = NULL;
    }


    return lst3;
}

/*
    Operação: limpa_lista
        Entrada: endereço do endereço de uma lista
        Pré-condições: lista ser válida
        Processo: esvazia todos os nós da lista
        Saída: 1 caso tenha limpado ou 0 caso o contrário
        Pós-condição: a lista fica vazia
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

/*
    Operação: apaga_lista
        Entrada: endereço do endereço de uma lista
        Pré-condições: nenhuma
        Processo: possui o mesmo processo que a função limpa_lista
        Saída: 1 caso tenha sucesso ou 0 caso o contrário
        Pós-condição: lista apagada
*/
int apaga_lista(Lista *lst){

    return(limpa_lista(lst));
}
