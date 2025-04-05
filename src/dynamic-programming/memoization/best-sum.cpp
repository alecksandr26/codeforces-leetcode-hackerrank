/*
  Write a function `bestSum(targetSum, numbers)` that takes in a
  targetSum and an array of numbers as arguments.

  The function should return an array containing the shortest
  combination of numbers that add up to exactly the targetSum.
  
  If there is a tie for the shortest comnination, you may return any
  one of the shortest.
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {

private:
	unordered_map<int, vector<int>> mem;
public:
	vector<int> bestSum(int target, vector<int> &A) {
		if (target < 0) return {};
		if (target == 0) return {};

		if (mem.count(target))
			return mem[target];
		
		vector<int> ans;
		for (const auto &a : A) {
			vector<int> lr = bestSum(target - a, A);
			lr.push_back(a);
			if (ans.empty() or lr.size() < ans.size())
				ans = lr;
		}
		
		return mem[target] = ans;
	}
};


int main(void)
{
	Solution sol;
	vector<int> A = {2, 3, 4, 5};
	vector<int> B = sol.bestSum(12, A);
	cout << "[";
	for (int i = 0; i < B.size() - 1; i++) {
		cout << B[i] << ", ";
	}
	cout << B[B.size() - 1] << "]" << endl;
	
	return 0;
}



