#include <bits/stdc++.h>

#define st size_t
#define ll long long
#define ul unsigned long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define abs(a) (((a) > 0) ? (a) : -1 * (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
using namespace std;

// url = https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
	int firstUniqChar(string s) {
		ios;
		int i, n;

		n = s.size();
		int arr[26];
		
		for (i = 0; i < 26; i++)
			arr[i] = 0;

		for (i = 0; i < n; i++)
			arr[s[i] - 'a']++;

		for (i = 0; i < n; i++)
			if (arr[s[i] - 'a'] == 1)
				return i;
		
		return -1;
	}
};

