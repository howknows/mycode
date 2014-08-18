#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#define MAX 1000
#define PORT 6767
#define MAXLINK 10

int main(int argc, char const *argv[])
{
	int listenfd,connfd,lenn,clenn;
	struct sockaddr_in serveraddr,clientaddr;//ipv4
	char buf[MAX];
	if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		printf("Creat socket error!:%s\n",strerror(errno) );
		exit(0);
	}
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_addr.s_addr=htonl(inet_addr("0.0.0.0"));
	serveraddr.sin_port=htons(PORT);
	if(bind(listenfd,(struct serveraddr*) &serveraddr,sizeof(serveraddr)) == -1){
		printf("Bind Error: %s\n",strerror(errno) );
		exit(0);
	}
	if(listen(listenfd,MAXLINK) == -1){
		printf("Listen error:%s\n",strerror(errno) );
		exit(0);
	}
	clenn=sizeof(clientaddr);
	printf("%s\n","Waiting for the clients!" );
	while(1){
		if((connfd=accept(listenfd,(struct clientaddr*)&clientaddr,&clenn)) ==-1){
			printf("Accept error%s\n",strerror(errno) );
			continue;
		}
	
		lenn=recv(connfd,buf,MAX,0);
		buf[lenn]='\0';
		printf("The client address:%s port: %d.Message from client:%s\n",inet_ntoa(clientaddr.sin_addr),htons(clientaddr.sin_port),buf );
		
		close(connfd);


	}
	close(listenfd);
	return 0;
}
