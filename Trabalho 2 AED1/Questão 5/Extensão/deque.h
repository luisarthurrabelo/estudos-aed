#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

typedef struct deque * Deque;

Deque cria_deque();

int deque_vazio(Deque);

int deque_cheio(Deque);

int insere_inicio(Deque, char *);

int insere_fim(Deque, char *);

int remove_inicio(Deque, char *);

int remove_fim(Deque, char *);

int apaga_deque(Deque *);

int esvazia_deque(Deque);

#endif // LISTA_H_INCLUDED
