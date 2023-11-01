#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

void solve(void)
{
	ul n, q;
	cin >> n >> q;
	
	vector<ll> vec(n, 0);
	
	while (q--) {
		ul r, l;
		cin >> l >> r;
		r--; l--;
		cout << l << " " << r << ENDL;
		vec[l] += 1;
		cout << "l: " << l << " " << vec[l] <<  ENDL;
		
		if (r + 1 < n) {
			vec[r + 1] = - ((r - l) + 1);
			cout << "r: " << r + 1 << " " << vec[r + 1] <<  ENDL;
		}
		
		for (ul i = 0; i < n; i++)
			cout << vec[i] << " ";
		cout << ENDL;

	}
	
	for (ul i = 1; i < n; i++)
		vec[i] += vec[i - 1] + i;

	for (ul i = 0; i < n; i++)
		cout << vec[i] << " ";
	
	cout << ENDL;
	
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





