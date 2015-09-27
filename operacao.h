#ifndef OPERACAO_H_
#define OPERACAO_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define SUB 0x0
#define ADD 0x1
#define MUL 0x2
#define EXP 0x3

typedef char operador;

typedef struct Operacoes {
	operador SUBTRACAO;
	operador ADICAO;
	operador MULTIPLICACAO;
	operador EXPONENCIACAO;
} Operacoes;

static Operacoes OPERACOES = {SUB, ADD, MUL, EXP};

typedef struct Equacao {
	short int x;
	short int y;
	operador op;
} Equacao;

short int calcula(Equacao eq);

short int randNumero(short int min, short int max);

operador randOperador();

void printOp(operador op);

Equacao geraEquacaoAleatoria();

#endif /* OPERACAO_H_ */
