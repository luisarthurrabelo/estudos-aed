/*
   
*/

#include <stdio.h>
#include <stdlib.h>

struct bebida{

    char nome[20];
    int volume;
    float preco;
};

void *inserirBebida(struct bebida **bebidas[]);
void apagarBebida(struct bebida *bebidas[]);
void mostrarBebidas(struct bebida *bebidas[]);

int main(){

    struct bebida *bebidas[20];
    int n;
    int ativo = 0;

    for(int i = 0; i < 20; i++){

        bebidas[i] = NULL;
    }

    while(ativo != 4){

        printf("--------------------------------------------\n");
        printf("[1] Inserir bebida na tabela\n");
        printf("[2] Apagar ultimo registro da tabela\n");
        printf("[3] Imprimir tabela\n");
        printf("[4] Sair\n");
        printf("--------------------------------------------\n");

        scanf("%d", &n);

        switch(n){

            case 1:
                inserirBebida(bebidas);
                break;
            
            case 2:
                apagarBebida(bebidas);
                break;

            case 3:
                mostrarBebidas(bebidas);
                break;
            
            case 4:
                ativo = 4;
                break;

            default:
                printf("opcao invalida!\n");
        }
    }

    return 0;
}

void *inserirBebida(struct bebida **bebidas[]){

    int n;

    for(int i = 0; i < 20; i++){

        if(bebidas[i] == NULL){

            n = i;
            break;
        }
    }

    struct bebida *beb;
    beb = (struct bebida *) malloc(sizeof(struct bebida));

    printf("Nome: ");
    scanf("%s", beb->nome);

    printf("volume: ");
    scanf("%d", &beb->volume);

    printf("preco: ");
    scanf("%f", &beb->preco);

    bebidas[n] = beb;
}

void apagarBebida(struct bebida *bebidas[]){

    int n;

    for(int i=0; i<20;i++){

        if(bebidas[i] == NULL){

            n = i - 1;
            break;
        }

    }

    if(bebidas[n] != NULL){

        printf("Bebida %d excluida!\n", n);
        bebidas[n] = NULL;
    }

    else{

        printf("Lista vazia!\n");
    }
}

void mostrarBebidas(struct bebida *bebidas[]){

    for (int i = 0; i < 20; i++){

        if(bebidas[i]!=NULL){

            printf("Bebidas Catalogadas: \n");
            printf("-------------------------------\n");
            printf("nome: %s\n", bebidas[i]->nome);
            printf("volume: %d\n", bebidas[i]->volume);
            printf("preco: %2.f\n", bebidas[i]->preco);
        }
    }
}