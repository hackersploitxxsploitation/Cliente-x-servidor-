#include <winsock.h>
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#define PORTA 5000
#define LEN 500

int  main(){
WSADATA  wsa;
SOCKET s;
  struct sockaddr_in  server,*ptr=&server;
  struct sockaddr_in aceitar,*p=&aceitar;
  server.sin_addr.s_addr=inet_addr("127.0.0.1");
  server.sin_family=AF_INET;
  server.sin_port=htons(PORTA);
if(WSAStartup(MAKEWORD(2,2),&wsa)==0){
    printf(" WSASstatup  iniciada com  sucesso  \n");
}
else{
    printf(" erro  WSASstatup   \n ");
}

s=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(s==INVALID_SOCKET){
    printf("  erro ao  criar o  socket de rede %d",GetLastError());
}
else{
    printf("  socket  criado com  sucesso \n");
}
if(bind(s,ptr,sizeof server)==0){
    printf(" bind  inicializada com sucesso  \n");
}
else{
    printf("  erro no  bind  \n ");
}
int b=listen(s,1);
switch(b){
case 0:puts("  funçao  escutando  \n");
break;
case INVALID_SOCKET:puts("  erro na listen() \n");
break;
}
//accept(s,(struct sockaddr *)&aceitar,sizeof(aceitar))
SOCKET  l =WSAAccept(s,NULL,NULL,NULL,NULL);
 while(1){
    if(l!=INVALID_SOCKET){
            printf("   conexão  aceita  \n  %d");
            break;
        }
else{
    printf("conexao recusada    %d ",GetLastError());

}




 }
 char k[LEN];
 int x= recv(l,k,LEN,0);
if(x==SOCKET_ERROR){
    printf("  erro  na  funçao  recv\n   %d",GetLastError());
}
else{
    puts(k);
    fflush(stdout);
}


     return 0;}


