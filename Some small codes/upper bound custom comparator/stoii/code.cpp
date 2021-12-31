string stoii(int x){
    string s ; 
    while(x>0){
        s.push_back((char)(x%10 + '0')); x/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}