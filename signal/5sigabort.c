#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<stdlib.h>
void sighand(int sid_num){
	printf("abort signal rec'd\n");
	printf("we can use this to perform clean up op's\n");
}
main(){
	signal(SIGABRT,sighand);
	
	printf("some thing has gone worng\n");
	abort();

	printf("can you see this\n");
	printf("can you see this\n");
	printf("can you see this\n");
}
