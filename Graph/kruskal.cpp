

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};


class Kruskal
{
public:
    vector<int> parent, rank;

    void build_set(int v)
    {
        parent[v] = v;
        rank[v] = 0;
    }

    int set_off(int v)
    {
        if (v == parent[v])
            return v;
        return set_off(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = set_off(a);
        b = set_off(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    int kruskal(int n, vector<Edge> edges)
    {

        int cost = 0;
        vector<Edge> result;

        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++)
            build_set(i);

        sort(edges.begin(), edges.end());

        for (Edge e : edges)
        {
            if (set_off(e.u) != set_off(e.v))
            {
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);
            }
        }

        return cost;
    }
};


