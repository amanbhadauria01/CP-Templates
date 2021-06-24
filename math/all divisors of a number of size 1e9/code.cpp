// way 1 
  set<int> divisors;
  for(int i = 1 ; i*i <= n; i++){
      if(n%i)continue;
      divisors.insert(n/i);
      divisors.insert(i);
  }
  divisors.insert(n);

// way 2

   for(int i = 2; i*i <= n ; i++){
       if(n%i)continue;
       while(n%i == 0)n/= i , primes[i]++;
   }

   for(auto x : primes){
       ans *= (x.se + 1);
   }
