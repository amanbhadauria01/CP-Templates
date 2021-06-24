#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e8;
#define D long double
const long double pi = 3.141592653589793238;
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int MOD = 998244353;
#define fi first
#define se second
#define endl '\n'
const int N = 3e5 + 10;
int n , m ;

// fn = fn-1 + fn-2

// 1 1 || fn    ==  fn+1
// 1 0 || fn-1  ==  fn 


vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> res = {{0,0},{0,0}};
    int n = a.size();
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++)
            res[i][j] += a[i][k] * b[k][j]; 
            res[i][j] %= MOD ; res[i][j] += MOD ; res[i][j] %= MOD;
        }
    }
    return res;
}

vector<vector<int>> power(vector<vector<int>> mat , int b){
    vector<vector<int>> res = {{1,0},{0,1}};
    if(b==0){
        return res;
    }
    vector<vector<int>> temp = power(mat,b/2);
    res = mul(temp,temp);
    if(b%2)res = mul(res,mat);
    return res;
}

void print(vector<vector<int>> mat){
    int n = mat.size();
    for(int i = 0 ; i < 2 ; i++){
      for(int j = 0 ; j < 2 ; j++)
        cout << mat[i][j] << " " ; cout << endl;  }
        cout << endl;
}

void solve(){
    cin >> n ;
    vector<vector<int>> mat = {{1,1},{1,0}};
    vector<vector<int>> res = power(mat,n-1);
    cout << res[0][0] << endl;
} 

signed main() {
        FIO
        int t = 1;
        // cin >> t;
        while(t--){
            solve();
        }

}