
// base 10 to base k 
vector<int> conv(int x){
    vector<int> ans; 
    while(x>0){
        ans.push_back(((x%k)+k)%k);
        x /= k ;
    }
    while((int)ans.size()<10)ans.push_back(0);
    reverse(ans.begin(),ans.end());
    return ans;
}

// base k to base 10 
int iconv(vector<int> v){
    int x = 0;
    for(auto y : v){
        x = k*x + y ; 
    }
    cout << x << endl;
    return x ; 
}
