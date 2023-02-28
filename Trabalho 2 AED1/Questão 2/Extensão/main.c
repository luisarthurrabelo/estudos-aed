#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pilha.h"
#define MAX 50

int main(){

    Info a;
    char lixo;
    int verif = 0;
    int h, ativo=0, x=0;
    Pilha p = cria_pilha();
    char operacao[MAX], posf[MAX];


    while(1)
    {
        esvazia_Pilha(&p);
        printf("\nDigite a expressao que quer consultar: ");
        gets(operacao);

        if (strcmp(operacao, "FIM") == 0)
            break;

        while(operacao[x] != '\0')
        {
            if( operacao[x]!='+' && operacao[x]!='-' && operacao[x]!='/' && operacao[x]!='*'
                && operacao[x]!='^' && operacao[x]!='(' && operacao[x]!=')' && operacao[x]!='[' &&
                operacao[x]!=']' && operacao[x]!='{' && operacao[x]!='}' && (operacao[x]<'A' || operacao[x]>'F'))
            {
                printf("Expressao invalida");
                break;
            }

            if(operacao[x] == '(')
            {
                a.ch = operacao[x];
                push(&p, a,1);
                verif = 1;
            }
            else if(operacao[x] == '[')
            {
                if(!pilha_vazia(p))
                {
                    le_topo(p,&a);
                    if(a.ch == '(')
                    {
                        printf("Erro de prioridade de escopo\n");
                        ativo = 1;
                        break;
                    }
                }
                a.ch = operacao[x];
                push(&p, a,1);
                verif = 2;
            }
            else if(operacao[x] == '{')
            {
                if(!pilha_vazia(p))
                {
                    le_topo(p,&a);
                    if(a.ch == '(' || a.ch == '[')
                    {
                        printf("Erro de prioridade de escopo\n");
                        ativo = 1;
                        break;
                    }
                }
                a.ch = operacao[x];
                push(&p, a,1);
                verif = 3;
            }
            else if(operacao[x] == ')')
            {
                if(verif != 1 || pilha_vazia(p))
                {
                    printf("Tentativa de fechar escopo de outro escopo diferente\n");
                    ativo = 1;
                    break;
                }
                else
                {
                    pop(&p, &a);
                    le_topo(p,&a);
                    if (a.ch == '(')
                        verif = 1;
                    else if (a.ch == '[')
                        verif = 2;
                    else if (a.ch == '{')
                        verif = 3;
                    else
                        verif = 0;
                }
            }
            else if(operacao[x] == ']')
            {

                if(verif != 2)
                {
                    printf("Tentativa de fechar escopo de outro escopo diferente\n");
                    ativo = 1;
                    break;
                }
                else
                {
                    pop(&p, &a);
                    le_topo(p,&a);
                    if (a.ch == '(')
                        verif = 1;
                    else if (a.ch == '[')
                        verif = 2;
                    else if (a.ch == '{')
                        verif = 3;
                    else
                        verif = 0;
                }
            }
            else if(operacao[x] == '}')
            {
                if(verif != 3)
                {
                    printf("Tentativa de fechar escopo de outro escopo diferente\n");
                    ativo = 1;
                    break;
                }
                else
                {
                    pop(&p, &a);
                    le_topo(p,&a);
                    if (a.ch == '(')
                        verif = 1;
                    else if (a.ch == '[')
                        verif = 2;
                    else if (a.ch == '{')
                        verif = 3;
                    else
                        verif = 0;
                }
            }

            x++;
        }
        if(!pilha_vazia(p))
        {
            printf("Escopos nao foram fechados corretamente\n");
        }
        if(ativo == 1)
        {

            return 0;
        }

        Pilha aux = cria_pilha();

        int i = 0, j = 0;

        while(operacao[i] != '\0')
        {
            switch (operacao[i])
            {
                case '(': case '[': case '{':
                    a.ch = operacao[i];
                    push(&aux, a, 1);
                    break;

                case ')':
                    while(1)
                    {
                        pop(&aux, &a);
                        if(a.ch == '(')
                            break;
                        posf[j++] = a.ch;
                    }
                    break;

                case ']':
                    while(1)
                    {
                        pop(&aux, &a);
                        if(a.ch == '[')
                            break;
                        posf[j++] = a.ch;
                    }
                    break;

                case '}':
                    while(1)
                    {
                        pop(&aux, &a);
                        if(a.ch == '{')
                            break;
                        posf[j++] = a.ch;
                    }
                    break;

                case '+':
                    if(operacao[i+1] == '\0'){
                        printf("errokk\n");
                        return 0;
                    }
                    while(1)
                    {
                        le_topo(aux,&a);
                        if(a.ch == '(' || a.ch == '[' || a.ch == '{' || pilha_vazia(aux))
                            break;
                        posf[j++] = a.ch;
                        pop(&aux, &a);

                    }
                    a.ch = '+';
                    push(&aux, a, 1);
                    break;

                case '-':
                    if(operacao[i+1] == '\0'){
                        printf("errokk\n");
                        return 0;
                    }
                    while(1)
                    {
                        le_topo(aux,&a);
                        if(a.ch == '(' || a.ch == '[' || a.ch == '{' || pilha_vazia(aux))
                            break;
                        posf[j++] = a.ch;
                        pop(&aux, &a);

                    }
                    a.ch = '-';
                    push(&aux, a, 1);
                    break;

                case '*':
                    if(operacao[i+1] == '\0'){
                            printf("errokk\n");
                            return 0;
                        }
                    while(1)
                    {
                        le_topo(aux,&a);
                        if(a.ch == '(' || a.ch == '[' || a.ch == '{'|| pilha_vazia(aux) || a.ch == '+' || a.ch == '-')
                            break;
                        pop(&aux, &a);
                        posf[j++] = a.ch;
                    }
                    a.ch = '*';
                    push(&aux, a, 1);
                    break;

                case '/':
                    if(operacao[i+1] == '\0'){
                            printf("errokk\n");
                            return 0;
                        }
                    while(1)
                    {
                        le_topo(aux,&a);
                        if(a.ch == '(' || a.ch == '[' || a.ch == '{'|| pilha_vazia(aux) || a.ch == '+' || a.ch == '-')
                            break;
                        pop(&aux, &a);
                        posf[j++] = a.ch;
                    }
                    a.ch = '/';
                    push(&aux, a, 1);
                    break;

                case '^':
                    if(operacao[i+1] == ' '){
                        printf("errokk\n");
                        return 0;
                    }
                    while(1)
                    {
                        le_topo(aux,&a);
                        if(a.ch == '('|| a.ch == '[' || a.ch == '{' || pilha_vazia(aux) || a.ch == '+' || a.ch == '-' || a.ch == '*' || a.ch == '/')
                            break;
                        pop(&aux, &a);
                        posf[j++] = a.ch;
                    }
                    a.ch = '^';
                    push(&aux, a, 1);
                    break;

                default:
                    if(operacao[i] != ' ')
                    {
                        int l = i + 1;

                        while(operacao[l] == ' ')
                            l++;

                        if (operacao[l] == '(' || operacao[l] == '[' || operacao[l] == '{' || (operacao[l] < 'A' && operacao[l] > 'F'))
                        {
                            printf("erro\n");
                            return 3;
                        }

                        if(operacao[i+1] != '+' || operacao[i+1] != '-')
                            posf[j++] = operacao[i];
                    }
            }
            i++;
        }

        while(!pilha_vazia(aux))
        {
            pop(&aux,&a);

            if(a.ch != '(' || a.ch != '[' || a.ch != '{')
            {
                posf[j++] = a.ch;
            }
        }

        posf[j] = '\0';
        printf("operacao pos fixa: %s\n", posf);

        Pilha resultado = cria_pilha();
        x = 0;
        float x2;
        float x1;

        while(posf[x] != '\0')
        {
            if(posf[x] >= 'A' && posf[x] <= 'F')
            {
                printf("Valor do literal %c: ", posf[x]);
                scanf("%f", &a.nro);
                push(&resultado, a, 0);
            }

            if(posf[x]=='+' || posf[x]=='-' || posf[x]=='/' || posf[x]=='*' || posf[x]=='^')
            {
                if(pop(&resultado, &a) == 0)
                {
                    printf("O numero de operandos nao e adequado!");
                    ativo=1;
                    break;
                }

                x2 = a.nro;

                if(pop(&resultado, &a) == 0)
                {
                    printf("O numero de operandos nao adequado!");
                    ativo=1;
                    break;
                }

                x1 = a.nro;

                if(posf[x]=='+')
                    x1=x1+x2;

                if(posf[x]=='-')
                    x1=x1-x2;

                if(posf[x]=='*')
                    x1=x1*x2;

                if(posf[x]=='/')
                    x1=x1/x2;

                if(posf[x]=='^')
                    x1=pow(x1,x2);

                a.nro = x1;
                push(&resultado, a, 0);
            }
            x++;
        }

        pop(&resultado, &a);
        x1 = a.nro;

        if(ativo == 1 || !pilha_vazia(p))
        {
            printf("erro\n");
            return 0;
        }
        else
        {
            printf("O resultado da expressao e: %.2f\n", x1);
        }
    }
    return 0;
}
