  set<int> divisors;
  for(int i = 1 ; i*i <= n; i++){
      if(n%i)continue;
      divisors.insert(n/i);
      divisors.insert(i);
  }
  divisors.insert(n);