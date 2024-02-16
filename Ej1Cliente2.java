package Ejercicios;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class Ej1Cliente2 
{
	public static void main(String [] args) throws UnknownHostException, IOException 
	{
	
		
		String Host = "192.168.204.46";
		int Puerto = 7777;//puerto remoto
		
		
		Socket Cliente = new Socket(Host, Puerto);
		
		// Creación flujo de entrada desde el servidor
		DataInputStream flujoEntrada = new  DataInputStream(Cliente.getInputStream());
		DataOutputStream flujoSalida = new DataOutputStream(Cliente.getOutputStream());
		int numero = flujoEntrada.readInt();
		System.out.println("Recibiendo del SERVIDOR: \n\t" + numero );
		
		int factorial = 1;
		

        // Calcula el factorial usando un bucle for
		System.out.println("Holi");
        for (int i = 1; i < numero; i++) {
            factorial *= i;
        }
        
        
        System.out.println("algo");
        flujoSalida.writeInt(factorial);
        System.out.println("Enviado numero" + factorial);
		
		// CERRAR STREAMS Y SOCKETS	
		flujoEntrada.close();	
		flujoSalida.close();
		
		

	}

	
	
	
	
}