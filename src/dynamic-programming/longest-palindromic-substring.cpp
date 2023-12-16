#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

// problem: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
	// Code goes here
	
	string longestPalindrome(string s)
	{
		ios;

		constexpr int size = 26;
		string res = "", temp = "";
		int m[size], pos[size];

		memset(m, 0, size * sizeof(int));
		
		
		for (size_t i = 0; i < s.size(); i++) {
			m[s[i] - 'a'] = !m[s[i] - 'a'];


			int n = 0;
			for (int j = 0; j < size; j++)
				n += m[j];

			if (n < 2) {
				temp.push_back(s[i]);
			}

			cout << temp << ENDL;
		}

		return res;
	}
};

int main(void)
{
	Solution sol;

	// Write to catch the test cases

	string s;

	cin >> s;
	
	cout << sol.longestPalindrome(s) << ENDL;
	
	return 0;
}
