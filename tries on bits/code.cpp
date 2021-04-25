#include <bits/stdc++.h>
using namespace std;
const long long MOD //= 998244353; 
              = 1e9 + 7;
#define int long long
typedef long double D;
#define INF 1e18 + 0
// #define fi first
// #define se second
#define pb push_back
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
const int N = 1000001;
const D pi  = 22.0 / 7.0 ;
int bit[34] = {0};
int power[34]; 
class node {
    public : 
    int lc , rc ; 
    node * left ;
    node * right;
    node (){
        lc = 0;
        rc = 0;
        left = NULL;
        right = NULL;
    }
    ~node (){
        delete this->left;
        delete this->right;
        delete this;
    }
};

void insert(node * root ){
    node * temp = root;
    for(int i = 0 ; i <= 33 ; i++){
       if(bit[i]){
           if(temp->right == NULL) temp->right = new node();
           temp->rc++;
           temp = temp->right;
       }else{
           if(temp->left == NULL ) temp->left = new node();
           temp->lc++;
           temp = temp->left;
       }
    }
}

void remove(node * root ){
    node * temp = root;
    for(int i = 0 ; i <= 33 ; i++){
        if(bit[i]){
            if(temp->right == NULL)return;
            temp->rc--;
            // if(temp->rc == 0){
            //     delete(temp->right);
            //     temp->right = NULL;
            // }
            temp = temp->right;
        }else{
            if(temp->left == NULL)return;
            temp->lc--;
            // if(temp->lc == 0){
            //     delete(temp->left);
            //     temp->left = NULL;
            // }
            temp = temp->left;
        }
    }
}

int find(node * root){
    node * temp = root;
    int ans = 0;
    for(int i = 0 ; i <= 33 ; i++){
        if(!bit[i]){ // goto 0
            if(temp->rc){
               ans += power[33-i];
               temp = temp->right;
            }else{
               temp = temp->left;
            } 
        }else{
            if(temp->lc){
                ans += power[33-i];
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
    }
    return ans;
}


void go(){
    int q ; cin >> q;
    node * tree = new node();
    power[0] = 1;
    for(int i = 1 ; i <= 33 ; i++) power[i] = 2*power[i-1];
    insert(tree);
    while(q--){
        char ch;
        int x ; 
        cin >> ch >> x ; 
        memset(bit,0,sizeof(bit));
        int i = 33;
        while(x>0){
            if(x%2 != 0) bit[i] = 1;
            x = x/2;
            i--;
        }
        node * root = tree; 
        if(ch == '+')insert(root);
        else if(ch== '-') remove(root);
        else cout << find(root) << endl;
    }
}  

signed main() {
        NeedForSpeed
        int t = 1;
        cout << fixed << setprecision(9) ;
        // cin >> t;
        while(t--){
            go();
        }

}