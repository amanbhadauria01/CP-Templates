#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int INF = 1e12;
const int N = 2e5 + 10;
int nxt[N] = {0},ans = 1;
int n ,q ;
void filler(){
  nxt[1] = 1 ;
   for(int i = 2 ; i*i < N ; i++){
     if(nxt[i] == 0)
     {
       nxt[i] = i; 
      for(int j = i*i ; j < N ; j += i){
       nxt[j] = i;
      }
     }
   }
   for(int i = 0 ; i < N ; i++)if(nxt[i]==0)nxt[i] = i; 
}

multiset<int> v[N];
map<int,int> cnt_divisor[N];

void add(int i , int x){
    while(x != 1){
      int div = nxt[x], add = 0;
      while(nxt[x]==div)add++ , x /= div;
      int lastcnt = cnt_divisor[i][div];
      cnt_divisor[i][div] += add;
      int mn = 0;
      if((int)v[div].size() == n)mn = *v[div].begin();
      if(lastcnt)v[div].erase(v[div].find(lastcnt));
      v[div].insert(cnt_divisor[i][div]);
      if((int)v[div].size() == n)
      for(int j = mn + 1 ; j <= *v[div].begin() ; j++){
        ans = ans*div;
        ans %= MOD; ans += MOD; ans %= MOD;
      }
    }
}

void solve(){
   cin >> n >> q ; 
   int x, i ; 
   for(i = 0 ;i < n ; i++){
     cin >> x ; add(i,x);
   }
   while(q--){
     cin >> i >> x ; i--;
     add(i,x);
     cout << ans << endl;
   }
}

signed main() {
        FIO
        int t = 1;
        filler();
        // cin >> t;
        while(t--){
            solve();
        }

}