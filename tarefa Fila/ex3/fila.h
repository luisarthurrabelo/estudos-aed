#ifndef FILHA_H_INCLUDED
#define FILHA_H_INCLUDED

typedef struct fila * Fila;

struct produto{

    int codigo;
    char descricao[20];
    float preco;
};
typedef struct produto Produto;

Fila cria_Fila();
int insere_Fim(Fila f, Produto elem);
int remove_ini(Fila f, Produto *elem);
int fila_cheia(Fila);
int fila_vazia(Fila li);
int tamanho_Fila(Fila f);
int apaga_Fila(Fila *);
int esvazia_Fila(Fila);

#endif // FILA_H_INCLUDED

