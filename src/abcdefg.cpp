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
	int arr[7] = {3, 1, 4, 1, 5, 9, 0};
	
	char p, q;
	cin >> p >> q;

	ll res = 0;
	int mi = min(p, q), ma = max(p, q);
	for (int i = mi - 'A'; i < ma - 'A'; i++)
		res += arr[i];
	cout << res << ENDL;
	
	return 0;
}



