const int N = 2e4 + 5;
 
vector<int> divisors[N];
 
void precompute()
{
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; i * j < N; j++)
			divisors[i * j].push_back(i);
	}
}
 