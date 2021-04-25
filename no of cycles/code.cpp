const int N = 1e6 + 10;
int n , a[N] ;
int visited[N];

int dfs(int u ){
    if(visited[u]){
      return visited[u]==1;
    }
    visited[u] = 1;
    int ans = dfs(a[u]);
    visited[u] = 2;
    return ans;
}

void go(){
  cin >> n ;
  for(int i = 1; i <= n ; i++)cin >> a[i];
  memset(visited,0,sizeof(visited));
  int cnt = 0;
  for(int i = 1 ; i <= n ; i++){
     if(!visited[i])cnt += dfs(i);
  }
}