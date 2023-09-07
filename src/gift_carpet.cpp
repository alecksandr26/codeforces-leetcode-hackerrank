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

void solve(void)
{
	st n, m;
	cin >> n >> m;

	vector<vector<char>> mat(n, vector<char> (m, 0));
	stack<char> s;
	
	s.push('a');
	s.push('k');
	s.push('i');
	s.push('v');
	
	
	for (st i = 0; i < n; i++)
		for (st j = 0; j < m; j++)
			cin >> mat[i][j];

	for (st j = 0; j < m; j++)
		for (st i = 0; i < n; i++)
			if (!s.empty() && s.top() == mat[i][j]) {
				s.pop();
				break;
			}
	
	string res = "YES";
	if (s.size() > 0)
		res = "NO";
	
	cout << res << ENDL;
}

int main(void)
{
	ios;
	st t;
	cin >> t;

	while (t--)
		solve();
	
	return 0;
}






