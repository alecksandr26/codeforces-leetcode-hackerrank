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

	map<ll, ll> m;
	ll l;
	
	while (n--) {
		cin >> l;
		if (m.count(l))
			m[l]++;
		else
			m[l] = 1;
		
	}

	ll mn;
	mn = 0;
	for (auto d : m) 
		mn += (d.second - d.first < d.second
		       && d.second - d.first > 0)
			? d.second - d.first
			: d.second;

	cout << mn << endl;
	
	
	return 0;
}

