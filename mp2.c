#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid, pid_padre;
  
  pid_t DAVID;


  DAVID = fork();
	
  if (DAVID == 0 )  
	  {   
	    pid_t ESPERA;
	    ESPERA=fork();
		    if(ESPERA==0)
		    {
			    pid = getpid();
			    pid_padre = getppid();   
			    printf("Soy el proceso P3 \n");
			    printf("Mi pid es: %d \n",pid);
			    printf("El pid de P2 es: %d \n",pid_padre);	
		    }
		    else
		    {
		    pid_padre = wait(NULL); 
		    pid = getpid();
		    pid_padre = getppid();   
		    printf("Soy el proceso P2 \n");
		    printf("Mi pid es: %d \n",pid);
		    printf("El pid de P1 es: %d \n",pid_padre);	
		    }  

		  }
	  else    
	  { 
	   pid_padre = wait(NULL); 
	   pid = getpid();
	   pid_padre = getppid();
	   printf("Soy el proceso P1 \n");  
	   printf("Mi pid es: %d \n",pid); 
	   printf("El pid de P2 es:%d \n",DAVID);
	  }
	  
	   exit(0);
	}
