#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int n;

void swap(int & a , int & b){
    int temp = a;
    a= b;
    b=temp;
    return;
}

int partition(int arr[], int low , int high){
    int pivot = arr[low];
    int ind = low;
    for(int i = low ; i <= high ; i++){
        if(arr[i] < arr[low]) ind++; 
    }
    int s = low , e = high;
    swap(arr[low],arr[ind]);

    while( s < ind && e > ind){
        while(arr[s] < arr[ind]) s++;
        while(arr[e] >= arr[ind]) e--;
        swap(arr[s],arr[e]);
    }
    return ind;
}

void quicksort(int arr[], int low , int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main() {
        NeedForSpeed
    
        cin >> n ;
        int arr[n];
        for(int i = 0 ;i < n ; i++){
            cin >> arr[i];
        }
        quicksort(arr,0,n-1);
        for(int i = 0 ;i < n ; i++) cout << arr[i] << " ";
        return 0;
}

  	 			 		   	 		 						 	  		