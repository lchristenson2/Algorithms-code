#include <iostream>
#include <stdio.h>

using namespace std;

void maxheapify(int* arr, int size, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  int largest = i;

  if(l < size && arr[l] > arr[largest]) {
    largest = l;
  }

  if(r < size && arr[r] > arr[largest]) {
    largest = r;
  }

  if(largest != i) {
    swap(arr[i], arr[largest]);
    maxheapify(arr, size, largest);
  }
}

void buildmaxheap(int* arr, int size) {
  for(int i = size/2; i >= 0; --i) {
    maxheapify(arr, size, i);
  }
}

void heapsort(int* arr, int size) {
  buildmaxheap(arr, size);

  for(int i = size; i > 0; --i) {
    swap(arr[0], arr[i]);
    maxheapify(arr, i, 0);
  }
}

int main() {
  int num_elements;
  cin >> num_elements;

  int* elements = new int[num_elements];

  for(int i = 0; i < num_elements; i++) {
    cin >> elements[i];
  }

  heapsort(elements, num_elements-1);

  for(int i = 0; i < num_elements; i++) {
    cout << elements[i] << ";";
  }

  return 0;
}
