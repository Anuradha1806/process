#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void ouch(int sig){
	printf("OUCH! - I Got a signal %d\n",sig);
	(void) signal(sig,SIG_DFL);
}

int main(){
	(void) signal(SIGINT,ouch);
	printf("PID  of the process =%d\n",getpid());
	while(1){
		printf("hello world\n");
		sleep(1);
	}
}
