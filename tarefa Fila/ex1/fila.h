#ifndef FILHA_H_INCLUDED
#define FILHA_H_INCLUDED

typedef struct fila * Fila;

struct matricula{

    long int matricula;
    char nome[20];
    float nota;
    char situacao;
};
typedef struct matricula Matricula;

Fila cria_Fila();
int insere_Fim(Fila f, Matricula elem);
int remove_ini(Fila f, Matricula *elem);
int fila_cheia(Fila);
int fila_vazia(Fila f);
int tamanho_Fila(Fila f);
int apaga_Fila(Fila *);
int esvazia_Fila(Fila);

#endif // FILA_H_INCLUDED

