#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void check_pending_sigs(sigset_t s){
	int i,res;
	//sigset_t s;
	//sigprocmask(SIG_BLOCK,NULL,&s);
	for(i=1;i<5;i++){
	
		res= sigismember(&s,i);
		if(res)
			printf("signal %d is blocked \n",i);
		else
			printf("signal %d is not blocked \n",i);
	}
}

void sighand(int no){
	printf("I am in sighand\n");
}

main()
{

	sigset_t s_set,s;
	signal(1,sighand);
        sigemptyset(&s_set);
        sigaddset(&s_set,2);
        
        sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);//set of sig's pointed by s_set var are blocked for current process

	printf("PID of the process %d\n",getpid());
	printf("send me a signal and see the effect now \n");
	getchar();
	getchar();
	sigpending(&s);


        check_pending_sigs(s);
	getchar();

        sigprocmask(SIG_UNBLOCK,&s_set,NULL);
      //  check_pending_sigs();
        printf("now signal are unblocked \n");
	while(1);


}
