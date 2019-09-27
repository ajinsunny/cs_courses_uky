/*
 * Instance: n >=0
 * Question: what is fibonacci(n)?
 * Method: recursive based on the definition:
 *   f(0) = f(1) = 1;
 *   f(n) = f(n-2) + f(n-1)
 * Running time: exponential number of recursive calls and '+' operations
 * Synopsis: g++ -std=c++11
 * CS315 Algorithms JWJ CS Ua (Spring 2017)K
 * Modified:
 *   to  calculate Fibonacci  modulo 10000
 *   to avoid overflow (just in case);
*/

#include <iostream>
#include <cstring>
#define MODULO 10000
using namespace std;

long fibonacci(unsigned long n) {
  count++;
  if (n < 2) return n;
  return (fibonacci(n-1)%MODULO + fibonacci(n-2)%MODULO)%MODULO;
}

int main() {
  // Read input number
  unsigned long n;
  cin >> n;

  // Run program 
  cout << "f(" << n << ")%" << MODULO << " = " << fibonacci(n) << endl;
}
