#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


string isValid(string &s) {
	unordered_map<char, int> countChars;

	for (const auto &c : s)
		countChars[c]++;

	unordered_map<int, int> freq;
	for (const auto &pair : countChars)
		freq[pair.second]++;
	if (freq.size() == 1)
		return "YES";
	
	if (freq.size() == 2) {
		vector<pair<int, int>> freqArray(freq.begin(), freq.end());
		const auto &p1 = freqArray[0], &p2 = freqArray[1];

		if ((p1.first == 1 and p1.second == 1)
		    or (p2.first == 1 and p2.second == 1))
			return "YES";
		
		if (abs(p1.first - p2.first) == 1
		    and (p1.second == 1 or p2.second == 1))
			return "YES";
	}
	return "NO";
}

int main(void)
{
	string s;
	
	s = "abcdefghhgfedecba";
	cout << isValid(s) << endl;

	s = "aaaabbbbccccddddeeeeffgg";
	cout << isValid(s) << endl;
	
	return 0;
}





