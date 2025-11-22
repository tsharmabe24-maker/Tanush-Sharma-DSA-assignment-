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
    int start = 0;
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    key[start] = 0;
    pq.push({0, start});
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u] = true;
        for (auto it : adj[u]) {
            int w = it.first;
            int v = it.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
    cout<<"Edges in MST:\n";
    int total = 0;
    for(int i=1;i<n;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<key[i]<<"\n";
        total += key[i];
    }
    cout<<"Total weight of MST: "<<total<<"\n";
    return 0;
}