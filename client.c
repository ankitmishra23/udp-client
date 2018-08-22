#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
int main()
{
	int client;
	struct sockaddr_in ca;
	char buf[100],buf2[100];
	client=socket(AF_INET,SOCK_DGRAM,0);
	if(client==-1)
	{
		printf("socket not created\n");
		return 0;
	}
	printf("socket created\n");
	ca.sin_family=AF_INET;
	ca.sin_port=htons(6000);
	ca.sin_addr.s_addr=inet_addr("127.0.0.1");
	while(!(strcmp("exit",buf2))==0)
	{
	printf("enter the message\n");	
	gets(buf);
	sendto(client,buf,strlen(buf),0,(struct sockaddr *)&ca,sizeof(ca));
	int len=sizeof(ca);
	int msg=recvfrom(client,buf2,100,0,(struct sockaddr *)&ca,&len);
	buf2[msg]='\0';
	printf("message from server-->%s",buf2);
	
	}
	close(client);
return 0;
}
