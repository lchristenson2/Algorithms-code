#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

struct graph{
  list<pair<int, int>> *E;     //create adjacceny list from  edges
  int V;    //number of vertices

  graph(int num_vertices) {
    V = num_vertices;
    E = new list<pair<int,int>>[V];
  }

  void new_edge(int u, int v, int w) {
    E[u].push_back(make_pair(v,w));
    E[v].push_back(make_pair(u,w));   //forming a tree, which is undirected, from the graph inputed
  }

  int* prim() {
    int* key = new int[V];    //tracks the minimum key at vertex v
    int* pi = new int[V-1];   //to track the neighboring vertices parents, which is vertex u, return this array to output the results in main()
    bool* isValid = new bool[V];    //tracks which vertices are already in the MST
    int u,v,i,w;
    list<pair<int,int>>::iterator j;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minqueue; //greater comparator ensures the top of the queue has the next vertex v with the min weight edge

    for(u = 0; u < V; u++){
      isValid[u] = 1;
      key[u] = INT_MAX;
      pi[u] = -1;
    }

    minqueue.push(make_pair(0,0));    //queue starts with one element which is the root
    key[0] = 0;

    while(!minqueue.empty()) {
      u = minqueue.top().second;    // key is the first item in the pair instad of vertex, this keeps the vertices in queue sorted
      minqueue.pop();
      isValid[u] = 0;   //vertex u is now in our MST

      for(j = E[u].begin(); j != E[u].end(); j++) {
        v = (*j).first;
        w = (*j).second;

        if(isValid[v] && w < key[v]) {
          key[v] = w;
          minqueue.push(make_pair(key[v], v));  //push pair <key,vertex> so the minqueue is sorted correctly & the min weighted edge connected to the MST in it's current state is always extracted
          pi[v] = u;
        }
      }
    }
    return pi;
  }
};

int main() {
  int num_vertices, num_edges;
  int i, j;
  int u, v, w;
  int* pi;

  cin >> num_vertices;
  cin >> num_edges;

  graph G(num_vertices);

  for(i = 0; i < num_edges; i++) {
    cin >> u >> v >> w;
    G.new_edge(u, v, w);
  }

  pi = G.prim();

  for(i = 1; i < num_vertices; i++) {   //exclude the root, it's parent vertex is -1
    cout << pi[i] << endl;
  }

  return 0;
}
