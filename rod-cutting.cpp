#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int*> rod_cut(int* p, int n) {   //extended bottom up cut rod algorithm
  int* r = new int[n+1];    //revenue
  int* s = new int[n+1];    //optimal size i
  int i, j, q;
  r[0] = 0;

  for(j = 1; j <= n; j++) {
    q = INT_MIN;

    for(i = 0; i < j; i++) {
      if(q < p[i] + r[j-i-1]) {
        q = p[i] + r[j-i-1];
        s[j] = i + 1;
      }
    }

    r[j] = q;
  }

  vector<int*> r_and_s;
  r_and_s.push_back(r);
  r_and_s.push_back(s);

  return r_and_s;   //return the maximum revenues and their respective locations of the first cut
}

void print_rod_cut(int* p, int n) {
  vector<int*> rs = rod_cut(p, n);; /* r = r_and_s[0], s = r_and_s[1] */

  cout << rs[0][n] << endl;   //print max revenue

  while(n > 0) {
    cout << rs[1][n] << " "; //print the cuts
    n -= rs[1][n];
  }

  cout << "-1" << endl;   //indicates the end of the cuts
}

int main() {
  int n, i;   //rod lengths
  int* p;     //price of rod of length i

  cin >> n;
  p = new int[n];

  for(i = 0; i < n; i++) {
    cin >> p[i];
  }

  print_rod_cut(p, n);

  return 0;
}
