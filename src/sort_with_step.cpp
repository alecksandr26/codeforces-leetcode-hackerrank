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
	st n, k;
	cin >> n >> k;
	int a[n];

	for(st i = 0; i < n; i++)
		cin >> a[i];

	int c = 0;
	for(st i = 0; i < n; i++)
		if(abs((int) i - (a[i] - 1)) % k != 0) // If it is possible to sort it
			c++;

	switch (c) {
	case 0:
		cout << 0 << endl;
		break;
	case 1: case 2:
		cout << 1 << endl;
		break;
	default:
		cout << -1 << endl;
	}
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
