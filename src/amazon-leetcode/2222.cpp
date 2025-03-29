#include <bits/stdc++.h>
using namespace std;

#define ios                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0) 

class Solution {
private:
	long long back(vector<pair<char, long>> &A, int i, int count = 1) {
		if (i >= A.size())
			return 0;
		
		long ans = 0;
		auto p = A[i];
		if (count >= 3)
			return A[i].second;
		int n = A.size();
		while (p.second--) {
			for (int j = i + 1; j < n; j += 2)
				ans += back(A, j, count + 1);
		}
		return ans;
	}
	
public:
	long long numberOfWays(string s) {
		ios;
		long long ans = 0;
		vector<pair<char, long>> vec;
		long con = 0;
		char prev = '#';
		
		for (int i = 0; i < s.size(); i++) {
			if (prev != '#' and prev != s[i]) {
				vec.push_back({prev, con});
				con = 0;
			}
			con++;
			prev = s[i];
		}

		vec.push_back({prev, con});
		
		for (pair<char, long> &p : vec) cout << "(" << p.first << "," << p.second << ")";
		cout << endl;
		int n = vec.size();
		for (int i = 0; i < n - 2; i++) {
			ans += back(vec, i);
		}
		
		return ans;
	}
};


int main(void)
{
	Solution sol;

	cout << sol.numberOfWays("001101001101") << endl;
	return 0;
}




