#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &A) {
		int m = 0, n = A.size();
		for (int i = 0; i < n - 1; i++)
			if (A[i + 1] - A[i] > 0)
				m += A[i + 1] - A[i];
		return m;
	}
};

int main(void)
{
	
	return 0;
}
