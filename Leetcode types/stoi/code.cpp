#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> graph[100100];
#define mod 1000000007


void solver()
{
  string s;
  cin >> s;
  ll ans = 0;
  int size = s.size();
  for(int i = 0 ; i < size ; i++){
    ans = ans*10 + s[i]-'0';
  }
  cout << ans;
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