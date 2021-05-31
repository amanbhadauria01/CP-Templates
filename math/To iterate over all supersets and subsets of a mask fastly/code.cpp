// for iterating subsets of a mask
for(int T= mask ; T>0 ; T = mask&(T-1))
// for iterating supersets of a mask, let n be the no of bits 
for(int T= mask ; T<(1<<n) ; T = mask|(T+1))
// for iterating through all masks with their submasks , complexity (3^n)
for (int T=0; T<(1<<n); ++T)
    for (int s=T; s; s=(s-1)&T)
