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
	st n, m;
	cin >> n >> m;
	string S, T;
	cin >> S;
	cin >> T;

	bool suf, pre;
	suf = pre = true;

	for (st i = 0; i < n; i++)
		if (S[i] != T[i]) {
			pre = false;
			break;
		}


	for (st i = m - n; i < m; i++) {
		if (S[i - (m - n)] != T[i]) {
			suf = false;
			break;
		}
	}


	if (pre && suf)
		cout << 0 << ENDL;
	else if (pre)
		cout << 1 << ENDL;
	else if (suf)
		cout << 2 << ENDL;
	else
		cout << 3 << ENDL;

	
	return 0;
}

