#include <stdio.h>
#include "bebidas.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst;
    Bebidas bebi;

    int ativo = 0;
    int n, N;

    while(ativo != 6){

        printf("--------------------------------------------\n");
        printf("[1] Cria lista\n");
        printf("[2] Inserir bebida na lista\n");
        printf("[3] Remover bebida da lista\n");
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

                printf("Lista criada.\n");
                break;

            case 2:
                printf("Digite a bebida que deseja adicionar: ");
                scanf("%s", &bebi.nome);

                printf("Digite o volume da bebida: ");
                scanf("%d", &bebi.volume);

                printf("Digite o preco da bebida: ");
                scanf("%f", &bebi.preco);

                if(insere_ord(lst, bebi) == 0)
                    printf("Nao foi possivel adicionar.\n");  
                
                else
                    printf("A bebida %s foi incluida.\n", &bebi.nome);

                break;
            
            case 3:
                printf("Digite a bebida que deseja remover: ");
                scanf("%s", &bebi.nome);

                if(remove_ord(lst, bebi.nome) == 0)
                    printf("Bebida %s nao encontrado.\n", &bebi.nome);

                else    
                    printf("A bebida %s foi removida.\n", &bebi.nome);

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
    int i, V;
    float P;
    char N[20];

    for(i = 1; get_pos(lst, i, N, &V, &P) == 1; i++){
        printf(" %s ", N);
        printf(" %dml", V);
        printf(" %.2f$\n", P);
    }

    printf("\nexistem %d elementos na lista.\n", i - 1);
    
}