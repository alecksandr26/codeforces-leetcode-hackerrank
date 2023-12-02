#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

int main(void)
{
	ios;
	string s;
	ul b, c;
	
	cin >> s >> b;

	ll i = s.size() - 1;
	b--;
	c = 0;
	while (i >= 0) {
		ul j = 1, num = 0;
		while (i >= 0 && num + j * (s[i] - '0') <= b) {
			num += j * (s[i] - '0');
			i--;
			j *= 10;
		}

		cout << num << ENDL;
		if (num == 0) {
			cout << "NO WAY" << ENDL;
			return 0;
		}
		c++;
		b = num;
	}
	
	c--;
	cout << c << ENDL;
	
	return 0;
}

