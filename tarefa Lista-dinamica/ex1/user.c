#include <stdio.h>
#include "lista.h"

void imprime_lista(Lista lst);

int main(){

    Lista lst;
    Alunos al;

    unsigned int elem;
    int ativo = 0;
    int n, N;

    while(ativo != 6){

        printf("--------------------------------------------\n");
        printf("[1] Cria lista\n");
        printf("[2] Inserir aluno na lista\n");
        printf("[3] Remover aluno da lista\n");
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
                printf("Insira a matricula do aluno: ");
                scanf("%u", &al.matricula);

                printf("Digite o nome do aluno: ");
                scanf("%s", &al.nome);

                printf("Digite a media do aluno: ");
                scanf("%f", &al.media);

                printf("Digite a quantidade de faltas: ");
                scanf("%d", &al.faltas);

                if(insere_ord(&lst, al) == 0)
                    printf("Nao foi possivel adicionar.\n");  
                
                else
                    printf("O aluno %s foi incluido.\n", al.nome);

                break;
            
            case 3:
                printf("Digite a matricula que deseja remover: ");
                scanf("%u", &elem);

                if(remove_ord(&lst, elem) == 0)
                    printf("Numero %u nao encontrado.\n", elem);

                else    
                    printf("A matricula %u foi removido.\n", elem);

                break;
            
            case 4:
                if(lst != NULL)
                    imprime_lista(lst);

                else
                    printf("Nao foi possivel imprimir.\n");
                
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
    unsigned int Mat;
    int i, Falta;
    float Media;
    char Nome[20];

    for(i = 1; get_pos(lst, i, &Mat, Nome, &Media, &Falta) == 1; i++){

        printf(" %u ", Mat);
        printf("- %s ", Nome);
        printf("- %.2f ", Media);
        printf("- %d faltas\n", Falta);
    }
    printf("\n");
    printf("existem %d elementos na lista.\n", i - 1);
    
}