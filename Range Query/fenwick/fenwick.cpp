
void add(int i , int val){
    while(i < N ){
        fen[i] += val;
        i += (i&(-i));
    }
}
int sum(int i){
    int s = 0;
    while(i>0){
        s+= fen[i];
        i-= (i&(-i));
    }
    return s;
}

int range(int l, int r){
    return sum(r)-sum(l-1);
}
