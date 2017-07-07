#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void){
	int pid;
	pid = fork();
	// pid : child process id
	if(pid != 0) 	/* ("Parent\n") */
		return 0;
	// pid != 0 means I am parent.
	// Parent process will be terminated
	// and child process will be run(Daemon)
	else{
		while(1){
		FILE *fp;
		fp = fopen("list.txt","a+");
		// File I/O
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		// time_t -> string 
		fprintf(fp,"now : %d %d-%d %02d:%02d:%02d\n",\
				tm.tm_year + 1900,\
			       	tm.tm_mon + 1,\
			       	tm.tm_mday,\
				tm.tm_hour,\
			       	tm.tm_min,\
			       	tm.tm_sec);
		// print current time to list.txt
		sleep(1);
		fclose(fp);
		// delay program and close file.
		}
	}
	return 0;
}

