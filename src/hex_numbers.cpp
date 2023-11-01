#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;



ul recursive(ul n, string m)
{
	ul num = stoll(m);
	if (n < num)
		return 0;
	
	return recursive(n, m + "1") + recursive(n, m + "0") + 1;
}


int main(void)
{
	ios;
	ul n;
	
	cin >> n;
	
	cout << recursive(n, "1") << ENDL;
	
	return 0;
}





