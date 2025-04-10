#include <bits/stdc++.h>
using namespace std;


string abbreviation(string &a, string &b) {
	int n = a.size(), m = b.size();

	// If 'b' is longer than 'a', transformation is not possible
	if (m > n)
		return "NO";

	// Initialize a 2D DP table
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	dp[0][0] = true;

	// Fill the DP table
	for (int i = 1; i <= n; ++i) {
		// If the current character in 'a' is lowercase, it can be deleted
		if (islower(a[i - 1]) && dp[i - 1][0]) {
			dp[i][0] = true;
		}
		for (int j = 1; j <= min(i, m); ++j) {
			// If characters match, carry over the previous state
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			// If 'a[i-1]' is lowercase, consider deleting or matching
			if (islower(a[i - 1])) {
				if (toupper(a[i - 1]) == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j];
				} else if (dp[i - 1][j]) {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}

	// The result is stored in dp[n][m]
	return dp[n][m] ? "YES" : "NO";
}


int main(void)
{
	return 0;
}





