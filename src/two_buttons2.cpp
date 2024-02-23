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
#define mk make_pair
#define DMAX (1e4 * 2 + 1)

unordered_map<int, int> vis(DMAX);
unordered_map<int, int> op(DMAX);

int main(void)
{
	ios;
	ll n, m;
	cin >> n >> m;

	queue<ll> q;

	q.push(n);
	op[n] = 0;
	while (!q.empty()) {
		ll c = q.front();
		q.pop();
		
		if (c < 0 || c > DMAX)
			continue;
		
		if (!vis[c * 2])
			q.push(c * 2);
		
		if (!vis[c - 1])
			q.push(c - 1);
		
		vis[c * 2] = 1;
		vis[c - 1] = 1;
		
		op[c * 2] = op[c] + 1;
		op[c - 1] = op[c] + 1;

		if (c * 2 == m) {
			cout << op[c * 2] << endl;
			break;
		}

		if (c - 1 == m) {
			cout << op[c - 1] << endl;
			break;
		}
	}
	
	return 0;
}





