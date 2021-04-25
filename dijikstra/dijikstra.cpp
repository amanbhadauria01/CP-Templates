void fill(int n){
    priority_queue<pair<ll,ll> , vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
    pq.push({0,0});
    for(int k = 0 ; k < n ; k++){
        visited[k] = false;
    }
    dist[i] = 0;
    while(pq.empty()==false){
        ll u = pq.top().second;
        pq.pop();
        if(visited[u]==true){
            continue;
        }
        visited[u]=true;
        for(auto j : graph[u]){
            ll v = j.first;
            ll w = j.second;
            if(visited[v]){
                continue;
            }
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[i][v],v});
            }
        }
    }
}