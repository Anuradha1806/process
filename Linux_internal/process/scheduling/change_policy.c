#include<stdio.h>
#include<sched.h>

int main()
{
        int policy;
        printf("My pid is %d\n",getpid());

        // get our scheduling policy 
        policy = sched_getscheduler(0); //return policy of calling process

        switch(policy)
        {
                case SCHED_OTHER:
                        printf("Policy is normal\n");
                        break;

                case SCHED_RR:
                        printf("Policy is round-robin\n");
                        break;
                case SCHED_FIFO:
                        printf("Policy is first-in, first-out.\n");
                        break;
                case -1:
                        perror("sched_getscheduler");
                        break;
                default:
                        fprintf(stderr,"unknown policy\n");
        }

        getc(stdin); //wait

        //set our scheduling policy
        struct sched_param sp={.sched_priority = 1};  // RR policy
        int ret;

        ret = sched_setscheduler(0,SCHED_RR,&sp); //sch policy and parameter of a calling process

        if(ret==-1){
                perror("sched_setscheduler");
                return 1;
        }

        // get our scheduling policy
        policy = sched_getscheduler(0);

        switch(policy)
        {
                case SCHED_OTHER:
                        printf("Policy is normal\n");
                        break;

                case SCHED_RR:
                        printf("Policy is round-robin\n");
                        break;
                case SCHED_FIFO:
                        printf("Policy is first-in, first-out.\n");
                        break;
                case -1:
                        perror("sched_getscheduler");
                        break;
                default:
                        fprintf(stderr,"unknown policy\n");

        }

        getc(stdin);
        while(1);
        return 0;

}
