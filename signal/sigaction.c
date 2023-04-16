#include <signal.h>
#include <stdio.h>

void sighand(int sigNo)
{
	printf("Signal handler function displaying sigNo : %d\n" , sigNo);

}
main()
{
	struct sigaction act;
	act.sa_handler = sighand;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT , &act , 0);

	while(1)
	{
		printf("Hello World\n");
		sleep(1);
	
	}

}
