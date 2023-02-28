#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst[3];
    int v[2] = {2, 1};
    int ativo = 0;
    int i = 0;
    int n, c, p;
    float elem;

    while(ativo != 12){

        printf("--------------------------------------------\n");
        printf("--LISTA %d--\n", i + 1);
        printf("\n[1] Criar lista\n");
        printf("[2] Inserir numero na lista\n");
        printf("[3] Remover numero da lista\n");
        printf("[4] Remover numero da lista(pela posicao)\n");
        printf("[5] Imprimir Lista\n");
        printf("[6] Limpar Lista\n");
        printf("[7] Apagar Lista\n");
        printf("[8] Verificar tamanho Lista\n");
        printf("[9] Comparar listas\n");
        printf("[10] Intercalar Listas\n");
        printf("[11] Mudar para a lista %d\n", v[i]);
        printf("[12] Sair\n");
        printf("--------------------------------------------\n");
        printf("Digite o valor desejado: ");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){

            case 1:
                lst[i] = cria_lista();
                if (lst[i] == NULL)
                    printf("Lista %d nao criada\n", i+1);
                else
                    printf("Lista %d criada com sucesso\n", i+1);
                break;

            case 2:
                printf("Insira o numero: ");
                scanf("%f", &elem);

                if(insere_ord(&lst[i], elem) == 0)
                    printf("Nao foi possivel adicionar.\n");

                else
                    printf("O numero %.2f foi incluido.\n", elem);

                break;

            case 3:
                printf("Digite o numero que deseja remover: ");
                scanf("%f", &elem);

                if(remove_ord(&lst[i], elem) == 0)
                    printf("O numero %.2f nao foi encontrado.\n", elem);

                else
                    printf("O numero %.2f foi removido.\n", elem);

                break;

            case 4:
                printf("Digite a posicao do elemento que deseja remover: ");
                scanf("%d", &p);

                if(remover_pos(&lst[i], p) == 0)
                    printf("O numero da posicao %d nao foi encontrado.\n", p);

                else
                    printf("O numero da posicao %d foi removido.\n", p);

                break;

            case 5:
                if(lst[i] != NULL)
                    imprime_lista(lst[i]);

                else
                    printf("Nao foi possivel imprimir.\n");

                break;

            case 6:
                if(limpa_lista(&lst[i]) == 0)
                    printf("Nao existe nenhuma lista.\n");

                else
                    printf("Lista esvaziada.\n");

                break;

            case 7:
                apaga_lista(&lst[i]);
                printf("Lista apagada.\n");
                break;

            case 8:
                c = lista_tamanho(lst[i]);

                if(lista_vazia(lst[i]) == 1)
                    printf("lista vazia\n");

                else if(c == 0)
                    printf("lista vazia\n");

                else
                    printf("A lista tem tamanho %d\n", c);
                break;

            case 9:
                if(lista_iguais(&lst[0], &lst[1]) == -1)
                    printf("Nao foi possivel comparar as listas.\n");

                if(lista_iguais(&lst[0], &lst[1]) == 0)
                    printf("As listas sao diferentes.\n");

                else
                    printf("As listas sao iguais.\n");

                break;

            case 10:
                lst[2] = lista_intercalar(lst[0], lst[1]);
                if(lst[2] == NULL)
                    printf("Lista intercalada nao foi criada\n");
                else
                {
                    printf("Lista intercalada:\n");
                    imprime_lista(lst[2]);
                    apaga_lista(&lst[2]);
                }
                break;


            case 11:
                if (i == 0)
                    i = 1;
                else
                    i = 0;
                break;

            case 12:
                ativo = 12;
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
    float N;

    for(i = 1; get_pos(lst, i, &N) == 1; i++){

        printf(" %.2f ", N);
    }
    printf("\n");
    printf("existem %d elementos na lista.\n", i - 1);
}
