#include<stdio.h>
#include<signal.h>

void sighand(int signum){
	printf("i have to wake up my boss now\n");
	alarm(5);
}

int main(){
	signal(SIGALRM,sighand);
	alarm(5);
	printf("\n HELLO\n");
	while(1);{
		printf("\nhello\n");
	}
}
