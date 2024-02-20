#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

// problem: https://codeforces.com/problemset/gymProblem/101498/L

vector<pair<ul, ll>> adj[N];

void solve(void)
{
	ul n, m;

	cin >> n >> m;


	while (m--) {
		ul a, b;
		ll w;

		cin >> a >> b >> w;
		adj[a].push_back({b, w});
	}
	
}

int main(void)
{
	ios;
	ul t;
	cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}



