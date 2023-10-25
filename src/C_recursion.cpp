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

ll solve(string &s)
{
	int i = s.size() - 1;

	if (s.size() == 1) {
		if (s[0] == '4')
			return 1;
		return 2;
	}

	while (i > 0 && s[i] != '7')
		i--;
	
	if (s[i] == '4') {
		int n = s.size() - 1;
		s = "";
		for (int k = 0; k < n; k++)
			s += "7";
		return solve(s) + 1;
	} else {
		s[i] = '4';
		for (st k = i + 1; k < s.size(); k++)
			s[k] = '7';
		return solve(s) + 1;
	}
}

int main(void)
{
	ios;
	ll n;
	
	cin >> n;

	string s = to_string(n);
	cout << solve(s) << ENDL;
	
	return 0;
}

