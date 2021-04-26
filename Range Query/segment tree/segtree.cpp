#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
typedef double D;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e6 + 5;
int seg[4*N],a[N];

int gcd(int a, int b){
  if(a == 0)return b;
  return gcd(b%a, a);
}

void build(int ind , int low , int high){
    if(low == high){
         seg[ind] = a[low];
         return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = gcd(seg[2*ind+1],seg[2*ind+2]);
}

void pointupdate(int ind , int low , int high , int l, int r ,  int val){
    if(low >= l && high <= r){
      seg[ind] = val; return ;
    }
    if(low > r || high < l || low > high)return ;
    int mid = (low + high)/2;
    pointupdate(2*ind+1,low,mid,l,r,val);
    pointupdate(2*ind+2,mid+1,high,l,r,val);
    seg[ind] = gcd(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind, int low , int high, int l , int r){
    if(low >= l && high <= r){
        return seg[ind];
    }
    if(low > r || high < l){
        return 0;
    }
    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return gcd(left,right);
}
