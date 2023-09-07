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
	ll h[4];
	ll total;

	cin >> h[0] >> h[1] >> h[2] >> h[3];

	map<ll, ll> m;

	for (int i = 0; i < 4; i++) {
		if (m.find(h[i]) == m.end())
			m.insert({h[i], 0});
		else
			m[h[i]]++;
	}


	total = 0;
	for (auto i : m)
		total += i.second;

	cout << total << endl;
	return 0;
}




