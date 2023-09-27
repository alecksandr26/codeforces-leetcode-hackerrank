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

	st n, i = 0;
	cin >> n;
	
	vector<ll> arr(n);
	ll sum = 0;
	while (n--) {
		cin >> arr[i];
		arr[i] += sum;
		sum = arr[i++];
	}

	cin >> n;

	while (n--) {
		ll i, j;
		cin >> i >> j;
		if (i == 0)
			cout << arr[j] << endl;
		else
			cout << arr[j] - arr[i - 1] << endl;
		
	}
	
	return 0;
}







