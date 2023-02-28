#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//typedef struct no *Lista;
//typedef struct node *No;
//typedef struct dataNode *DataNode;

typedef struct no *Lista;

//Prototipos
Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, char *elem);
int remove_ord(Lista *lst, char *elem);
int get_pos(Lista lst, int pos, char *elem);
int limpa_lista(Lista *lst);
int apaga_lista(Lista *lst);


#endif