#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void imprime(lista);

int main()
{
    int maximo = 0, n = 0;
    lista li[4]= {NULL, NULL, NULL, NULL};
    int inteiro, i = 0, valor1;

    while(maximo != 11)
    {
        printf("\n-----------------------Lista %d-----------------------\n", i+1);
        printf(" 1 - Criar lista\n");
        printf(" 2 - Inserir um elemento na lista\n");
        printf(" 3 - Remover um elemento da lista\n");
        printf(" 4 - Imprimir lista\n");
        printf(" 5 - Limpar a lista\n");
        printf(" 6 - Apagar a lista\n");
        printf(" 7 - Remover e apresentar o maior elemento de uma lista\n");
        printf(" 8 - Inverter a lista\n");
        printf(" 9 - Intercalar e apresentar os elementos das listas\n");
        printf(" 10 - Mudar de lista\n");
        printf(" 11 - Sair\n");
        printf("\n");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){
           case 1:

                li[i] = cria_lista();

                if(li[i] == NULL)
                    printf("A lista foi criada!\n");
                else
                    printf("A lista nao foi criada!\n");
                break;

            case 2:

                printf ("Digite o valor desejado:\n");
                scanf("%d", &inteiro);
                insere_elem(&li[i], inteiro);
                break;

            case 3:

                printf ("Qual valor deseja remover?\n");
                scanf("%d", &inteiro);
                remove_elem(&li[i], inteiro);
                break;

            case 4:

                imprime(li[i]);
                break;

            case 5:

                esvazia_lista(&li[i]);
                if(li[i] == NULL)
                    printf("Lista esvaziada\n");
                else
                    printf("Erro ao esvaziar lista\n");
                break;

            case 6:

                apaga_lista(&li[i]);
                if(li[i] == 0)
                    printf("memoria liberada\n");
                break;

            case 7:

                remover_maior(&li[i], &valor1);
                printf("O elemento %d foi removido\n", valor1);
                break;

            case 8:

                li[2] = inverter(&li[i]);
                imprime(li[2]);
                break;

            case 9:
                printf("Lista intercalada:\n");
                li[3] = intercalar(li[0], li[1]);
                imprime(li[3]);
                break;

            case 10:
                if(i == 0)
                    i = 1;
                else
                    i = 0;
                break;

            default:
                printf("Escolha invalida!\n");
        }

    }
    return 0;
}

void imprime(lista li){

    if(lista_vazia(li) == 1){

        printf("\n --Lista Vazia--\n");

    }
    printf("\nLista: ");

    int pos;
    int inteiro;

    for(pos = 1; get_elem_pos(li, pos, &inteiro) == 1; pos++)
    {
        printf("\n %d\n", inteiro);
    }
    printf ("Quantidade de elementos: %d", pos - 1);
}
