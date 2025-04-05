/*
  fib(n) -> m
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int fib(int n) {
		int tab[n + 1];
		memset(tab, 0, sizeof(int) * (n + 1));
		
		tab[0] = 1;
		tab[1] = 1;
		for (int i = 2; i <= n; i++)
			tab[i] = tab[i - 1] + tab[i - 2];
		return tab[n];
		
	}
};


class RecSolution {
public:
	int fib(int n) {
		if (n <= 1)
			return 1;
		return fib(n - 1) + fib(n - 2);
	}
};

int main(void)
{
	Solution sol;

	cout << sol.fib(2) << endl;
	cout << sol.fib(5) << endl;
	cout << sol.fib(10) << endl;
	cout << sol.fib(44) << endl;
	
	return 0;
}





