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
	ul counter;
};

vector<TrieNode> trie = {{.counter = 0}};
ul curr_node = 0;

void add_word(string &word)
{
	ul pt = 0;
	for (auto &c : word) {
		if (!trie[pt].next.count(c)) {
			trie[pt].next[c] = ++curr_node;
			trie.push_back({.counter = 0});
		}
		pt = trie[pt].next[c];
	}
	trie[pt].counter++;
}


bool compare(const pair<string, ul> &a, const pair<string, ul> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

void trie_dfs(ul pt, pair<string, ll> &best_word, string &f)
{
	if (trie[pt].counter
	    and (best_word.second == -1 or compare({f, trie[pt].counter}, best_word)))
		best_word = {f, trie[pt].counter};

	for (auto &p : trie[pt].next) {
		f.push_back(p.first);
		trie_dfs(p.second, best_word, f);
		f.pop_back();
	}
}

void find_word(pair<string, ll> &best_word, string &word)
{
	ul pt = 0;
	string f = "";
	for (auto &c : word) {
		if (!trie[pt].next.count(c))
			return;
		pt = trie[pt].next[c];
		f += c;
	}
	trie_dfs(pt, best_word, f);
}

int main(void)
{
	ios;
	ul n;
	cin >> n;
	while (n--) {
		string word;
		cin >> word;
		add_word(word);
	}

	ul q;
	cin >> q;
	while (q--) {
		pair<string, ll> best_word = {"", -1};
		string word;
		cin >> word;
		find_word(best_word, word);
		if (best_word.second == -1) {
			cout << "-1" << ENDL;
			continue;
		}
		cout << best_word.first << " " << best_word.second << ENDL;
	}
	
	return 0;
}





