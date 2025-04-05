/*
  Write a function `canConstruct(target, wordBank)` that accepts a
  target string and an array of strings.
  
  The function should return a boolean indicating whether or not the
  `target` can be constructed by concatenating elements of the
  `wordBank` array.
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class Solution {
private:
	unordered_map<string, bool> mem;
	bool solve(string target, vector<string> &wordBank) {
		if (target.empty()) return true;
		if (mem.count(target)) return mem[target];
		for (const auto &s : wordBank) {
			if (target.size() >= s.size()
			    and target.rfind(s) == target.size() - s.size())
				if (solve(target.substr(0, target.size() - s.size()), wordBank))
					return mem[target] = true;
		}
		return mem[target] = false;
	}
	
public:
	bool canConstruct(string &target, vector<string> &wordBank) {
		return solve(target, wordBank);
	}
};


int main(void)
{
	Solution sol;
	vector<string> wordBank = {"ab", "abc", "cd", "def", "abcd"};
	string target = "abcdef";
	cout << sol.canConstruct(target, wordBank) << endl;
	return 0;
}






