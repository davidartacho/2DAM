package Ejercicios;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Ej1 
{
	public static void main(String args []) throws UnknownHostException, IOException
	{
		Scanner entrada = new Scanner(System.in);
		
		int numero = 0;
		int resultadoFact = 0;
		String Host = "192.168.204.46";
		int Puerto = 6666;//puerto remoto
		
		System.out.println("Introduce el numero que quieras");
		numero = entrada.nextInt();
		
		System.out.println("Enviando numero");
		
		Socket Cliente = new Socket(Host, Puerto);

		// Creación flujo de salida hacia el servidor
		DataOutputStream flujoSalida = new DataOutputStream(Cliente.getOutputStream());

		
		flujoSalida.writeInt(numero);
		
		DataInputStream flujoEntrada = new DataInputStream(Cliente.getInputStream());
		resultadoFact = flujoEntrada.readInt();
		
		System.out.println("El numerin"+ resultadoFact);
		

		// CERRAR STREAMS Y SOCKETS	
		
		flujoSalida.close();	
		Cliente.close();	
		flujoEntrada.close();

		
		
		
		
	}
}
