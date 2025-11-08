#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

#define SHMKEY 772002
#define SHMSIZE 100

int main(){

	int id = shmget(SHMKEY, SHMSIZE, 0 | 0666);
	char * dataPtr = (char *) shmat(id , NULL , SHM_RDONLY);
	
    printf("Process 2 is Running .. trying to get data from process 1 \n");

    printf("%s \n",dataPtr);

	shmdt (dataPtr);

	while(1);
}
