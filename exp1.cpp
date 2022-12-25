// Sameer Hossain
// ID: 301357905
// Experiment 1

// Implement a program that compares the running time for two loops which access
// very different number of array elements but which should have roughly the
// same number of cache misses. Try to estimate the average time for an array
// access with a cache miss and one without.

#include <iostream>
#include <time.h>

using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
  return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

double cacheEffectArray(int *arr, int size, int stride) {
  clock_t start, end;
  double cpu_time_used;

  start = clock();
  for (int i = 0; i < size; i += stride) {
    arr[i] *= 3; // array[i] = array[i] * 3;
  }
  end = clock();
  cpu_time_used = elapsed_time(start, end);
  cout << std::fixed;
  cout << "Total number elements accessed: " << size / stride << endl;
  cout << "Time taken: " << cpu_time_used << " ms " << endl;
  cout << "Access time of each element: " << cpu_time_used / (size / stride) << " ms " << endl << endl;
  delete[] arr;

  return cpu_time_used;
}

int main() {
  // Initialize variables & constants
  int SIZE = 1000000;
  double time1, time2;
  int *arr1 = new int[SIZE];
  int *arr2 = new int[SIZE];

  // Fill arrays with random numbers
  for (int i = 0; i < SIZE; i++) {
    arr1[i] = rand() % 100;
    arr2[i] = rand() % 100;
  }

  cout << endl << "____________Cache Effect Loop #1____________" << endl << endl;

  cout << "Loop 1: Stride = 1" << endl;
  // Modified Loop 1
  // for i from 0 to array_length by increments of 1
  //     access element B[i]
  //     This will access 1 element per loop iteration.
  time1 = cacheEffectArray(arr1, SIZE, 1);

  cout << "Loop 2: Stride = 16" << endl;
  // Modified Loop 2
  // for i from 0 to array_length by increments of 16
  //     access each element A[i], A[i+1], A[i+2], ... A[i+16].
  //     This will access 16 elements per loop iteration.
  time2 = cacheEffectArray(arr2, SIZE, 16);

  // Calculate the ratio of the two times
  double ratioTime = time1 / time2;
  double ratioElements = (SIZE) / (SIZE / 16);
  cout << "Ratio(Loop 1:Loop 2) of elements checked: " << ratioElements << endl;
  cout << "Ratio(Loop 1:Loop 2) of time taken: " << ratioTime << endl;
  cout << "Ratio(Loop 1:Loop 2) of time taken per element: " << ratioTime / ratioElements << endl;

  cout << endl << "____________      Test End      ____________" << endl;

  return 0;
}