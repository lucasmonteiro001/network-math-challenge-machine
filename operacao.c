#include "operacao.h"

short int calcula(Equacao eq) {

	short int val = 0;

	if (eq.op == OPERACOES.ADICAO)
		val = eq.x + eq.y;
	else if (eq.op == OPERACOES.SUBTRACAO)
		val = eq.x - eq.y;
		// faz o tratamento de buffer overflow
		if (val < 0)
			return 0;
	else if (eq.op == OPERACOES.EXPONENCIACAO)
		val = pow(eq.x, eq.y);
		// faz o tratamento de buffer overflow
		if (val < 0)
			return 0;
	else if (eq.op == OPERACOES.MULTIPLICACAO)
		val = eq.x * eq.y;

		return val;
}

short int randNumero(short int min, short int max) {
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);

	short int a = min, b = max;

	short int val = a + (b - a) * (double) rand() / (double) RAND_MAX + 1.0;

	return val;
}

operador randOperador() {
	struct timeval t1;
	gettimeofday(&t1, NULL);
	srand(t1.tv_usec * t1.tv_sec);

	int a = 0, b = 3;

	int val = a + (b - a) * (double) rand() / (double) RAND_MAX + 1.0;

	if (val == 0)
		return OPERACOES.SUBTRACAO;
	else if (val == 1)
		return OPERACOES.ADICAO;
	else if (val == 2)
		return OPERACOES.MULTIPLICACAO;
	else if (val == 3)
		return OPERACOES.EXPONENCIACAO;
	else
		perror("O valor aleatorio nao esta dentro do intervalo permitido");

	return -1;
}

void printOp(operador op) {
	switch (op) {
	case SUB:
		printf("-");
		break;
	case ADD:
		printf("+");
		break;
	case MUL:
		printf("*");
		break;
	case EXP:
		printf("**");
		break;
	default:
		perror("Operador invalido!!!\n");
		break;
	}
}

Equacao geraEquacaoAleatoria() {

	const int MIN_VAL = 0;
	const int MAX_VAL = 100;

	short int x = randNumero(MIN_VAL, MAX_VAL);
	short int y = randNumero(MIN_VAL, MAX_VAL);
	short int op = randOperador();

	Equacao eq = { x, y, op };

	return eq;

}

