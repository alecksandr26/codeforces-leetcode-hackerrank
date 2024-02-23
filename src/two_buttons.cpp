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


vll vis(1e4 + 5);
vll dis(1e4 + 5);

int main(void)
{
	ios;
	ll n, m;
	cin >> n >> m;
	
	queue<ll> q;
	
	q.push(n);
	dis[n] = 0;
	while (!q.empty()) {
		ll curr = q.front();
		q.pop();
		
		vis[curr + 2] = 1;
		q.push(curr * 2);
		dis[curr * 2] = dis[curr] + 1;
		
		if (curr * 2 == m) {
			cout << dis[curr * 2] << ENDL;
			return 0;
		}
		
		q.push(curr - 1);
		dis[curr - 1] = dis[curr] + 1;

		if (curr - 1 == m) {
			cout << dis[curr - 1] << ENDL;
			return 0;
		}
	}
	
	return 0;
}




