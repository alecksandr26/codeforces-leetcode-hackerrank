#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
	vector<pair<int, int>> V;
	unordered_map<int, int> mem;
	int solve(int index, int prev_ele, int prev_index) {
		if (index >= V.size())
			return 0;
		if (mem.count(index))
			return mem[index];
		
		if (prev_index == -1
		    or (prev_ele < V[index].first and prev_index < V[index].second))
			return mem[index] = max(solve(index + 1, V[index].first, V[index].second) + 1,
				   solve(index + 1, prev_ele, prev_index));
		return mem[index] = solve(index + 1, prev_ele, prev_index);
	}
public:
	static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
		return a.first < b.first;
	}
	int lengthOfLIS(vector<int> &A) {
		int n = A.size();
		for (int i = 0; i < n; i++)
			V.push_back({A[i], i});
		sort(V.begin(), V.end(), cmp);
		return solve(0, -1, -1);
	}
};


class Solution2 {
public:
	int lengthOfLIS(vector<int> &A) {
		int n = A.size();
		vector<int> dp(n, 1);
		int ans = 0;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < i; j++)
				if (A[i] > A[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
					ans = max(ans, dp[i]);
				}

		return ans;
	}
};



int main(void)
{
	Solution2 sol;
	vector<int> A;
	int ans;
	
	// A = {7,7,7,7,7,7,7};
	// ans = sol.lengthOfLIS(A);
	// cout << ans << endl;
	
	// A = {10, 9, 2, 5, 3, 7, 101, 18};
	// ans = sol.lengthOfLIS(A);
	// cout << ans << endl;

	A = {-4, -2, -1, 0, -1, -2, -3};
	ans = sol.lengthOfLIS(A);
	cout << ans << endl;
	
	return 0;
}




