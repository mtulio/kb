// This file defines the remote server object that implements
// the iCalendar interface.

import java.util.Date;
import java.rmi.*;
import java.rmi.registry.*;
import java.rmi.server.*;


//-----------------------------------------
// Classe: CalendarImpl
//         Realiza a interface iCalendar 
//-----------------------------------------
public class CalendarImpl extends UnicastRemoteObject
						  implements iCalendar     // a iCalendar disponibiliza os métodos
{

//----- class constructor
  public CalendarImpl ()
  throws RemoteException //obrigatório
	{
	  System.out.println ("Server object was created.") ;
	}


//----- getDate implementation
  public Date getDate ()    // metodo que vai ser dicponibilizado pelo RMI -> nova data
  throws RemoteException
	{
	  System.out.println ("Calendar server accessed.") ;
	  return new Date () ;
	}


//----- main class code
  public static void main (String args [])
	{
	  CalendarImpl cal ;
	  
	  try
	{
	  LocateRegistry.createRegistry (1299) ; // 1299 - porta onde o servidor vai estar escutando as requisições de métodos
											 // avisa ao servidor de RMI onde (qual porta) vai estar ounvindo
	  cal = new CalendarImpl () ;
	  Naming.bind ("rmi:///CalendarImpl", cal) ; // servidor de nomes RMI (///significa= // local host)
												 // referência à instância call
	  System.out.println  ("Server object is ready for RMIs") ;
	}

	  catch (Exception e)
	{
	  e.printStackTrace () ;
	}
	}
}