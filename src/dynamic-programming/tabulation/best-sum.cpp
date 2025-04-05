
/*
  best sum problem
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
	
public:
	vector<int> bestSum(int target, vector<int> &A) {
		vector<int> tab[target + 1];
		for (int i = 0; i <= target; i++) {
			if (not tab[i].empty() or i == 0) {
				for (int a : A) {
					if (i + a <= target) {
						vector<int> sum;
						for (int e : tab[i])
							sum.push_back(e);
						sum.push_back(a);
						if (tab[i + a].empty() or sum.size() < tab[i + a].size())
							tab[i + a] = sum;
					}
				}
			}
		}
		return tab[target];
	}
};

int main(void)
{
	Solution sol;
	vector<int> A = {2, 3, 4, 5, 10, 12};
	vector<int> B = sol.bestSum(12, A);
	cout << "[";
	for (int i = 0; i < B.size() - 1; i++) {
		cout << B[i] << ", ";
	}
	cout << B[B.size() - 1] << "]" << endl;
	
	return 0;
}



