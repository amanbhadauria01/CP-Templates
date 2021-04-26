#include <bits/stdc++.h>
  using namespace std;
  typedef long long int ll;
  vector<int> graph[100100];
  #define mod 1000000007
  ll nCr[1001][1001];
  void filler(int p){
      memset(nCr,0,sizeof(nCr));
      nCr[0][0] = 1;
      for(int i = 1 ; i <= p ; i++){
          nCr[i][0] = 1;
          for(int j = 1 ; j <= p ; j++){
              nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
              nCr[i][j] = nCr[i][j]%p;
          }
      }
  }

  ll ncr(int n, int r, int p){
      if(n < r){
          return 0;
      }
      if(n==r){
          return 1;
      }
      if(r==1){
          return n;
      }
      return nCr[n][r];
  }

  ll go(int n , int r, int p){
      if(r==0){
          return 1;
      }
      return (go(n/p,r/p,p)*ncr(n%p,r%p,p))%p;
  }

  void solver(){
      int n , r , p ;
      cin >> n >> r >> p;
      filler(p);
      cout << go(n,r,p) << endl;
  }

  signed main()
  {
      cin.tie(NULL), ios_base::sync_with_stdio(false), cout.tie(NULL);
        solver();

      return 0;
  }