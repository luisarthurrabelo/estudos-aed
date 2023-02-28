#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct no * Lista;
Lista cria_lista();
int lista_vazia(Lista);
int insere_ord(Lista *, float);
int remove_ord(Lista *, float);
int get_pos(Lista, int, float *);
int remover_pos(Lista *, int);
int limpa_lista(Lista *);
int apaga_lista(Lista *);
int lista_tamanho(Lista);
int lista_iguais(Lista *, Lista *);
Lista lista_intercalar(Lista, Lista);

#endif // LISTA_H_INCLUDED
