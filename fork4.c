#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{

pid_t pid1, pid2,pid,pid3,pid4,pid5;
pid_t acumulado;
acumulado = getpid();
pid1 = fork();
if (pid1==0)
	{
		
		pid3=fork();
		
		if(pid3==0)
		{	
			printf("Soy el proceso 4 \n");
			printf("%d \n",getpid());
			if(getpid()%2==0)
			{
				printf("El numero es: %d \n",acumulado + 10);
			}
			else
			{
				printf("El numero es: %d \n",acumulado - 100);
			}
			
		}	
		else
		{
			pid=wait(NULL);
			printf("Soy el proceso 2 \n");
			printf("%d \n",getpid());
			if(getpid()%2==0)
			{
				printf("El numero es: %d \n",acumulado + 10);
			}
			else
			{
				printf("El numero es: %d \n",acumulado - 100);
			}
			
		}
			
		
		
		
		
	}
else
{	
	
	pid2=fork();
	if(pid2==0)
	{
		pid4=fork();
		if(pid4==0)
		{
			printf("Soy el proceso 5 \n");
			printf("%d \n",getpid());
			if(getpid()%2==0)
			{
				printf("El numero es: %d \n",acumulado + 10);
			}
			else
			{
				printf("El numero es: %d \n",acumulado - 100);
			}	
		}
		else
		{
			pid=wait(NULL);
			printf("Soy el proceso 3 \n");
			printf("%d \n",getpid());
			if(getpid()%2==0)
			{
				printf("El numero es: %d \n",acumulado + 10);
			}
			else
			{
				printf("El numero es: %d \n",acumulado - 100);
			}
		}
	
	}
	else
	{
	pid=wait(NULL);
	pid=wait(NULL);
	printf("Soy el proceso 1 \n");
	printf("%d \n",getpid());
	}
}
exit(0);
}
