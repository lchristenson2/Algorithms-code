#include <iostream>

using namespace std;

void countSort(int** arr, int size, int k) {
  int* count = new int[4];  //accounting for all possible values in vectors
  int** newArr = new int*[size];
  int i, j;

  //initializes counters to zero
  for(i = 0; i < 4; i++) {
    count[i] = 0;
  }

  //allocate space for all arrays in newArr
  for(i = 0; i < size; i++) {
    newArr[i] = new int[10];
  }

  //count appearances of the kth element in each array
  for(i = 0; i < size; i++) {
    ++count[arr[i][k]];
  }

  //change count to contain the actual position in newArr
  for(i = 1; i <= 4; i++) {
    count[i] += count[i-1];
  }

  //sorting
  for(i = size-1; i >= 0; i--) {
    for(j = 9; j >= 0; j--) {
      newArr[count[arr[i][k]] - 1][j] = arr[i][j];
    }
    --count[arr[i][k]];
  }

  //copy elements from newArr to arr
  for(i = 0; i < size; i++) {
    for(j = 0; j < 10; j++) {
      arr[i][j] = newArr[i][j];
    }
  }

}

void radixSort(int** arr, int num_vectors) {
  //counting sort for every index (starting from the last) rather than digit
  for(int i = 9; i >= 0; i--) {
    countSort(arr, num_vectors, i);
  }
}

int main() {
  int num_vectors;
  int vector_size = 10;

  int i, j;

  cin >> num_vectors;

  int** vectors = new int*[num_vectors];

  for(i = 0; i < num_vectors; i++) {
    vectors[i] = new int[vector_size];
  }

  for(i = 0; i < num_vectors; i++) {
    for(j = 0; j < 10; j++) {
      cin >> vectors[i][j];
    }
  }

  radixSort(vectors, num_vectors);

  for(i = 0; i < num_vectors; i++) {
    for(j = 0; j < 10; j++) {
      cout << vectors[i][j] << ";";
    }
    cout << endl;
  }

  return 0;
}
