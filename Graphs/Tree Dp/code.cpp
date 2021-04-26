#include <bits/stdc++.h>
using namespace std;
const long long MOD //= 998244353; 
               = 1e9 + 7;
typedef long long ll;
// #define INF 1e18 + 0
// #define f first
// #define s second
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const ll N = 1e7 + 10;
const ll INF = 1e18 + 0;
typedef long double D;
vector<ll> graph[200010];
ll nodes[N],subtree[N],f[N];

void preprocess(ll s , ll p , ll n){
    nodes[s] = 1;
    ll sub = 0;
    for(auto i : graph[s]){
        if(i == p) continue;
        preprocess(i,s,n);
        nodes[s] += nodes[i];
        sub      += (subtree[i] + nodes[i]);
    }
    subtree[s] = sub;
}

void dfs(ll s, ll p , ll par , ll n){
   f[s] = subtree[s] + (par + (n-nodes[s]));
   for(auto i : graph[s]){
       if(i != p){
           dfs(i,s,f[s]-(subtree[i]+nodes[i]),n);
       }
   }
}

void go(){ 
   ll n ; cin >> n ;
   for(int i = 0 ; i < n -1; i++){
       ll u , v; cin >> u >> v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }
   memset(nodes,0,sizeof(nodes)); memset(subtree,0,sizeof(subtree));
   memset(f,0,sizeof(f));
   preprocess(1,0,n);
   dfs(1,0,0,n);
//    ll sum = 0;
   for(int i = 1 ; i<= n ; i++){
    //    sum += f[i];
    cout << f[i] << " " ;
   }
//    cout << sum 
}

int main() {
        NeedForSpeed
        int t = 1;
        // cout << fixed << setprecision(6) ;
        // cin >> t;
        while(t--){
            go();
        }

}


   	 			 		   	 		 						 	  		