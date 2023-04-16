/*
//process termination using sleep system call
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int id;
	int cnt=0;
	printf("i am going to create a new process\n");
	id=fork();
	if(id)
	{
		while(cnt<10)
		{
			cnt++;
			printf("i am parent,my child process is %d\n",id);
			sleep(1);
		}
	}

	else
	{
		while(cnt<20)
		{
			cnt++;
			printf("i am child process i got id value as %d\n",id);
			sleep(1);
		}
	}

}
*/


/*
//process termiantion  using wait system call
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int pid,stat;
	pid=fork();
	if(pid==0)
	{
		printf("\n child process\n");
		printf("\n child process pid is %d\n",getpid());
		exit(0);
	}

	pid=wait(&stat);
	printf("%d\n",pid);
	printf("%d\n",WEXITSTATUS(stat));
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t chpid,child1,child2;
	int ii,stat;

	printf("I am a process my process id %d\n",getpid());
	printf("i am creating two child processes & make them to run some code\n");

	child1=fork();

	if(child1==0)
	{
		printf("i am first child ,my pid is %d\n",getpid());
		printf("i am tired ,sleeping for 10 second\n");
		sleep(10);
		exit(0);
	}

	 child2=fork();

        if(child2==0)
        {
                printf("i am second child ,my pid is %d\n",getpid());
                printf("i am tired ,sleeping for 5 second\n");
                sleep(5);
                exit(0);
        }

	printf("i am parent ,my children are working and sleeping,i wait for them\n");
	chpid=wait(&stat);
	if(chpid==child1)
		printf("my first child terminated with status %\n",WEXITSTATUS(stat));
	if(chpid==child2)
		printf("my second child terminated with status %d\n",WEXITSTATUS(stat));

	chpid=wait(&stat);
	if(chpid==child1)
		  printf("my first child terminated with status %\n",WEXITSTATUS(stat));
        if(chpid==child2)
                printf("my second child terminated with status %d\n",WEXITSTATUS(stat));


	printf("both children got terminated ,now i will do the same\n");

}
*/

/*
//exec
//terminal or shell application 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ret;
	printf("i am  going to exec an 'ls' program\n");
	ret=execl("/bin/ls","ls","-l",0);//0 indicate end of string,that is mandatory
	printf("l executed is program %d\n",ret);
	 printf("l executed is program %d\n",ret);
	 printf("l executed is program %d\n",ret);

}
*/
/*
//exec(1)
#include<stdio.h>
#include<stdlib.h>
int main()
{
        int ret;
       printf("i am  going to exec an 'ps' program\n");
        ret=execl("/bin/ps","ps","-elf",0);//0 indicate end of string,that is mandatory

        printf("l executed is program %d\n",ret);
         printf("l executed is program %d\n",ret);
         printf("l executed is program %d\n",ret);

}
*/
/*
//exec(2)
//same as 1)shell appl but using cla
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *args[3];
	printf("i am gpoing to exec an 'ls' program in current process\n");

      	args[0]="ls";
	 args[1]="-l";
	 args[2]=0;

	 execv("/bin/ls",args);
	 printf("i have run an exec program\n");

	
}
*/

/*
//cmd_exec
#include<stdio.h>
int main()
{
	int ret;
	printf("i am going to exec an CLA\n");
	ret=execl("/home/anuradha/process","cmd","linux","kernel","driver","program",0);
	printf("i executed is program %d\n",ret);
}
*/


//27/03/2020
//fork_wait_execute
//shell terminal application

/*
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	int option,stat;
	while(1)
	{
		printf("enter 1 to exec 'ls' program in child process and 0 to exit\n");
		scanf("%d",&option);
		if(!option)
			exit(0);
		printf("\n");
		if(fork()==0)
		{
			execl("/bin/ls","ls",0);
			exit(5);
		}

		pid=wait(&stat);
		printf("%d\n",WEXITSTATUS(stat));
		printf("%d\n",WEXITSTATUS(stat));
		printf("child with pid %d is terminated\n",pid);
	}
}

*/
//it find the path it self
//execlp
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("i am going to exec an ls process in current process\n");
	execlp("ls","ls",0);
	printf("i execed 'ls' process\n");
}*/


//wait(1)
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
        pid_t chpid1,chpid2,child1,child2;
        int ii,stat;

        printf("I am a process my process id %d\n",getpid());
        printf("i am creating two child processes & make them to run some code\n");

        child1=fork();

        if(child1==0)
        {
                printf("i am first child ,my pid is %d\n",getpid());
                printf("i am tired ,sleeping for 10 second\n");
                sleep(10);
                exit(0);
        }

         child2=fork();

        if(child2==0)
        {
                printf("i am second child ,my pid is %d\n",getpid());
                printf("i am tired ,sleeping for 5 second\n");
                sleep(5);
                exit(0);
        }


	printf("i am parent ,my children are working and sleeping,i wait for them\n");
       
       	chpid2=waitpid(child2,&stat,0);
        printf("my second  child terminated with status %d\n",WEXITSTATUS(stat));
	printf("terminated child2 pid from wait=%d\n",chpid2);
        

	chpid1=waitpid(child1,&stat,0);
	printf("my first child terminated with status %d\n",WEXITSTATUS(stat));
	printf("terminated child1 pid from wait=%d\n",chpid1);


       // chpid1=waitpid(child1,&stat1,0);
        //if(chpid==child1)
        //          printf("my first child terminated with status %d\n",WEXITSTATUS(stat));
        //if(chpid==child2)
         //       printf("my second child terminated with status %d\n",WEXITSTATUS(stat));



        printf("both children got terminated ,now i will do the same\n");

}


