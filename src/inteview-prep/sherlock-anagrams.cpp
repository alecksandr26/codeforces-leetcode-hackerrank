#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int sherlockAndAnagrams(string &s) {
	unordered_map<string, int> anagrams;
	int n = s.size();
	int l = 1;
	int ans = 0;
	while (l < n) {
		for (int i = 0; i <= n - l; i++) {
			string sub = s.substr(i, l);
			sort(sub.begin(), sub.end());
			if (anagrams.count(sub))
				ans += anagrams[sub]++;
			else anagrams[sub]++;
		}
		l++;
	}
	return ans;
}


int main(void)
{
	string s;
	s = "abba";
	cout << sherlockAndAnagrams(s) << endl;

	s = "cdcd";
	cout << sherlockAndAnagrams(s) << endl;
	s = "kkkk";
	cout << sherlockAndAnagrams(s) << endl;
	
	return 0;
}







