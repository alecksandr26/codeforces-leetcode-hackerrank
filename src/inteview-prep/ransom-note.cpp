#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void checkMagazine(vector<string> &mag, vector<string> &note) {
	unordered_map<string, int> words;

	for (const auto &w : mag) {
		words[w]++;
	}

	for (const auto &w : note) {
		if (words.count(w) == 0 or words[w] == 0) {
			cout << "No" << endl;
			return;
		}
		words[w]--;
	}

	cout << "Yes" << endl;
}


int main(void)
{
	vector<string> mag = {"give", "me", "one", "grand", "today",
			      "night"};
	vector<string> note = {"give", "one", "grand", "today"};
	
	checkMagazine(mag, note);
	return 0;
}






