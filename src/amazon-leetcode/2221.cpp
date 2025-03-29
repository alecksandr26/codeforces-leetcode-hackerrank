#include <bits/stdc++.h>
using namespace std;
#define ios                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)


class Solution {
private:
	int triangularSum(vector<int> &A, int n) {
		if (n == 1) return A[0];
		for (int i = 0; i < n - 1; i++)
			A[i] = (A[i] + A[i + 1]) % 10;
		return triangularSum(A, n - 1);
	}
public:	
	int triangularSum(vector<int>& nums) {
		ios;
		return triangularSum(nums, nums.size());
	}
};


int main(void)
{
	
	return 0;
}

