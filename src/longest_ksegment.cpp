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
	st n, k;
	
	// Que bugs :'(
	scanf("%zu %zu", &n, &k);
	
	ul arr[n];
	int i = 0;
	while (i < (int) n)
		scanf("%lu", &arr[i++]);
	
	map<ul, ul> f;
	int l = 0, r = 0, l_m = 0, r_m = 0, dc = 0;
	int m_s = 0;
	while (r < (int) n) {
		if (f[arr[r]] == 0)
			dc++;
		f[arr[r]]++;

		while (dc > (int) k) {
			f[arr[l]]--;
			if (f[arr[l]] == 0)
				dc--;
			l++;
		}

		if (r - l + 1 > m_s) {
			m_s = r - l + 1;
			r_m = r;
			l_m = l;
		}

		r++;
	}

	printf("%i %i\n", l_m + 1, r_m + 1);
	
	return 0;
}



