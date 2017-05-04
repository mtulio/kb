// This file defines the interface declaration
// for a remote object

import java.rmi.*;

public interface iCalendar extends Remote //remote para habilitar o RMI 
{
  java.util.Date getDate() // retorna data
  throws RemoteException ; // todos os m�todos t�m que retornar esta excessao  
}