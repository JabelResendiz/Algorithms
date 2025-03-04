#include <bits/stdc++.h>

using namespace std;

/*

Let G be a tree. For every query of the form (u,v) we want to find the lowest
common ancestor of the nodes u and v, i.e we want to find a node w that lies on the path
from u to the root node, that lies on the path from v to the root node, and if there are 
multiple nodes we pick the one that is fartest away from the root node

O(N log N) processing the tree
O(log N) for wach LCA query

*/

int n,l;
vector<vector<int>> adj , up;

int timer;
vector<int>tin, tout;

void dfs(int v, int p){

    tin[v]=++timer;
    up[v][0]=p;
    for(int i=1;i<=l;++i){
        up[v][i]=up[up[v][i-1]][i-1];

    }

    for(int u:adj[v]){
        if(u!=p)
            dfs(u,v);
    }

    tout[v]=++timer;

}


bool is_ancestor(int u,int v){
    return tin[u]<= tin[v] && tout[u]>=tout[v];
}

int lca(int u,int v){

    if(is_ancestor(u,v))
        return u;
    if(is_ancestor(v,u))
        return v;
    for(int i=l;i>=0;--i){
        if(!is_ancestor(up[u][i],v))
            u=up[u][i];
    }

    return up[u][0];

}

void prepocess(int root){

    tin.resize(n);
    tout.resize(n);
    timer=0;
    l=ceil(log2(n));
    up.assign(n,vector<int>(l+1));
    dfs(root,root);

}

int main(){
    return 0;
}