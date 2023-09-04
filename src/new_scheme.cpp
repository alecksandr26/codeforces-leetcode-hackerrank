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
	
	vector<ll> v(8);

	st i = 0;

	while (i < 8)
		cin >> v[i++];

	string r = "Yes";
	for (i = 0; i < 7; i++)
		if (v[i] > v[i + 1])
			r = "No";

	for (i = 0; i < 8; i++)
		if (!(v[i] >= 100 && v[i] <= 675))
			r = "No";

	for (i = 0; i < 8; i++)
		if (v[i] % 25)
			r = "No";
	cout << r << endl;
	
	return 0;
}

