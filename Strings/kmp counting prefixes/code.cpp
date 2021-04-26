#include <bits/stdc++.h>
using namespace std;
const long long MOD //= 998244353; 
              = 1e9 + 7;
typedef long long int ll;
typedef long double D;
#define INF 1e18 + 0
// #define fi first
// #define se second
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1000001;
const D pi  = 22.0 / 7.0 ;
ll lps[N];
ll c[N];

// lps filler
void filler(string &s){
    ll n = s.size();
    for(ll i = 1 ; i < n ; i++){
       ll j = lps[i-1];
       while( j > 0 && s[i]!=s[j]) j = lps[j-1];
       if(s[i]==s[j]) j++;
       lps[i] = j;
    }
}

void go(){
  string s; cin >> s;
  ll n = s.size();
  memset(lps,0,sizeof(lps));
  memset(c,0,sizeof(c));
  filler(s);
  // counting no of times each prefix occurs

  // count of prefix which is also a suffix
  for(int i = 0   ;i < n ; i++) c[lps[i]]++;
  // as the prefixes which were also a suffix in the above prefixes were not counted above counting them 
  // for each i adding its ans to its longest prefix which was also a suffix
  for(int i = n-1 ; i >= 0 ; i--) c[lps[i-1]] += c[i];
  // now counting each prefix original
  for(int i= 1   ; i <=  n ; i++) c[i]++;

   vector<ll> v;
   v.push_back(n);
   ll j = lps[n-1];
   while(j > 0){
       v.push_back(j);
       j = lps[j-1];
   }
   reverse(v.begin(),v.end());
   cout << v.size() << endl;
   for(auto i : v) cout << i << " " << c[i] << endl; 
}  

int main() {
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(9) ;
        // cin >> t;
        while(t--){
            go();
        }

}