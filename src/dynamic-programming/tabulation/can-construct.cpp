/*
  can construct tabulation version
 */
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool canConstruct(string target, vector<string> &wordBank) {
		vector<bool> tab(target.size() + 1, false);
		for (int i = 0; i <= target.size(); i++) {
			if (tab[i] or i == 0) {
				for (auto &w : wordBank) {
					if (i + w.size() <= target.size())
						tab[i + w.size()] = true;
				}
			}
		}
		return tab[target.size()];
	}
};


int main(void)
{
	Solution sol;
	vector<string> wordBank = {"abc", "cdef", "ab", "c", "df", "def"};
	string target = "abcdef";

	cout << sol.canConstruct(target, wordBank) << endl;
	
	return 0;
}



