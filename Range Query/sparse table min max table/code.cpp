
int a[N];
const int K = 20;
int Log[N],st[N][K+1];

int fun(int a , int b){
  return min(a,b);
}

void filler(int n){
  assert(n>=0);
  Log[1] = 0;
  for(int i = 2 ; i < N ; i++)Log[i] = Log[i/2] + 1;

  for(int i = 0 ; i < n ; i++){
    st[i][0] = a[i];
  }
  for(int j = 1 ; j <= K ; j++){
    for(int i = 0 ; i + (1<<j) <= n ; i++){
       st[i][j] = fun(st[i][j-1],st[i + (1<< (j-1))][j-1]);
    }
  }
}

int query(int l , int r){
  int j = Log[r-l+1];
  return fun(st[l][j],st[r-(1<<j)+1][j]);
}

void go(){
  filler(n);
} 
