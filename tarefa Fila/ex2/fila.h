#ifndef FILHA_H_INCLUDED
#define FILHA_H_INCLUDED

typedef struct fila * Fila;

Fila cria_Fila();
int insere_Fim(Fila f, char *elem);
int remove_ini(Fila f, char *elem);
int fila_cheia(Fila);
int fila_vazia(Fila li);
int tamanho_Fila(Fila f);
int apaga_Fila(Fila *);
int esvazia_Fila(Fila);

#endif // FILA_H_INCLUDED

