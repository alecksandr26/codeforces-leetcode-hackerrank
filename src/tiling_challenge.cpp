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

	vector<vector<char>> mat(n, vector<char>(n, 0));

	for (st i = 0; i < n; i++)
		for (st j = 0; j < n; j++)
			cin >> mat[i][j];


	for (int i = 0; i < (int) n; i++)
		for (int j = 0; j < (int) n; j++)
			if (mat[i][j] == '.') {
				// Try to put the piece
				if ((j > - 1 && mat[i][j - 1] == '.')
				    && (i > -1 && mat[i - 1][j] == '.')
				    && (j < (int) n - 1 && mat[i][j + 1] == '.')
				    && (i < (int) n - 1 && mat[i + 1][j] == '.')) {
					mat[i][j - 1] = '#';
					mat[i - 1][j] = '#';
					mat[i][j] = '#';
					mat[i][j + 1] = '#';
					mat[i + 1][j] = '#';
				}
			}

	string res = "YES";
	for (st i = 0; i < n; i++)
		for (st j = 0; j < n; j++)
			if (mat[i][j] == '.')
				res = "NO";
	
	cout << res << ENDL;
	
	return 0;
}




