#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int canRotate(int digit) {
		switch (digit) {
		case 0: case 1: case 8:
			return digit;
		case 2:
			return 5;
		case 5:
			return 2;
		case 6:
			return 9;
		case 9:
			return 6;
		default:
			return -1;
		}
	}
	
	bool isGood(int x) {
		int m = 1, y = 0, a = x;
		while (a) {
			int r = a % 10;
			if ((r = canRotate(r)) == -1)
				return false;
			y += r * m;
			a /= 10;
			m *= 10;
		}
		return x != y;
	}
public:
	int rotatedDigits(int n) {
		vector<int> tab(n + 2, 0);
		tab[1] = 0;
		tab[2] = 1;
		for (int i = 3; i <= n; i++) {
			tab[i] = tab[i - 1];
			if (isGood(i)) {
				tab[i] += 1;
			}
		}
		return tab[n];
	}
};

int main(void)
{
	Solution sol;

	assert(sol.rotatedDigits(10) == 4);
	assert(sol.rotatedDigits(2) == 1);
	assert(sol.rotatedDigits(1) == 0);
	
	return 0;
}





