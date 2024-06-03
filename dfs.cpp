#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
public:
    int V;
    vector<vector<int> > adjList;
     Graph(int vertices) {
        V = vertices;
        adjList.resize(vertices);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void DFS(int startVertex) {
        stack<int> dfsStack;
        vector<bool> visited(V, false);
      dfsStack.push(startVertex);
      while (!dfsStack.empty()) {
            int vertex = dfsStack.top();
            dfsStack.pop();
           if (!visited[vertex]) {
                cout << vertex << " ";
                visited[vertex] = true;
                for (int i = 0; i < adjList[vertex].size(); i++) {
                    int adjacent = adjList[vertex][i];
                    if (!visited[adjacent]) {
                        dfsStack.push(adjacent);
                    }
                }
            }
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    Graph g(vertices);
    cout << "Enter the edges (format: u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;
    cout << "DFS traversal starting from vertex " << startVertex << ": ";
    g.DFS(startVertex);
    return 0;
}
