#include <stdio.h>
#include "lista.h"

void Criar(Lista *);
void Apagar(Lista *);
void Imprimi(Lista);
void Insere_elemento(Lista *);
void Insere_posicao(Lista *);
void Remove_elemento(Lista *);
void Remove_todos(Lista *);
void Remove_menor(Lista *);
void Inverter(Lista, Lista *);

int main()
{
    Lista reais = NULL, invertida = NULL;
    int i = 1, n;
    while (1)
    {
        if (i == 1)
        {
            printf("--------------------Lista normal--------------------------\n");
            printf("Escolha uma das seguintes opcoes: \n");
            printf("[1] Criar a lista\n");
            printf("[2] Apagar a lista\n");
            printf("[3] Imprimir a lista\n");
            printf("[4] Adicionar um elemento no inicio da lista\n");
            printf("[5] Adicionar um elemento na posicao desejada\n");
            printf("[6] Remover elemento da lista\n");
            printf("[7] Remover todas as ocorrencias de um elemento da lista\n");
            printf("[8] Remover o menor elemento da lista\n");
            printf("[9] Criar a lista invertida\n");
            printf("[10] Mudar para a lista invertida\n");
            printf("[11] Encerrar o programa\n\n");
            printf("Digite a opcao desejada: ");

            scanf("%d", &n);

            if (n == 1)
                Criar(&reais);

            else if (n == 2)
                Apagar(&reais);

            else if (n == 3)
                Imprimi(reais);

            else if (n == 4)
                Insere_elemento(&reais);

            else if (n == 5)
                Insere_posicao(&reais);

            else if (n == 6)
                Remove_elemento(&reais);

            else if (n == 7)
                Remove_todos(&reais);

            else if (n == 8)
                Remove_menor(&reais);

            else if (n == 9)
                Inverter (reais, &invertida);

            else if (n == 10)
                i = 2;

            else if (n == 11)
            {
                if (reais != NULL && invertida != NULL)
                printf("A lista nao foi apagada!!\n");
                else
                {
                    break;
                }
            }
            else
                printf("Digite um numero valido!\n");
        }
        else
        {
            if(invertida == NULL)
            {
                i = 1;
                printf("Lista invertida nao criada\n\n");
                continue;
            }
            printf("--------------------Lista invertida---------------------\n");
            printf("Escolha uma das seguintes opcoes: \n");
            printf("[1] Apagar a lista\n");
            printf("[2] Imprimir a lista\n");
            printf("[3] Adicionar um elemento no inicio da lista\n");
            printf("[4] Adicionar um elemento na posicao desejada\n");
            printf("[5] Remover elemento da lista\n");
            printf("[6] Remover todas as ocorrencias de um elemento da lista\n");
            printf("[7] Remover o menor elemento da lista\n");
            printf("[8] Mudar para a lista normal\n");
            printf("[9] Encerrar o programa\n\n");
            printf("Digite a opcao desejada: ");

            scanf("%d", &n);

            if (n == 1)
                Apagar(&invertida);

            else if (n == 2)
                Imprimi(invertida);

            else if (n == 3)
                Insere_elemento(&invertida);

            else if (n == 4)
                Insere_posicao(&invertida);

            else if (n == 5)
                Remove_elemento(&invertida);

            else if (n == 6)
                Remove_todos(&invertida);

            else if (n == 7)
                Remove_menor(&invertida);

            else if (n == 8)
                i = 1;

            else if (n == 9)
            {
                if (reais != NULL && invertida != NULL)
                printf("A lista nao foi apagada!!\n");
                else
                {
                    break;
                }
            }
            else
                printf("Digite um numero valido!\n");
        }
        printf ("\n");

    }

    return 0;
}

void Criar(Lista *lst)
{
    if (*lst != NULL)
        printf ("Apague a lista primeiro\n");
    else
    {
        *lst = Cria_lista();
        printf ("Lista criada com sucesso\n");
    }
}

void Apagar(Lista *lst)
{
    if (apaga_lista(lst) == 1)
        printf("Lista apagada com sucesso\n");
    else
        printf("Lista nao apagada\n");
}

void Imprimi(Lista lst)
{
    int i = 1;
    double info;

    if (get_elem_pos(lst, i, &info) == 0)
    {
        printf("Lista invalida ou vazia\n");
        return;
    }

    printf("A lista possui os numeros: \n");
    while (get_elem_pos(lst, i, &info) == 1)
    {
        printf("%.3lf\n\n", info);
        i++;
    }
}

void Insere_elemento(Lista *lst)
{
    double info;
    printf("Digite o elemento a ser adicionado: ");
    scanf("%lf", &info);

    if (insere_elem(lst, info) == 1)
        printf("Elemento adicionado na lista com sucesso\n");
    else
        printf("Elemento nao adicionado na lista com sucesso\n");
}

void Insere_posicao(Lista *lst)
{
    int pos;
    double info;
    printf("Digite o elemento a ser adicionado: ");
    scanf("%lf", &info);

    printf("Digite a posicao da lista desejada: ");
    scanf("%d", &pos);

    if (insere_pos(lst, info, pos) == 1)
        printf("Elemento adicionado na lista com sucesso\n");
    else
        printf("Elemento nao adicionado na lista com sucesso\n");
}

void Remove_elemento(Lista *lst)
{
    double info;
    printf("Digite o elemento a ser removido: ");
    scanf("%lf", &info);

    if (remove_elem(lst, info) == 1)
        printf("Elemento removido da lista\n");
    else
        printf("Elemento nao removido da lista\n");
}

void Remove_todos(Lista *lst)
{
    double info;
    printf("Digite o elemento a ser removido: ");
    scanf("%lf", &info);

    if (remove_todos(lst, info) == 1)
        printf("Elemento removido da lista\n");
    else
        printf("Elemento nao removido da lista\n");
}

void Remove_menor(Lista *lst)
{
    double info;
    if (remove_menor(lst, &info) == 1)
        printf("Elemento %lf removido da lista\n", info);
    else
        printf("Elemento %lf nao removido da lista\n", info);
}

void Inverter(Lista lst, Lista *lst2)
{
    if (inverte(lst, *lst2) == 1)
        printf("Lista invertida criada\n");
    else
        printf("Lista invertida nao criada\n");
}
