#include <bits/stdc++.h>

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;


int main(void)
{
	ios;
	ul n;

	cin >> n;
	
	vector<pair<ll, ll>> v(n);
	
	for (ul i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;


	ll meanx, meany, sumx2, sumy2;
	sumx2 = sumy2 = meanx = meany = 0;
	
	for (ul i = 0; i < n; i++) {
		sumx2 += v[i].first * v[i].first;
		sumy2 += v[i].second * v[i].second;
		meanx += v[i].first;
		meany += v[i].second;
	}


	meanx /= n;
	meany /= n;

	ul act = (sumx2 - n * meanx * meanx) + (sumy2 - n * meany * meany);
	while ((sumx2 - n * (meanx - 1) * (meanx - 1)) + (sumy2 - n * meany * meany) <= act) {
		meanx--;
		act = (sumx2 - n * meanx * meanx) + (sumy2 - n * meany * meany);
	}

	while ((sumx2 - n * meanx * meanx) + (sumy2 - n * (meany - 1) * (meany - 1)) <= act) {
		meany--;
		act = (sumx2 - n * meanx * meanx) + (sumy2 - n * meany * meany);
	}
	
	
	cout << meanx << " " << meany << ENDL;
	
	
	return 0;
}




