#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
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
int n  ;
string s ;
int dp[N] = {0} , pre[N] = {0}; 

int sum(int l , int r){
    if(r<0)return 0 ;
    if(r<l)return 0 ;  
    return pre[r] - (l-1>=0 ? pre[l-1] : 0) ; 
}

// this code is for finding distinct subsequences 
// where no two adjacent elements are taken
void go(){
   cin >> s ;
   n = s.size() ; 
   // we need to find no of distinct subsequences 
   // where we wont take adjacent elements
   // our dp[i] means no of distinct subsequences where last char is s[i]
   vector<int> prev(26,-1);
   dp[0] = 1 ; 
   pre[0]= 1 ;
   dp[1] = 1 ;
   pre[1]= 2 ;  
   prev[s[0]-'a'] = 1 ;
   for(int i = 2 ; i <= n ; i++){
       int r = i-2;
       int l = 0;
       if(prev[s[i-1]-'a']!=-1)l = prev[s[i-1]-'a'];
       dp[i] += sum(l,r);
       prev[s[i-1]-'a'] = i ; 
       pre[i] = pre[i-1] + dp[i];
       pre[i] %= MOD ; pre[i] += MOD ; pre[i] %= MOD;
       dp[i] %= MOD ; dp[i] += MOD ; dp[i] %= MOD;
   }
   int res = pre[n] ; 
   res-- ; 
   res+= MOD ; res %= MOD; 
   cout << res << endl;
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