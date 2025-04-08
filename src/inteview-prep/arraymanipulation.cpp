#include <bits/stdc++.h>
using namespace std;


long arrayManipulation(int n, vector<vector<int>> q) {
	vector<long> A(n + 2, 0);

	for (int i = 0; i < q.size(); i++) {
		long a = q[i][0] - 1, b = q[i][1] - 1, k = q[i][2];
		A[a] += k;
		A[b + 1] -= k;
	}
	long ans = 0, current = 0;
	for (int i = 0; i < n; i++) {
		current += A[i];
		ans = max(ans, current);
	}
	return ans;
}

int main(void)
{
	int n; 
	vector<vector<int>> q;
	
	n = 5;
	q = {{1, 2, 100},
	      {2, 5, 100},
	      {3, 4, 100}};
	cout << arrayManipulation(n, q) << endl;
	
	return 0;
}








