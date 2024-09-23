#include <bits/stdc++.h>

using namespace std;


vector<bool> visited;
vector<int>componente_conexa;
stack<int> stack_vertex;

void dfs(int u,vector<int> adj[],int cc,bool b){

    visited[u]=true;

    for(int i=0;i<adj[u].size();i++){
        if(!visited[adj[u][i]]){
            componente_conexa[adj[u][i]]=cc;
            dfs(adj[u][i],adj,cc,b);   
        }
    }

    if(b){
        stack_vertex.push(u);
    }
     
    
}
void strongly_connected_components(int n, vector<int> adj[]){

    visited.assign(n,false);
    componente_conexa.assign(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,0,1);
        }
    }
    
    vector<int>adj2[n];
    for(int i=0;i<n;i++){
        for(int v: adj[i]){
            adj2[v].push_back(i);
        }
    }

    visited.assign(n,0);
    componente_conexa.assign(n,0);
    int cc=0;
    while(!stack_vertex.empty()){
        
        int v=stack_vertex.top();
        stack_vertex.pop();
        if(!visited[v]){
            componente_conexa[v]=cc;
            dfs(v,adj2,cc,0);
            cc++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<componente_conexa[i]<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> adj[]={
        {1},{2,4,5},{6,3},{2,7},{0,5},{6},{5,7},{}
    };
    
    strongly_connected_components(8,adj);

    
}