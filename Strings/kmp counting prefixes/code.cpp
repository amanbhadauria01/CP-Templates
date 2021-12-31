int lps[N];
int c[N];

// lps filler
void filler(string &s){
    int n = s.size();
    for(int i = 1 ; i < n ; i++){
       int j = lps[i-1];
       while( j > 0 && s[i]!=s[j]) j = lps[j-1];
       if(s[i]==s[j]) j++;
       lps[i] = j;
    }
}

void go(){
  string s; cin >> s;
  int n = s.size();
  memset(lps,0,sizeof(lps));
  memset(c,0,sizeof(c));
  filler(s);
  // for doing string matching just do txt + # + pat and find ans
  
  // counting no of times each prefix occurs

  // count of prefix which is also a suffix
  for(int i = 0   ;i < n ; i++) c[lps[i]]++;
  // as the prefixes which were also a suffix in the above prefixes were not counted above counting them 
  // for each i adding its ans to its longest prefix which was also a suffix
  for(int i = n-1 ; i >= 0 ; i--) c[lps[i-1]] += c[i];
  // now counting each prefix original
  for(int i= 1   ; i <=  n ; i++) c[i]++;

   vector<int> v;
   v.push_back(n);
   int j = lps[n-1];
   while(j > 0){
       v.push_back(j);
       j = lps[j-1];
   }
   reverse(v.begin(),v.end());
   cout << v.size() << endl;
   for(auto i : v) cout << i << " " << c[i] << endl; 
}  
