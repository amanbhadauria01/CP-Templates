using namespace std;
typedef long long int ll;


void euclid(int a, int m , int & x, int & y){
    if(a==1){
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    euclid(m%a,a,x1,y1);
    x = y1 - (m/a)*x1;
    y = x1;
}

int go(int a, int m){
   int x, y ;
   euclid(a,m,x,y);
   return (x+m)%m;
}

int main()
{   
    int t;
    cin >> t;
    while(t--){
        int a, m ;
        cin >> a >> m;
        if( __gcd(a,m) != 1){
            cout << -1 << endl;
            continue;
        }
        cout << go(a,m)<< endl;
    }
	
	return 0;
}