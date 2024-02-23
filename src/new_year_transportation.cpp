#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef pair<ll, ll> pll;

#define fore(i, a, n) for (ul i = a; i < n; i++)
#define pb push_back

vul vis(3 * 1e4 + 5);
vector<vul> adj(3 * 1e4 + 5);

bool dfs(ul i, ul t)
{
	if (vis[i])
		return false;
	vis[i] = 1;

	if (i == t)
		return true;
	
	for (auto &a : adj[i]) {
		if (dfs(a, t))
			return true;
	}

	
	return false;
}

int main(void)
{
	ios;

	ul n, t;

	cin >> n >> t;
	
	fore(i, 0, n) {
		ul a;
		cin >> a;
		adj[i].pb(i + a);
		vis[i] = 0;
	}
	t--;
	if (dfs(0, t))
		cout << "YES" << ENDL;
	else
		cout << "NO" << ENDL;
	
	return 0;
}







