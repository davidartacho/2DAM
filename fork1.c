#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
//La ejecucion mostrara a el primer hijo siempre luego mostrara al hijo del segundo hijo, despues al segundo hijo y pro ultimo al padre
pid_t pid1, pid2,pid,pid3;

pid1 = fork();
if (pid1==0)
	{
		printf("soy el Hijo 1 \n");
		if(getpid()%2==0)
		{
			printf("%d \n",getpid());
			printf("%d \n",getppid());
		}
		else
		{
			printf("%d \n",getpid());
		}
		
	}
else
{
	pid=wait(NULL);
	pid2 = fork();
	if(pid2==0)
	{
		pid3 = fork();
		if(pid3 == 0)
		{
			printf("Soy el hijo del Hijo 2 \n");
			if(getpid()%2==0)
			{
				printf("%d \n",getpid());
				printf("%d \n",getppid());
			}
			else
			{
				printf("%d \n",getpid());
			}
		}
		else
		{	
			pid=wait(NULL);
			printf("Soy el hijo 2 \n");
			if(getpid()%2==0)
			{
				printf("%d \n",getpid());
				printf("%d \n",getppid());
			}
			else
			{
				printf("%d \n",getpid());
			}
		}
		
	}
	else
	{
		pid=wait(NULL);
		printf("soy el padre");
		
	}
}
exit(0);
}
