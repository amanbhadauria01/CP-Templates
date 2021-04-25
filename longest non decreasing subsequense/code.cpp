#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 998244353;
#define fi first
#define se second
#define inf 2000000000000000000LL 
const int N = 1e6 + 10;
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }

int a[N];

void go(){
  int n , m ; cin >> n >> m ; 
  D xx; 
  for(int i = 0 ; i < n ; i++){
    cin >> a[i] >> xx;
  } 
  // longest non decreasing subsequence starts
  vector<int> d(n+1,INT_MAX);
  d[0] = INT_MIN;
  for(int i = 0 ; i < n ; i++){
    int j = upper_bound(d.begin(),d.end(),a[i])-d.begin();
    if(d[j-1] <= a[i] && a[i] < d[j])d[j] = a[i];
  }
  int x = 1;
  for(int i = n ; i>= 0 ; i--){
    if(d[i]!=INT_MAX){
      x = i; break;
    }
  }
  // ends
  cout << n-x ;
} 


signed main() {
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(12) ;
        // cin >> t;
        while(t--){
            go();
        }

}