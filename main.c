#include "operacao.h"
#include "mensagem.h"
#include <string.h>

int main() {

	Desafio d = geraDesafio();
	imprimeDesafio(d);

	Resposta r = geraResposta(d.resultado);
	imprimeResposta(r);

//	existe a funcao confereResposta(desafio, resposta)

	MsgResposta m = geraMsgDeResposta(r);

	printf("tamanho msg de resposta: %d\n", sizeof(m));
	printf("tamanha msg de desafio: %d\n", sizeof(d.msg));

	return (EXIT_SUCCESS);
}
