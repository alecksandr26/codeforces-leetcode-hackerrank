#include <algorithm>
#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;

class Solution {
public:
	// Code goes here

	void spread(vector<vector<int>> &A, vector<vector<int>> &M, int i, int j, int t) {
		int n = A.size(), m = A[0].size();

		// Base Case
		if (i >= n or j >= m or i < 0 or j < 0
		    or A[i][j] == 0 or A[i][j] == 2
		    or (M[i][j] <= t and M[i][j] > 0))
			return;

		M[i][j] = t;
		
		// else, Recursive case
		spread(A, M, i, j + 1, t + 1);
		spread(A, M, i, j - 1, t + 1);
		spread(A, M, i - 1, j, t + 1);
		spread(A, M, i + 1, j, t + 1);
	}

	// Time: O(N * M * 4^(N * M)), Space: O(N * M)
	int orangesRotting(vector<vector<int>>& A) {
		ios;
		vector<vector<int>> M(A.size(), vector<int>(A[0].size(), 0));

		int n = A.size(), m = A[0].size();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (A[i][j] == 2) {
					spread(A, M, i, j + 1, 1); // Right
					spread(A, M, i, j - 1, 1); // Left
					spread(A, M, i - 1, j, 1); // Up
					spread(A, M, i + 1, j, 1); // Down
				}
					

		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (M[i][j] > ans) ans = M[i][j];
				if (A[i][j] == 1 and M[i][j] == 0)
					return -1;
			}
		return ans;
	}
};

int main(void)
{
	Solution sol;

	// Write to catch the test cases
	
	return 0;
}




