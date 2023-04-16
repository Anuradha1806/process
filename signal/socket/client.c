/*#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>


main(){
	char *serv_ip = "127.0.0.1";
	int sockfd,ret_val;
	struct sockaddr_in servaddr;
	sockfd = socket(AF_INET, SOCK_STREM,0);

	bzero(&servaddr,sizeof(servaadr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port  = htons(8000);
	inet_pton(AF_INET, serv_ip,&servaddr,sin_addr);

	ret_val = connect(sockfd, (struct sockaddr*) &servaddr,sizeof(servaadr));
	if(ret_val<0){
		perror("connect:");
		exit(1);
*/



// CLIENT CODE
#include<stdio.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/types.h>

main()
{
        char *serv_ip ="127.0.0.1";
        int sockfd, ret_val;
        struct sockaddr_in servaddr;
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(8000);
        inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);

        ret_val = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

        if(ret_val<0)
        {
                perror("connect:");
                exit(1);
        }
        printf("Client established connection with server\n");

        close(sockfd);
}
