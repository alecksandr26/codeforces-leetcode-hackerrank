#include <bits/stdc++.h>
#define st size_t
#define ll long long
#define ul unsigned long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define abs(a) (((a) > 0) ? (a) : -1 * (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define ENDL '\n'
template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
using namespace std;


int main(void)
{
	ios;
	st n;
	ll x;
	cin >> n >> x;

	vector<ll> arr(n);

	map<ll, stack<st>> m;

	for (st i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]].push(i);
	}

	vector<ll> sol;
	for (st i = 0; i < n; i++) {
		if (m.count(x - arr[i])
		    && m[x - arr[i]].top() != i) {
			m[x - arr[i]].pop();
			sol.push_back(i);
		}
	}

	if (sol.size() > 0) {
		sort(sol.begin(), sol.end());
		for (ll &a : sol)
			cout << a + 1 << ENDL;
	} else {
		cout << "IMPOSSIBLE" << ENDL;
	}
	

	return 0;
}

