#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{

pid_t pid1, pid2,pid,pid3,pid4,pid5,pid_abu,pid_abu2;

pid1 = fork();
if (pid1==0)
	{
		pid_abu = getpid();
		pid_abu2 = getppid();
		pid2=fork();
		
		if(pid2==0)
		{	
			pid4 = fork();
			if(pid4 ==0)
			{
				printf("Soy el proceso 5 \n");
				printf("%d \n",getpid());
				printf("El pid de mi abuelo es: %d \n",pid_abu);
			}
			else
			{
				pid=wait(NULL);
				printf("Soy el proceso 3 \n");
				printf("%d \n",getpid());
				printf("El pid de mi abuelo es: %d \n",pid_abu2);
			}
			
		}
		else
		{
			
			pid3=fork();
			if(pid3 ==0)
			{
				pid5 = fork();
				if(pid5 ==0)
				{
					printf("Soy el proceso 6 \n");
					printf("%d \n",getpid());
					printf("El pid de mi abuelo es: %d \n",pid_abu);
				}
				else
				{
					pid = wait(NULL);
					printf("Soy el proceso 4 \n");
					printf("%d \n",getpid());
					printf("El pid de mi abuelo es: %d \n",pid_abu2);
				}
				
			}
			else
			{	
				
				pid=wait(NULL);
				pid=wait(NULL);
				printf("Soy el proceso 2 \n");
				printf("%d \n",getpid());
			}
		}
		
		
	}
else
{	
	
	
	pid=wait(NULL);
	printf("Soy el proceso 1 \n");
	printf("%d \n",getpid());
}
exit(0);
}
