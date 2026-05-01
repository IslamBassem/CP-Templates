vector<int> Dijkstra(int src, vector<vector<pair<int,int>>>&adj) {
    int n = adj.size();
    vector<int> dist(n, LLONG_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
    dist[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto [dis, cur] = pq.top();
        pq.pop();
        if (dist[cur] < dis) continue;
        for (auto &[i, w]: adj[cur]) {
            if (dis + w < dist[i]) {
                dist[i] = dis + w;
                pq.emplace(dist[i], i);
            }
        }
    }
 
    return dist;
}
