/*
  Write a function `allConstruct(target, wordBank)` that accepts a
  target string and an array of strings.

  The function should return a 2D array containing all of the ways
  that the `target` can be constructed by concatenating elements of
  the `wordBank` array. Each element of the 2D array should represent
  one combination that constructs the `target`.

  You may reuse elements of `wordbank` as many times as needed.
 */

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
	unordered_map<string, vector<vector<string>>> mem;
public:
	vector<vector<string>> allConstruct(string target, vector<string> &wordBank) {
		if (target.empty())
			return {{}};
		if (mem.count(target))
			return mem[target];

		vector<vector<string>> ans;
		for (const auto &s : wordBank) {
			if (target.size() >= s.size()
			    and target.rfind(s) == target.size() - s.size()) {
				vector<vector<string>> localAns = allConstruct(target.substr(0, target.size() - s.size()), wordBank);
				for (auto vec : localAns) {
					vec.push_back(s);
					ans.push_back(vec);
				}
			}
		}
		mem[target] = ans;
		return ans;
	}
};


int main(void)
{
	Solution sol;
	
	// vector<string> wordBank = {"ab", "abc", "cd", "def", "abcd", "c"};
	// string target = "abcdef";
	vector<string> wordBank = {"a", "a", "a", "a", "a", "a", "a", "a"};
	string target = "aaaaaaa";

	vector<vector<string>> ans = sol.allConstruct(target, wordBank);
	// for (const auto &vec : ans) {
	// 	cout << "(";
	// 	for (int i = 0; i < vec.size() - 1; i++)
	// 		cout << vec[i] << ", ";
	// 	if (vec.size())
	// 		cout << vec[vec.size() - 1];
	// 	cout << ")" << endl;
	// }
	
	return 0;
}





