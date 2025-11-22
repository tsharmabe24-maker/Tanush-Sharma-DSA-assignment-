#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;
    cin>>src;
    const int INF = 1e9;
    vector<int> dist(n, INF);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d!= dist[u]) continue;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout<<"Shortest distances from source "<<src<<":\n";
    for(int i=0;i<n;i++){
        if(dist[i] == INF){
            cout<<i<<": INF\n";
        } else {
            cout<<i<<": "<<dist[i]<<"\n";
        }
    }   
    return 0;
}