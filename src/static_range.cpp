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

int main(void)
{
	ios;
	st n, q;
	cin >> n >> q;

	vector<ll> arr(n);

	ll sum = 0;
	for (st i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		arr[i] = sum;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		if (l > 0)
			cout << arr[r - 1] - arr[l - 1] << ENDL;
		else
			cout << arr[r - 1] << ENDL;
	}

	
	return 0;
}

