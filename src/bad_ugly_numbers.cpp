#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'
#define ALOTT 1900000

typedef long long ll;
typedef unsigned long long ul;


bool prime(ll n)
{
	if (n < 2)
		return false;
	for (ll x = 2; x * x <= n; x++)
		if (n % x == 0)
			return false;
	return true;
}

bool find_number(string &s, ul n)
{
	if (n == 0)
		return true;

	for (char i = '1'; i < '9'; i++) {
		s += i;
		if (prime(stoll(s)) )
			return find_number(s, n - 1);
		s.pop_back();
	}

	return false;
}

void solve(void)
{
	ul n;
	cin >> n;

	string s = "";
	if (find_number(s, n))
		cout << s << ENDL;
	else
		cout << -1 << ENDL;
	
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




