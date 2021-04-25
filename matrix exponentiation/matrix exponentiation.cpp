#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

void mul(int a[3][3], int b[3][3]){
    int mul[3][3];
    for(int i = 0 ; i < 3 ; i++){
        for(int j =0 ; j < 3 ; j++){
           mul[i][j] = 0;
           for(int k = 0 ; k < 3 ; k++){
               mul[i][j] += a[i][k]*b[k][j] ;
               mul[i][j] = mul[i][j]%MOD;
           }
        }
    }
    for(int i = 0  ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            a[i][j] = mul[i][j];
        }
    }
}

int power(int F[3][3], int n){
    int M[3][3] = {{3,0,1},{1,0,0},{1,0,0}};
    if(n==1){
        return (F[0][0]*8 + F[0][1]*0 + F[0][2]*2)%MOD;
    }
    power(F,n/2);
    mul(F,F);

    if(n%2 != 0){
        mul(F,M);
    }
    return (F[0][0]*8 + F[0][1]*0 + F[0][2]*2)%MOD;
}

int findNthterm(int n){
    int F[3][3] = {{3,0,1}, {1,0,0}, {1,0,0}};
    if(n==0){
        return 0;
    }
    if(n==1){
        return 2%MOD;
    }
    if(n==2){
        return 8%MOD;
    }
    return power(F,n-2)%MOD;
}

void go()
{   
    ll n , m;
    cin >> n >> m;
    MOD = m;
    cout << findNthterm(n) << endl;
}


int main()
{
    NeedForSpeed 

    int t = 1;
    // cin >> t;
    while (t--)
        go();
}