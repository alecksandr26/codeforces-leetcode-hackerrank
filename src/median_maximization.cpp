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

void solve(void)
{
	ll n, s;
	cin >> n >> s;

	vector<ll> v(n);

	ll i = 0, r = 0;
	while (i < n) {
		r = s / (n - i);
		v[i++] = r;
		s -= r;
	}

	if (n < 10) {
		for (auto &i : v)
			cout << i << " ";
		cout << ENDL;
	}
		
	if (n % 2 == 0)
		cout << v[(n / 2) - 1] << ENDL;
	else
		cout << v[n / 2] << ENDL;
}

int main(void)
{
	ios;
	st t;
	cin >> t;
	
	while (t--)
		solve();
	
	return 0;
}

