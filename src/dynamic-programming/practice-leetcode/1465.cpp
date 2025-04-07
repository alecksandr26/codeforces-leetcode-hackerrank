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
	int constrainedSubsetSum(vector<int> &A, int k) {
		// By default pq compare the first element in a pair
		priority_queue<pair<int, int>> pq;
		int DP[A.size()];
		memset(DP, 0, sizeof(int) * A.size());
		int m = INT_MIN;
		for (int i = 0; i < A.size(); i++) {
			DP[i] = A[i];
			pair<int, int> mk = {0, 0};
			while (pq.size()) {
				mk = pq.top();
				pq.pop();
				if (mk.second >= i - k)
					break;
			}
			DP[i] = max(DP[i], A[i] + mk.first);
			pq.push({DP[i], i});
			m = max(m, DP[i]);
		}

		return m;
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



