// Sameer Hossain
// ID: 301357905

// Experiment 2

// Implement a loop that accesses a number of different locations in an array 
// over-and-over again, and see how the average access time changes as the 
// array size increases, from a size small enough to fit in L1 cache to a size 
// too large to fit in L2 (or L3) cache.  Try to estimate the sizes of your caches.

#include <iostream>
#include <time.h>
#include <cstdio>

using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
  return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

void cacheEffectLoop(int size) {
  int *arr = new int[size];
  int count = 0;

  clock_t start = clock();
  for (int64_t i = 0; i < 64 * 1024 * 1024; i++) {
    arr[(i * 64) % (size-1)]++;
    count++;
  }
  clock_t end = clock();
  clock_t cpu_time_used = elapsed_time(start, end);

  // average time for an array access with a cache miss
  double avgTime = (double)cpu_time_used / count;
  cout << "Access time of each element: " << avgTime << " ms | ";
  cout << "Total access time: " << cpu_time_used << " ms " << endl;

  delete[] arr;
}

int main() {
  cout << endl << "____________Cache Effect Loop #2____________" << endl << endl;

  for (int sz = 1024; sz <= 64 * 1024 * 1024; sz <<= 1) {
    cout << "Size: " << sz / 1024 << "KB | ";
    cacheEffectLoop(sz);
  }

  cout << endl << "____________      Test End      ____________" << endl;

  return 0;
}