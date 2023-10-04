#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
	  pid_t pid, pid_1,pid_2,pid_3;
	  
	 

	 pid_1 = fork();
 
	  if (pid_1 == 0)  
	  {   
	    	    pid_2 = fork();
	    	    if(pid_2 == 0)	
	    	    {
	    	    	pid_3 = fork();
	    	    		if(pid_3 == 0)
	    	    		{
	    	    			printf("Soy el proceso 4 \n");
	    	    			printf("%d \n",getpid());
					printf("%d \n",getppid());
					printf("La suma es:%d \n",getpid() + getppid());
	    	    		
	    	    		}
	    	    		else
	    	    		{	
	    	    			pid=wait(NULL);
	    	    			printf("Soy el proceso 3 \n");
	    	    			printf("%d \n",getpid());
					printf("%d \n",getppid());
					printf("La suma es:%d \n",getpid() + getppid());
	    	    		
	    	    		}
	    	    
	    	    	
	    	    }
	    	    else
	    	    {
	    	    	pid = wait(NULL);
	    	    	printf("Soy el proceso 2 \n");
	    	    	printf("%d \n",getpid());
			printf("%d \n",getppid());
			printf("La suma es:%d \n",getpid() + getppid());
	    	    
	    	    }
		 
	  }

	  else   
	  { 
	 
	   	pid = wait(NULL);
	   	printf("Soy el proceso 1 \n");
	   	printf("%d \n",getpid());
		printf("%d \n",getppid());
		printf("La suma es:%d \n",getpid() + getppid());
	   
	   
	   
	  }
	  exit(0);
  }
