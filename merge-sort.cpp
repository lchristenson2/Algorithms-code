#include <iostream>
#include <array>
#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int mid, int r) {
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int* R = new int[n1+1];
  int* L = new int[n2+1];

  int i, j;

  for(i = 0; i < n1; i++) {
    L[i] = arr[l+i];
  }

  for(j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  L[n1+1] = INT_MAX;
  R[n2+1] = INT_MAX;

  i = 0, j = 0;
  int k = l;

  while(i < n1 && j < n2) {
    if(L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else{
        arr[k] = R[j];
        j++;
    }
    k++;
 }

 while (i < n1) {
   arr[k] = L[i];
   i++;
   k++;
 }

 while (j < n2) {
   arr[k] = R[j];
   j++;
   k++;
 }
}

void mergesort(int arr[], int l, int r) {
  if(l < r) {
    int mid = (l+r)/2;

    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    merge(arr, l, mid, r);
  }
}

int main() {
  int num_elements;
  cin >> num_elements;

  int* elements = new int[num_elements];

  for(int i = 0; i < num_elements; i++) {
    cin >> elements[i];
  }

  mergesort(elements, 0, num_elements-1);

  for(int k = 0; k < num_elements; k++) {
    cout << elements[k] << ";";
  }

  //cout << endl;
  return 0;
}
