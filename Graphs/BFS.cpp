//BFS using adjacency list

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 5
class Graph {
 public:
  vector<int> adjList[N];
  void addEdge(int u, int v) {
    adjList[u].push_back(v);
   // adjList[v].push_back(u); // In case of undirected graph, to and fro traversal is allowed
  }

  void bfs(int src) {
    vector<bool> visited(N, false);
    vector<int> distance(N, -1);
    vector<int> parent(N, -1);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    distance[src] = 0;
    vector<int> path;
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      path.push_back(u);
      for(int j=0;j<adjList[u].size();j++)
      {
            int v=adjList[u][j];
            if (!visited[v]) {
              q.push(v);
              visited[v] = true;
              distance[v] = distance[u] + 1;
              parent[v] = u;
            }
      }
    }

    cout << "BFS: starting from vertex: " << src << endl;
    for (auto d : path) cout << d << " ";
    cout<< endl;

    cout << "Distance of nodes from : " << src << endl;
    for (int i = 0; i < distance.size(); i++)
      cout << "node " << i << " -> " << distance[i] << endl;

    cout << "Parent of: " << endl;
    for (int j = 0; j < parent.size(); j++)
      cout << "node " << j << " is " << parent[j] << endl;
  }
};
int main() {
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(3, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.bfs(0);
}