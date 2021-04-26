#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> graph[100100];
#define mod 1000000007


void solver()
{
  int n;
  cin >> n ;
  string s;
  cin >> s;
  int start = 0 , end = 0;
  for(int i = 0 ; i < n ; i++){
    if(s[i]=='0'){
      start++;
    }else{
      break;
    }
  }
  for(int i = n-1 ; i >= 0 ; i--){
    if(s[i]=='1'){
      end++;
    }else{
      break;
    }
  }
  for(int i = 0 ; i < start ; i++){
    cout << 0;
  }
  if(start + end < n){
    cout << 0;
  }
  for(int i = 0 ; i < end ; i++ ){
    cout << 1;
  }
  cout << endl;
}


signed main()
{
    cin.tie(NULL), ios_base::sync_with_stdio(false), cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
      solver();
    }

    return 0;
}