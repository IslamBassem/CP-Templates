vector<int> par,sz;
// DSU temp
int find(int u){
    if (par[u]==u) return u;
    return par[u]=find(par[u]);
}
bool unite(int u, int v){
    u=find(u);
    v=find(v);
    if (u==v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u]+=sz[v];
    sz[v]=0;
    par[v]=u;
    return true;
}
// MST temp (kruskal)
vector<array <int, 3>> edges;
void connect() {
    int val = 0;
    sort(edges.begin(), edges.end());
    for(auto &[w, u, v]: edges) {
        if(unite(v, u)) val+=w;
    }
    cout << val;
}
