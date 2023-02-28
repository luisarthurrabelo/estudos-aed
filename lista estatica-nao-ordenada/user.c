#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst;

    int ativo = 0;
    int n, N;
    float elem;

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

                if(lst == NULL){
                    printf("Falha na alocacao\n");
                    return -1;
                }

                break;

            case 2:
                printf("Digite o numero que deseja adicionar: ");
                scanf("%f", &elem);

                if(insere_elem(lst, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");  
                
                else
                    printf("O numero %f foi incluido.\n", elem);

                break;
            
            case 3:
                printf("Digite o numero que deseja remover: ");
                scanf("%f", &elem);

                if(remove_elem(lst, elem) == 0)
                    printf("Numero %f nao encontrado.\n", elem);

                else    
                    printf("O elemento %f foi removido.\n", elem);

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
    float N;

    for(i = 1; get_pos(lst, i, &N) == 1; i++)
        printf(" %f ", N);

    printf("existem %d elementos na lista.\n", i - 1);
    
}