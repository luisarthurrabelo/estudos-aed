/*
    Avaliativa: Lista Din�mica/Encadeada

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
    Opera��o Cria_lista:

    -Entrada: nenhuma

    -Pr�-condi��o: nenhuma

    -Processo: nenhum

    -Sa�da: endere�o nulo

    -P�s-condi��o: nenhuma
*/

lista cria_lista (){
    return NULL;
}

/*
    Opera��o lista_vazia:

    -Entrada: endere�o de uma lista

    -Pr�-condi��o: nenhuma

    -Processo: verifica se a lista est� vazia

    -Sa�da: 1 para vazia e 0 caso contr�rio

    -P�s-condi��o: nenhuma
*/

int lista_vazia (lista li){
    if (li == NULL)
        return 1;

    else
        return 0;
}

/*
    Opera��o insere_elem:

    -Entrada: endere�o de um endere�o de uma lista, elemento a ser adicionado (real)

    -Pr�-condi��o: nenhuma

    -Processo: alocar um n� li2 e altera o valor do elemento pelo par�metro passado, adicionar no in�cio da lista esse n�

    -Sa�da: 1 caso inseriu ou 0 caso o contr�rio

    -P�s-condi��o: lista com um n� a mais
*/

int insere_elem(lista* li, int inteiro){

    lista li2 = (lista) malloc(sizeof(struct no));                                    //aloca��o para uma struct no_aluno

    if (li2 == NULL)
        return 0;

    li2 -> inteiro = inteiro;

    li2->prox = *li;

    *li = li2;


    return 1;
}

/*
    Opera��o remove_elem:

    -Entrada: endere�o de um endere�o de uma lista, uma vari�vel real (inteiro)

    -Pr�-condi��o: lista n�o estar vazia

    -Processo: percorre a lista at� encontrar um valor da lista igual � info e depois remove o mesmo da lista

    -Sa�da: 1 caso removeu ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
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
    Opera��o esvazia_lista:

    -Entrada: endere�o do endere�o de uma lista

    -Pr�-condi��o: lista n�o estar vazia

    -Processo: remover todos os elementos da lista, at� a mesma ficar vazia

    -Sa�da: 1 caso tenha esvaziado a lista ou 0 caso o contr�rio

    -P�s-condi��o: lista vazia
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
    Opera��o apaga_lista:

    -Entrada: endere�o do endere�o de uma lista

    -Pr�-condi��o: nenhuma

    -Processo: retornar a fun��o (esvazia_lista)

    -Sa�da: esvazia_lista

    -P�s-condi��o: nenhuma
*/

int apaga_lista (lista* li){

    return (esvazia_lista(li));
}

/*
    Opera��o get_elem_pos:

    -Entrada: endere�o de uma lista, uma vari�vel inteira pos (Posi��o desejada) e o endere�o de um n�mero real R

    -Pr�-condi��o: A lista n�o estar vazia e a posi��o pos ser maior ou igual a 1

    -Processo: Percorre a lista at� chegar na posi��o desejada e adiciona a informa��o do n� encontrado na vari�vel R

    -Sa�da: 1 caso tenha tido sucesso ou 0 caso o contr�rio

    -P�s-condi��o: nenhuma
*/

int get_elem_pos(lista li, int pos, int* inteiro){               //li (n�o passa por referencia pois a lista n�o � alterada em momento nenhum, so estou pegando os elementos)

    if (lista_vazia (li) == 1 || pos <= 0)
        return 0;

    int cont = 1;                                                              //se a lista n�o � vazia come�a-se o contador com 1
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
    Opera��o remove_maior:

    -Entrada: endere�o de um endere�o de uma lista, endere�o de uma vari�vel real (valor)

    -Pr�-condi��o: lista n�o estar vazia

    -Processo: percorre a lista at� achar o maior elemento, altera o valor da variavel valor para a informa��o presente nesse n�

    -Sa�da: 1 caso removeu ou 0 caso o contr�rio

    -P�s-condi��o: lista com menos um n�
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
    Opera��o inverter:

    -Entrada: endere�o do endere�o de uma lista (li)

    -Pr�-condi��o: li n�o estar vazia

    -Processo: aloca uma nova lista (li2) com os elementos de li invertidos

    -Sa�da: uma lista com os elementos de li invertidos

    -P�s-condi��o: lista invertida li2
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
    Opera��o intercalar:

    -Entrada: endere�o de duas lista (li e li2)

    -Pr�-condi��o: li ou li2 n�o estar vazia

    -Processo: aloca uma nova lista (li3) com os elementos de li e li2 intercalados

    -Sa�da: uma lista com os elementos de li e li2 intercalados

    -P�s-condi��o: lista intercalada li3
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
