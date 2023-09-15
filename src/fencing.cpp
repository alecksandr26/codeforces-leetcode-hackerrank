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
	ll n, m, k;
	cin >> n >> m >> k;

	vector<vector<char>> mat(n, vector<char>(m, '.'));
	
	while (k--) {
		int r, c;
		
		cin >> r >> c;
		mat[r - 1][c - 1] = 'x';
	}

	ll mf = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'x') {
				if (j == 0 || (j > 0 && mat[i][j - 1] == '.'))
					mf++;
				if (i == 0 || (i > 0 && mat[i - 1][j] == '.'))
					mf++;
				
				if (j == m - 1 || (j < m - 1 && mat[i][j + 1] == '.'))
					mf++;
				if (i == n - 1 || (i < n - 1 && mat[i + 1][j] == '.'))
					mf++;

				
			}
		}
	}

	cout << mf << ENDL;
	
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




