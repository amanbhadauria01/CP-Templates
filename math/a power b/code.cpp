int power(int a, int b, int m)
{
	int ans=1;
	a %= m; a +=m; a %= m;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}