#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

#define update(i, delta) sum[i] = (sum[i] + delta) % MOD;

const int MaxN = 100000;
const LL MOD = 1000000007;

LL a[MaxN + 10];
LL sum[MaxN + 10];

void precalc(int n)
{
    a[0] = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = 0;
        LL s = 0;
        for (int j = i; j <= n; j+=i)
            s = (s + a[j] * a[j]) % MOD;
        sum[i] = s;
    }
}

/*
void update(int i, LL delta)
{
    //cout << "update: " << i << " " << delta << endl;
    sum[i] = (sum[i] + delta) % MOD;
}
*/

void change(int x, LL y)
{
    LL delta = ((y*y % MOD) - (a[x]*a[x] % MOD)) % MOD;
    a[x] = y;
    int x2 = sqrt(x) + 1;
    while (x2*x2 > x)
        x2--;
    if (x2*x2 == x)
    {
        update(x2, delta);
        x2--;
    }
    for (int i = 1; i <= x2; i++)
        if (x % i == 0)
    {
        update(i, delta);
        update(x / i, delta);
    }
}

void solve()
{
    int n, q;
    scanf("%d%d",&n,&q);

    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    precalc(n);

    for (int qr = 0; qr < q; qr++)
    {
        int tp,x,y;
        scanf("%d",&tp);
        if (tp == 1)
        {
            scanf("%d",&x);
            sum[x] %= MOD;
            sum[x] += MOD;
            sum[x] %= MOD;
            printf("%lld\n", sum[x]);
        }
        else
        {
            scanf("%d%d", &x, &y);
            change(x, y);
        }
    }
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	//freopen("input.txt","r",stdin);

	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++)
        solve();

	return 0;
}
