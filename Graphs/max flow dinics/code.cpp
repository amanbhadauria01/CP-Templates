#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
const int N = 2e5 + 10;


#define vll vector<int>
struct edge {int x, y, cap, flow;};
const int inf = (1e18);
#define pb push_back

struct DinicFlow {
	// *** change inf accordingly *****
	vector <edge> e; vll cur, d;
	vector<vll> adj; int n, source, sink;
	DinicFlow() {}
	DinicFlow(int v){ n=v; cur=vll(n+1);
		d = vll(n+1); adj = vector<vll>(n+1);}
	void addEdge(int from, int to, int cap) {
		edge e1 = {from, to, cap, 0};
		edge e2 = {to, from, 0, 0}; 
		adj[from].pb(e.size()); e.pb(e1);
		adj[to].pb(e.size()); e.pb(e2); }
	int bfs(){ queue <int> q;
		for(int i = 0; i <= n; ++i) d[i] = -1;
		q.push(source); d[source] = 0;
		while(!q.empty() and d[sink] < 0) {
			int x = q.front(); q.pop();
			for(int i = 0; i < (int)adj[x].size(); ++i){
				int id = adj[x][i], y = e[id].y;
				if(d[y]<0 and e[id].flow < e[id].cap){
					q.push(y); d[y] = d[x] + 1;
		} } } return d[sink] >= 0; }
	int dfs(int x, int flow) { if(!flow) return 0;
		if(x == sink) return flow;
		for(;cur[x] < (int)adj[x].size(); ++cur[x]){
			int id = adj[x][cur[x]], y = e[id].y;
			if(d[y] != d[x] + 1) continue;
			int pushed = dfs(y,min(flow,e[id].cap-e[id].flow));
			if(pushed){ e[id].flow+=pushed; 
				e[id^1].flow -= pushed; return pushed; }
		} return 0; }
	int maxFlow(int src, int snk) {
		this->source=src;this->sink = snk; int flow=0;
		while(bfs()){ for(int i=0;i<=n;++i) cur[i]=0;
		 while(int pushed=dfs(source,inf))flow+=pushed;
		} return flow;
} };

void solve(){
  int n ; cin >> n ; 
  int a[3] , b[3];
  for(int i = 0 ; i < 3 ; i++)cin >> a[i];
  for(int i = 0 ; i < 3 ; i++)cin >> b[i];
  DinicFlow U(10);
  U.addEdge(1,2,a[0]);
  U.addEdge(1,3,a[1]);
  U.addEdge(1,4,a[2]);
  U.addEdge(5,8,b[0]);
  U.addEdge(6,8,b[1]);
  U.addEdge(7,8,b[2]);

  U.addEdge(2,7,inf);
  U.addEdge(2,5,inf);
  U.addEdge(3,6,inf);
  U.addEdge(3,5,inf);
  U.addEdge(4,7,inf);
  U.addEdge(4,6,inf);
  
  int mx = min(a[0],b[1]) + min(a[1],b[2]) + min(a[2],b[0]);
  cout << n-U.maxFlow(1,8) << " " << mx << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}