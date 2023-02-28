#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst;

    int ativo = 0;
    int n, N;
    char elem[20];

    while(ativo != 6){

        printf("--------------------------------------------\n");
        printf("[1] Cria lista\n");
        printf("[2] Inserir uma string na lista\n");
        printf("[3] Remover uma string da lista\n");
        printf("[4] Imprimir Lista\n");
        printf("[5] Limpar Lista\n");
        printf("[6] Sair\n");
        printf("--------------------------------------------\n");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){

            case 1:
                lst = cria_lista();

                if(lst == NULL){
                    printf("Falha na alocacao\n");
                    return -1;
                }

                break;

            case 2:
                printf("Digite a string que deseja adicionar: ");
                scanf("%s", elem);

                if(insere_elem(lst, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");  
                
                else
                    printf("A string %s foi incluida.\n", elem);

                break;
            
            case 3:
                printf("Digite o string que deseja remover: ");
                scanf("%s", elem);

                if(remove_elem(lst, elem) == 0)
                    printf("A string %s nao foi encontrada.\n", elem);

                else    
                    printf("O elemento %s foi removido.\n", elem);

                break;
            
            case 4:
                imprime_lista(lst);
                break;

            case 5:
                if(limpa_lista(lst) == 0)
                    printf("Nao foi possivel apagar.\n");
                
                printf("Lista apagada.\n");
                break;

            case 6:
                ativo = 6;
                break;

            default:
                printf("opcao invalida!\n");
        }
    }

    apaga_lista(&lst);
    return 0;
}

void imprime_lista(Lista lst){

    if(lista_vazia(lst) == 1){

        printf("\n --Lista Vazia--\n");
        return;
    }

    printf("\nLista: ");
    int i;
    char N[20];

    for(i = 1; get_pos(lst, i, N) == 1; i++)
        printf(" %s ", N);

    printf("existem %d elementos na lista.\n", i - 1);
    
}