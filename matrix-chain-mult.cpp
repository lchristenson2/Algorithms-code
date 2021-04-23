/* use dynamic programming */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int** matrix_chain_order(int* p, int n) {
  int** m = new int*[n+1];
  int** s = new int*[n];
  int i, j;

  //initialize m matrix
  for(i = 1; i < n+1; i++) {
    m[i] = new int[n+1];    //m[1..n, 1..n]
  }

  //initialize s matrix
  for(i = 1; i < n; i++) {
    s[i] = new int[n+1];    //s[1..n-1, 2..n]
  }

  //single matrices, no multiplication, so diagonals of m are 0
  for(i = 1; i < n; i++) {
    m[i][i] = 0;
  }

  int l, k, q;
  for(l = 2; l <= n; l++) {    //l = chain length
    for(i = 1; i <= n-l+1; i++) {
      j = i + l - 1;
      m[i][j] = INT_MAX;

      //34-39: get the minimum cost of parenthesizing A_i * A_i+1 .. A_j
      for(k = i; k <= j-1; k++) {
        q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];

        if(q < m[i][j]) {
          m[i][j] = q;  //update minium cost table
          s[i][j] = k;  //update table which represents the optimal parenthesis positions
        }
      }
    }
  }

  cout << m[1][n] << endl;  //this is our min cost
  return s;
}

void print_optimal_parens(int** s, int i, int j) {
  if(i == j) {
    cout << "A" << i-1;
  }
  else {
    cout << "(";
    print_optimal_parens(s, i, s[i][j]);
    print_optimal_parens(s, s[i][j] + 1, j);
    cout << ")";
  }
}

int main() {
  int* p;
  int** s;
  int num_matrices, num_sequences, i;

  cin >> num_matrices;
  num_sequences = num_matrices + 1;
  p = new int[num_sequences];

  for(i = 0; i < num_sequences; i++) {
    cin >> p[i];
  }

  s = matrix_chain_order(p, num_matrices);
  print_optimal_parens(s, 1, num_matrices);
  cout << endl;

  return 0;
}
