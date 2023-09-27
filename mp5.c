
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
//En este programa se escribe AAA luego CCC y luego se ejecuta otro proceso ejecuta BBB y CCC lo que pasa es que el proceso padre crea a un hijo (BBB) y luego crea otro hijo entonces se ejecuta el programa y escribe AAA y CCC porque no espera a los hijos luego se vuelve a ejecutar por parte del hijo y por eso imprime BBB y luego CCC en una ejecucion diferente.
pid_t pid1, pid2,pid;
printf("AAA \n");
pid1 = fork();

if (pid1==0)
	{
	printf("BBB \n");
	}
else
{
	pid=wait(NULL);
	pid2 = fork();
	if(pid2==0)
	{
		
		
	}
	else
	{
	
		printf("CCC \n");
	}
}
exit(0);
}
/*
	ARBOL DE PROCESOS
	
	   1000
	  |----|
	1001	1002
*/

