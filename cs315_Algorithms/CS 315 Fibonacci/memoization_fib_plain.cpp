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
 *   no chrono used in this version
*/

#include <iostream>
#include <ctime>
#include <cstring>

#define MODULO 10000

using namespace std;

unsigned long fib_arr[100000];

long fibonacci(unsigned long n) {
  if (n < 2) return n;
  if (fib_arr[n] > 0) return fib_arr[n];
  fib_arr[n] = (fibonacci(n-1)%MODULO + fibonacci(n-2)%MODULO)%MODULO;
  return fib_arr[n];
}

int main() {

  // Read input number
  unsigned long n;
  cin >> n;

  cout << "f(" << n << ")%" << MODULO << " = " << fibonacci(n) << endl;

}
