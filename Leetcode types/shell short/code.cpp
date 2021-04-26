#include<bits/stdc++.h>
using namespace std;

int arr[100100];

void shellsort(int n){
    for(int gap = n/2 ; gap >0 ; gap = gap/2){
        for(int j = gap ; j < n ; j++){
            for(int i = j-gap ; i>=0 ; i = i-gap){
                if(arr[i] <= arr[i+gap]){
                    break;
                }else{
                    swap(arr[i],arr[i+gap]);
                }
            }
        }
    }
}

void print(int n){
    for(int i = 0 ; i < n ; i++)
      cout << arr[i] << " " ;
      cout << endl;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    shellsort(n);
    print(n);
}