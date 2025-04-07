/*
  can construct tabulation version
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time: O(m^2 * n), Space: O(m), where m is the lenght of the target and m is the lenght of words
	bool canConstruct(const string &target, vector<string> &wordBank) { // O(m^2 * n)
		vector<bool> tab(target.size() + 1, false);
		for (int i = 0; i <= target.size(); i++) { // O(m)
			if (tab[i] or i == 0) {
				for (auto &w : wordBank) { // O(n)
					if (i + w.size() <= target.size()
					    and target.find(w, i) != string::npos) // O(m)
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



