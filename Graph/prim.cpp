
#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

struct Edges
{
    int w = INF, to = -1;
    bool operator<(Edges const &other) const
    {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

class Prim
{
public:
   

    void prim( int n, vector<vector<Edges>> adj)
    {
        priority_queue<pair<int, int>> q;
    }
};