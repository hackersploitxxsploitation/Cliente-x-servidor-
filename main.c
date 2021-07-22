#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <winsock2.h>
#include <windows.h>

int main()
{  WSADATA p;
int b =WSAStartup(MAKEWORD(2,2),&p);
if(b==0){
    printf("WSAStartup iniciada com sucesso\n");
}
else {
    printf("\nFalha ao iniciar WSAStartup\n");

}
char v[]=" BEM  VINDO AO SCANNER WINDOWS"
         " ESSE PORTA SCANNER ENUMERA SOMENTE UMA PORTA E IP";
printf("%s\n",v);

SOCKET s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
struct sockaddr_in  cliente,*ptr=&cliente;

cliente.sin_family=AF_INET;
cliente.sin_port=htons(5000);
cliente.sin_addr.s_addr=inet_addr("127.0.0.1");


int m=connect(s,ptr,sizeof(cliente));
if(m==0){
        char buff[400],*m=&buff;
        char p[500]="ola  servidor  como vai  tudo   bem \n",*C=&p;
      int n=  send(s,p,sizeof p,0);
        if(n==SOCKET_ERROR){
            printf("  erro na funçai send");
        }
        else{
            printf("pacotes  enviados  com  sucesso  \n  %i",GetLastError());
        }
    printf("A porta se encontra aberta \n");
    if(recv(s,m,sizeof m,0)==SOCKET_ERROR){
        printf("  pacotes nao recebidso  \n %d",GetLastError());


    }
else{
    printf("pacotes recebidos  \n");

    while(2){

        puts(buff);
fflush(stdout);
    }
}

    closesocket(s);
    WSACleanup();
}
else{
    printf("A porta se encontra  fechada");
    closesocket(s);
    WSACleanup();
}
    return 0;
}
