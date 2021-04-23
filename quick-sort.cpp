#include <iostream>
#include <stdio.h>
using namespace std;

int partition(int* arr, int l, int r) {
  int i = l - 1;

  for(int j = l; j < r; j++) {

    if(arr[j] <= arr[r]) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[r]);
  return i+1;
}

void quicksort(int* arr, int l, int r) {
  if(l < r) {
    int p = partition(arr, l, r);

    quicksort(arr, l, p-1);
    quicksort(arr, p+1, r);
  }
}

int main() {
  int num_elements;
  cin >> num_elements;

  int* elements = new int[num_elements];

  for(int i = 0; i < num_elements; i++) {
    cin >> elements[i];
  }

  quicksort(elements, 0, num_elements-1);

  for(int i = 0; i < num_elements; i++) {
    cout << elements[i] << ";";
  }

  return 0;
}
