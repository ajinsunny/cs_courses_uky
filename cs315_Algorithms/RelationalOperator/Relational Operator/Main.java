/* Made for CS315 Spring 2017, by Ethan Toney
 *
 * COMPILE:    javac Main.java
 * RUN-TEST:   test.sh java
 * RUN:        java Main
 */

import java.io.*;

public class Main {

  /**
   * Compares two numbers and prints the approprate response to stdout.
   */
  private static void compare(int n1, int n2) {
    if( n1 < n2 ){
      System.out.println("<");
    }else if( n1 > n2 ){
      System.out.println(">");
    }else{
      System.out.println("=");
    }
  }

  /**
   * This solution will read in n+1 number of lines where n is the number on
   * the first line of code.
   */
  private static void solution1() throws IOException {
    BufferedReader in = new BufferedReader( new InputStreamReader( System.in ));

    int n = Integer.parseInt( in.readLine() );

    for( int i=0 ; i<n ; i++ ){
      String[] parts = in.readLine().split(" ");
      int n1 = Integer.parseInt(parts[0]);
      int n2 = Integer.parseInt(parts[1]);
      compare(n1, n2);
    }

    in.close();
  }

  /**
   * This solution will read in all lines on input regardless of what the
   * number is on the first line of the input.
   */
  private static void solution2() throws IOException {
    BufferedReader in = new BufferedReader( new InputStreamReader( System.in ));

    String line = in.readLine();

    while( (line = in.readLine()) != null ){
      String[] parts = line.split(" ");
      int n1 = Integer.parseInt(parts[0]);
      int n2 = Integer.parseInt(parts[1]);
      compare(n1, n2);
    }

    in.close();
  }

  public static void main(String[] args) throws IOException {
    solution1();
  }

}
