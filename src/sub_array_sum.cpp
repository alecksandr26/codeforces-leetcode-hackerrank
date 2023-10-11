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
	cin >> n;

	vector<ll> arr(n);
	int i = 0;
	
	while (n--)
		cin >> arr[i++];
	
	ll m = arr[0], aux = arr[0];
	for (i = 1; i < (int) arr.size(); i++) {
		aux = max(arr[i], aux + arr[i]);
		m = max(m, aux);
	}
		
	cout << m << ENDL;
	
	return 0;
}

