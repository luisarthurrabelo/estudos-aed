#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst;

    char elem[10];
    int ativo = 0;
    int n, N;

    while(ativo != 7){

        printf("--------------------------------------------\n");
        printf("[1] Cria lista\n");
        printf("[2] Inserir string na lista\n");
        printf("[3] Remover string da lista\n");
        printf("[4] Imprimir Lista\n");
        printf("[5] Limpar Lista\n");
        printf("[6] Apagar Lista\n");
        printf("[7] Sair\n");
        printf("--------------------------------------------\n");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){

            case 1:
                lst = cria_lista();

                printf("Lista criada com sucesso\n");
                break;

            case 2:
                printf("Insira uma string: ");
                scanf("%s", &elem);

                if(insere_ord(&lst, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");  
                
                else
                    printf("A string %s foi incluido.\n", elem);

                break;
            
            case 3:
                printf("Digite a string que deseja remover: ");
                scanf("%s", &elem);

                if(remove_ord(&lst, elem) == 0)
                    printf("String %s nao encontrado.\n", elem);

                else    
                    printf("A string %s foi removido.\n", elem);

                break;
            
            case 4:
                if(lst != NULL)
                    imprime_lista(lst);

                else
                    printf("Nao foi possivel imprimir.\n");
                
                break;

            case 5:
                if(limpa_lista(&lst) == 0)
                    printf("Lista nao foi criada.\n");
                
                else
                    printf("Lista esvaziada.\n");

                break;

            case 6:
                apaga_lista(&lst);
                printf("Lista apagada.\n");
                break;

            case 7:
                ativo = 7;
                break;

            default:
                printf("opcao invalida!\n");
        }
    }

    return 0;
}

void imprime_lista(Lista lst){

    if(lista_vazia(lst) == 1){

        printf("\n --Lista Vazia--\n");
        return;
    }

    printf("\nLista: ");
    int i, Falta;
    char N[10];

    for(i = 1; get_pos(lst, i, N) == 1; i++){

        printf(" %s ", N);
    }
    printf("\n");
    printf("existem %d elementos na lista.\n", i - 1);
}