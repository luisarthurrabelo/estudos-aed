#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct no* Pilha;

union info
{
    char ch;
    float nro;
};

typedef union info Info;

Pilha cria_pilha();

int pilha_vazia(Pilha);

int push(Pilha *, Info, int);

int le_topo(Pilha , Info *);

int pop(Pilha *, Info *);

int esvazia_Pilha(Pilha *);

#endif // LISTA_H_INCLUDED
