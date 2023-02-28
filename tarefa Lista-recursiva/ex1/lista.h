#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

typedef struct no *Lista;

//Prototipos
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, char elem);
int remove_ord(Lista *lst, char elem);
int get_pos(Lista lst, int pos, char *elem);
int apaga_lista(Lista *lst);


#endif // ponto H INCLUDED