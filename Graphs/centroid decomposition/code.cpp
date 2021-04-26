#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int inf = 1e18;
const int N = 1e6 + 10;
int n; 
set<int> graph[N];
int ans[N];
int nodes;
int subtree[N];

int dfs(int u , int p){
  subtree[u] = 1; nodes++;
  for(auto i : graph[u]){
    if(i==p)continue;
    subtree[u] += dfs(i,u);
  }
  return subtree[u];
}

int centroid(int u , int p){
   for(auto i : graph[u]){
     if(i==p)continue;
     if(subtree[i]> (nodes/2))return centroid(i,u);
   }
   return u;
}

void decompose(int u , int val){
   nodes = 0;
   dfs(u,u);
   int k = centroid(u,u);
   ans[k] = val;
   for(auto i : graph[k]){
      graph[i].erase(k);
      decompose(i,val+1);
   }
}

void solve(){
   cin >> n ; 
   for(int i = 0 ; i < n-1 ; i++){
     int u , v ; cin >> u >> v ; 
     graph[u].insert(v); graph[v].insert(u);
   }
   decompose(1,0);
   for(int i = 1; i <= n ;i++){
     cout << (char)('A' + ans[i]) << " ";
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