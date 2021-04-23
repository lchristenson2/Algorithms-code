#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
  char data;
  int freq;

  node *left, *right;

  node() {
    left = NULL;
    right = NULL;
    data = 64;
    freq = 0;
  }
};

void min_heapify(node C[], int size, int i) {
  int l = i;
  int r = i + 1;

  int smallest = i;

  if(l < size && C[l].freq < C[i].freq) {
    smallest = l;
  }

  if(r < size && C[r].freq < C[smallest].freq) {
    smallest = r;
  }

  if(smallest != i) {
    swap(C[i], C[smallest]);
    min_heapify(C, size, smallest);
  }
}

void build_min_heap(node C[], int size) {
  for(int i = size-1; i >= 0; i--) {
    min_heapify(C, size, i);
  }
}

void print_codes(string codes[], int n) {
  for(int i = 0; i < n; i++) {
   cout << (char)(i+65) << ":" << codes[i] << endl;
  }
}

void get_codes(node* root, string codes[], string code) {
  if(root) {
    if(root->data > 64) {
      codes[root->data - 65] = code;
    }
    get_codes(root->left, codes, code + "0");
    get_codes(root->right, codes, code + "1");
  }
}

bool comp(node* x, node* y) {
  return x->freq < y->freq;
}

void huffman(node C[], int n) {
  node *x, *y, *r;

  build_min_heap(C, n);
  vector<node*> queue;

  for(int i = 0; i < n; i++) {
    queue.push_back(new node(C[i]));
  }

  while(queue.size() != 1) {
    x = queue[0];
    queue.erase(queue.begin());
    y = queue[0];
    queue.erase(queue.begin());

    r = new node;
    r->data = 64;

    if(x->freq > y->freq) {
      r->left = y;
      r->right = x;
    }
    else{
      r->left = x;
      r->right = y;
    }

    r->freq = x->freq + y->freq;

    queue.insert(queue.begin(), r);
    sort(queue.begin(), queue.end(), comp);
  }

  string codes[n];

  get_codes(queue[0], codes, "");
  print_codes(codes, n);
}

int main() {
  int i, n = 6;
  node C[n];

  for(i = 0; i < n; i++) {
    C[i].data = 65 + i;
    cin >> C[i].freq;
  }

  huffman(C, n);

  return 0;
}
