#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void imprime_fila(Fila, Pessoa);

int main(){

    Fila f = NULL;
    Pessoa elem;
    int ativo = 1;
    int n, verifica = 0;

    while(ativo == 1){

        printf("--------------------------------------------\n");
        printf("--Fila--\n");
        printf("\n 1 - Criar Fila\n");
        printf(" 2 - Inserir cadastro na Fila\n");
        printf(" 3 - Remover cadastro da Fila\n");
        printf(" 4 - Imprimir Fila\n");
        printf(" 5 - Limpar Fila\n");
        printf(" 6 - Apagar Fila\n");
        printf(" 7 - Sair\n");
        printf("--------------------------------------------\n");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        if (n == 1 && verifica == 0)
        {
            f = cria_fila();
            verifica = 1;
            printf("A fila foi criada com sucesso\n");
        }

        else if(verifica == 1)
        {
            if(n == 1)
            {
                printf("\nA fila ja foi criada\n");
            }
            else if(n == 2)
            {

                printf("Insira o nome do paciente: ");
                scanf("%[^\n]", elem.nome);

                printf("Insira a idade: ");
                scanf("%d", &elem.idade);

                printf("Insira o peso: ");
                scanf("%f", &elem.peso);

                printf("Insira a altura: ");
                scanf("%f", &elem.altura);

                printf("Insira a doenca: ");
                getchar();
                scanf("%c", &elem.doenca);

                printf("Insira a gravidade: ");
                scanf("%d", &elem.gravidade);

                printf ("\n");

                if(insere_ord(&f, elem) == 0)
                    printf("Nao foi possivel adicionar.\n");
                else
                    printf("incluido.\n");

            }
            else if(n == 3)
            {
                if(remove_ini(&f, &elem) == 0)
                    printf("Lista vazia.\n");

                else{

                    printf("O paciente:\n\n");
                    printf("Nome: %s\n", elem.nome);
                    printf("Idade: %d\n", elem.idade);
                    printf("Peso: %.2f\n", elem.peso);
                    printf("Altura: %.2f\n", elem.altura);
                    printf("Doenca: %c\n", elem.doenca);
                    printf("Gravidade: %d\n\n", elem.gravidade);
                    printf("Foi removido\n");
                }

            }
            else if(n == 4)
            {
               if(f != NULL)
                    imprime_fila(f, elem);
                else
                    printf("Nao foi possivel imprimir.\n");

            }
            else if(n == 5)
            {

              if(esvazia_fila(&f) == 0)
                    printf("Nao existe nenhuma fila.\n");
                else
                    printf("Fila esvaziada.\n");

            }
            else if(n == 6)
            {
                apaga_fila(&f);
                printf("Fila apagada.\n");

            }
            else if(n == 7)
            {
                return 0;
            }
            else
            {
                printf("Opcao invalida");
                return 0;
            }

            printf("\n\n");
        }
        else
        {
            printf("\nLista ainda nao criada!\n\n");
        }
    }

    return 0;
}

void imprime_fila(Fila f, Pessoa elem)
{
    if(fila_vazia(f) == 1){

        printf("\n --Fila Vazia--\n");
        return;
    }
    printf("\nFila:\n\n");

    Fila aux = cria_fila();

    while (fila_vazia(f) == 0)
    {
        remove_ini (&f, &elem);

        printf("Nome: %s\n", elem.nome);
        printf("Idade: %d\n", elem.idade);
        printf("Peso: %.2f\n", elem.peso);
        printf("Altura: %.2f\n", elem.altura);
        printf("Doenca: %c\n", elem.doenca);
        printf("Gravidade: %d", elem.gravidade);

        insere_ord(&aux, elem);
        printf ("\n\n");
    }
     while(fila_vazia(aux)==0)
    {
        remove_ini(&aux, &elem);
        insere_ord(&f, elem);
    }

}
