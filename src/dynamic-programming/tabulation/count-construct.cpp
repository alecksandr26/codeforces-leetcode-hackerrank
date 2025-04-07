/*
  count construct tabulation version
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Time: O(m^2 * n), Space: O(m)
	int countConstruct(const string &target, const vector<string> &wordBank) {
		vector<int> tab(target.size() + 1, 0);
		for (int i = 0; i <= target.size(); i++) { // O(m)
			if (tab[i] > 0 or i == 0) {
				for (const string &w : wordBank) { // O(n)
					if (i + w.size() <= target.size()
					    and target.find(w, i) != string::npos) { // O(m)
						tab[i + w.size()]++;
					}
				}
			}
		}
		return tab[target.size()];
	}
};


int main(void)
{
	Solution sol;
	vector<string> wordBank = {"ab", "c", "a", "bc", "abc"};
	string target = "abc";
	cout << sol.countConstruct(target, wordBank);
	return 0;
}
