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
const int N = 1e6 + 10;
int fen[N] ; 
int n ; 

void add(int i , int val){
    while(i < 4*n){
        fen[i] += val; 
        i      += (i&(-i));
    }
}

int sum(int i){
    int s = 0 ; 
    while(i>0){
        s += fen[i];
        i -= (i&(-i));
    }
    return s ;
}

void solve(){
    static int cases = 1 ; 
    string s , t ; 
    cin >> n >> s >> t ;
    cases++;
    deque<int> dq[26];
    for(int i = 0 ; i < 4*n ; i++)fen[i] = 0 ;
    for(int i = 0 ; i < n ; i++){
        dq[s[i]-'a'].push_back(i);
    }
    for(int j = 0 ; j < 26 ; j++)dq[j].push_back(inf);
    int res = inf ; 
    int extra = 0 ;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < (int)(t[i]-'a') ; j++){
            if(dq[j].front() == inf)continue ; 
            int pos = dq[j].front() + sum(dq[j].front()+1) ; 
            res = min(res,pos - i + extra);
        }
        if(dq[t[i]-'a'].front() == inf)break;
        int pos = dq[t[i]-'a'].front() + sum(dq[t[i]-'a'].front() + 1);
        extra += pos - i ;
        add(1,1);
        add(dq[t[i]-'a'].front()+1,-1);
        dq[t[i]-'a'].pop_front();
    }
    if(res == inf)res = -1;
    cout << res << endl;
} 

signed main() {
        FIO
        int t = 1;
        cin >> t;
        while(t--){
            solve();
        }

}