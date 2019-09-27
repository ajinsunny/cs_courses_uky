//http://en.cppreference.com/w/cpp/chrono
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
 *   modified to add run time measurements (chrono);
*/

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>

#define MODULO 10000

using namespace std;

long fibonacci(unsigned long n) {
  if (n < 2) return n;
  return (fibonacci(n-1)%MODULO + fibonacci(n-2)%MODULO)%MODULO;
}

int main(int argc, char *argv[]) {
  // Check command line arguments to tell if timing information should be printed
  char timing_arg[] = "-t";
  bool print_timing = (argc == 2 && strcmp(argv[1], timing_arg) == 0);

  // Read input number
  unsigned long n;
  cin >> n;

  // Run program and deal with timing stuff
  chrono::time_point<chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  cout << "f(" << n << ")%" << MODULO << " = " << fibonacci(n) << endl;
  end = std::chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds = end-start;
  time_t end_time = std::chrono::system_clock::to_time_t(end);

  if( print_timing )
    cout << "elapsed time: " << elapsed_seconds.count() << "s" << endl << endl;
}
