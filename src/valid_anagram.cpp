
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

// url = https://leetcode.com/problems/valid-anagram/


class Solution {
public:
	bool isAnagram(string s, string t) {
		int i, n;
		int arr[26];

		memset(arr, 0, 26);
		n = s.size();
		for (i = 0; i < n; i++)
			arr[s[i] - 'a']++;

		n = t.size();
		for (i = 0; i < n; i++)
			arr[t[i] - 'a']--;


		for (i = 0; i < 26; i++)
			if (arr[i])
				return false;

		return true;
	}
};


