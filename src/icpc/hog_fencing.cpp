#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;

int main(void)
{
	ios;
	
	ll n;
	cin >> n;

	// P = 2(b + h) => P / 2 = b + h
	ll m = n / 2;
	m--;

	ll A = LONG_MIN;
	// A = b * h
	ll i;
	for (i = 1; i <= m; i++) {
		if (A < i * m)
			A = i * m;
		m -= 1;
		
	}

	cout << A << ENDL;
	
	
	return 0;
}






