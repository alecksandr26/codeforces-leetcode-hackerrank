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
	cin >> s;

	ul res = 0;
	for (ul i = 0; i < s.size(); i++)
		if (s.substr(i, 4) == "kick")
			res++;
	cout << res << ENDL;
	
	return 0;
}

