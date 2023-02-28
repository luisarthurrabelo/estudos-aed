#include <stdio.h>
#include "deque.h"

int main()
{

    int n;
    char A[21];
    Deque N = NULL;
    while (1)
    {
        printf("Escolha uma das seguintes opcoes: \n");
        printf("[1] Criar o deque\n");
        printf("[2] Apagar o deque\n");
        printf("[3] Esvaziar o deque\n");
        printf("[4] Verifica se o deque esta vazio\n");
        printf("[5] Verifica se o deque esta cheio\n");
        printf("[6] Imprimir o deque do inicio ao fim\n");
        printf("[7] Imprimir o deque do fim ao inicio\n");
        printf("[8] Adicionar no final do deque\n");
        printf("[9] Remover do inicio do deque\n");
        printf("[10] Adicionar no inicio do deque\n");
        printf("[11] Remover do final do deque\n");
        printf("[12] Encerrar o programa\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &n);

        if (n == 1)
        {
            if (N == NULL)
            {
                if ((N = cria_deque()) != NULL)
                    printf("Deque criado com sucesso\n");
                else
                    printf("Deque nao criado\n");
            }
            else
                printf("Deque ja foi criado\n");
        }

        else if(n == 2)
        {
            if (apaga_deque(&N))
                printf("Deque apagado com sucesso\n");
            else
                printf("Deque invalido\n");
        }

        else if(n == 3)
        {
            if (esvazia_deque(N))
                printf("Deque esvaziado com sucesso\n");
            else
                printf("Deque invalido ou vazio\n");
        }

        else if(n == 4)
        {
            if (deque_vazio(N))
                printf("Deque vazio\n");
            else
                printf("Deque invalido ou nao esta vazio\n");
        }

        else if(n == 5)
        {
            if (deque_cheio(N))
                printf("Deque cheio\n");
            else
                printf("Deque invalido ou nao esta cheio\n");
        }

        else if(n == 6)
        {
            if (deque_vazio(N))
                printf("Deque invalido ou vazio\n");

            Deque L = cria_deque();
            while(!deque_vazio(N))
            {
                remove_inicio(N, A);
                printf("\nString: %s\n", A);
                insere_fim(L, A);
            }
            while(!deque_vazio(L))
            {
                remove_inicio(L, A);
                insere_fim(N, A);
            }

            apaga_deque(&L);
        }

        else if(n == 7)
        {
            if (deque_vazio(N))
                printf("Deque invalido ou vazio\n");

            Deque L = cria_deque();
            while(!deque_vazio(N))
            {
                remove_fim(N, A);
                printf("\nString: %s\n", A);
                insere_inicio(L, A);
            }
            while(!deque_vazio(L))
            {
                remove_fim(L, A);
                insere_inicio(N, A);
            }
            apaga_deque(&L);
        }

        else if(n == 8)
        {
            printf("Digite a string ser adicionada: ");
            getchar();
            scanf("%[^\n]", A);

            if(insere_fim(N, A))
                printf("String adicionada com sucesso\n");
            else
                printf("Falha em adicionar a string");
        }


        else if(n == 9)
        {
            if (remove_inicio(N, A))
            {
                printf("\nString\n: %s", A);
            }
            else
                printf("Deque invalido ou vazio\n");
        }

        else if(n == 10)
        {
            printf("Digite a string ser adicionada: ");
            getchar();
            scanf("%[^\n]", A);

            if(insere_inicio(N, A))
                printf("String adicionada com sucesso\n");
            else
                printf("Falha em adicionar a string");
        }

        else if(n == 11)
        {
            if (remove_fim(N, A)){
                printf("\nString: %s\n", A);
            }
            else{
                printf("Deque invalido ou vazio\n");
            }

        }

        else if(n == 12)
        {
            return 0;
        }

        else
            printf("Digite um numero valido!\n");

        printf("\n");
    }


    return 0;
}


