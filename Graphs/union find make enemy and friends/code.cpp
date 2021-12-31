#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e18;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int N = 2e2 + 10;
int n , m ;
int a[201][201];
int p[2*N] , e[2*N] , r[2*N]; 
bool ok;

int findd(int x){
    if(x==-1)return -1;
    if(x==p[x])return x;
    return p[x] = findd(p[x]);
}

bool joinn(int u , int v){
    u = findd(u) ; v = findd(v);
    int eU = findd(e[u]) , eV = findd(e[v]);
    // here we are making u and v friends
    // hence enemy of u cant be friend of v 
    // enemy of v cant be friend of u    
    if(eU == v || eV == u){
        ok = 0;
        return 0;
    }
    // and enemy of u and enemy of v must be friends
    if(eU!= -1 && eU != eV)joinn(eU,eV);
    if(u!=v){
        if(u>v)swap(u,v);
        r[u] += r[v];
        p[v] = u;
        return 1;
    } 
    return 1;
}

bool makeEnemy(int u , int v){
    u = findd(u) ; v = findd(v);
    int eU = findd(e[u]) , eV = findd(e[v]);
    // here we are making u and v enemy
    // hence enemy of u and v should be enemy
    if(eU != -1 && eU == eV){
        ok = 0;
        return 0 ;
    }
    // and enemy of u and enemy of v should be enemies
    if(eU != -1 && eU !=eV)makeEnemy(eU,eV);
    e[u] = v ;
    e[v] = u ; 
    return 1;
}

bool isfriends(int u , int v){
   u = findd(u) ; v = findd(v);
   if(u!=v)return 0;
   return 1;
}

void solve(){
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < m ; j++)
        cin >> a[i][j];
    for(int k = 1 ; k <= 1 ; k++){    
        for(int i = 0 ; i < n+m ; i++)p[i] = i , e[i] = -1 , r[i] = 1;
        ok = 1 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i*m+j<k){
                    if(a[i][j]==1)makeEnemy(i,n+j);
                    else          joinn(i,n+j);
                }else{
                    if(a[i][j]==1)joinn(i,n+j);
                    else          makeEnemy(i,n+j);
                }
            }
        }
        if(!ok)continue;
        cout << "YES\n";
        for(int i = 0 ; i < n ; i++){
            if(isfriends(i,0))cout << 0 ;
            else cout << 1 ;
        }
        cout << endl;
        for(int i = n ; i < n+m ; i++){
            if(isfriends(i,0))cout << 0 ;
            else cout << 1 ; 
        }
        cout << endl;
        return ;
    }
    cout << "NO\n";    
}
 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}