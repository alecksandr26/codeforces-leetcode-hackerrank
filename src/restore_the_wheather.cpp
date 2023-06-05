#include <bits/stdc++.h>

#define st size_t
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

/*
  output:
  2 2 5 4 11 
  0 4 -1 0 -4 0 
  4 8 9 
  9 2 1
  1 0 3
  0 -8 5 -4 -1 
 */

/* url: https://codeforces.com/problemset/problem/1833/B */
/* solution: https://youtu.be/PDiX44XFXJI */

#define ABS(a) (((a) > 0) ? (a) : -1 * (a))

int main(void)
{
	unsigned int t;
	cin >> t;
	
	while (t--) {
		ll b, k;
		st n;
		cin >> n >> k;
		
		vector<pair<ll, st>> fir; // To keep track of the index of each element
		vector<ll> sec, res(n);	  // Create the array of answers
		
		for (st i = 0; i < n; i++) {
			cin >> b;
			fir.push_back(make_pair(b, i));
		}

		for(st i = 0 ; i < n ; i++) {
			cin >> b;
			sec.push_back(b);
		}

		// Sort the two arrays
		sort(fir.begin(), fir.end());
		sort(sec.begin(), sec.end());

		// Build the answer
		for(st i = 0; i < n; i++)
			res[fir[i].second] = sec[i];
		
		for(st i = 0; i < n; i++)
			cout << res[i] << " ";
		
		cout << endl;
	}
	
	return 0;
}
