#include<bits/stdc++.h>
using namespace std;

class LRU{
    public:
   int capacity;
   list<int> List;
   list<int> :: iterator it;
   unordered_map<int,pair<int,list<int> :: iterator >> M;
   int size = 0;
   LRU(){
    capacity = 1;
    List.clear();
    M.clear();
   }
   void set(int key , int value){
       if(M.count(key)==0 && capacity == size ){
         int temp = List.front();
         List.pop_front();
         M.erase(temp);
         List.push_back(key);
       }else if(M.count(key)==0){
         List.push_back(key);
         size++;
       }else{
         it = M[key].second;
         List.erase(it);
         List.push_back(key);
       }
        it = List.end();
        it--;
        M[key].second = it;
        M[key].first = value;
   }
   int get(int key){
      if(M.count(key)==0)
        return -1;
      it = M[key].second;
    //   cout << *it << endl ;
      List.erase(it);
      List.push_back(key);
      it = List.end();
      it--;
      M[key].second = it;
      return M[key].first;
   }
};

int main(){
  LRU l;
  l.set(10,23);
  cout << l.get(12)  << endl;
  return 0;
}