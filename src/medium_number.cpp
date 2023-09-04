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
	ll n1, n2, n3, medium = 0, max, min;
	cin >> n1 >> n2 >> n3;

	max = max(n1, n2);
	max = max(max, n3);
	min = min(n1, n2);
	min = min(min, n3);

	// cout << n1 << " " << n2 << " " << n3 << endl;
	// cout << "max: " << max << " min: " << min << endl;

	if (max != n1 and min != n1)
		medium = n1;
	else if (max != n2 and min != n2)
		medium = n2;
	else
		medium = n3;

	cout << medium << endl;
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

