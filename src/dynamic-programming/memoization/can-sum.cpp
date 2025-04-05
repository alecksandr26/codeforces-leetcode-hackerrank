
/*
  Write a function `canSum(targetSum, numbers)` that takes in a
  targetSum and an array of number as arguments.

  The function should return a boolean indicating whether or not it
  is possible to generate the targetSum using numbers from the array.

  You may use an element of the array as many times as needed.

  You may assume that all input numbers are nonnegative.
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution {
private:
	unordered_map<int, bool> mem;
public:
	bool canSum(int target, vector<int> &A) {
		if (target < 0)
			return false;
		if (target == 0)
			return true;
		if (mem.count(target))
			return mem[target];
		for (const auto &a : A) {
			if (canSum(target - a, A))
				return mem[target] = true;
		}
		return mem[target] = false;
	}
};

int main(void)
{
	Solution sol;
	vector<int> A = {5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7, 5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7, 5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7, 5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7,5, 3, 4, 7};
	cout << sol.canSum(98765, A) << endl;
	return 0;
}







