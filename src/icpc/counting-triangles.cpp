#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

// problem: https://codeforces.com/gym/102890/problem/C

void solve(void)
{
	ll n, k;
	
	cin >> n >> k;
	n++;
	k++;
	
	cout << (k * (((n * (n + 1)) / 2) % 1000000007))
		% 1000000007 << ENDL;
}

int main(void)
{
	ios;
	ll t;
	cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}





