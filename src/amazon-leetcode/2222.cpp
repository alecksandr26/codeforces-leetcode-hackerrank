#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define ios                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)


// My First Attempt
class FirstSolution {
private:
	unordered_map<int, long long> mem;
	
	long long back(vector<pair<char, long>> &A, int i, int count = 1) {
		if (i >= A.size())
			return 0;
		
		long ans = 0;
		auto p = A[i];
		if (count >= 3)
			return A[i].second;
		int n = A.size();
		while (p.second--) {
			for (int j = i + 1; j < n; j += 2)
				ans += back(A, j, count + 1);
		}
		
		return ans;
	}
	
public:
	long long numberOfWays(string s) {
		ios;
		long long ans = 0;
		vector<pair<char, long>> vec;
		long con = 0;
		char prev = '#';
		
		for (int i = 0; i < s.size(); i++) {
			if (prev != '#' and prev != s[i]) {
				vec.push_back({prev, con});
				con = 0;
			}
			con++;
			prev = s[i];
		}

		vec.push_back({prev, con});
		
		for (pair<char, long> &p : vec) cout << "(" << p.first << "," << p.second << ")";
		cout << endl;
		int n = vec.size();
		for (int i = 0; i < n - 2; i++) {
			ans += back(vec, i);
		}
		
		return ans;
	}
};



class Solution {
private:
	static const long DP_SIZE = 100001;
	
	// Length of the string, level of selection, previus building
	long long dp[DP_SIZE][4][3];

	long long solve(string &s, int index, int selection, int prev_build) {
		// Base Case
		if (selection == 0) return 1;
		if (index >= s.size()) return 0;

		// Memoize
		if (dp[index][selection][prev_build + 1] != -1) return dp[index][selection][prev_build + 1];
		
		// Recursive Case
		if (s[index] - '0' == prev_build)
			return dp[index][selection][prev_build + 1] = solve(s, index + 1, selection, prev_build);
		return dp[index][selection][prev_build + 1] = solve(s, index + 1, selection - 1, s[index] - '0')
			+ solve(s, index + 1, selection, prev_build);
	}
	
public:
	long long numberOfWays(string s) {
		for (int i = 0; i < DP_SIZE; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 3; k++)
					dp[i][j][k] = -1;
		return solve(s, 0, 3, -1);
	}
};


class BetterSolution {
public:
	long long numberOfWays(string s) {
		long long total = 0;
		long long ones = 0;
		long long zeros = 0;

		// NOTE that the only combinations of to exist are: 010 and 101,
		// there are two types of pairs: 01 and 10, then we could count only the pairs
		long long p01 = 0;
		long long p10 = 0;
		
		for (const char &c : s) {
			if (c == '1') {
				ones++;
				p01 += zeros; // since we find a new '1', count all the pairs '01'
				total += p10; // since we find a new '1', count all the pairs '101'
			} else {
				zeros++;
				p10 += ones;  // since we find a new '0', count all the pairs '101'
				total += p01; // since we find a new '0', count all the pairs '010'
			}
		}
		return total;
	}
};


int main(void)
{
	Solution sol;
	cout << sol.numberOfWays("001101001101") << endl;

	return 0;
}




