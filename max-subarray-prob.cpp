#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
   return (a > b) ? a : b;
 }

int max(int a, int b, int c) {
  return max(max(a, b), c);
}

int find_xing(int arr[], int low, int mid, int high) {
  int leftsum, rightsum;
  int maxleft, maxright;
  int sum = 0;

  leftsum = INT_MIN;

  for(int i = mid; i >= low; i--) {
    sum += arr[i];

    if(sum > leftsum) {
      leftsum = sum;
      maxleft = i;
    }
  }

  rightsum = INT_MIN;
  sum = 0;

  for(int j = mid + 1; j <= high; j++) {
    sum += arr[j];

    if(sum > rightsum) {
      rightsum = sum;
      maxright = j;
    }
  }
  return max(maxleft, maxright, leftsum + rightsum);
}

int find_max(int arr[], int low, int high) {
  if (high == low) {
    return arr[low]; //base case
  }
  else {
    int mid = (low+high)/2;

    int leftsum = find_max(arr, low, mid);
    int rightsum = find_max(arr, mid+1, high);
    int crosssum = find_xing(arr, low, mid, high);

    if(leftsum >= rightsum && leftsum >= crosssum) {return leftsum;}

    else if(rightsum >= leftsum && rightsum >= crosssum) {return rightsum;}

    else {return crosssum;}
    }
  }

int main() {
  int num_elements;
  cin >> num_elements;

  int* elements = new int[num_elements];

  for(int i = 0; i < num_elements; i++) {
    cin >> elements[i];
  }

  cout << find_max(elements, 0, num_elements-1);
}
