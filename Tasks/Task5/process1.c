#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#define SHMKEY 772002
#define SHMSIZE 100

int main(){

	int id = shmget(SHMKEY, SHMSIZE, IPC_CREAT | 0666);
	char * dataPtr = (char *) shmat(id , NULL , 0);

	printf("Process 1 Running\n");
	
	strcpy(dataPtr,"This is Process 1");
	
	shmdt (dataPtr);

	while(1);
}
