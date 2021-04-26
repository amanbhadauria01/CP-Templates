#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int arr1[100100];
int arr2[100100];


int solver(int x, int y){
    
    int gap = ceil((double)(x+y)/2);
    for( ; gap > 0 ; gap = ((double)gap/2)){
        for(int j = gap ; j < (x+y) ; j++){
            for(int i = j-gap ; i >= 0 ; i = i-gap){
                if(i >= x && i+gap >= x){
                    if(arr2[i-x] < arr2[i+gap-x]){
                        break;
                    }else{
                        swap(arr2[i-x],arr2[i+gap-x]);
                    }
                }else if( i < x && i+gap >= x){
                    if(arr1[i] < arr2[i+gap-x]){
                        break;
                    }else{
                        swap(arr1[i],arr2[i+gap-x]);
                    }
                }else if(i < x && i+gap < x){
                    if(arr1[i] < arr1[i+gap]){
                        break;
                    }else{
                        swap(arr1[i],arr1[i+gap]);
                    }
                }
            }
        }
    }
    
}

void print(int x, int y){
    for(int i = 0 ; i < x ; i++){
        cout << arr1[i] << " ";
    }
    for(int j = 0 ; j < y ; j++){
        cout << arr2[j] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        for(int i = 0 ; i < x ; i++){
            cin >> arr1[i];
        }
        for(int i = 0 ; i < y ; i++){
            cin >> arr2[i];
        }
        solver(x,y);
        print(x,y);
    }
	
	return 0;
}