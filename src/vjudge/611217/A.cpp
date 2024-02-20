#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;

struct TrieNode {
	map<char, ul> next;
	bool end;
};

vector<TrieNode> trie = {{.end = false}};
ul curr_node = 0;

bool check_conflic(string &word)
{
	ul pt = 0;
	for (auto &c : word) {
		if (!trie[pt].next.count(c))
			return false;
		pt = trie[pt].next[c];
		if (trie[pt].end)
			return true;
	}
	
	return trie[pt].end or trie[pt].next.size();
}

void add_word(string &word)
{
	ul pt = 0;
	for (auto &c : word) {
		if (!trie[pt].next.count(c)) {
			trie[pt].next[c] = ++curr_node;
			trie.push_back({.end = false});
		}
		pt = trie[pt].next[c];
	}
	trie[pt].end = true;
}

int main(void)
{
	ios;
	ul n;
	cin >> n;

	while (n--) {
		string password;
		cin >> password;
		if (check_conflic(password)) {
			cout << "vulnerable" << ENDL;
			return 0;
		}
		add_word(password);
	}

	cout << "non vulnerable" << ENDL;
	
	return 0;
}

