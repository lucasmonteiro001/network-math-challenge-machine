#ifndef MENSAGEM_H_
#define MENSAGEM_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operacao.h"

#define TAMANHO_MSG_DESAFIO 6 // bytes
#define TAMANHO_MSG_RESPOSTA 3 // bytes

#define TAMANHO_OPERADOR 1
#define TAMANHO_NUMERO 2

#define COD_DESAFIO 0x01
#define COD_RESPOSTA 0x02

typedef enum { false = 0, true = !false } bool;

typedef struct Desafio {
	short int resultado; // resultado da eq gerada pela mensagem
	void *msg;
} Desafio;

typedef struct Resposta {
	short int resposta;
} Resposta;

typedef struct MsgResposta {
	void *msg;
} MsgResposta;

Desafio geraDesafio();

Resposta geraResposta(short int resultado);

MsgResposta geraMsgDeResposta(Resposta);

void imprimeDesafio(Desafio m);

void imprimeResposta(Resposta r);

bool confereResposta(Desafio d, Resposta r);

Equacao carregaEquacaoDeDesafio(Desafio d);

Resposta carregaRespostaDeMsg(MsgResposta m);

#endif /* MENSAGEM_H_ */
