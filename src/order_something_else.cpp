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


int main(void)
{
	ios;

	st n;
	cin >> n;
	
	ll p, q;

	cin >> p >> q;

	ll min = LONG_MAX;
	while (n--) {
		ll d;
		cin >> d;
		min = min(min, d);
	}
	
	ll price = (min + q > p) ? p : min + q;
	cout << price << endl;
	
	
	
	return 0;
}


