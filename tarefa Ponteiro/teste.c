
#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
    int codigo;
    char nome[50];
    double media;
    int numeroDeFaltas;
};
typedef struct Aluno aluno;

void locacaoDinamica(struct Aluno *alu[]);
void preencheVetor ( int n, struct Aluno alu[]);
void selectionSort( int n, struct Aluno alu[]);
void imprimeVetor( int n, struct Aluno alu[]);

int main()
{
    int n;
    printf("Digite a quantidade de alunos");
    scanf("%d", &n);


    struct Aluno *alu[n];

    locacaoDinamica(alu);
    preencheVetor ( n, alu);
    selectionSort( n, alu);
    imprimeVetor(n, alu);


    return 0;
}

void locacaoDinamica(struct Aluno *alu[]) {
    
   alu = (aluno*)malloc(sizeof(aluno));
}

void preencheVetor ( int n, struct Aluno alu[])
{
    for(int i=0; i<n; i++)
    {
        printf("Digite o codigo do aluno %d:", i+1);
        scanf("%d", &alu[i].codigo);
        printf("Digite o nome do aluno %d:", i+1);
        scanf("%s", alu[i].nome);
        printf("Digite a media do aluno %d:", i+1);
        scanf("%lf", &alu[i].media);
        printf("Digite o numero de faltas do aluno %d:", i+1);
        scanf("%d", &alu[i].numeroDeFaltas);
    }
}

void selectionSort( int n, struct Aluno alu[]) {

     struct Aluno aux;
     int j, i;

     for (i = 1 ; i< n; i++)
     {
         aux = alu[i];
         for(j=i; (j>0)&& (aux.codigo<alu[j-1].codigo); j--)
         {
             alu[j] = alu[j-1];

         }
         alu[j]=aux;
     }
}

void imprimeVetor( int n, struct Aluno alu[]) {

    printf("\n");
    printf("----Dados dos alunos----\n");

    for(int i=0; i<n; i++)
    {
        printf("Codigo do aluno %d: %d\n", i+1,alu[i].codigo);
        printf("Nome do aluno %d: %s\n", i+1,alu[i].nome );
        printf("Media do aluno %d: %lf\n", i+1,alu[i].media );
        printf("Numero de faltas do aluno %d: &d\n", i+1, alu[i].numeroDeFaltas);
    }
}