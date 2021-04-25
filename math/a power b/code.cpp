int power(int a, int b, int mod){ 
	int x = 1, y = a; 
	while (b > 0){ 
		if (b%2){ 
			x = (x*y)%mod; 
		} 
		y = (y*y)%mod; 
		b /= 2; 
	} 
	return x%mod; 
}