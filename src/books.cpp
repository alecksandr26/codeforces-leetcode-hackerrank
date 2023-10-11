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
	st n;
	ll t;
	cin >> n >> t;
	
	vector<ll> arr(n);

	int i = 0;
	ll sum = 0;
	while (n--) {
		cin >> arr[i];
		sum += arr[i];
		arr[i++] = sum;
	}
	
	int j = -1;
	i = 0;
	ll ans = 0;
	while (i < (int) arr.size()) {
		if (arr[i] - ((j > -1) ? arr[j] : 0) <= t) {
			i++;
			ans = max(ans, i - j - 1);
		} else
			j++;

	}

	cout << ans << ENDL;
	
	return 0;
}

