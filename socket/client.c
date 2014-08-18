#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#define MAX 1000

int main(int argc, char const *argv[])
{
	int sockfd,lenn;
	char sendline[MAX];
	struct sockaddr_in clientaddr;

	if(argc!=2){
		printf("%s\n","Use: ./client <Ip address>" );
		exit(0);
	}

	if((sockfd=socket(AF_INET,SOCK_STREAM,0)) == -1){
		printf("Creat socket error: %s\n",strerror(errno) );
		exit(0);
	}
	memset(&clientaddr,0,sizeof(clientaddr));
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port = htons(6767);

	if((inet_pton(AF_INET,argv[1],&clientaddr.sin_addr)) <= 0){
		printf("Ip transforn error\n" );
		exit(0);
	}
	
	if(connect(sockfd,(struct clientaddr*)&clientaddr,sizeof(clientaddr))<0){
		printf("Connect error:%s\n",strerror(errno) );
		exit(0);
	}
	printf("%s\n","Please input" );
	
	fgets(sendline,MAX,stdin);
	if(send(sockfd,sendline,strlen(sendline),0) < 0){
		printf("Send msg error :%s\n",strerror(errno) );
		exit(0);}
	close(sockfd);
	return 0;
}