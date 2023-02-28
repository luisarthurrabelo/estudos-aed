#ifndef BEBIDAS_H_INCLUDED
#define BEBIDAS_H_INCLUDED

typedef struct lista *Lista;

struct bebidas{
    char nome[20];
    int volume;
    float preco;
};
typedef struct bebidas Bebidas;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, Bebidas bebida);
int remove_ord(Lista lst, char *elem);
int get_pos(Lista lst, int n, char *elem, int *volu, float *preco);
int apaga_lista(Lista *end_lst);
int limpa_lista(Lista end_lst);

#endif