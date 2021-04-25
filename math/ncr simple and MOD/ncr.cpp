#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define MOD 998244353
#define fi first
#define se second
#define inf 1e18 
const int N = 1e6 + 10;
// random_device rd;
// mt19937 rng(rd());
// int getRand(int l,int r){ // get random number in the range [l,r]
//   uniform_int_distribution<int> uid(l,r);
//   return uid(rng);
// }

int power[65];
int C[100][100];

void filler(){
    memset(C,0,sizeof(C));
    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j <= i ; j++){
            if(j==0 || j == i) C[i][j] = 1;
            else               C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}