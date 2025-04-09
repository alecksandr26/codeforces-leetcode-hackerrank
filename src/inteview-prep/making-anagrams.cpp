#include <bits/stdc++.h>
using namespace std;

int makeAnagram(string &a, string &b) {
	int tableA[26], tableB[26];
	for (int i = 0; i < 26; i++)
		tableA[i] = tableB[i] = 0;
	for (const auto &c : a)
		tableA[c - 'a']++;
	for (const auto &c : b)
		tableB[c - 'a']++;
	int m = 0;
	for (int i = 0; i < 26; i++)
		m += abs(tableA[i] - tableB[i]);
	return m;
}

int main(void)
{
	
	return 0;
}








