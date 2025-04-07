/*
  all construct 
 */
#include <bits/stdc++.h>
using namespace std;



class Solution {
private:
	
public:
	// Time: O(m)
	vector<vector<string>> allConstruct(const string &target, const vector<string> &wordBank) {
		vector<vector<vector<string>>> tab(target.size() + 1);
		tab[0].push_back({});
		for (int i = 0; i < target.size(); i++) { // O(m)
			if (tab[i].size() or i == 0) {
				for (const string &w : wordBank) { // O(n)
					if (i + w.size() <= target.size()
					    and target.find(w, i) == i) { // O(m)
						// O( ... ) < O(m^2)
						for (const auto &vec: tab[i]) {
							// O( ... ) < O(m)
							vector<string> new_vec = vec;
							new_vec.push_back(w);
							tab[i + w.size()].push_back(new_vec);
						}
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
	
	vector<vector<string>> ans = sol.allConstruct(target, wordBank);
	for (auto &vec : ans) {
		cout << "[";
		int i = 0;
		for (; i < vec.size() - 1; i++) {
			cout << vec[i] << ", ";
		}
		if (i == vec.size() - 1)
			cout << vec[i];
		cout << "]" << endl;
	}
	
	
	return 0;
}



