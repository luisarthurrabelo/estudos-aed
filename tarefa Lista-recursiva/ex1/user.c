#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst;

    int ativo = 0;
    int n, N;
    char elem;

    while(ativo != 6){

        printf("--------------------------------------------\n");
        printf("[1] Cria lista\n");
        printf("[2] Inserir caractere na lista\n");
        printf("[3] Remover caractere da lista\n");
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
                printf("Digite o caractere: ");
                scanf("%c", &elem);

                if(insere_ord(&lst, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");  
                
                else
                    printf("O caractere %c foi incluido.\n", elem);

                break;
            
            case 3:
                printf("Digite o caractere que deseja remover: ");
                scanf("%d", &elem);

                if(remove_ord(&lst, elem) == 0)
                    printf("Caractere %c nao encontrado.\n", elem);

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
    char N;

    for(i = 1; get_pos(lst, i, &N) == 1; i++)
        printf(" %c ", N);

    printf("existem %d elementos na lista.\n", i - 1);
    
}