#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;

// Porblem: https://leetcode.com/problems/valid-anagram/?envType=daily-question&envId=2023-12-16

class Solution {
public:
	// Code goes here
	bool isAnagram(string s, string t)
	{
		ios;

		constexpr int size = 26;
		int m[size];

		// Initialized the map
		memset(m, 0, size * sizeof(int));
		
		// Load the string into the map
		for (auto &c : s)
			m[c - 'a']++;

		// Balance the map
		for (auto &c : t)
			m[c - 'a']--;

		// Check if it is an anagram
		for (int i = 0; i < size; i++)
			if (m[i])
				return false;
		
		return true;
	}
};

int main(void)
{
	Solution sol;
	
	// Write to catch the test cases

	string s, t;

	cin >> s >> t;
	
	cout << (sol.isAnagram(s, t) ? "YES" : "NO") << ENDL;
	
	return 0;
}
