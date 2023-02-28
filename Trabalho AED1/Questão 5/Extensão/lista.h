#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no * Lista;

Lista Cria_lista ();

int lista_vazia (Lista);

int insere_final (Lista *, int);

int insere_inicio (Lista *, int);

int insere_pos (Lista *, int, int);

int remove_inicio (Lista *, int *);

int remove_final (Lista *, int *);

int remove_pares (Lista *);

int get_elem_pos (Lista, int, int *);

int apaga_lista (Lista *);

#endif // LISTA_H_INCLUDED
