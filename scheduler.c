#include "threadutils.h"


/*
0. You should state the signal you received by:
   printf('TSTP signal!\n') or printf('ALRM signal!\n')
1. If you receive SIGALRM, you should reset alarm() by timeslice argument passed in ./main
2. You should longjmp(SCHEDULER,1) once you're done
*/
void sighandler(int signo){
    printf("hand");
    if(signo==SIGALRM){
        sigprocmask(SIG_SETMASK, &base_mask, NULL);
        printf("ALRM signal!\n");
        alarm(timeslice);
    }
    else if(signo==SIGTSTP){
        sigprocmask(SIG_SETMASK, &base_mask, NULL);
        printf("TSTP signal!\n");
    }
    longjmp(SCHEDULER,1);      
}

/*
0. You are stronly adviced to make setjmp(SCHEDULER) = 1 for ThreadYield() case
                                   setjmp(SCHEDULER) = 2 for ThreadExit() case
1. Please point the Current TCB_ptr to correct TCB_NODE
2. Please maintain the circular linked-list here
*/
void scheduler(){
    Current = Head;
    while (1){
        int status=setjmp(SCHEDULER);
        if(status==0){
            longjmp(Current->Environment,1);
        }
        else if(status == 1){
            Current=Current->Next;
        }
        else if(status==2){
            //remove the TCB
            Work=Current;
            Current=Current->Next;
            if (Current==Work){
                Head = NULL;
                free(Work);
                break;
            }
            else{
                Current->Prev=Work->Prev;
                Work->Prev->Next=Current;
                free(Work);
            }
        }
    }
    longjmp(MAIN,1);
}