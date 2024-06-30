
#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

vector<bool>visited;
vi phi;
vi d;
vi low;
set<pair<int,int>> bridges;


void dfs_visit(vi adj[],int u,int time){

    visited[u]=true;
    time+=1;
    d[u]=time;
    low[u]=d[u];

    for(int i=0;i<adj[u].size();i++){
        if(!visited[adj[u][i]]){
            phi[adj[u][i]]=u;
            dfs_visit(adj,adj[u][i],time);
            low[u]=min(low[u],low[adj[u][i]]);

            
        }

        else if(phi[u]!=adj[u][i]){
            low[u]=min(low[u],d[adj[u][i]]);
        }
    }

    if(phi[u]!=-1 && low[u]==d[u]){
        bridges.insert({min(phi[u],u), max(phi[u],u)});
    }

    
}

void bridges_edges(int V,vi adj[]){
    visited.assign(V,false);
    d.assign(V,-1);
    low.assign(V,-1);
    phi.assign(V,-1);
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs_visit(adj,i,-1);
        }
    }
    
}

int main(){

    vi adj[]={
        {1,2,3,4},{0,3,4},{0,5,6},{0,1,4},{0,1,3},{2,6},{2,5}
    };

    bridges_edges(7,adj);
    for(auto c :bridges){
        
        cout<<c.first<<" "<<c.second<<endl;
    }

}