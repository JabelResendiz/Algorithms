

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>

using namespace std;

int infinite = (int)1e9;
vi parent;

// O((V+E)logE)
vi dijkstra_heap(int V, vii adj[], int S)
{

    // V-number de vertex
    // S- init
    vi d;

    parent.assign(V, -1);
    d.assign(V, infinite);
    d[S] = 0;

    priority_queue<pair<int, int>> q;
    q.push({d[S], S});

    while (!q.empty())
    {

        int u = q.top().second;
        int m = abs(q.top().first);

        q.pop();

        if (m <= d[u])
        {
            for (int j = 0; j < adj[u].size(); j++)
            {
                if (d[u] + adj[u][j][1] < d[adj[u][j][0]])
                {
                    d[adj[u][j][0]] = d[u] + adj[u][j][1];
                    parent[adj[u][j][0]] = u;
                    q.push({-d[adj[u][j][0]], adj[u][j][0]});
                }
            }
        }
    }

    return d;
}

// O(V^2)

vi dijkstra_denso(int V, vii adj[], int S)
{

    vi d;
    d.assign(V, infinite);
    parent.assign(V, -1);

    d[S] = 0;
    vector<bool> mask;
    mask.assign(V, false);

    for (int i = 0; i < V; i++)
    {
        int m = infinite;
        int u = -1;

        for (int j = 0; j < V; j++)
        {

            if (!mask[j] && m > d[j])
            {
                m = d[j];
                u = j;
            }
        }

        for (int j = 0; j < adj[u].size(); j++)
        {

            if (d[u] + adj[u][j][1] < d[adj[u][j][0]])
            {
                d[adj[u][j][0]] = d[u] + adj[u][j][1];
                parent[adj[u][j][0]] = u;
            }
        }

        mask[u] = true;
    }

    return d;
}

int main()
{
    vii adj[] = {
        {{1, 10}, {3, 5}},
        {{3, 2}, {2, 1}},
        {{4, 4}},
        {{1, 3}, {2, 9}, {4, 2}},
        {{0, 7}, {2, 6}}};

    vi d = dijkstra_heap(5, adj, 0);

    for (int i = 0; i < 5; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
    vi d2 = dijkstra_denso(5, adj, 0);
    for (int i = 0; i < 5; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << parent[i] << " ";
    }
}