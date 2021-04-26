  #include <bits/stdc++.h>
  using namespace std;
  typedef long long int ll;
  vector<int> graph[100100];
  #define mod 1000000007
  ll num[1001000], rem[1001000];


  void update(ll & temp, ll vecif , ll vecis ){
      temp = vecis;
      if(vecif < vecis){
        temp = vecif;
      }
  }

 void euclid(ll a, ll b ,ll & x, ll & y){
      if(a==1){
          x=1;
          y=0;
          return;
      }
      ll x1 , y1;
      euclid(b%a,a,x1,y1);
      y = x1;
      x = y1 - (b/a)*x1;
  }

  ll inv(ll pp , ll num){
     ll x, y ;
     euclid(pp,num,x,y);
     return x;
  }
  void go(int n , ll prod , ll & result){
      result = 0;
      for(int i = 0 ; i < n ; i++){
          ll pp = prod/num[i];
          result += (rem[i])*inv(pp,num[i])*pp;
      }
      while(result < 0){
          result += prod;
      } 
      result = result%prod;
      cout << result << endl;
  }
  void solver(){
     int n;
     cin >> n;
     for(int i = 0 ; i< n ; i++){
         cin >> num[i];
     }
     for(int i = 0 ; i < n ; i++){
         cin >> rem[i];
     }
     ll prod = 1;
     for(int i = 0 ; i< n ; i++){
         prod *= num[i];
     }
     ll result = 0;
     go(n,prod,result);
  }

  signed main()
  {
      cin.tie(NULL), ios_base::sync_with_stdio(false), cout.tie(NULL);
      // int t;
      // cin >> t;
      // while(1){
        solver();
      // }

      return 0;
  }