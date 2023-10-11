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
	cin >> n;

	vector<ll> v(n), v2(n);
	vector<int> a(n, 1);
	
	for (int i = 0; i < (int) n; i++) {
		cin >> v[i];
		v2[i] = v[i];
	}

	sort(v2.begin(), v2.end());

	ll c = 0;
	for (int i = 0; i < (int) n; i++) {
		if (a[i] && v[i] != v2[i]) {
			c++;
			cout << v[n - i - 1]
			     << " == "
			     << (ll) i + 1 << ENDL;
			cout << v[i]
			     << " == "
			     << (ll) n - i << ENDL;
			if (v[n - i - 1] == (ll) i + 1
			    && v[i] == (ll) n - i)
				a[n - i - 1] = 0;
		}
	}

	cout << c << ENDL;
	if (c % 2 == 0)
		cout << "Oh No!\n";
	else
		cout << "Smokin Joe!\n";
	
	return 0;
}

