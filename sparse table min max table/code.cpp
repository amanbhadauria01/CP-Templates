#include <bits/stdc++.h>
using namespace std;
// #define int long long 
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define MOD 1000000007
#define fi first
#define se second
#define inf 1e9 
const int N = 2e5 + 10;
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }

int a[N],b[N];
pair<int,int> seg[N];
const int K = 20;
int Log[N],stMin[N][K+1],stMax[N][K+1];


void filler(int n){
  Log[1] = 0;
  for(int i = 2 ; i < N ; i++)Log[i] = Log[i/2] + 1;

  for(int i = 0 ; i < n ; i++){
    stMin[i][0] = b[i];
    stMax[i][0] = a[i];
  }
  for(int j = 1 ; j <= K ; j++){
    for(int i = 0 ; i + (1<<j) <= n ; i++){
       stMin[i][j] = min(stMin[i][j-1],stMin[i + (1<< (j-1))][j-1]);
       stMax[i][j] = max(stMax[i][j-1],stMax[i + (1<< (j-1))][j-1]);
    }
  }
}

int queryMin(int l , int r){
  int j = Log[r-l+1];
  return min(stMin[l][j],stMin[r-(1<<j)+1][j]);
}
int queryMax(int l , int r){
  int j = Log[r-l+1];
  return max(stMax[l][j],stMax[r-(1<<j)+1][j]);
}

int bs1(int i , int n){
   int l = i, r = n-1;
   int ans = -1;
   while(l <= r){
      int mid = (l + r) / 2;
      pair<int,int> p = {queryMax(i,mid),queryMin(i,mid)};
      int diff = p.fi - p.se ; 
      if(diff == 0){
        ans = mid;
      }
      if(diff < 0){
        l = mid+1;
      }else if(diff >= 0){
        r = mid-1;
      }
   }
   return ans;
}

int bs2(int i , int n){
  int l = i , r = n-1;
  int ans = -1;
  while(l <= r){
    int mid = (l + r ) / 2;
    pair<int,int> p = {queryMax(i,mid),queryMin(i,mid)};
    int diff = p.fi - p.se;
    if(diff== 0){
      ans = mid;
    }
    if(diff <= 0){
      l = mid+1;
    }else{
      r = mid-1;
    }
  }
  return ans;
}


void go(){
  int n ; cin >> n ; 
  for(int i = 0 ; i < n ; i++)cin >> a[i];
  for(int i = 0 ; i < n ; i++)cin >> b[i];

  
  filler(n);
  long long int ans = 0;
  for(int i = 0 ; i < n ; i++){
    int r1 = bs1(i,n);
    int r2 = bs2(i,n);
    // cout << r1 << " " << r2 << " ," ;
    if(r1 != -1 && r2 != -1)
    ans += r2-r1+1;
  }   
  cout << ans;

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