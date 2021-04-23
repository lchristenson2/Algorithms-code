#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Graph{
  list<int> *E;  //edges are put into an adjacency list so the program knows if there are branching paths
  int V;    //number of vertices
  bool* visited;   //how the program will keep track of vertices that have been visited already

  Graph(int num_vertices) {
    V = num_vertices;
    E = new list<int>[V];
    visited = new bool[V];

    for(int i = 0; i < num_vertices; i++) {
      visited[i] = 0;   //all vertices unvisited before DFS first runs
    }
  }

  void new_edge(int u, int v) {
    E[u].push_back(v);
  }

  Graph transpose() {
    Graph g(V);

    list<int>::iterator j;
    for(int i = 0; i < V; i++) {
      for(j = E[i].begin(); j != E[i].end(); j++) {
        g.E[*j].push_back(i);
      }
    }
    return g;
  }

  void DFS(int v, vector<int> &scc) {
    list<int>::iterator i;
    visited[v] = 1;   //source should be visited upon running, base case
    scc.push_back(v);

    for(i = E[v].begin(); i != E[v].end(); i++) {   //vertices after source
      if(!visited[*i]) {
        DFS(*i, scc);
      }
    }
  }

  void add_to_queue(int v, stack<int> &queue) {
    list<int>::iterator i;
    visited[v] = 1;   //source should be visited upon running, base case

    for(i = E[v].begin(); i != E[v].end(); i++) {   //vertices after source
      if(!visited[*i]) {
        add_to_queue(*i, queue);
      }
    }
    queue.push(v);
  }

  vector<vector<int>> get_sccs() {
    int i, v;
    vector<vector<int>> sccs;
    Graph T = transpose();
    stack<int> queue;

    for(i = 0; i < V; i++) {
      if(!visited[i]) {
        add_to_queue(i, queue);
      }
    }

    while(!queue.empty()) {
      v = queue.top();
      queue.pop();

      if(!T.visited[v]) {
        vector<int> scc;
        T.DFS(v, scc);
        sccs.push_back(scc);
      }
    }

    return sccs;
  }
};

int main() {
  int num_vertices, num_edges;
  int i, j;
  int u, v;
  vector<vector<int>> sccs;

  cin >> num_vertices;
  cin >> num_edges;

  Graph G(num_vertices);
  int* V = new int[num_vertices];

  for(i = 0; i < num_edges; i++) {
    cin >> u >> v;
    G.new_edge(u,v);
  }

  sccs = G.get_sccs();

  for(i = 0; i < sccs.size(); i++) {
    sort(sccs[i].begin(), sccs[i].end());   //sorts the scc list so that each scc's min vertex is at the front
    for(j = 0; j < sccs[i].size(); j++) {
      V[sccs[i][j]] = sccs[i][0];
    }
  }

  for(i = 0; i < num_vertices; i++) {
    cout << V[i] << endl;
  }

  return 0;
}
