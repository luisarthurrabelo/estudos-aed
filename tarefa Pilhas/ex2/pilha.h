#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha * Pilha;

struct funcionario{

    char nome[30];
    long int matricula;
    char setor;
    float salario;
};
typedef struct funcionario Funcionario;

Pilha cria_pilha();
int push(Pilha *p, Funcionario bebi);
int pop(Pilha *p, long int *elem);
int pilha_cheia(Pilha);
int pilha_vazia(Pilha li);
int tamanho_Pilha(Pilha p);
int apaga_Pilha(Pilha *);
int esvazia_Pilha(Pilha *);
int get_Topo(Pilha p, Funcionario *elem);

#endif // PILHA_H_INCLUDED

