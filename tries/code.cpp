#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
typedef long long ll;
#define INF 1000000000
#define NeedForSpeed ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);



class Trie {
public:
    /** Initialize your data structure here. */
    Trie * next[26];
    bool isword;
    
    Trie() {
        for(int i = 0 ; i < 26 ; i++) next[i] = NULL;
        isword = false;
    }
    
    /** Inserts a word into the trie. */
    
    
    void insert(string word) {
        Trie * node = this;
        for(char ch : word){
            ch -= 'a';
            if(node->next[ch]==NULL){node->next[ch] = new Trie();}
            node = node->next[ch];
        }
        node->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * node = this;
        for(char ch : word){
            ch -= 'a';
            if(node->next[ch]==NULL){return false ;}
            node = node->next[ch];
        }
        return node->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * node = this;
        for(char ch : prefix){
            ch -= 'a';
            if(node->next[ch]==NULL) return false;
            node = node->next[ch];
        }
        return true;
    }
};


int main() {
        NeedForSpeed
 
}

  	 			 		   	 		 						 	  		