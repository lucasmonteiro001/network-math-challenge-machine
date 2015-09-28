#include "cliente.h"

int cliente(/*int argc*/, int portno)
{
    int sockfd,n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (/*argc*/ < 3) {
       printf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    //portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
    	printf("ERRO em abrir o socket");
    }
    server = gethostbyname(/*argv[1]*/);
    if (server == NULL) {
        printf(stderr,"ERRO, nenhum servidor\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
        printf("ERRO em conectar");
    }
    printf("Por favor entre com a messagem: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0){
       printf("ERROR writing to socket");
    }
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0){
        printf("ERRO em ler do socket");
    }
    printf("%s\n",buffer);
    close(sockfd);
    return 0;
}
