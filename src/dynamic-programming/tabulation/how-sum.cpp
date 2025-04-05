/*
  how sum tabulation
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> howSum(int target, vector<int> &A) {
		vector<int> tab[target + 1];
		for (int i = 0; i <= target; i++)
			if (not tab[i].empty() or i == 0)
				for (const auto &a : A)
					if (i + a <= target && tab[i + a].empty()) {
						for (const auto &e : tab[i])
							tab[i + a].push_back(e);
						tab[i + a].push_back(a);
					}

		return tab[target];
	}
};


int main(void)
{
	Solution sol;
	vector<int> A = {2, 3, 4};
	vector<int> B = sol.howSum(12, A);
	cout << "[";
	for (int i = 0; i < B.size() - 1; i++) {
		cout << B[i] << ", ";
	}
	cout << B[B.size() - 1] << "]" << endl;
	
	
	return 0;
}






