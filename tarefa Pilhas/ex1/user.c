#include <stdio.h>
#include "pilha.h"

void imprime_Pilha(Pilha p);

int main(){

    Pilha p;
    int ativo = 0;
    int i = 0;
    int n;
    char elem[20];

    while(ativo != 1){

        printf("--------------------------------------------\n");
        printf("--Pilha--\n");
        printf("\n[1] Criar Pilha\n");
        printf("[2] Inserir elemento na Pilha\n");
        printf("[3] Remover elemento da Pilha\n");
        printf("[4] Imprimir Pilha\n");
        printf("[5] Limpar Pilha\n");
        printf("[6] Apagar Pilha\n");
        printf("[7] Verificar tamanho Pilha\n");
        printf("[8] Sair\n");
        printf("--------------------------------------------\n");
        printf("Digite o valor desejado: ");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){

            case 1:
                p = cria_pilha();
                if(p == NULL)
                    printf("A pilha nao foi criada\n");
                else
                    printf("A pilha foi criada com sucesso\n");
                    
                break;

            case 2:
                printf("Insira o elemento que deseja adicionar: ");
                scanf("%s", elem);

                if(push(p, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");
                else
                    printf("O elemento %s foi incluido.\n", elem);

                break;

            case 3:
                if(pop(p, elem) == 0)
                    printf("O elemento %s nao foi encontrado.\n", elem);
                else
                    printf("O elemento %s foi removido.\n", elem);

                break;

            case 4:
                if(p != NULL)
                    imprime_Pilha(p);
                else
                    printf("Nao foi possivel imprimir.\n");
            
                break;

            case 5:
                if(esvazia_Pilha(p) == 0)
                    printf("Nao existe nenhuma lista.\n");
                else
                    printf("Lista esvaziada.\n");

                break;

            case 6:
                apaga_Pilha(&p);
                printf("Lista apagada.\n");

                break;

            case 7:
                if (tamanho_Pilha(p) >= 0)
                    printf("A lista tem tamanho igual a %d\n", tamanho_Pilha(p));
                else
                    printf("Lista invalida\n");

                break;

            case 8:
                ativo = 1;
                break;

            default:
                printf("opcao invalida!\n");
            }

    }

    return 0;
}

void imprime_Pilha(Pilha p){

    if(pilha_vazia(p) == 1){

        printf("\n --Pilha Vazia--\n");
        return;
    }

    Pilha aux;
    aux = cria_pilha();

    char N[20];

    printf("\nPilha: \n");

    while(tamanho_Pilha(p) > 0){

        get_Topo(p, N);
        push(aux, N);
        pop(p, N);
    }

    while(tamanho_Pilha(aux) > 0){

        get_Topo(aux, N);
        printf("%s\n", N);
        push(p, N);
        pop(aux, N);
    }

    apaga_Pilha(&aux);
}
