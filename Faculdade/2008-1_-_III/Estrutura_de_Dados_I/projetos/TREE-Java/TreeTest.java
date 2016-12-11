// Fig. 22.16: TreeTest.java
// This program tests the Tree class.
//import com.deitel.jhtp3.ch22.Tree;
package ARVORE;
// Class TreeTest definition
public class TreeTest {
   public static void main( String args[] )
   {
      Tree tree = new Tree();
      int intVal;

      System.out.println( "Inserting the following values: " );

      for ( int i = 1; i <= 10; i++ ) {
         intVal = ( int ) ( Math.random() * 100 );
         System.out.print( intVal + " " );
         tree.insertNode( intVal );
      }

      System.out.println ( "\n\nPreorder traversal" );
      tree.preorderTraversal();

      System.out.println ( "\n\nInorder traversal" );
      tree.inorderTraversal();

      System.out.println ( "\n\nPostorder traversal" );
      tree.postorderTraversal();
      System.out.println();
   }
}

/**************************************************************************
 * (C) Copyright 1999 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
