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

void solve(void)
{
	st n;
	cin >> n;

	ll even = 0, odd = 0, m;
	for (st i = 0; i < n; i++) {
		cin >> m;
		
		bool e = true;
		if (m % 2 != 0)
			e = false;
			
		if (i % 2 == 0) {
			if (!e)
				even++;
		} else {
			if (e)
				odd++;
		}
	}

	if (even == odd)
		cout << even << ENDL;
	else
		cout << -1 << ENDL;

}

int main(void)
{
	ios;
	st t;
	cin >> t;

	while (t--)
		solve();
	
	return 0;
}

