#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//typedef struct no *Lista;
//typedef struct node *No;
//typedef struct dataNode *DataNode;

struct aluno{

    unsigned int matricula;
    char nome[20];
    float media;
    int faltas;
};

typedef struct no *Lista;
typedef struct aluno Alunos;

//Prototipos
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, struct aluno al);
int remove_ord(Lista *lst, unsigned int mat);
int get_pos(Lista lst, int pos, unsigned int *mat, char *nome, float *media, int *faltas);
int apaga_lista(Lista *lst);


#endif