#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
typedef double D;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
string graph[100];
ll n , m;
ll mover[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
bool visited[60][60];

bool bfsisCycle(ll i , ll j){
   queue<pair< pair<ll,ll>,pair<ll,ll> > > q;
   q.push({{i,j},{-1,-1}});
   visited[i][j] = true;
   while(!q.empty()){
     pair<ll,ll> u = q.front().first;
     pair<ll,ll> p = q.front().second;
     q.pop();
     for(int i = 0 ;i < 4 ; i++){
       ll x = mover[i][0] + u.first;
       ll y = mover[i][1] + u.second;
       if(x < 0 || x == n || y < 0 || y == m){
         continue;
       }
       if(x == p.first && y == p.second){
         continue;
       }
       if(graph[u.first][u.second] != graph[x][y]){
         continue;
       }
       if(visited[x][y]){
         return true;
       }
       q.push({{x,y},{u.first,u.second}});
       visited[x][y] = true;
     }
   }
   return false;
}

void go()
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    cin >> graph[i];
  }
  memset(visited,false,sizeof(visited));
  for(int i = 0 ; i < n; i++){
    for(int j = 0 ; j < m ; j++){
      if(!visited[i][j]){
        bool ans = bfsisCycle(i,j);
        if(ans){
          cout << "Yes" << endl;
          return;
        }
      }
    }
  }
  cout << "No" << endl;
}


int main()
{
  NeedForSpeed int t = 1;
  // cin >> t;
  while (t--)
    go();
}
