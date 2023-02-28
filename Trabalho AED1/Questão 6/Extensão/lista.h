#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no * Lista;

Lista Cria_lista ();

int lista_vazia (Lista);

int insere_elem (Lista *, double);

int insere_pos (Lista *, double, int);

int remove_elem (Lista *, double);

int remove_todos (Lista *, double);

int remove_menor (Lista *, double *);

int inverte (Lista, Lista *);

int get_elem_pos (Lista, int, double *);

int apaga_lista (Lista *);

#endif // LISTA_H_INCLUDED
