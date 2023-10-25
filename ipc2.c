#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

     int fd[2]; 
     char buffer[2];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     			
                close(fd[1]); // Cierra el descriptor de escritura
                 int suma = 0;
                 int numero;
            while (buffer[0]!= '+') 
            {
            
        	 read(fd[0],buffer,sizeof(buffer));
                numero = atoi(buffer);
                suma += numero;
                
            }
 
                printf("\t La suma es: %d \n", suma);
     
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                printf("El padre escribe en el PIPE...\n");
                char numeros[] = "251867+";
               
                write(fd[1], numeros, 30);
                 
                wait(NULL);    
     }
     
        
}
