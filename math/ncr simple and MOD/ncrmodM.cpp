#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 1000000007;
#define endl '\n'
#define fi first
#define se second

const int INF = 1e12;
const int N = 1e6 + 10;

int fact[N],ifact[N];

int power(int a, int b){ 
	int x = 1, y = a; 
	while (b > 0){ 
		if (b%2){ 
			x = (x*y)%MOD; 
		} 
		y = (y*y)%MOD; 
		b /= 2; 
	} 
	return x%MOD; 
}

int ncr(int n , int r){
    if(n < r)return 0;
    int ans = fact[n];
    ans %= MOD; ans += MOD; ans %= MOD;
    ans *= ifact[n-r];
    ans %= MOD; ans += MOD; ans %= MOD;
    ans *= ifact[r];
    ans %= MOD; ans += MOD; ans %= MOD;
    return ans;
}

void filler(){
    fact[0] = 1;
    for(int i = 1 ; i < N ; i++){
        fact[i] = i*fact[i-1];
        fact[i] %= MOD; fact[i]+= MOD; fact[i] %= MOD;
    }
    ifact[N-1] = power(fact[N-1], MOD-2);
    for(int i = N-2 ; i >= 0 ; i--){
        ifact[i] = (i+1)*ifact[i+1];
        ifact[i] %= MOD; ifact[i] += MOD; ifact[i] %= MOD;
    } 
    
}

void solve(){
    filler();
    cout << power(2,MOD-2) << endl ;
    cout << ifact[2] << endl; 
}

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
              solve();
        }
}