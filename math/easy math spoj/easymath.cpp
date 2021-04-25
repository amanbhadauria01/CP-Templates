#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll const N = 1e7+10;
ll size=5;
ll a[20];

ll gcd(ll a, ll b){
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

ll l(ll a, ll b){
    return (a*b)/gcd(a,b);
}

ll go(ll i , ll cnt , ll n , ll lcm)
{
   if(i == size){
       if(cnt%2 != 0) return -1*(n/lcm);
       else return n/lcm;
   } 
   ll ans = go(i+1,cnt+1,n,l(lcm,a[i]));
   ans += go(i+1,cnt,n,lcm);
   return ans;
}

void solve(){
  int n , m;  
  while(cin >> n >> m){
      for(int i = 0 ; i < m ; i++){
          cin >> a[i];
      }
      size = m;
      cout << go(0,0,n,1) << endl;
  }
}

int main()
{
    NeedForSpeed ll t = 1;
    // cin >> t;
    while(t--)
        solve();
}