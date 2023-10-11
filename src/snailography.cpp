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
	int i, j, m, n;
	string s;
	cin >> n;
	cin >> s;

	vector<vector<char>> v(n, vector<char>(n, '#'));
	
	i = j = n / 2;
	m = 1;
	int d = 0, k = 0;
	while (k < (int) s.size()) {
		switch (d) {
		case 0: // arriba
			for (int h = 0; h < m && k < (int) s.size(); h++)
				v[i--][j] = s[k++];

			d = 1;
			break;
		case 1: // derecha
			for (int h = 0; h < m && k < (int) s.size(); h++)
				v[i][j++] = s[k++];
			d = 2;
			m++;
			break;
		case 2: // abajo
			for (int h = 0; h < m && k < (int) s.size(); h++)
				v[i++][j] = s[k++];
			
			d = 3; // izquierda
			break;
		case 3: // izquierda
			for (int h = 0; h < m && k < (int) s.size(); h++)
				v[i][j--] = s[k++];
			d = 0;
			m++;
			break;
				
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (v[i][j] != '#') {
				cout << v[i][j];
			}
		}
	}

	cout << ENDL;
	return 0;
}





