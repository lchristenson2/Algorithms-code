#include <iostream>
#include <list>
#include <vector>

using namespace std;

int h(int k, int m) { //hash function
  return k % m;
}

int search(vector<list <int>> table, int k, int m) {
  int i, j;
  i = 0;

  list<int>::iterator pos;

  while(i != m) {
    j = h(i, m);

    int index = 0;
    for(pos = table[j].begin(); pos != table[j].end(); pos++) {
      if(*pos == k) {
        return index;   //return position successfully
      }
      index++;
    }
    i++;
  }

  return -1;  //return this if the search fails
}

vector<list <int>> insert(vector<list <int>> table, int k, int m) {
  int j = h(k, m);
  table[j].push_front(k);   //new elements always get pushed to the front

  return table;
}

vector<list <int>> del(vector<list <int>> table, int k, int m) {
  list<int>::iterator index;   //to get to the index of deletion
  int des = search(table, k, m);
  int j = h(k,m);

  if(des != -1) {
    for (index = table[j].begin(); index != table[j].end(); index++) {
      if (*index == k) {
        break;
      }
    }

    table[j].erase(index);
    cout << k << ":DELETED;";
  }
  else {
    cout << k << ":DELETE_FAILED;";
  }
  cout << endl;

  return table;
}

void output(vector<list <int>> table, int m) {
  int i, j;
  list<int>::iterator pos;    //to iterate thru each list

  i = 0;
  j = h(i, m);

  while(i != m) {   //repeat until we reach the end
    cout << j << ":";

    for(pos = table[j].begin(); pos != table[j].end(); pos++) {
      cout << *pos << "->";
    }
    cout << ";" << endl;  //done printing this list

    i++;
    j = h(i, m);
  }
}

int main() {
  /* Using vector of lists since the vector library supports operator[]; makes
    getting to each list much more convenient
  */

  vector<list <int>> table;
  int m, i;
  cin >> m;

  for(i = 0; i < m; i++) {
    list<int> bucket;
    table.push_back(bucket);
  }
  char choose_op;
  int num;

  cin >> choose_op;
  while(choose_op != 'e') {

    switch(choose_op) {

      case 'o':
      {
        output(table, m);
        break;
      }

      case 's': {
        cin >> num;
        int j = search(table, num, m);

        if(j != -1) {
          cout << num << ":FOUND_AT" << h(num,m) << "," << j << ";";
        }
        else {
          cout << num << ":NOT_FOUND;";
        }
        cout << endl;
        break;
      }

      case 'i': {
        cin >> num;
        table = insert(table, num, m);
        break;
      }

      case 'd': {
        cin >> num;
        table = del(table, num, m);
        break;
      }

      default :
        break;
    }

    cin >> choose_op;
  }

  return 0;
}
