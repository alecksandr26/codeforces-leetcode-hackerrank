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



int main(void)
{
	Solution sol;
	// vector<int> A = {1,3,6,7,9,4,10,5,6};
	
	int ans = sol.lengthOfLIS(A);
	cout << ans << endl;
	return 0;
}




