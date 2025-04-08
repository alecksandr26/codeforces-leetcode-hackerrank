#include <bits/stdc++.h>
using namespace std;

string twoStrings(string &s1, string &s2) {
	int A[26];
	
	memset(A, 0, sizeof(int) * 26);
	for (const auto &c : s1)
		A[c - 'a'] = 1;
	for (const auto &c : s2)
		if (A[c - 'a'])
			return "YES";
	return "NO";
}


int main(void)
{
	
	return 0;
}






