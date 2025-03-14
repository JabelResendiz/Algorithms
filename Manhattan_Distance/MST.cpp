

#include <bits/stdc++.h>

using namespace std;


/*
Given some points in the plane, find the edges that connect
all the points and have a minimim total sum of weight.

The weight of an edge that connect two points is their Manhattan distance.

 in  
$O(n \log{n})$  by finding for each point its nearest neighbor in each octant,
this will give us O(n) candidate edges which, as we show below, will guarantee that they contain the MST

*/

struct point {
    long long x, y;
};

// Returns a list of edges in the format (weight, u, v). 
// Passing this list to Kruskal algorithm will give the Manhattan MST.
vector<tuple<long long, int, int>> manhattan_mst_edges(vector<point> ps) {
    vector<int> ids(ps.size());
    iota(ids.begin(), ids.end(), 0);
    vector<tuple<long long, int, int>> edges;
    for (int rot = 0; rot < 4; rot++) { // for every rotation
        sort(ids.begin(), ids.end(), [&](int i, int j){
            return (ps[i].x + ps[i].y) < (ps[j].x + ps[j].y);
        });
        map<int, int, greater<int>> active; // (xs, id)
        for (auto i : ids) {
            // lower_bound(ps[i].x) busca el primer elemento en el mapa cuyo valor de x es mayor o igual ps[i].x
            // si no existe devuelve el iterador a active.end()
            // se borra el elemento apuntado por el iterador y luego se incrementa para apuntar al siguiente
            for (auto it = active.lower_bound(ps[i].x); it != active.end();
            active.erase(it++)) {
                int j = it->second;
                if (ps[i].x - ps[i].y > ps[j].x - ps[j].y) break;
                assert(ps[i].x >= ps[j].x && ps[i].y >= ps[j].y);
                edges.push_back({(ps[i].x - ps[j].x) + (ps[i].y - ps[j].y), i, j});
            }
            active[ps[i].x] = i;
        }
        for (auto &p : ps) { // rotate
            if (rot & 1) p.x *= -1;
            else swap(p.x, p.y);
        }
    }
    return edges;
}

int main()
{
    
    vector<point>ps = {

        {2,3},
        {5,2},
        {1,1},
        {4,4}
    };

    auto edges= manhattan_mst_edges(ps);

    for (auto& edge : edges) {
        long long weight = std::get<0>(edge);
        int u = std::get<1>(edge);
        int v = std::get<2>(edge);
        std::cout << "Edge: (" << weight << ", " << u << ", " << v << ")\n";
    }

    return 0;

}