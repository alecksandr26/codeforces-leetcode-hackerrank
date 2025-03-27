#include <bits/stdc++.h>
#include <queue>
#include <vector>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;


class Solution {
public:
	// Code goes here
	struct compare {
		bool operator()(const pair<char, int> &A, const pair<char, int> &B) {
			return A.second < B.second;
		}
	};

	// Time: O(n), Space: O(n)
	string reorganizeString(string s) {
		vector<int> occur(26, 0); // Occurrences 

		// Catch all the occurrences
		for (char c : s) occur[c - 'a']++;
		
		priority_queue<pair<char, int>, std::vector<pair<char, int>>, compare> pq;
		
		// Fill the priority queue with the occurrences
		for (int i = 0; i < 26; i++) if (occur[i] > 0) pq.push({i + 'a', occur[i]});
		
		// It works basically, because we are taking each pair of occurences at once
		// so we can only concatenate it just one time, if we don't find another pair of occurences,
		// it means that it doens't work
		string res = "";
		pair<char, int> prev = {'#', 0};
		while (not pq.empty()) {
			auto curr = pq.top();
			pq.pop();
			res += curr.first;
			if (prev.second > 0) pq.push(prev);
			curr.second--;
			prev = curr;
		}
		if (res.size() != s.size()) return "";
		return res;
	}
};

int main(void)
{
	Solution sol;

	// Write to catch the test cases
	
	cout << "aab => " << sol.reorganizeString("aab") << "\n";
	cout << "aaab => " << sol.reorganizeString("aaab") << "\n";
	cout << "vvvlo => " << sol.reorganizeString("vvvlo") << "\n";
	
	return 0;
}




