#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h>

void main(){

     int fd[2]; 
	time_t now;
        struct tm *tm_info;
        char buffer[80];

        time(&now);
        tm_info = localtime(&now);
        strftime(buffer, 80, "Fecha/hora: %a %b %d %H:%M:%S %Y\n", tm_info);
        
        
     pid_t pid;
    
    
     pipe(fd); 
      
     
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]);
                printf("El hijo con pid %d n",getpid());
                read(fd[0], buffer, 10);
                printf("\t Mensaje leido del pipe: %s \n", buffer);
     
     }
     
     else
     
     {
                close(fd[0]); 
                printf("El padre escribe en el PIPE...\n");
                write(fd[1], buffer, strlen(buffer)); 
                 
                wait(NULL);    
     }
     
        
}
