#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;


int main(void)
{
	ios;
	ul n;
	
	cin >> n;
	
	vector<ul> vec(n);

	for (ul i = 1; i <= n; i++)
		vec[i - 1] = i;
	
	for (ul i = 1; i < n; i++)
		vec[i] += vec[i - 1];


	for (ul i = 0; i < n; i++)
		if (n == vec[i]) {
			cout << "YES" << ENDL;
			return 0;
		}
	
	cout << "NO" << ENDL;
	
	return 0;
}


