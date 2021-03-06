// int 
int power(int a, int b){
    if(b==0)return 1;
    int temp = power(a,b/2);
    temp *= temp;
    if(b%2)temp *= a;
    return temp;
}

// int mod

int power(int a , int b){
    if(b==0)return 1 ; 
    int temp = power(a,b/2);
    temp *= temp ; 
    temp %= MOD ; 
    if(b%2)temp *= a , temp %= MOD;
    return temp ;  
}
// matrix

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b){
    int n = a.size();
    vector<vector<int>> res(n);
    for(int i = 0 ; i < n ; i++){
        res[i].resize(n,0);
    }

    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
                res[i][j] += a[i][k] * b[k][j] ;
                res[i][j] %= MOD ; res[i][j] += MOD ; res[i][j] %= MOD;
            }
        }
    }
    return res;
}

vector<vector<int>> power(vector<vector<int>> mat , int b){
    int n = a.size();
    vector<vector<int>> res(n);
    for(int i = 0 ; i < n ; i++){
        res[i].resize(n);
        res[i][i] = 1 ;
    }
    if(b==0){
        return res;
    }
    vector<vector<int>> temp = power(mat,b/2);
    res = mul(temp,temp);
    if(b%2)res = mul(res,mat);
    return res;
}
