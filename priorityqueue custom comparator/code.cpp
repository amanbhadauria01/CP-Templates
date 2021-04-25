#include <bits/stdc++.h>
using namespace std;
const long long MOD //= 998244353; 
              = 1e9 + 7;
typedef long long ll;
typedef long double D;
#define INF 1e18 + 0
// #define fi first
// #define se second
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1000001;
const D pi  = 22.0 / 7.0 ;
vector<pair<ll,ll>> graph[200100];
ll dist[N][4];
bool visited[N][4];
class c{
    public : 
    ll d,u,f;

};

struct cmp{
  bool operator() (c a, c b){
      return a.d > b.d ;
  }
};

void go(){ 
    
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