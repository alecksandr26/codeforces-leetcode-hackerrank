#include "../include/template.hpp"

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
		ll n, k, b;
		cin >> n>> k;
		vector < pair < ll, ll > >fir;
		vector < ll > sec,res(n);
		for(ll i = 0 ; i < n ; i++) {
			cin>>b;
			fir.push_back(make_pair(b,i));
		}
		for(ll i = 0 ; i < n ; i++) {
			cin>>b;
			sec.push_back(b);
		}
		sort(fir.begin(),fir.end());
		sort(sec.begin(),sec.end());
		for(ll i = 0 ; i < n ; i++) {
			res[fir[i].second] = sec[i];
		}
		for(ll i = 0 ; i < n ; i++) {
			cout<<res[i]<<" ";   
		}
		cout<<endl;
	}
	
	return 0;
}
