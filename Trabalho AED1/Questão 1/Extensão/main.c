#include <stdio.h>
#include "lista.h"

void cria(Lista *);

void tam(Lista *);

void imprimi(Lista);

void apaga(Lista *);

void esvazia(Lista *);

void insr(Lista *);

void rem_ord(Lista *);

void rem_p(Lista *);

void rem_v(Lista *);

void intercala(Lista *, Lista *, Lista *);

int main()
{
    Lista lst[3];
    lst[0] = NULL;
    lst[1] = NULL;
    lst[2] = NULL;
    int n, i = 0;

    while (1)
    {
        printf("-------------------Lista %d-------------------\n", i+1);
        printf("Escolha uma das seguintes opcoes:\n");
        printf("[1] Criar a lista\n");
        printf("[2] Tamanho da lista\n");
        printf("[3] Imprimi a lista\n");
        printf("[4] Apagar a lista\n");
        printf("[5] Esvaziar a lista\n");
        printf("[6] Insere de forma ordenada um caractere\n");
        printf("[7] Remove de forma ordenada um caractere\n");
        printf("[8] Remove o caractere da posicao indicada\n");
        printf("[9] Remove todas as vogais\n");
        printf("[10] Intercalar a primeira e a segunda lista e imprimi o resultado\n");
        if (i == 0)
            printf("[11] Mudar para a segunda lista\n");
        else
            printf("[11] Mudar para a primeira lista\n");
        printf("[12] Encerra o programa\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &n);
        getchar();

        if(n == 1)
            cria(&lst[i]);
        else if(n == 2)
            tam(&lst[i]);
        else if(n == 3)
            imprimi(lst[i]);
        else if(n == 4)
            apaga(&lst[i]);
        else if(n == 5)
            esvazia(&lst[i]);
        else if(n == 6)
            insr(&lst[i]);
        else if(n == 7)
            rem_ord(&lst[i]);
        else if(n == 8)
            rem_p(&lst[i]);
        else if(n == 9)
            rem_v(&lst[i]);
        else if(n == 10)
        {
            intercala(&lst[0], &lst[1], &lst[2]);
        }
        else if(n == 11)
        {
            if (i == 0)
                i = 1;
            else
                i = 0;
        }
        else if(n == 13)
            break;
        else
            printf("Digite um numero valido");

        printf("\n\n");
    }

    return 0;
}

void cria(Lista *lst)
{
    if(*lst != NULL)
        printf("Lista nao foi apagada");
    else
    {
        *lst = Cria_lista();
        if (*lst != NULL)
            printf("Lista criada com sucesso");
        else
            printf("Lista nao criada");
    }
}

void tam(Lista *lst)
{
    if (tamanho(*lst) >= 0)
        printf("A lista tem tamanho igual a %d", tamanho(*lst));
    else
        printf("Lista invalida");
}

void imprimi(Lista lst)
{
    int i = 1;
    char C;
    if (get_elem_pos(lst, i, &C) == 0)
    {
        printf("Lista invalida ou vazia");
    }
    else
    {
    printf("A lista possui os elementos:\n");

    printf("[%c]", C);
    i++;
    while (get_elem_pos(lst, i, &C) == 1)
    {
        printf(" [%c]", C);
        i++;
    }
    }
}

void apaga(Lista *lst)
{
    if( apaga_lista(lst) == 1)
        printf("Lista apaga com sucesso");
    else
        printf("Lista nao apagada");
}

void esvazia(Lista *lst)
{
    if(esvazia_lista(*lst) == 1)
        printf("Lista esvaziada com sucesso");
    else
        printf("Lista nao esvaziada");
}

void insr(Lista *lst)
{
    char C;
    printf("Digite o elemento que deseja adicionar: ");

    scanf("%c", &C);

    if (insere_ord(*lst, C) == 1)
        printf("Elemento adicionado com sucesso");
    else
        printf("Elemento nao adicionado");

}

void rem_ord(Lista *lst)
{
    char C;
    printf("Digite o elemento que deseja remover: ");

    scanf("%c", &C);

    if (remove_ord(*lst, C) == 1)
        printf("Elemento removido com sucesso");
    else
        printf("Elemento nao removido");

}

void rem_p(Lista *lst)
{
    int pos;
    printf("Digite a posicao do elemento que deseja remover: ");
    scanf("%d", &pos);
    if (remover_pos(*lst, pos) == 1)
        printf("Elemento removido com sucesso");
    else
        printf("Elemento nao removido");

}

void rem_v(Lista *lst)
{
    if (remover_vogais(*lst) == 1)
        printf("Vogais removidas com sucesso");
    else
        printf("Vogais nao removidas");
}

void intercala(Lista *lst1, Lista *lst2, Lista *lst3)
{
    if((*lst3 = intercala_listas(*lst1, *lst2)) != NULL)
    {
        imprimi(*lst3);
        printf("\n");
        apaga(lst3);
    }
    else
        printf("Nao foi possivel criar a lista intercalada");
}
