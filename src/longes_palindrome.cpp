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
	
	string S;
	cin >> S;
	
	int arr[26];
	int i, j, m;

	memset(arr, 0, 26 * sizeof(int));

	m = 0;
	for (i = 0; i < (int) S.size(); i++) {
		if ((j = arr[S[i] - 'A'])) {
			int l = --j, r = i;
			bool pal = true;
			
			while (l < r) {
				if (S[l++] != S[r--]) {
					pal = false;
					break;
				}
			}

			if (pal)
				m = max(m, i - j + 1);
		}
		arr[S[i] - 'A'] = i + 1;
	}

	cout << m << ENDL;
	
	return 0;
}

