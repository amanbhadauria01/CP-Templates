#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
typedef double D;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e5 + 9;
int seg[4*N],a[N],lazy[4*N];
void build(int ind , int low , int high){
    if(low == high){
         seg[ind] = a[low];
         return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
}

void rangeUpdate(int ind, int low , int high , int l , int r , int val){
    if(lazy[ind]!=0){
        seg[ind] += (high-low+1)*lazy[ind];
        if(low != high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    // completely outside
    if(r < low || l > high ||  low > high ) return;
    // completely inside
    if(low >= l && high <= r){
       seg[ind] += (high-low+1)*val;
       if(low != high){
           lazy[2*ind+1] += val;
           lazy[2*ind+2] += val;
       }
       return;
    }
    // rest
    int mid = (low + high)/2;
    rangeUpdate(2*ind+1,low,mid,l,r,val);
    rangeUpdate(2*ind+2,mid+1,high,l,r,val);
    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int querylazy(int ind , int low, int high, int l , int r ){
    if(lazy[ind]!=0){
        seg[ind] += (high-low+1)*lazy[ind];
        if(low != high){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    // completely outside
    if(r < low || l > high || low > high) return 0;
    // completely inside
    if(l <= low && high <= r) return seg[ind];
    // rest
    int mid = (low+high)/2;
    return querylazy(2*ind+1,low,mid,l,r) + querylazy(2*ind+2,mid+1,high,l,r);
}

