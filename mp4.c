#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
//La salida que genera este codigo es CCC luego AAA y en otra linea BBB,no se podria generar otra salida porque en este caso se ejecuta primero el proceso con un pid el cual sera diferente de cero y lego se ejecutara otro proceso cuyo pid es cero cuando se acabe la ejecucion del primero.
pid_t pid,DAVID;
 printf("CCC \n");
 DAVID = fork();
 if (DAVID==0)
 {
 	
 	printf("BBB\n");
 } 
 else 
 {
 	pid=wait(NULL);
 	printf("AAA \n");
 }
 exit(0);
}

