#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e12;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 998244353 ;
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 10;
int n,q,a[N];
const int LOGN = 18;
int dp[N][LOGN];
int last[N] = {0};
int idx[N] = {0};
int power[60];

/// it is problem D of round 717 Div 2 codeforces

void filler(){
  power[0] = 1;
  for(int i = 1 ; i < 60 ; i++)power[i] = power[i-1]*2;  
  last[1] = 1 ;
   for(int i = 2 ; i*i < N ; i++){
     if(last[i] == 0)
     {
       last[i] = i; 
      for(int j = i*i ; j < N ; j += i){
       last[j] = i;
      }
     }
   }
   for(int i = 0 ; i < N ; i++)if(last[i]==0)last[i] = i; 
}


void solve(){
   filler(); 
   cin >> n >> q ;
   for(int i = 0 ; i < n ; i++)cin >> a[i];
   for(int i = 0 ; i < N ; i++)idx[i] = n ;
   for(int j = 0 ; j < LOGN  ; j++)dp[n][j] = n ;
   for(int i = n-1 ; i >= 0 ; i--){
       set<int> primes;
       int x = a[i];
       while(x>1){
           primes.insert(last[x]);
           x /= last[x];
       }
       int mnidx = n ;
       for(auto p : primes)mnidx = min(mnidx,idx[p]);
       for(auto p : primes)idx[p] = i;
       mnidx = min(dp[i+1][0],mnidx);
       dp[i][0] = mnidx;    
   }
   for(int j = 1 ; j < LOGN ; j++){
       for(int i = 0 ; i < n ; i++){
           dp[i][j] = dp[dp[i][j-1]][j-1];
       }
   }
   for(int i = 0 ; i < q ; i++){
       int l , r ; cin >> l >> r ; l--; r--; 
       int cur = l , cnt = 0;
       if(dp[cur][0]>r){
           cout << 1 << endl; continue;
       }
       for(int j = LOGN-1 ; j >= 0 ; j--){
           if(dp[cur][j]<=r){
               cur = dp[cur][j];
               cnt += power[j];
           }
       }
       cout << cnt + 1 << endl;
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

