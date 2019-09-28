/*
 * Instance: n >=0
 * Question: what is fibonacci(n)?
 * Method: recursive based on the definition:
 *   f(0) = f(1) = 1;
 *   f(n) = f(n-2) + f(n-1)
 * modified with memoization
 * Running time: linear number of recursive calls and '+' operations
 * Synopsis: g++ -std=c++11
 * CS315 Algorithms JWJ CS UK (Spring 2017)
 * Modified:
 *   to  calculate Fibonacci  modulo 10000
 *   to avoid overflow (just in case);
 *   no chrono used in this version
 * memoization explained:
 *   Idea: store computed values of fibonacci(n) in an array,
           use the value from the store when needed and available,
           otherwise, make a recursive call and store the value.
 *   - add an array fib_arr[n] that will store computed fibonacci(n)
 *   - initialize it to -1 (fibonacci(n) != -1)
 *    (initializing to 0 is OK here as well, and would be done by g++)
 *   - initialize fib_arr[0] = 0; fib_arr[1] = 1 (ground values)
 *   - when fibonacci(i) is called check:
 *            if fib_arr[i] = -1 (i.e., unknown)  call fibonacci(i)
 *                      call fibonacci(i)
 *                      return fib_arr[i] = fibonacci(i);
 *            else
 *             if fib_arr[i] > -1 (earlier fib_arr[i] := fibonacci(i))
 *                   return fib_arr[i] (no need to call fibonacci(i))
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
