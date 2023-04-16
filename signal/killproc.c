#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

main(){
	pid_t pid;
	int sig_no;
	printf("enter the pid\n");
	scanf("%d",&pid);
	printf("enter the signal that need to be sent\n");
	scanf("%d",&sig_no);
	kill(pid,sig_no);
	perror("sig_rest");
}
