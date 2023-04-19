/*
 
#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("one\n");
	fork();
	printf("two\n");
	return 0;
}
*/


/*
#include<stdio.h>
#include<unistd.h>
int main()
{
        printf("one\n");
        fork();
        printf("two\n");
        while(1);
        return 0;
}
*/


/*
#include<stdio.h>
#include<unistd.h>
int main()
{
        printf("one\n");
        fork();
	fork();
	fork();
        printf("two\n");
        while(1);
        return 0;
}
*/


/*
#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	pid=fork();
	if(pid)
	{
		printf("1\n");
		printf("2\n");
	}
	else
	{
		printf("3\n");
		printf("4\n");
	}
	while(1);
	return 0;

}
*/

/*
#include<stdio.h>
#include<unistd.h>
int main()
{
        int pid;
	printf("current process pid=%d\n",getpid());
        pid=fork();
	if(pid==0)
        {
                printf("new child process =%d\n",getpid());
                printf("new child parent process ppid=%d\n",getppid());
        }
        else
        {
                printf("parent process pid =%d\n",getpid());
                printf("parents parent process ppid=%d\n",getppid());
        }
        while(1);
        return 0;

}
*/

/*
#include<stdio.h>
#include<unistd.h>
int main()
{
        int pid;
        printf("current process pid=%d\n",getpid());
        pid=fork();
        if(pid==0)
        {
		
                printf("new child process =%d\n",getpid());
                printf("new child parent process ppid=%d\n",getppid());
        }
        else
        {
		sleep(3);
                printf("parent process pid =%d\n",getpid());
                printf("parents parent process ppid=%d\n",getppid());
        }
        while(1);
        return 0;

}
*/

/*
#include<stdio.h>
#include<unistd.h>
int main()
{
        int pid;
        printf("current process pid=%d\n",getpid());
        pid=fork();
        if(pid==0)
        {
		sleep(5);
                printf("new child process =%d\n",getpid());
                printf("new child parent process ppid=%d\n",getppid());
        }
        else
        {
                printf("parent process pid =%d\n",getpid());
                printf("parents parent process ppid=%d\n",getppid());
        }
        while(1);
        return 0;

}
*/

/*
//atexit
#include<stdio.h>
#include<stdlib.h>
void callback1(void)
{
	printf("callback1 func called\n");
}

void callback2(void)
{
        printf("callback2 func called\n");
}

void callback3(void)
{
        printf("callback3 func called\n");
}


int main()
{
	printf("registering callback1\n");
	atexit(callback1);
	printf("registering callback2\n");
        atexit(callback2);
	printf("registering callback3\n");
        atexit(callback3);
	printf("main()....exiting now\n");
exit(0);

}
*/
/*
//vfork
#include<stdio.h>
#include<unistd.h>
int main()
{
        int pid;
        printf("current process pid=%d\n",getpid());
        pid=vfork();
        if(pid==0)
        {
                printf("new child process =%d\n",getpid());
                printf("new child parent process ppid=%d\n",getppid());
        }
        else
        {
                printf("parent process pid =%d\n",getpid());
                printf("parents parent process ppid=%d\n",getppid());
        }
        while(1);
        return 0;

}

*/


//here segmentation fault is generated
//vfork
/*
#include<stdio.h>
#include<unistd.h>
int main()
{
        int pid;
        printf("current process pid=%d\n",getpid());
        pid=vfork();
        if(pid==0)
        {
                printf("new child process =%d\n",getpid());
                printf("new child parent process ppid=%d\n",getppid());
        }
        else
        {
                printf("parent process pid =%d\n",getpid());
                printf("parents parent process ppid=%d\n",getppid());
	}
	//while(1);
	return 0;
}
*/     
//vfork
//segmentation fault is not generated
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        int pid;
        printf("current process pid=%d\n",getpid());
        pid=vfork();
        if(pid==0)
        {
                printf("new child process =%d\n",getpid());
                printf("new child parent process ppid=%d\n",getppid());
        }
        else
        {
                printf("parent process pid =%d\n",getpid());
                printf("parents parent process ppid=%d\n",getppid());
        }
        //while(1);
	exit(0);
        return 0;
}

