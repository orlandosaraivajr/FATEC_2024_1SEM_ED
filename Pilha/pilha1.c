/*
 * Exemplo do uso de pilha com uso de vetor.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 */
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 6


struct Pilha {
    int     data[STACK_MAX];
    int     size;
};

void inicializar(Pilha *S) {
    S->size = 0;
}

void push(Pilha *S, int d) {
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
    else
        fprintf(stderr, "Erro: pilha cheia\n");
}

int pop(Pilha *S) {
    int retorno;
    if (S->size == 0) {
        fprintf(stderr, "Erro: pilha vazia\n");
        exit(-1);
    } else {
        S->size--;
        retorno = S->data[S->size];
        S->data[S->size] = 0;
        return(retorno);
    }
}

void imprime_pilha(Pilha *S) {
    int x;
	for (x = S->size; x > 0 ; x--)
		printf("%d ",S->data[x-1]);
	printf("\n");
}

int main() {
    Pilha minhaPilha;
    int valor;

    inicializar(&minhaPilha);

    push(&minhaPilha, 3);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 5);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 1);
    imprime_pilha(&minhaPilha);

    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);

}
