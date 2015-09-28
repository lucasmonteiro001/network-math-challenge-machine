#include "Servidor.h"

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int Servidor(int portno)
{
     int sockfd, newsockfd;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (portno < 2) {
         fprintf(stderr,"ERRO, nenhuma porta provida.\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0){
        error("ERRO em abrir o socket");
     	exit(1);
     }
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
    	 printf("ERROR on binding");
     }
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
     if (newsockfd < 0){
         printf("ERRO em eceitar");
     }
     bzero(buffer,256);
     n = read(newsockfd,buffer,255);
     if (n < 0){
    	 printf("ERRO em ler do Socket");
     }
     printf("Aqui esta a menssagem: %s\n",buffer);
     n = write(newsockfd,"Peguei sua menssagem",18);
     if (n < 0){
    	 printf("ERRO em escrever no socket");
     }
     close(newsockfd);
     close(sockfd);
     return 0;
}
