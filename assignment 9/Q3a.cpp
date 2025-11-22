#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

struct DSU{
    vector<int> parent, rnk;
    DSU(int n){
        parent.resize(n);
        rnk.resize(n, 0);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;
        if(rnk[rootX]<rnk[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        if(rnk[rootX] == rnk[rootY]) rnk[rootX]++;
        return true;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });
    DSU dsu(n);
    int mst_weight = 0;
    cout<<"Edges in MST:\n";
    for(auto& edge : edges){
        if(dsu.unite(edge.u, edge.v)){
            mst_weight += edge.w;
            cout<<edge.u<<" - "<<edge.v<<" : "<<edge.w<<"\n";
        }
    }
    cout<<"Total weight of MST: "<<mst_weight<<"\n";
    return 0;
}