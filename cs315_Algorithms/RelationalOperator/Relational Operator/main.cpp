/* Made for CS315 Spring 2017, by Ethan Toney
 *
 * COMPILE:    gcc -std=c++11 main.cpp
 * RUN-TEST:   test.sh cpp
 * RUN:        ./a.out
 */

#include <iostream>

using namespace std;

/*
 * Compares two numbers and prints the approprate response to stdout.
 */
void compare(int n1, int n2){
  if( n1 < n2 ){
    cout << "<" << endl;
  }else if( n1 > n2 ){
    cout << ">" << endl;
  }else{
    cout << "=" << endl;
  }
}

/*
 * This solution will read n lines of input where n is the number specified by
 * the first line of input.
 */
void solution1() {
  int n;

  cin >> n;

  for( int i=0 ; i<n ; i++ ){
    int n1, n2;
    cin >> n1 >> n2;
    compare(n1, n2);
  }
}

/*
 * This solution will read all input lines regardless of what the first line of
 * input is.
 */
void solution2() {
  int n1, n2;

  cin >> n1;
  while( cin >> n1 >> n2 ){
    compare(n1, n2);
  }
}

int main() {
  solution1();
  return 0;
}
