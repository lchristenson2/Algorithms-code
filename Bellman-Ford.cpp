#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
  int src, dest, wt;

  Edge(int u, int v, int w) {
    src = u;
    dest = v;
    wt = w;
  }
};

struct Graph{
  int V, E;    //number of vertices
  vector<Edge*> edges;

  Graph(int num_vertices, int num_edges) {
    V = num_vertices;
    E = num_edges;
  }

  void new_edge(int u, int v, int w) {
    edges.push_back(new Edge(u,v,w));
  }

  bool bellman_ford(int src, int* delta) {
    int i, j, u, v, w;

    delta[0] = 0;
    for(i = 1; i < V; i++) {
      delta[i] = INT_MAX;
    }

    for(i = 1; i < V; i++) {
      for(j = 0; j < E; j++) {
        u = edges[j]->src;
        v = edges[j]->dest;
        w = edges[j]->wt;

        //relax each edge
        if(delta[u] != INT_MAX && delta[v] > delta[u] + w) {
          delta[v] = delta[u] + w;
        }
      }
    }

    //check for negative weighted cycles
    for(i = 0; i < V; i++) {
      u = edges[i]->src;
      v = edges[i]->dest;
      w = edges[i]->wt;

      if(delta[v] > delta[u] + w) {
        return 0;
      }
    }

    return 1;
  }
};

int main() {
  int num_vertices, num_edges;
  int i, u, v, w;
  int* delta = new int[num_vertices];  //tracks the shortest distance b/n the src vertex to each other vertex

  cin >> num_vertices >> num_edges;
  Graph G(num_vertices, num_edges);

  for(i = 0; i < num_edges; i++) {
    cin >> u >> v >> w;
    G.new_edge(u, v, w);
  }

  if(G.bellman_ford(0, delta)) {    //bellman_ford returns a boolean, so push delta[] as an argument
    cout << "TRUE" << endl;
    for(i = 0; i < num_vertices; i++) {
      if(delta[i] == INT_MAX) {
        cout << "INFINITY" << endl;
      }
      else {
        cout << delta[i] << endl;
      }
    }
  }
  else{
    cout << "FALSE" << endl;
  }

  return 0;
}
