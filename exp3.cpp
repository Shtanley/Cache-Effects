// Sameer Hossain
// ID: 301357905
// Experiment 1

// Compare the times to traverse a list (containing a large number of elements) 
// implemented in an array, in a simple linked list, and in an unrolled linked list. 

#include <iostream>
#include <time.h>
#include <cstdio>
#include "UList.h"
#include "List.h"

using namespace std;

double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds 
  return (finish - start)/(double)(CLOCKS_PER_SEC/1000); 
} 

// Make an array large enough so that it is larger than the L1 cache 
// & measure the time to traverse it.
void arrayTraversal(int size) {
  int *arr = new int[size];

  clock_t start = clock();
  for (int64_t i = 0; i < size; i++) {
    arr[(i) % (size-1)]++;
  }
  clock_t end = clock();

  double cpu_time_used = elapsed_time(start, end);
  cout << "Total array access time: " << cpu_time_used << " ms " << endl;

  delete[] arr;
}

// Fill a simple linked list with a large number of elements and measure the time to
// traverse it.
void linkedListTraversal(int size) {
  // Initializde the linked list
  List<int> list;
  clock_t start, end;
  double cpu_time_used = 0;

  // Fill the list with elements
  for (int i = 0; i < size; i++) {
    list.push_back(0);
  }

  // Traverse the list by popping the last element & measure the time
  start = clock();
  for (int i = 0; i < size; i++) {
    
    list.pop_back();
    
  }
  end = clock();
  cpu_time_used = elapsed_time(start, end);
  cout << "Total LL access time: " << cpu_time_used << " ms " << endl;
}

// Fill an unrolled linked list with a large number of elements & 
// measure the time to traverse it.
void uListTraversal(int size) {
  // Initialize the unrolled linked list
  double cpu_time_used = 0;
  unrolled_list list;
  int* arr = new int[1000];
  
  // Fill the list with elements
  for (int i = 0; i < size; i++) {
    list.insert(arr);
  }

  // Traverse the list by incrementing each element in the array
  cpu_time_used = list.increment();

  cout << "Total ULL access time: " << cpu_time_used << " ms " << endl;
}

int main() {
  cout << endl <<  "_____________Cahe Effect Traversal_____________" << endl << endl;
  int size = 1000;
  cout << std::fixed;
  uListTraversal(size); 
  size = 1000000;
  linkedListTraversal(size);
  arrayTraversal(size);

  cout << endl << "____________      Test End      ____________" << endl;

  return 0;
}