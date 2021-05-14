#include<unistd.h>
#include<stdio.h>
#include<sys/syscall.h>
#include<stdlib.h>

struct Process{
	int pid;
	char command[16];
};

int main(void){
	int result;
	syscall(548, &result);
	printf("Process number is %d.\n", result);
	struct Process* process = (struct Process*)malloc(result*sizeof(struct Process)); 
	syscall(549, process);
	printf("PID\t\tCOMMAND\n");
	for(int i = 0; i < result; i++){
		printf("%d\t\t%s\n",(process+i)->pid, (process+i)->command);
	}
	free(process);
	return 0;
}


