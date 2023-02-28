#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

typedef struct lista *Lista;

//Prototipos
Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, char *elem);
int remove_elem(Lista lst, char *elem);
int get_pos(Lista lst, int n, char *elem);
int apaga_lista(Lista *end_lst);
int limpa_lista(Lista end_lst);

#endif // ponto H INCLUDED