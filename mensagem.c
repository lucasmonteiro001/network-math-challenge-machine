#include "mensagem.h"

Desafio geraDesafio() {

	char cod = 0x1;

	Equacao eq = geraEquacaoAleatoria();
	int resultado = calcula(eq);

	// TODO PERGUNTAR O QUE EH O CAMPO CODIGO
	void *mes = malloc(TAMANHO_MSG_DESAFIO);

	// seta todos os campos para zero
	memset(mes, '\0', sizeof(mes));

	// copia para a mensagem os valores gerados pela equacao
	memcpy(mes, &cod, sizeof(cod));
	memcpy(mes + 1, &eq.x, sizeof(eq.x));
	memcpy(mes + 3, &eq.y, sizeof(eq.y));
	memcpy(mes + 5, &eq.op, sizeof(eq.op));

	Desafio m = { resultado, mes };

	return m;

}

Resposta geraResposta(short int resultado) {
	Resposta r = {resultado};
	return r;
}

MsgResposta geraMsgDeResposta(Resposta r) {

	char cod = COD_RESPOSTA;

	void *mes = malloc(TAMANHO_MSG_RESPOSTA);

	// seta todos os campos para zero
	memset(mes, '\0', sizeof(mes));

	// copia para a mensagem os valores gerados pela equacao
	memcpy(mes, &cod, sizeof(cod));
	memcpy(mes + 1, &r.resposta, sizeof(r.resposta));

	MsgResposta m = { mes };

	return m;

}

void imprimeDesafio(Desafio d) {

	Equacao eq = carregaEquacaoDeDesafio(d);

	printf("Por favor responda quanto eh %d ", eq.x);
	printOp(eq.op);
	printf(" %d:\n", eq.y);

}

void imprimeResposta(Resposta r) {

	short int resp;

	memcpy(&resp, &r.resposta, TAMANHO_NUMERO);

	printf("%d\n", resp);
}

bool confereResposta(Desafio d, Resposta r) {

	if (d.resultado == r.resposta)
		return true;

	return false;
}

Equacao carregaEquacaoDeDesafio(Desafio d) {

	short int x;
	memcpy(&x, d.msg + 1, TAMANHO_NUMERO);

	short int y;
	memcpy(&y, d.msg + 3, TAMANHO_NUMERO);

	operador op;
	memcpy(&op, d.msg + 5, TAMANHO_OPERADOR);

	Equacao eq = {x, y, op};

	return eq;

}

Resposta carregaRespostaDeMsg(MsgResposta m) {

	short int resp;

	memcpy(&resp, &m.msg + 1, TAMANHO_NUMERO);

	Resposta r = geraResposta(resp);

	return r;

}
