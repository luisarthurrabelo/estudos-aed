#include <stdio.h>
#include "pilha.h"

int main()
{
    int x=0;
    char y;
    Pilha p = cria_pilha();
    int n=0;
    int aux;
    printf("Digite um numero para converter: ");
    scanf("%d", &x);

    while(x>=0)
    {
        printf("\n---------------------------------------\n");
        printf("'O' para converter em octal\n");
        printf("'B' para converter em binario\n");
        printf("'H' para converter em hexadecimal\n");
        printf("---------------------------------------\n\n");
        printf("Digite a opcao desejada: ");

        getchar();
        scanf("%c", &y);

        switch(y)
        {
            case 'O':
                printf("\nO numero %d em octal eh igual a ", x);
                for(int i=0;(x/8)!=0;i++)
                {
                    aux = x%8;
                    push(p, &aux);
                    x = x/8;
                }

                push(p, &x);

                while(pilha_vazia(p)==0)
                {
                    pop(p, &n);
                    printf("%d", n);
                }

                printf("\n");

                break;

            case 'B':

                printf("\nO numero %d em binario eh igual a ", x);
                for(int i=0;x!=0;i++)
                {
                    aux = x%2;
                    if(x % 2 !=0)
                        push(p, &aux);

                    else
                        push(p, &aux);

                    x = x / 2;
                }

                while(pilha_vazia(p)==0)
                {
                    pop(p, &n);
                    printf("%d", n);
                }

                printf("\n");

                break;

            case 'H':
                printf("\nO numero %d em hexadecimal eh igual a ", x);
                for(int i=0;(x/16)!=0;i++)
                {
                    aux = x%16;
                    push(p, &aux);
                    x = x/16;
                }

                push(p, &x);

                while(pilha_vazia(p)==0)
                {
                    pop(p, &n);
                    if(n == 10)
                        printf("A");
                    else if(n == 11)
                        printf("B");
                    else if(n == 12)
                        printf("C");
                    else if(n == 13)
                        printf("D");
                    else if(n == 14)
                        printf("E");
                    else if(n == 15)
                        printf("F");
                    else
                        printf("%d", n);
                }

                printf("\n");

                break;

        }
        aux = 0;
        printf("Digite um numero para converter: ");
        scanf("%d", &x);
    }
    return 0;

}
