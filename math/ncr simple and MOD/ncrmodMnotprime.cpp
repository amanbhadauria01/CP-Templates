#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<int> graph[100100];
#define mod 1000000007
ll nCr[1001][1001];
ll x;
vector<ll> factors;
vector<ll> rem;

void euclid(ll a, ll b, ll &x, ll &y)
{
    if (a == 1)
    {
        x = 1;
        y = 0;
        return;
    }
    ll x1, y1;
    euclid(b % a, a, x1, y1);
    y = x1;
    x = y1 - (b / a) * x1;
}

ll inv(ll pp, ll num)
{
    ll x, y;
    euclid(pp, num, x, y);
    return x;
}

void filler(int p)
{
    memset(nCr, 0, sizeof(nCr));
    nCr[0][0] = 1;
    for (int i = 1; i <= p; i++)
    {
        nCr[i][0] = 1;
        for (int j = 1; j <= p; j++)
        {
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
            nCr[i][j] = nCr[i][j] % p;
        }
    }
}

void factoring(ll x)
{
    ll sqr = sqrt(x);
    ll factor = 2;
    while (factor <= sqr && x != 1)
    {
        if (x % factor == 0)
        {
            factors.push_back(factor);
            x = x / factor;
            sqr = sqrt(x);
        }
        factor++;
    }
    if (x != 1)
    {
        factors.push_back(x);
    }
}

ll ncr(int n, int r, int p)
{
    if (n < r)
    {
        return 0;
    }
    if (n == r)
    {
        return 1;
    }
    if (r == 1)
    {
        return n;
    }
    return nCr[n][r];
}

ll lucas(int n, int r, int p)
{
    if (r == 0)
    {
        return 1;
    }
    return (lucas(n / p, r / p, p) * ncr(n % p, r % p, p)) % p;
}

ll crt()
{
    ll prod = 1;
    ll n = factors.size();
    for (int i = 0; i < n; i++)
    {
        prod *= factors[i];
    }
    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        ll pp = prod / factors[i];
        result += (rem[i]) * inv(pp, factors[i]) * pp;
    }
    while (result < 0)
    {
        result += prod;
    }
    result = result % prod;
    return result;
}

ll go(ll n, ll m)
{
    factors.clear();
    factoring(x);
    rem.clear();
    for (int i = 0; i < factors.size(); i++)
    {
        filler(factors[i]);
        ll temp = lucas(n, m, factors[i]);
        rem.push_back(temp);
    }
    ll x = crt();
    return x;
}

signed main()
{
    cin.tie(NULL), ios_base::sync_with_stdio(false), cout.tie(NULL);
    int t;
    cin >> t;
    ll n, m;
    while (t--)
    {
        cin >> n >> m >> x;
        if (n < m)
        {
            cout << 0 << endl;
            continue;
        }
        if (n == m)
        {
            cout << 1 << endl;
            continue;
        }
        cout << go(n, m) << endl;
    }

    return 0;
}