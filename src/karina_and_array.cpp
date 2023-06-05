#include <bits/stdc++.h>
#define st size_t
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define abs(a) ((a) > 0) ? (a) : -1 * (a)
#define max(a, b) ((a) > (b)) ? (a) : (b)
#define min(a, b) ((a) > (b)) ? (b) : (a)

using namespace std;

// url: https://codeforces.com/problemset/problem/1822/B
// solution: https://www.youtube.com/watch?v=9Lsuv0pZfqM

int main(void)
{
	st t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		ll *arr = new ll[n];

		for (st i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);
		
		cout << (max(arr[0] * arr[1], arr[n - 2] * arr[n - 1])) << endl;
		
		delete[] arr;
	}

	return 0;
}



