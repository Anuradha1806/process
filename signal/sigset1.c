#include<stdio.h>
#include<signal.h>

void sighand(int no){
	printf("i am in sighandker\n");
}
main(){
	sigset_t s_set;
	signal(1,sighand);
	sigemptyset(&s_set);
	sigaddset(&s_set,1);
	perror("sig1");
	sigaddset(&s_set,4);
	perror("sig4");
	sigprocmask(SIG_BLOCK,&s_set,NULL);
	perror("sigmask");
	printf("pid of process %d\n",getpid());
	printf("send me siganl one and see the effect now\n");
	getchar();
	getchar();
	sigprocmask(SIG_UNBLOCK,&s_set,NULL);
	printf("now the siganl are unblocked\n");
	while(1);
}
	
