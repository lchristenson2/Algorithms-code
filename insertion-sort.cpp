#include <iostream>
#include <array>

using namespace std;

void insertionsort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int key = arr[i];
    int j = i;

    while (j > 0 && arr[j-1] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j] = key;
  }
}

int main() {
  int num_elements;
  cin >> num_elements;

  int* elements = new int[num_elements];

  for(int i = 0; i < num_elements; i++) {
    cin >> elements[i];
  }

  for(int p = 2; p <= num_elements; p++) {
    int* temp = new int[p];

    for(int j = 0; j < p; j++) {
       temp[j] = elements[j];
    }

    insertionsort(temp, p);

    for(int k = 0; k < p; k++) {
      cout << temp[k] << ";";
    }

    cout << endl;
  }

  return 0;
}
