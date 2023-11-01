#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

void solve(void)
{
	ul n;
	cin >> n;
	
	vector<ul> vec(n);

	for (ul i = 0; i < n; i++)
		cin >> vec[i];
	
	
	for (ul i = 0; i < vec.size() - 1; i++)
		if (vec[i] == vec[i + 1]) {
			n--;
			vec[i] = 0;
		}

	cout << n << ENDL;
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





