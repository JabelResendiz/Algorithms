

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



int main(){

    vector<Edge> edges = {{0, 1, 3}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, {2, 8, 2}, {2, 3, 7}, {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};
    
    Kruskal obj;
    
    
    cout << obj.kruskal(14, edges);
}


