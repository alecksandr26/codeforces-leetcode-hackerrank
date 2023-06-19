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

using namespace std;

// url: https://codeforces.com/problemset/problem/1840/E
// solution: https://codeforces.com/blog/entry/117060

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}



void solve(void)
{
	string s[2];
	st t, q;
	int bad;
	cin >> s[0] >> s[1];
	cin >> t >> q;

	queue<pair<st, st>> blocked;

	bad = 0;
	for (st i = 0; i < s[1].size(); i++) {
		if (s[0][i] != s[1][i])
			bad++;
	}
	
	for (st i = 0; i < q; i++)  {
		while (!blocked.empty() && blocked.front().first == i) {
			if (s[0][blocked.front().second] != s[1][blocked.front().second])
				bad++;
			blocked.pop();
		}
			
		int query, index, s1, pos1, s2, pos2;
		char temp;
		cin >> query;
		switch (query) {
		case 1:
			cin >> index;
			index--;
			if (s[0][index] != s[1][index])
				bad--;
			blocked.emplace(i + t, index);
			break;
		case 2:
			cin >> s1 >> pos1 >> s2 >> pos2;
			s1--;
			s2--;
			pos1--;
			pos2--;

			if (s[s1][pos1] != s[1 ^ s1][pos1])
				bad--;

			if (s[s2][pos2] != s[1 ^ s2][pos2])
				bad--;

			temp = s[s1][pos1];
			s[s1][pos1] = s[s2][pos2];
			s[s2][pos2] = temp;

			if (s[s1][pos1] != s[1 ^ s1][pos1])
				bad++;

			if (s[s2][pos2] != s[1 ^ s2][pos2])
				bad++;

			
			break;
		case 3:
			cout << (!bad ? "YES" : "NO") << endl;
			break;
		}
	}
}

int main(void)
{
	st t;


	cin >> t;
	while (t--)
		solve();

	return 0;
}
