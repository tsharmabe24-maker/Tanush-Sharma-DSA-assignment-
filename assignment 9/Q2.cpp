#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis){
    vis[u] = true;
    cout<<u<<" ";
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v, adj, vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cin>>src;
    vector<bool> vis(n, false);
    cout<<"DFS: ";
    dfs(src, adj, vis);
    return 0;
}