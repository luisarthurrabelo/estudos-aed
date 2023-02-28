#include <stdio.h>
#include "lista.h"

void Criar(Lista *);
void Apagar(Lista *);
void Imprimi(Lista);
void Insere_final(Lista *);
void Insere_inicio(Lista *);
void Insere_posicao(Lista *);
void Remove_inicio(Lista *);
void Remove_final(Lista *);
void Remove_pares(Lista *);

int main()
{

    Lista inteiros = Cria_lista();
    int n;
    while (1)
    {
        printf("Escolha uma das seguintes opcoes: \n");
        printf("[1] Criar a lista\n");
        printf("[2] Apagar a lista\n");
        printf("[3] Imprimir a lista\n");
        printf("[4] Adicionar um elemento no final da lista\n");
        printf("[5] Adicionar um elemento no inicio da lista\n");
        printf("[6] Adicionar um elemento na posicao desejada\n");
        printf("[7] Remover o primeiro elemento da lista\n");
        printf("[8] Remover o ultimo elemento da lista\n");
        printf("[9] Remover todos os numeros pares\n");
        printf("[10] Encerrar o programa\n\n");
        printf("Digite a opcao desejada: ");

        scanf("%d", &n);

        if (n == 1)
            Criar(&inteiros); // Cria a lista

        else if (n == 2)
            Apagar(&inteiros); // Apaga a lista

        else if (n == 3)
            Imprimi(inteiros); // Imprimi toda a lista

        else if (n == 4)
            Insere_final(&inteiros); // Insere no final da lista

        else if (n == 5)
            Insere_inicio(&inteiros); // Insere no início da lista

        else if (n == 6)
            Insere_posicao(&inteiros); // Insere na posição desejada

        else if (n == 7)
            Remove_inicio(&inteiros); // Remove do início da lista

        else if (n == 8)
            Remove_final(&inteiros); // Remove do final da lista

        else if (n == 9)
            Remove_pares(&inteiros); // Remove todos os elementos pares

        else if (n == 10)
        {
            if (inteiros != NULL) // Se a lista não estiver sido apagada, não finalizar o programa
            printf("A lista nao foi apagada!!\n");
            else
            {
                break;
            }
        }

        else // Usuário digitou algo que não esteja entre 1 <= n <= 10
        {
            printf("Digite um numero valido\n");
        }
        printf("\n");
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
    int i = 1, info;

    if (get_elem_pos(lst, i, &info) == 0)
    {
        printf("Lista invalida ou vazia\n");
        return;
    }

    printf("A lista possui os numeros: \n");
    while (get_elem_pos(lst, i, &info) == 1)
    {
        printf("%d\n", info);
        i++;
    }
}

void Insere_final(Lista *lst)
{
    int info;
    printf("Digite o elemento a ser adicionado: ");
    scanf("%d", &info);

    if (insere_final(lst, info) == 1)
        printf("Elemento %d adicionado na lista com sucesso\n", info);
    else
        printf("Elemento %d nao adicionado na lista com sucesso\n", info);
}

void Insere_inicio(Lista *lst)
{
    int info;
    printf("Digite o elemento a ser adicionado: ");
    scanf("%d", &info);

    if (insere_inicio(lst, info) == 1)
        printf("Elemento %d adicionado na lista com sucesso\n", info);
    else
        printf("Elemento %d nao adicionado na lista com sucesso\n", info);
}

void Insere_posicao(Lista *lst)
{
    int pos, info;

    printf("Digite o elemento a ser adicionado: ");
    scanf("%d", &info);

    printf("Digite a posicao da lista desejada: ");
    scanf("%d", &pos);

    if (insere_pos(lst, info, pos) == 1)
        printf("Elemento %d adicionado na lista com sucesso\n", info);
    else
        printf("Elemento %d nao adicionado na lista com sucesso\n", info);
}

void Remove_inicio(Lista *lst)
{
    int info;

    if (remove_inicio(lst, &info) == 1)
        printf("O numero %d foi removido da lista\n", info);
    else
        printf("Nao foi possivel fazer a remocao\n");
}

void Remove_final(Lista *lst)
{
    int info;

    if (remove_final(lst, &info) == 1)
        printf("O numero %d foi removido da lista\n", info);
    else
        printf("Nao foi possivel fazer a remocao\n");
}

void Remove_pares(Lista *lst)
{
    if (remove_pares(lst) == 1)
        printf("Todos elementos pares removidos\n");
    else
        printf("Nao foi possivel remover os elementos pares\n");
}


