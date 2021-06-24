#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
// const int inf = 1e18;
// #define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }
const int N = 2e5 + 10;
int n , q ;
const int LOGN = 32;
int jmp[N][LOGN];
bool vis[N] = {0};
int len[N] = {0};


// this code works for only those graphs which have only one edge going out of each node

void dfs(int u){
    if(vis[u])return ;
    vis[u] = 1;
    dfs(jmp[u][0]);
    len[u] = len[jmp[u][0]]+1;
}

int lift(int x, int d){
    if(d<=0)return x;
    for(int j = LOGN - 1; j >= 0 ; j--){
        if((1LL<<j) <= d){
            x = jmp[x][j];
            d -= (1LL<<j);
        }
    }
    return x;
}

void go(){
  cin >> n >> q ; 
  for(int i = 1 ; i <= n ; i++){
      cin >> jmp[i][0];
  }
  for(int j = 1 ; j < LOGN ; j++){
      for(int i = 1 ; i <= n ; i++){
          jmp[i][j] = jmp[jmp[i][j-1]][j-1];
      } 
  }
  for(int i = 1 ; i <= n ; i++)
     if(!vis[i])dfs(i); 

  while(q--){
     int x,y;
     cin >> x >> y;
     int xx = lift(x,len[x]);
     if(lift(x,len[x]-len[y])==y){
         cout << len[x]-len[y] << endl;
     }else if(lift(xx,len[xx]-len[y])==y){
         cout << len[x] + len[xx] - len[y] << endl;
     }else{
         cout << -1 << endl;
     }
  }
} 

signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        // cin >> t;
        while(t--){
            // cout << "Case #" << cases << ": ";
            go();
        }

}