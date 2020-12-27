#include "threadutils.h"

void BinarySearch(int thread_id, int init, int maxiter){
	ThreadInit(thread_id, init, maxiter);
	/*
	Some initilization if needed.
	*/
	Current->y=0;	//left
	Current->z=100;	//right

	for (Current->i = 0; Current->i < Current->N; ++Current->i){
		sleep(1);
		/*
		Do the computation, then output result.
		Call ThreadExit() if the work is done.
		*/
		int mid=(Current->y+Current->z)/2;
		printf("BinarySearch: %d\n", mid);
		if(mid>Current->x){
			Current->z=mid-1;
		}  
		else if (mid<Current->x){
			Current->y=mid+1;
		}
		else{
			break;
		}
		ThreadYield();
	}
	ThreadExit();
}

void BlackholeNumber(int thread_id, int init, int maxiter){
	ThreadInit(thread_id, init, maxiter);
	/*
	Some initilization if needed.
	*/

	for (Current->i = 0; Current->i < Current->N; ++Current->i){
		sleep(1);
		/*
		Do the computation, then output result.
		Call ThreadExit() if the work is done.
		*/
		int curnum=Current->x;	//nowdigit
		int digit[3];			//single digit
		for (int i=0; i<3; i++){
			digit[i]=curnum%10;
			curnum/=10;
		}
		int temp;
		if (digit[0]>digit[1]){
			temp=digit[0];
			digit[0]=digit[1];
			digit[1]=temp;
		}
		if (digit[1]>digit[2]){
			temp=digit[1];
			digit[1]=digit[2];
			digit[2]=temp;
		}
		if (digit[0]>digit[1]){
			temp=digit[0];
			digit[0]=digit[1];
			digit[1]=temp;
		}
		Current->y=(digit[2]*10+digit[1])*10+digit[0];
		Current->z=(digit[0]*10+digit[1])*10+digit[2];
		Current->x=(Current->y)-(Current->z);

		printf("BlackholeNumber: %d\n", Current->x);
		if(Current->x == 495){
			break;
		}
		ThreadYield();
	}
	ThreadExit();
}

void FibonacciSequence(int thread_id, int init, int maxiter){
	ThreadInit(thread_id, init, maxiter);
	/*
	Some initilization if needed.
	*/
	Current->y=1;
	Current->z=0;

	for (Current->i = 0; Current->i < Current->N; ++Current->i){
		sleep(1);
		/*
		Do the computation, then output result.
		*/  
		Current->x=Current->y+Current->z;
		Current->z=Current->y;
		Current->y=Current->x;
		printf("FibonacciSequence: %d\n", Current->x);
		ThreadYield();
	}
	ThreadExit();
}
