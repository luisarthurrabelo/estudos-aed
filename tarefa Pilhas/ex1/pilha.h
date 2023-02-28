#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha * Pilha;

Pilha cria_pilha();
int push(Pilha, char *elem);
int pop(Pilha, char *elem);
int pilha_cheia(Pilha);
int pilha_vazia(Pilha li);
int tamanho_Pilha(Pilha p);
int apaga_Pilha(Pilha *);
int esvazia_Pilha(Pilha);
int get_Topo(Pilha, char *elem);

#endif // PILHA_H_INCLUDED

