#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int maxSubsetSum(vector<int> &arr) {
	int n = arr.size();
	vector<int> dp(n, 0);
	dp[0] = max(arr[0], 0);
        dp[1] = max(dp[0], arr[1]);
	for (int i = 2; i < n; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	return dp[n - 1];
}

int main(void)
{
	vector<int> arr;
	arr = {3, 5, -7, 8, 10};
	cout << maxSubsetSum(arr) << endl;
	return 0;
}




