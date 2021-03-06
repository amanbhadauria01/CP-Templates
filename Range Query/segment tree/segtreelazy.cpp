#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
typedef double D;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1e5 + 9;
int seg[4*N],lazy[4*N];

// this segment tree adds values for a range and finds max of a range

int fun(int a, int b){
    return max(a,b);
}

void build(int ind , int low , int high){
    if(low>high)return ;
    if(low == high){
         seg[ind] = a[low];
         return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind] = fun(seg[2*ind+1],seg[2*ind+2]);
}

void rangeUpdate(int ind, int low , int high , int l , int r , int val){
    if(low>high)return ;
    if(lazy[ind]!=0){
        seg[ind] += lazy[ind];
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
       seg[ind] += val;
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
    seg[ind] = fun(seg[2*ind+1],seg[2*ind+2]);
}

int querylazy(int ind , int low, int high, int l , int r ){
    if(low>high)return 0;
    if(lazy[ind]!=0){
        seg[ind] += lazy[ind];
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
    return fun(querylazy(2*ind+1,low,mid,l,r),querylazy(2*ind+2,mid+1,high,l,r));
}

void update(int l , int r , int val){
    assert(n-1>=0);
    rangeUpdate(0,0,n-1,l,r,val);
}

int query(int l , int r){
    assert(n-1>=0);
    return querylazy(0,0,n-1,l,r);
}
