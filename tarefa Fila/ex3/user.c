#include <stdio.h>
#include "fila.h"

void imprime_Fila(Fila *f);

int main(){

    Fila f;
    int ativo = 0;
    int i = 0;
    int n;

    Produto elem;

    while(ativo != 1){

        printf("--------------------------------------------\n");
        printf("--Fila--\n");
        printf("\n[1] Criar Fila\n");
        printf("[2] Inserir elemento na Fila\n");
        printf("[3] Remover elemento da Fila\n");
        printf("[4] Imprimir Fila\n");
        printf("[5] Tamanho Fila\n");
        printf("[6] Limpar Fila\n");
        printf("[7] Apagar Fila\n");
        printf("[8] Sair\n");
        printf("--------------------------------------------\n");
        printf("Digite o valor desejado: ");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){

            case 1:
                f = cria_Fila();

                printf("A Fila foi criada com sucesso\n");
                    
                break;

            case 2:
                printf("Insira o codigo: ");
                scanf("%d", &elem.codigo);

                printf("Insira a descricao: ");
                scanf("%s", &elem.descricao);

                printf("Insira o preco: ");
                scanf("%f", &elem.preco);

                if(insere_Fim(f, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");
                else
                    printf("A produto %d foi incluido.\n", elem.codigo);

                break;

            case 3:
                if(remove_ini(f, &elem) == 0)
                    printf("A lista ja se encontra vazia.\n");
                else
                    printf("O produto %d foi removido.\n", elem.codigo);

                break;

            case 4:
                if(f != NULL)
                    imprime_Fila(&f);
                else
                    printf("Nao foi possivel imprimir.\n");
            
                break;

            case 5:
                if(tamanho_Fila(f) == -1)
                    printf("A lista nao existe.\n");
                else
                    printf("A fila possui %d elementos.\n", tamanho_Fila(f));

                break;

            case 6:
                if(esvazia_Fila(f) == 0)
                    printf("Nao existe nenhuma lista.\n");
                else
                    printf("Lista esvaziada.\n");

                break;

            case 7:
                if(f == NULL)
                    printf("A fila nao existe");
                else
                    apaga_Fila(&f);

                printf("Lista apagada.\n");

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

void imprime_Fila(Fila *f){

    if(fila_vazia(*f) == 1 || *f == NULL){

        printf("\n --Fila Vazia--\n");
        return;
    }

    Fila aux;
    aux = cria_Fila();

    Produto elem;

    printf("\nFila: \n");

    while(fila_vazia(*f) == 0){

        remove_ini(*f, &elem);

        printf("%d ", elem.codigo);
        printf("%s ", elem.descricao);
        printf("%.2f ", elem.preco);

        insere_Fim(aux, elem);
        printf("\n");
    }

    while(fila_vazia(aux) == 0){

        remove_ini(aux, &elem);
        insere_Fim(*f, elem);  
    }

    apaga_Fila(&aux);
}
