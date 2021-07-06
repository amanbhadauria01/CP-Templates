const int N = 1e5+10;
bool vis[N],special[N];
int low[N],child[N];
int tim = 0 , othertime[N],par[N];
vector<int> graph[N];
#define fi first
#define se second

void dfs(int u){
    vis[u] = 1;
    low[u] = tim ; 
    othertime[u] = tim;
    tim++;
    for(auto v : graph[u]){
        if(vis[v]==0){
            child[u]++;
            par[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(par[u]!=-1 && low[v]>=othertime[u])special[u] = 1;
            if(par[u]==-1 && child[u]>1)special[u] = 1;
        }else{
            if(v!=par[u])low[u]=min(low[v],low[u]);
        }
    }
}

int doctorStrange(int n, int m, vector<vector<int>> & g)
{
    // initialization and graph making
    for(int i = 0 ; i <= n ; i++)vis[i] = 0 , special[i] = 0 , low[i] = 0 , child[i] = 0,othertime[i] = 0;
    for(int i = 0 ; i <= n ; i++)graph[i].clear()  , par[i] = -1;
    for(auto p : g)if(p.size()>1)graph[p[1]].push_back(p[0]) , graph[p[0]].push_back(p[1]);
    // algo starts
    tim = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(vis[i]==0)dfs(i);
    }
    int cnt = 0;
    for(int i = 1 ; i <= n ; i++)cnt += special[i];
    return cnt;
}