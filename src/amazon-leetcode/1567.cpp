#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
	int getMaxLen(vector<int>& A) {
		int c = 0;
		int n = A.size();

		for (int i = 0; i < n; ++i) {
			long dm = A[i];
			int dc = 1;
			for (int j = i + 1; j < n; ++j) {
				dm *= (long) A[j];
				dc++;
				if (dm > (long) 0 and dc > c) {
					c = dc;
				}
			}
			if (dm > 0 and dc > c) {
				c = dc;
			}
		}

		return c;
	}
};



class Solution2 {
	struct st {
		int l, i, j;
	};

	struct st solve(vector<int> &A, int i, int j) {
		// Base case
		if ((j - i + 1) <= 2) {
			cout << "(" << A[i] << ", " << A[j] << "), ";
			if (i != j and A[i] * A[j] > 0) return { .l = 2, .i = i, .j = j };
			if (A[i] > A[j]) return { .l = 1, .i = i, .j = j };
			return { .l = 1, .i = i, .j = j };
		}
		// Recursive case
		int m = i + (j - i + 1) / 2;
		struct st l = solve(A, i, m);
		struct st r = solve(A, m + 1, j);
		
		// Try to merge
		int new_l = max(l.l, r.l);
		for (int k = l.i; k <= r.j; ++k) {
			int dm = A[k];
			int dl = 1;
			for (int u = i + 1; u <= r.j; ++u) {
				dm *= A[u];
				dl++;
				if (dm > 0 and dl > new_l) {
					new_l = dl;
				}
			}
		}
		
		return {.l = new_l, .i = l.i, .j = r.j};
	}
	
public:
	int getMaxLen(vector<int>& A) {
		int res = solve(A, 0, A.size() - 1).l;
		cout << endl;
		return res;
	}
};


class Solution3 {
public:
	int getMaxLen(vector<int> &A) {
		int pos = 0, neg = 0, maxl = 0;
		for (const int &i : A) {
			if (i == 0) { pos = 0; neg = 0; continue; }
			
			if (i < 0) swap(pos, neg);
			if (pos > 0 or i > 0) ++pos;
			if (neg > 0 or i < 0) ++neg;
			maxl = max(maxl, pos);
		}
		return maxl;
	}
};

int main(void)
{
	
	return 0;
}




