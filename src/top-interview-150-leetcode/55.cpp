#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canJump(vector<int> &A) {
		int n = A.size();
		int i = 0;
		while (i < n) {
			int k = A[i];
			if (k == 0) break;
			int maxj = -1, next = -1;
			for (int j = i + 1; j <= i + k and j < n; j++) {
				if (maxj == -1 or A[j] + (j - i) > maxj) {
					maxj = A[j] + (j - i);
					next = j;
				}
			}
			if (next == -1) break;
			i = next;
			if (i + 1 == n) break;
		}
		return i + 1 == n;
	}
};



int main(void) {
	
	return 0;
}


