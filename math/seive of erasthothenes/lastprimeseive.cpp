#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define D long double
#define FIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int MOD = 1000000007;
#define fi first
#define se second
#define endl '\n'
const int INF = 1e12;
const int N = 2e5 + 10;

// val is storing number of unique prime factors
int last[N] = {0};
int val[N] = {0};
void filler(){
  last[1] = 1 ;
   for(int i = 2 ; i*i < N ; i++){
     if(last[i] == 0)
     {
       last[i] = i; 
      for(int j = i*i ; j < N ; j += i){
       last[j] = i;
      }
     }
   }
   for(int i = 0 ; i < N ; i++)if(last[i]==0)last[i] = i; 
   for(int i = 2 ; i < N ; i++){
       int j = i/last[i];
       val[i] = val[j] + (last[i] != last[j]);
   }   
}
