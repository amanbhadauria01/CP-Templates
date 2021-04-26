#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
typedef double D;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll p[1000],r[1000],x[1000],y[1000];
class edge{
  public : 
  ll x,y,w;
};
edge E[755*755];
bool compare(edge a, edge b){
  return a.w < b.w;
}
void init(int n){
  for(int i = 0 ;i <= n ;i++){
     p[i] = i; r[i] = 1;
  }
}

ll findP(ll x){
  if(x==p[x]){
    return x;
  }
  return p[x] = findP(p[x]);
}

ll joint(ll x, ll y){
  x = findP(x); y = findP(y);
  if(x != y){
    if(r[x] > r[y]){
      r[x] += r[y] ; p[y]= x;
    }else{
      r[y] += r[x] ; p[x] = y;
    }
    return 1;
  }
  return 0;
}

void go(){
  ll n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    cin >> x[i] >> y[i];
  }
  init(n);
  ll m;
  cin >> m;
  ll cnt = 0;
  while(m--){
    ll a , b;
    cin >> a >> b;
    cnt += joint(a,b);
  }
  // cout <<"J" << endl;
  if(cnt == n-1){
    cout <<"No new highways need" << endl;
  }else{
    m = 0;
    for(int i =1 ; i <= n;  i++){
      for(int j = i+1 ; j <= n ; j++){
        E[m].x = i ; E[m].y = j;
        E[m].w = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
        m++;
      }
    }
  }
  sort(E,E+m,compare);
  for(int i = 0 ; i < m ; i++){
    if(joint(E[i].x,E[i].y)){
      cout << E[i].x << " " << E[i].y << endl;
    }
  }
  // cout<<"K" << endl;
}

int main() {
        NeedForSpeed
        int t;
        cin >> t;
        while(t--)
        go();

}


   	 			 		   	 		 						 	  		