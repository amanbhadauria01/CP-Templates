// add cumulative values 

void dfs2(int u , int p , vector<int> & temp){
   for(auto v : graph[u]){
      if(v==p)continue;
      dfs(v,u,temp);
      temp[u] += temp[v];
   }
}
// traverse the point pairs add value for those and decrease value for their lca

vector<int> temp(n+1,0);
for(int j = 0 ; j < m ; j++){
    if((1<<j)&i){
        int u = vec[j].fi , v = vec[j].se ;
        int l = lca[u][v];
        temp[u]++;
        temp[v]++;
        temp[l]-=2; 
    }
}
dfs2(1,0,temp);

// all the temp[i] > 1 are the ones which comes across paths 
 