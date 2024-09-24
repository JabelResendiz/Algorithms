#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<vector<int>> 
// algortimo para hallar el flujo maximo de un grafo
// la idea es que por cada camino aumentativo en el grafo desde source hasta sink
// se calcula la capacidad de flujo de p y se le agregue a la arista inversa de la tomada en el camino
// de esta forma se procede hasta que ya no haya mas camino entre source hast sink
// complejidad : O(E*f) con f el valor de flujo maximo

bool bfs(vii& residual_graph, int source, int sink, vi& parent) {
    vector<bool> visited(residual_graph.size(), false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < residual_graph.size(); ++v) {
            if (!visited[v] && residual_graph[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                if (v == sink) {
                    return true;
                }
            }
        }
    }
    return false;
}


int ford_fulkerson(vii& graph, int source, int sink) {
    vii residual_graph = graph;
    vi parent(graph.size(), -1);
    int max_flow = 0;

    while (bfs(residual_graph, source, sink, parent)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    vii graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;

    cout << "El flujo máximo es: " << ford_fulkerson(graph, source, sink) << endl;

    return 0;
}
