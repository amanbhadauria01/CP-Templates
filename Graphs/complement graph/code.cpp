#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 1e6 + 10;
int n , m , k; 
vector<int> graph[N];

int r[N] , p[N];

int findd(int x){
    if(x==p[x])return x;
    return p[x] = findd(p[x]);
}

bool joinn(int u , int v){
    u = findd(u); v = findd(v);
    if(u!=v){
        if(r[u]>r[v])swap(u,v);
        r[u] += r[v];
        p[v] = u; 
    }
    return 0;
}

void solve(){
   cin >> n >> m  ; 
   for(int i = 1 ; i <= n ; i++)p[i] = i , r[i] = 1;
   for(int i = 0 ; i < m ; i++){
       int u ,v  ; cin>> u >> v ; 
       graph[u].push_back(v); graph[v].push_back(u);
   }
   set<int> components;
   for(int i = 1; i <= n ; i++)components.insert(i);
   for(int i = 1; i <= n ; i++){
       map<int,int> m ; 
       for(auto v : graph[i]){
           int par = findd(v);
           m[par]++;
       }
       vector<int> toerase;
       for(auto j : components){
           int par = findd(j);
           if(m[par]<r[par])joinn(par,i) , toerase.push_back(j);
       }
       toerase.push_back(i);
       int par = findd(i);
       for(auto j : toerase)components.erase(j);
       components.insert(par);
   }
   cout << components.size() << endl; 
   vector<int> sz;
   for(int i = 1 ; i <= n ; i++){
       int par = findd(i);
       if(par==i)sz.push_back(r[i]);
   } 
   sort(sz.begin(),sz.end());
   for(auto i : sz)cout << i << " "; cout << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}