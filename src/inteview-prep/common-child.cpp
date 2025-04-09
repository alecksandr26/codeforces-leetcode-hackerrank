#include <bits/stdc++.h>
using namespace std;

int commonChild(string &s1, string &s2) {
	int n = s1.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][n];
}

int main(void)
{
	string s1;
	string s2;
	
	s1= "SHINCHAN";
	s2= "NOHARAAA";
	cout << commonChild(s1, s2) << endl;


	s1= "ABCDEF";
	s2= "FBDAMN";
	cout << commonChild(s1, s2) << endl;

	s1= "AA";
	s2= "BB";
	cout << commonChild(s1, s2) << endl;

	s1= "HARRY";
	s2= "SALLY";
	cout << commonChild(s1, s2) << endl;
		
	return 0;
}






