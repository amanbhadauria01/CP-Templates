int power(int a, int b, int m)
{
	int ans=1;
	a %= m; a +=m; a %= m;
	b %= (m-1); b += (m-1); b %= (m-1);
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

for(int i = 2; i*i <= n ; i++){
    if(n%i)continue;
    while(n%i == 0)n/= i , primes[i]++;
}

for(auto x : primes){
    ans *= (power(x.fi,(x.se + 1)) - 1)/(x.fi-1);
}
// link for explainations - https://cp-algorithms.com/algebra/divisors.html#:~:text=If%20there%20is%20only%20one,%2Cpe11).&text=So%20the%20number%20of%20divisors,(e2%2B1).