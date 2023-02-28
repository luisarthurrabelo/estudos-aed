#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no* lista;

lista cria_lista ();

int lista_vazia (lista);

int insere_elem(lista*, int);

int remove_elem (lista*, int);

int get_elem_pos(lista, int, int*);

int esvazia_lista (lista*);

int apaga_lista (lista*);

int remover_maior (lista*, int*);

lista inverter (lista*);

lista intercalar (lista, lista);
#endif // LISTA_H_INCLUDED
