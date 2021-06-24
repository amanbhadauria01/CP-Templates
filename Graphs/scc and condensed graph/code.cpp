#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 1e6 + 10;
int n , m  ;
vector<pair<int,int>> graph[N];
set<pair<int,int>> adj[N];
vector<int> igraph[N];
vector<pair<pair<int,int>,int>> edges;
bool vis[N] = {0};
int par[N],val[N]={0};
vector<int> st,component;

void dfs(int u){
    vis[u] = 1;
    for(auto it : graph[u]){
        int v = it.fi;
        if(vis[v])continue;
        dfs(v);
    }
    st.push_back(u);
}

void dfs2(int u){
    vis[u] = 1;
    for(auto v : igraph[u]){
        if(!vis[v])dfs2(v);
    }
    component.push_back(u);
}

int dfs3(int u){
    int ans = 0;
    for(auto it : adj[u]){
        int v = it.fi , w = it.se;
        ans = max(ans,dfs3(v)+w);
    }
    ans += val[u];
    return ans;
}

int fun(int w){
    int l = 0 , r = 1e6;
    int k = 0;
    while(l<=r){
        int m = (l+r)/2;
        int val = (m*(m+1))/2;
        if(val<=w)k = m , l = m+1;
        else r = m-1;
    }
    int res = w*(k+1);
    res -= ((k*(k+1)*(2*k+1))/6 + (k*(k+1))/2)/2;
    return res;
}

void solve(){
   cin >> n >> m ;
   // delete w if yours edges are not weighted
   for(int i = 0 ; i < m ; i++){
       int x , y , w ; cin >> x >> y >> w ; 
       graph[x].push_back({y,w}); igraph[y].push_back(x);
       edges.push_back({{x,y},w});
   }
   int src ; cin >> src;
   // first dfs to store the order 
   for(int i = 1 ; i <= n ; i++){
       if(!vis[i])dfs(i);
   }
   for(int i = 1 ; i <= n ; i++)vis[i] = 0;
   reverse(st.begin(),st.end());
   // second dfs to make roots of condensed graph
   for(auto u : st){
       if(!vis[u]){
           component.clear();
           dfs2(u);
           int root = component.front();
           for(auto x : component)par[x] = root;
       }
   }
   // making of condensed graph
   for(int i = 1 ; i <= n ; i++){
      for(auto it : graph[i]){
          int u = i , v = it.fi , w = it.se;
          u = par[u] ; v = par[v];
          if(u!=v)adj[u].insert({v,w});
      }
   }
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}