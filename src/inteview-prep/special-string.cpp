#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


long substrCount2(int n, string &s) {
	long count = s.size();
	for (int l = 1; l < n; l++) {
		for (int i = 0; i < n - l; i++) {
			string subS = s.substr(i, l + 1);
			int m = subS.size();
			bool isValid = true;
			char c = subS[0];
			for (int i = 0; i < m / 2; i++)
				if (subS[i] != c or subS[m - i - 1] != c) 
					isValid = false;
			if (isValid) {
				count++;
			}
		}
	}
	return count;
}


long substrCount(int n, string &s) {
	vector<pair<char, int>> groups;
	int count = 0;
	// Create the groups of caracters
	groups.push_back({s[0], 1});
	for (int i = 0; i < n - 1; i++) {
		if (s[i + 1] != s[i]) {
			groups.push_back({s[i + 1], 1});
			count++;
		} else {
			groups[count].second++;
		}
	}
	
	// count groups of one character alone
	long total = 0;
	for (const auto &p : groups)
		total += p.second * (p.second + 1) / 2;
	
	// count groups of one character in the middle
	for (int i = 0; i < groups.size() - 1; i++)
		if (groups[i].second == 1 and groups[i - 1].first == groups[i + 1].first)
			total += min(groups[i - 1].second, groups[i + 1].second);

	return total;
}


int main(void)
{
	string s;
	
	s = "asasd";
	cout << substrCount(s.size(), s) << endl;
	cout << substrCount2(s.size(), s) << endl;
	
	s = "abcbaba";
	cout << substrCount(s.size(), s) << endl;
	cout << substrCount2(s.size(), s) << endl;
	
	s = "aaaa";
	cout << substrCount(s.size(), s) << endl;
	cout << substrCount2(s.size(), s) << endl;

	s = "aaaabaaaa";
	cout << substrCount(s.size(), s) << endl;
	cout << substrCount2(s.size(), s) << endl;
	
	return 0;
}







