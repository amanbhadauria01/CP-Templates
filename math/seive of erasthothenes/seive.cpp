#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long int ll;
typedef double D;
#define INF 1000000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
ll const N = 2e7 + 10;
bool prime[N];
int tp[N];

void filler(){
  memset(prime,true,sizeof(prime));
  for(int i = 2;  i*i < N; i++){
      if(prime[i]==true){
          for(int p = i*i ; p < N ; p += i ){
             prime[p] = false; 
          }
      }
  }
}
