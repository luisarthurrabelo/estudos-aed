
#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int codigo;
    char nome[100];
    double media;
    int faltas;
};

struct aluno cadastroAluno(struct aluno *alunos, int n);
int ordenarFunction(int max, struct aluno *alunos);
void mostrarAlunos(struct aluno *alunos, int max);

int main(int argc, char *argv[]){

    int max;

    max = atoi(argv[1]);
    struct aluno *alunos;

    alunos = malloc(max * sizeof(struct aluno));

    if(alunos == NULL){

        printf("\nErro de alocacao de memoria.");
        return 1;
    }

    cadastroAluno(alunos, max);
    ordenarFunction(max, alunos);
    mostrarAlunos(alunos, max);

    free(alunos);
    return 0;
}

struct aluno cadastroAluno(struct aluno *alunos, int n){

    for(int i = 0; i < n; i++){

        printf("Codigo: ");
        scanf("%d", &alunos[i].codigo);

        printf("Nome: ");
        scanf("%s", &alunos[i].nome);

        printf("media: ");
        scanf("%lf", &alunos[i].media);

        printf("Faltas: ");
        scanf("%d", &alunos[i].faltas);

        printf("-------------------------------\n");

        if(alunos[i].codigo < 0 || alunos[i].faltas < 0){
            printf("Apenas valores positivos sao aceitos.\n");
            i--;
        }
    }

    return *alunos;
}

int ordenarFunction(int max, struct aluno *alunos){

    struct aluno aux;
    int i, j;

    for(i = 1; i < max; i++){

        aux = alunos[i];

        for(j = i; (j > 0) && (aux.codigo < alunos[j - 1].codigo); j--)
        {
            alunos[j] = alunos[j - 1];
        }

        alunos[j] = aux;
    }
}

void mostrarAlunos(struct aluno *alunos, int max){

    for (int i = 0; i < max; i++){

        printf("Alunos Cadastrados: \n");
        printf("-------------------------------\n");
        printf("codigo: %d\n", alunos[i].codigo);
        printf("nome: %s\n", alunos[i].nome);
        printf("media: %.2lf\n", alunos[i].media);
        printf("faltas: %d\n", alunos[i].faltas);
    }
}