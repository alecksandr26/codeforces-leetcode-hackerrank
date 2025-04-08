
#include <bits/stdc++.h>
using namespace std;


vector<int> rotLeft(vector<int> &A, int d) {
	vector<int> res;
	int n = A.size();
	d %= n;

	for (int i = d; i < n; i++)
		res.push_back(A[i]);
	
	for (int i = 0; i < d; i++)
		res.push_back(A[i]);

	return res;
}


int main(void)
{
	int d = 4;
	vector<int> A = {1, 2, 3, 4, 5};

	vector<int> ans = rotLeft(A, d);

	int i = 0;
	for (; i < ans.size() - 1; i++)
		cout << ans[i] << ", ";
	if (i < ans.size())
		cout << ans[i] << endl;
	
	return 0;
}






