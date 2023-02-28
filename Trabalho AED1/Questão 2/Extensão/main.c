#include <stdio.h>
#include "lista.h"
#define STR 16

void Criar(Lista *);

void Apagar(Lista *);

void Imprimi(Lista );

void Isr_elem(Lista *);

void Isr_elempos(Lista *);

void remover(Lista *);

void esvazia(Lista *);

void remove_menor(Lista *);

void concatenar(Lista *, Lista *);

int main()
{
    int n;
    Lista li[2];
    int i = 0;
    li[0] = NULL;
    li[1] = NULL;
    while (1)
    {
        printf("Lista %d:\n", i + 1);
        printf("Escolha uma das seguintes opcoes: \n");
        printf("[1] Criar a lista\n");
        printf("[2] Apagar a lista\n");
        printf("[3] Imprimir a lista\n");
        printf("[4] Adicionar elemento na lista\n");
        printf("[5] Adicionar elemento na posicao indicada\n");
        printf("[6] Esvaziar lista\n");
        printf("[7] Remover o elemento\n");
        printf("[8] Remover menor elemento\n");
        printf("[9] Concatenar duas listas\n");
        printf("[10] Tamanho da lista\n");
        printf("[11] Mudar de lista\n");
        printf("[12] Encerrar o programa\n\n");
        printf("Digite a opcao desejada: \n");

        scanf("%d", &n);

        if (n == 1)
            Criar(&li[i]); // Cria a lista

        else if (n == 2)
            Apagar(&li[i]); // Apaga a lista

        else if (n == 3)
            Imprimi(li[i]); // imprimi a lista

        else if (n == 4)
            Isr_elem(&li[i]); // Insere elemento na lista

        else if (n == 5)
            Isr_elempos(&li[i]); // Insere elemento na posicao indicada

        else if (n == 6)
            esvazia(&li[i]);   // esvazia a lista

        else if (n == 7)
            remover(&li[i]);   // remove elemento da lista

        else if (n == 8)
            remove_menor(&li[i]);

        else if (n == 9)
            concatenar(&li[0], &li[1]);
        else if (n == 10)
            printf("tamanho da lista é: %d", tamanho(li[i]));
        else if(n == 11)
        {
            if(i == 0)
                i++;
            else
                i--;
        }

        else if (n == 12)
        {
            if (li[0] != NULL || li[1] != NULL) // Se a lista não estiver sido apagada, não finalizar o programa
                printf("A lista nao foi apagada!!\n");
            else
            {
                break;
            }
        }
        else
            printf("Digite um numero valido!\n");
        printf("\n");
    }
    return 0;
}

void Criar(Lista *li)
{
    if (*li != NULL)
        printf ("Apague a lista primeiro\n");
    else
    {
        *li = cria_lista();
        printf ("Lista criada com sucesso\n");
    }
}
void Apagar(Lista *li)
{
    if (apaga_lista(li) == 1)
        printf("Lista apagada com sucesso\n");
    else
        printf("Lista nao apagada\n");
}

void Imprimi(Lista li)
{
    int i = 1;
    char info[STR];

    if (get_elem(li, info, i) == 0)
    {
        printf("Lista invalida ou vazia\n");
        return;
    }

    printf("A lista possui os nomes: \n");
    while (get_elem(li, info, i) == 1)
    {
        printf("%s\n", info);
        i++;
    }
}

void Isr_elem(Lista *li)
{

    char info[STR];

    getchar();
    scanf("%[^\n]", info);

    if (insere_elem(*li, info) == 1)
        printf("O elemento %s foi adicionado na lista\n", info);
    else
        printf("Nao foi possivel fazer a adicao\n");
}

void Isr_elempos(Lista *li)
{
    char info[STR];
    printf("digite o elemento que quer adicionar na lista\n");
    getchar();
    scanf("%[^\n]", info);
    int z;
    printf("digite a posição que deseja coloca-lo\n");
    scanf("%d", &z);
    if(inserir_string_pos(*li, info, z) == 1)
        printf("Elemento inserido na posição desejada\n");
    else
        printf("Nao foi possivel inserir\n");
}

void esvazia(Lista *li)
{
    if(esvazia_lista(*li) == 1)
        printf("Lista esvaziada\n");
    else
        printf("Lista nao esvaziada");
}

void remover(Lista *li)
{
    char info[STR];
    printf("digite o elemento que quer remover da lista\n");
    getchar();
    scanf("%[^\n]", info);

    if(remove_elem(*li, info)==1)
        printf("elemento removido com sucesso\n");
    else
        printf("não foi possível\n");
}

void remove_menor(Lista *li)
{
    if(remov_menor(*li) == 1)
        printf("menor elemento removido");
    else
        printf("erro");
}

void concatenar(Lista *l1, Lista *l2)
{
    Lista lc = concatenar_lista(*l1, *l2);
    if (lc == NULL)
        printf("Lista concatenada nao criada\n");
    else
    {
        Imprimi(lc);
        apaga_lista(&lc);
    }
}
