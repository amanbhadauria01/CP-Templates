#include <bits/stdc++.h>
using namespace std;
typedef long long int int;
#define mod 1000000007
const int N = 1000010;


void update(int i , int add){
    while(i < N ){
        fen[i] += add;
        i += (i&(-i));
    }
}
int sum(int i){
    int s = 0;
    while(i>0){
        s+= fen[i];
        i-= (i&(-i));
    }
    return s;
}

int find(int k) {
    int curr = 0, ans = 0, prevsum = 0;
    for (int i = 19; i >= 0; i--) {
        if ((curr + (1 << i)) < N && fen[curr + (1 << i)] + prevsum < k) {
            ans = curr + (1 << i);
            curr = ans;
            prevsum += fen[curr];
        }
    }
 
    return (ans + 1);
}


int range(int l, int r){
    return sum(r)-sum(l-1);
}
// calculates lowerbound index for prefix sum array , smjhe naa ??
int lowerbound(int k){
    // curr is index 
   int curr = 0 , ans = 0 , prevsum = 0;
//    cout << curr << ",";
   for(int i = 19; i>=0 ; i--){
      if(curr + (1<<i) < n)
       if((fen[curr + (1<<i)] + prevsum) < k){
        //    cout << "fencurr " << curr + (1<<i) << " " <<  fen[curr + (1<<i)] << " " << fen[curr + (1<<i)] + prevsum << "  , " << k << endl;
            // cout << fen[curr + (i)]
           curr = curr + (1<<i);
        //    cout << curr << ",";
           prevsum += fen[curr];
       }
   }
   return (curr + 1);
}

void go()
{  
    cin >> n; 
    // cout << 2 << endl;
    for(int i = 1 ; i < n ; i++){
        // cout << 3 << endl;
        update(i,i);
        // cout << 4 << endl;
    }
    int q;
    cin >> q;
    // cout << 1 << endl;
    // if(fen[64] < 4){
    //     cout << "yes" << endl;
    // }
    // for(int i = 1 ; i < n ; i++){
    //     cout << sum(i) << " ";
    // }
    while(q--){
        int x;
        cin >> x;
        // cout << "fen : ";
        // cout << fen[64] << endl;
        cout << lowerbound(x) << endl;
        cout << find(x) << endl;
    }  

}

signed main()
{
    cin.tie(NUint), ios_base::sync_with_stdio(false), cout.tie(NUint);
    int t;
    cin >> t;
    while(t--)
    go();

    return 0;
}