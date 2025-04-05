/*
  Write a function `howSum(targetSum, numbers)` that takes in a
  targetSum and an array of numbers as arguments.

  The function should return an array containing any combination
  of elements that add up to exactly the targetSum. If there is no
  combination that adds up to the targetSum, then return null.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	unordered_map<int, bool> mem;
	vector<int> ans;
	bool solve(int target, vector<int> &A) {
		if (target < 0) return false;
		if (target == 0) return true;
		if (mem.count(target))
			return mem[target];
		for (const auto &a : A) {
			if (solve(target - a, A)) {
				ans.push_back(a);
				return true;
			}
		}
		return false;
	}
	
public:
	vector<int> howSum(int target, vector<int> &A) {
		solve(target, A);
		return ans;
	}
};


int main(void)
{
	Solution sol;
	vector<int> A = {2, 3, 4};
	vector<int> B = sol.howSum(8, A);
	cout << "[";
	for (int i = 0; i < B.size() - 1; i++) {
		cout << B[i] << ", ";
	}
	cout << B[B.size() - 1] << "]" << endl;
	return 0;
}




