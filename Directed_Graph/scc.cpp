#include <bits/stdc++.h>

using namespace std;

//O(V+E)

int number_componentes;
vector<bool> visited;
vector<int>componente_conexa; // al salida , los elemetnos y sus componentes
stack<int> stack_vertex; // una pila para ordenar sus f[u]

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

vector<bool>visited2;
stack<int> s;
void dfs_visit_topologicalSort(vector<set<int>>adj2,int u){

    
    visited2[u]=true;
    
    for(int v: adj2[u]){
        
        if(!visited2[v]){
            dfs_visit_topologicalSort(adj2,v);
        }
    }

    s.push(u);
}
// grafo de las componentes fuertemente conexas en un DAG , osea con su orden topologico
int main(){

    vector<int> adj[]={
        {1},{2,4,5},{6,3},{2,7},{0,5},{6},{5,7},{}
    };
    
    strongly_connected_components(8,adj);
    for(int i=0;i<componente_conexa.size();i++){
        number_componentes=max(number_componentes,componente_conexa[i]);
    }
    number_componentes++;

    vector<set<int>> adj2(number_componentes);
    
    for(int i=0;i<8;i++){
        
        for(int j=0;j<adj[i].size();j++){
            
            if(componente_conexa[i]!=componente_conexa[adj[i][j]]){
                
                adj2[componente_conexa[i]].insert(componente_conexa[adj[i][j]]);
            }
        }
    }
    
    vector<int> topological_order;
    visited2.assign(number_componentes,false);
    
    dfs_visit_topologicalSort(adj2,0);
    
    while(!s.empty()){
        topological_order.push_back(s.top());
        s.pop();
    }
    
    for(auto c:topological_order){
        cout<<c<<" ";
    }
    
}