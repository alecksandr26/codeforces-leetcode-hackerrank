#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;


ul fac(ll n)
{
	if (n <= 1)
		return 1;
	
	if (n == 2)
		return 2;

	return n * fac(n - 1);
}


int main(void)
{
	ul n, res;
	cin >> n;

	res = 0;
	for (ul j = 1; j <= n; j++) {
		for (ul i = 0; i <= j; i++) {
			res += fac(j) / (fac(i) * fac(j - i));
		}
	}
	
	cout << res << ENDL;
	
	return 0;
}




