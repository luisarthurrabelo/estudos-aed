#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct TADlista * Lista;

Lista Cria_lista ();

int lista_vazia (Lista);

int lista_cheia (Lista);

int tamanho (Lista);

int insere_ord (Lista, char);

int remove_ord (Lista, char);

int remover_pos (Lista, int);

int remover_vogais (Lista elem);

Lista intercala_listas(Lista, Lista);

int get_elem_pos (Lista, int, char *);

int esvazia_lista(Lista);

int apaga_lista(Lista *);

#endif // LISTA_H_INCLUDED
