#include "threadutils.h"

void BinarySearch(int thread_id, int init, int maxiter)
{
    ThreadInit(thread_id, init, maxiter);
    /*
    Some initilization if needed.
    */
    for (Current->i = 0; Current->i < Current->N; ++Current->i)
    {
        sleep(1);
        /*
        Do the computation, then output result.
        Call ThreadExit() if the work is done.
        */  
        ThreadYield();
    }
    ThreadExit()
}

void BlackholeNumber(int thread_id, int init, int maxiter)
{
    ThreadInit(thread_id, init, maxiter);
    /*
    Some initilization if needed.
    */
    for (Current->i = 0; Current->i < Current->N; ++Current->i)
    {
        sleep(1);
        /*
        Do the computation, then output result.
        Call ThreadExit() if the work is done.
        */  
        ThreadYield();
    }
    ThreadExit()
}

void FibonacciSequence(int thread_id, int init, int maxiter)
{
    ThreadInit(thread_id, init, maxiter);
    /*
    Some initilization if needed.
    */
    for (Current->i = 0; Current->i < Current->N; ++Current->i)
    {
        sleep(1);
        /*
        Do the computation, then output result.
        */  
        ThreadYield();
    }
    ThreadExit()
}
