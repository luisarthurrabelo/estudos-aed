#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

//typedef struct no *Lista;
//typedef struct node *No;
//typedef struct dataNode *DataNode;

typedef struct no *Lista;

//Prototipos
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int get_pos(Lista lst, int pos, int *elem);
int apaga_lista(Lista *lst);


#endif // ponto H INCLUDED