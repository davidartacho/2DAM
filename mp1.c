#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid,espera;
  
  pid_t DAVID;


  DAVID = fork();

  if (DAVID == -1 ) 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (DAVID == 0 )  
  {   
    
      
    printf("Soy el alumno David \n");	  

  }
  else    
  { 
   espera = wait(NULL); 
   pid = getpid();
  

   printf("Soy el padre y mi pid es: %d \n",pid); 
   printf("Soy el padre y el pid de mi hijo es: %d \n",DAVID); 
   
   
  }
  
   exit(0);
}
