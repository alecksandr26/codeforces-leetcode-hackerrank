#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class RecursiveSolution {
public:
	int fib(int n) {
		if (n <= 2) return 1;
		return fib(n - 1) + fib(n - 2);
	}
};

class MemoizationSolution {
private:
	unordered_map<int, int> mem;
	
public:
	int fib(int n) {
		if (n <= 2) return 1;
		if (mem.count(n))
			return mem[n];
		return mem[n] = fib(n - 1) + fib(n - 2);
	}
};

int main(void)
{

	// RecursiveSolution sol;
	// cout << sol.fib(43) << endl;
	// 2.111s

	MemoizationSolution sol;
	cout << sol.fib(43) << endl;
	// 0.002s
	
	return 0;
}






