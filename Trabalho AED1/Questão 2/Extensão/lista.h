#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct lista * Lista;

Lista cria_lista();
int insere_elem(Lista, char *);
int inserir_string_pos(Lista, char *, int );
int remove_elem(Lista, char *);
int remov_menor(Lista);
int lista_cheia(Lista);
int tamanho(Lista);
int apaga_lista(Lista *);
int esvazia_lista(Lista);
int get_elem(Lista, char *, int );
Lista concatenar_lista(Lista, Lista);

#endif // LISTA_H_INCLUDED
