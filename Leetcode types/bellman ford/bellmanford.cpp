#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

class Edge{
    public :
    int src , dest , weight;
    Edge(){

    }
    Edge(int src , int dest , int weight){
       src = src;
       dest = dest;
       weight = weight;
    }
};

void go(){
    int n;
    cin >> n;
    int e;
    cin >> e;
    Edge * edges = new Edge[e];
    for(int i = 0 ; i < e ; i++){
        int x, y ,w;
        cin >> x >> y >> w;
        edges[i].src = x;
        edges[i].dest = y;
        edges[i].weight = w;
    }
    int dist[110];
    for(int i = 0 ; i < n ; i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    for(int i = 0 ; i < n-1 ; i++){
        for(int i = 0 ;i < e ; i++){
            int u = edges[i].src;
            int v = edges[i].dest;
            int w = edges[i].weight;
            if(dist[u]==INT_MAX){
                continue;
            }
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i = 0 ; i < e ; i++){
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if(dist[v] > dist[u] + w){
            cout << "NEGATIVE CYCLE" << endl;
            return;
        }
    }
    for(int i = 0 ;i < n ; i++){
        cout << dist[i] << " " ;
    }
    cout << endl;
}


int main() {
        NeedForSpeed
        go();
}


   	 			 		   	 		 						 	  		