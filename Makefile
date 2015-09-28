######################################################################
# Arquivo criado por Bruno Peres e adaptado para a disciplina de 
# Redes 2015/2 por Lucas Monteiro
######################################################################

# Lista dos objetos (arquivos .c, troca-se a extensao para .o) necessarios para o programa final
OBJS = main.o operacao.o mensagem.o Servidor.o cliente.o

# Nome do executavel que sera gerado
MAIN = tp0

# Especifica o compilador
CC = gcc

# Especifica as operacoes do compilador, habilita aviso sobre erros
CFLAGS = -Wall -pg -g3

# Comando terminal para limpar sem confirmacao
RM = rm -f

# Compilacao do programa e passos das ligacoeses de dependencias
$(MAIN): $(OBJS)
	@echo ""
	@echo " --- COMPILANDO PROGRAMA ---"
	@$(CC) $(CFLAGS) $(OBJS) -lm -o $(MAIN)
	@echo ""

%.o: %.c %.h
	@echo ""
	@echo " --- COMPILANDO OBJETO \"$@\""
	@$(CC) $(CFLAGS) $< -c 

clean:
	$(RM) $(MAIN) *.o
	$(RM) gmon.out
	
run:
	./$(MAIN) 
