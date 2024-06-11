
#include <bits/stdc++.h>

using namespace std;



/*


Graph: 
adj.size()=2 , el primer argumento es la arista con la que esta conectada y el segundo parametro es el peso de esa arista

Ejemplo:


vector<vector<int>>adj[]=
{
{ {1,10} , {2,5} }, // el vertice 0 unido a los vertices 1y 2 con pesos 10 y 5
{ {0,10},  {2,2} },// el vertice 1 unido a los vertices 0 y 2 con pesos 10 y 2
{ {0,5},  {1,2}  } // el vertice 2 unido a los vertices 0 y 1 con pesos 5 y 2
}

*/

class Prim
{
public:
    int prim(int n, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>> q;

        vector<bool> mask;
        mask.assign(n, false);
        mask[0] = true;

        int cost = 0;

        for (int i = 0; i < adj[0].size(); i++)
        {
            q.push({-adj[0][i][1], adj[0][i][0]});
        }

        while (q.size() != 0)
        {
            auto aux = q.top();
            q.pop();

            int k = aux.second;
            if (mask[k])
                continue;

            mask[k] = true;
            cost += abs(aux.first);

            for (int i = 0; i < adj[k].size(); i++)
            {
                if (!mask[adj[k][i][0]])
                {
                    q.push({-adj[k][i][1], adj[k][i][0]});
                }
            }
        }

        return cost;
    }
};