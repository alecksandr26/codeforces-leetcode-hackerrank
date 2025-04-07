#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
	
public:
	// Time: O(n * k), Space: O(n)
	int constrainedSubsetSum(vector<int> &A, int k) {
		int DP[A.size()];
		memset(DP, 0, sizeof(int) * A.size());
		int m = INT_MIN;
		for (int i = 0; i < A.size(); i++) {
			DP[i] = A[i];
			for (int j = i - 1; j >= 0 and j >= i - k; j--)
				DP[i] = max(DP[i], A[i] + DP[j]);
			m = max(m, DP[i]);
		}
		return m;
	}
};

class Solution2 {
public:
	int constrainedSubsetSum(vector<int>& A, int k) {
		int n = A.size();
		vector<int> dp(n);
		// Max-heap that stores pairs (dp value, index)
		priority_queue<pair<int, int>> pq;
        
		dp[0] = A[0];
		pq.push({dp[0], 0});
		int result = dp[0];

		for (int i = 1; i < n; i++) {
			// Remove indices that are out of the current window
			while (!pq.empty() && pq.top().second < i - k) {
				pq.pop();
			}
            
			// If the max dp in the window is positive, add it to A[i]
			// Otherwise, just take A[i] (i.e. start a new subsequence)
			dp[i] = A[i] + (pq.empty() ? 0 : max(0, pq.top().first));
            
			// Push the current value and index into the heap
			pq.push({dp[i], i});
			result = max(result, dp[i]);
		}
        
		return result;
	}
};

int main(void)
{
	Solution2 sol;
	vector<int> A = {10, 2, -10, 5, 20};
	int k = 2;
	int ans = sol.constrainedSubsetSum(A, k);
	cout << ans << endl;
	assert(ans == 37);

	A = {-1, -2, -3};
	k = 1;
	ans = sol.constrainedSubsetSum(A, k);
	cout << ans << endl;
	assert(ans == -1);

	A = {10, -2, -10, -5, 20};
	k = 2;
	ans = sol.constrainedSubsetSum(A, k);
	cout << ans << endl;
	assert(ans == 23);
	
	return 0;
}



