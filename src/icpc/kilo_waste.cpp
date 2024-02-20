#include <bits/stdc++.h>

#define N ((int) 1e5)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;

vector<int> min_rice_waste(int k, int p, vector<int>& presnts, vector<int>& dinners)
{
	int dp_size = *max_element(dinners.begin(), dinners.end()) + 1;
	vector<int> dp(dp_size, N);
	dp[0] = 0;
	
	for (int i = 1; i < dp_size; ++i) {
		for (int p : presnts) {
			if (i - p >= 0) {
				cout << "------------------" << ENDL;
				cout << "p = " << p << " dp[i - p] = " << dp[i - p] << ENDL;
				cout << "dp[i - p] + i % p = " << (dp[i - p] + (i % p)) << ENDL;
				cout << "i = " << i << " dp[i] = " << dp[i] << ENDL;
			} else
				dp[i] = min(dp[i], abs(i - p));
		}
	}

	vector<int> result;
	for (int d : dinners) {
		result.push_back(dp[d]);
	}

	return result;
}

int main(void)
{
	int k, p;
	cin >> k >> p;

	vector<int> presnts(p);
	for (int i = 0; i < p; ++i) {
		cin >> presnts[i];
	}

	vector<int> dinners(k);
	for (int i = 0; i < k; ++i) {
		cin >> dinners[i];
	}

	vector<int> result = min_rice_waste(k, p, presnts, dinners);

	for (int r : result) {
		cout << r << ENDL;
	}

	return 0;
}










