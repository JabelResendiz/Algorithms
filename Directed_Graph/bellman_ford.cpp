

#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>

// arcos de costo negativo pero no ciclos de costo negativo alcanzables desde el origen s
// O(E*V) y en el peor de los casos cuando E=O(V^2) entonces el algortimo es V^3


using namespace std;

int infinite = (int)1e9;
vi parent;
vi d;

void initialize_single_source(vii adj[], int s,int n)
{

    d.assign(n, infinite);
    parent.assign(n, -1);
    d[s] = 0;
}
void bellman_ford(vii adj[], int s,int n)
{

    initialize_single_source(adj, s,n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int v = 0; v < adj[j].size(); v++)
            {
                if (d[adj[j][v][0]] > d[j] + adj[j][v][1])
                {
                    d[adj[j][v][0]] = d[j] + adj[j][v][1];
                    parent[adj[j][v][0]] = j;
                }
            }
        }
    }

    for (int j = 0; j <n; j++)
    {
        for (int v = 0; v < adj[j].size(); v++)
        {
            if (d[adj[j][v][0]] > d[j] + adj[j][v][1])
            {
                cout<<"Existe un ciclo de costo negativo"<<endl;
                return;
            }
        }
    }

    for(int v: d){
        cout<<v<<" ";
    }

    cout <<endl;
}

int main()
{

    vii adj[]={
       { {1,6},{2,7}},
       {{2,8},{4,-4},{3,5}},
       {{3,-3},{4,9}},
       {{1,-2}},
       {{0,2},{3,7}}
    };

    

    bellman_ford(adj,0,5);
    
}