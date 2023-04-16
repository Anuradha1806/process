#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>


void sh_for_one(int signum){
	printf("this is handler for signal no one \n");
}


void sh_for_nine(int signum){
	printf("this is handler for signal no %d  \n",signum);
}

int main()
{
	printf("the pid is %d",getpid());
	signal(1,sh_for_one);
	signal(9,sh_for_nine);
	perror("siginstall:");
	getchar();
	getchar();

	while(1){
		printf(" I am Happy now\n");
		sleep(4);
	}
}
