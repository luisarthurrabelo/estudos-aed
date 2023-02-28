#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst;

    int ativo = 0;
    int n, N;
    int elem;

    while(ativo != 6){

        printf("--------------------------------------------\n");
        printf("[1] Cria lista\n");
        printf("[2] Inserir numero na lista\n");
        printf("[3] Remover numero da lista\n");
        printf("[4] Imprimir Lista\n");
        printf("[5] Limpar Lista\n");
        printf("[6] Sair\n");
        printf("--------------------------------------------\n");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){

            case 1:
                lst = cria_lista();

                printf("Lista criada com sucesso\n");
                break;

            case 2:
                printf("Digite o numero: ");
                scanf("%d", &elem);

                if(insere_ord(&lst, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");  
                
                else
                    printf("O numero %d foi incluido.\n", elem);

                break;
            
            case 3:
                printf("Digite o numero que deseja remover: ");
                scanf("%d", &elem);

                if(remove_ord(&lst, elem) == 0)
                    printf("Numero %d nao encontrado.\n", elem);

                else    
                    printf("O elemento %d foi removido.\n", elem);

                break;
            
            case 4:
                imprime_lista(lst);
                break;

            case 5:
                apaga_lista(&lst);
                printf("Lista apagada.\n");

                break;

            case 6:
                ativo = 6;
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
    int i;
    int N;

    for(i = 1; get_pos(lst, i, &N) == 1; i++)
        printf(" %d ", N);

    printf("existem %d elementos na lista.\n", i - 1);
    
}