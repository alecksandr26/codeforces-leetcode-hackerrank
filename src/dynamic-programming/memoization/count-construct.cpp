/*
  Write a function `countConstruct(target, wordBank)` that accepts a
  target string and an array of strings.

  The function should return the number of ways that the `target` can
  be constructed by concatenating elements of the `wordBank` array.

  you may reause elements of `wordBank` as many times as needed.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	
	unordered_map<string, int> mem;
public:
        // Time: O(n * (m ^ 2)), Space: O(m^2)
	int countConstruct(string target, vector<string> &wordBank) { // O(n * (m ^ 2))
		if (target.empty())
			return 1;
		if (mem.count(target))
			return mem[target];
		int c = 0;
		for (const auto &s : wordBank) // O(n * m)
			if (s.size() <= target.size()
			    and target.rfind(s) == target.size() - s.size()) // O(m)
				c += countConstruct(target.substr(0, target.size() - s.size()), wordBank);
		return mem[target] = c;
	}
};

int main(void)
{
	Solution sol;
	vector<string> wordBank = {"ab", "abc", "cd", "def", "abcd", "c"};
	string target = "abcdef";
	cout << sol.countConstruct(target, wordBank) << endl;
	
	return 0;
}




