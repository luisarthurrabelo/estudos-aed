#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void imprime_Pilha(Pilha *p);

int main(){

    Pilha p;
    Funcionario funcionario;

    int ativo = 0;
    int n;

    while(ativo != 1){

        printf("--------------------------------------------\n");
        printf("--Pilha--\n");
        printf("\n[1] Criar Pilha\n");
        printf("[2] Inserir elemento na Pilha\n");
        printf("[3] Remover elemento da Pilha\n");
        printf("[4] Imprimir Pilha\n");
        printf("[5] Limpar Pilha\n");
        printf("[6] Apagar Pilha\n");
        printf("[7] Verificar tamanho da Pilha\n");
        printf("[8] Sair\n");
        printf("--------------------------------------------\n");
        printf("Digite o valor desejado: ");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){

            case 1:
                p = cria_pilha();
                printf("Pilha criada\n");
                
                break;

            case 2:
                printf("Insira a matricula: ");
                scanf("%ld", &funcionario.matricula);

                printf("Insira o nome: ");
                scanf("%s", &funcionario.nome);
                getchar();

                printf("Insira o setor: ");
                scanf("%c", &funcionario.setor);

                printf("Insira o salario: ");
                scanf("%f", &funcionario.salario);
                
                if(push(&p, funcionario) == 0)
                    printf("\nNao foi possivel adicionar.\n");
                else
                    printf("O funcionario %s foi incluido.\n", &funcionario.nome);

                break;

            case 3:
                if(pop(&p, &funcionario.matricula) == 0)
                    printf("O elemento %ld nao foi encontrado.\n", funcionario.matricula);
                else
                    printf("O elemento %ld foi removido.\n", funcionario.matricula);

                break;

            case 4:
                if(p != NULL)
                    imprime_Pilha(&p);
                
                else
                    printf("Nao foi possivel imprimir.\n");
            
                break;

            case 5:
                if(esvazia_Pilha(&p) == 0)
                    printf("Nao existe nenhuma pilha.\n");
                else
                    printf("Pilha esvaziada.\n");

                break;
                
            case 6:
                apaga_Pilha(&p);
                printf("Pilha apagada.\n");

                break;

            case 7:
                if (tamanho_Pilha(p) >= 0)
                    printf("A Pilha tem tamanho igual a %d\n", tamanho_Pilha(p));
                else
                    printf("Pilha invalida\n");

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

void imprime_Pilha(Pilha *p)
{
    if(pilha_vazia(*p) || *p == NULL)
        printf("Pilha invalida ou vazia\n");

    else{

        Pilha aux = cria_pilha();
        Funcionario elem;

        printf("Pilha: \n");
        
        while(pilha_vazia(*p) == 0)
        {
            get_Topo(*p, &elem);
            push(&aux, elem);
            pop(p, &elem.matricula);
        }

        while(pilha_vazia(aux) == 0)
        {
            get_Topo(aux, &elem);
            printf("matricula: %ld\n", elem.matricula);
            printf("nome: %s\n", elem.nome);
            printf("setor: %c\n", elem.setor);
            printf("setor: %f\n", elem.salario);
            printf("-----------------------------\n");
            
            push(p, elem);
            pop(&aux, &elem.matricula);
        }
    }
}

