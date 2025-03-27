#include <bits/stdc++.h>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
class LRUCache {
private:
	struct Node {
		int key, val;
		struct Node *next, *prev;

		Node(int key_, int val_) : key(key_), val(val_), next(NULL), prev(NULL) {}
	};
	
	unordered_map<int, Node *> m;
	Node *head, *tail;
	size_t cap, n;

	void push_front(Node *node) {
		if (head == NULL) {
			tail = head = node;
			return;
		}
		head->prev = node;
		node->next = head;
		head = node;
	}
	void remove(Node *node) {
		if (node->prev) node->prev->next = node->next;
		if (node->next) node->next->prev = node->prev;
		if (tail == node) tail = node->prev;
		if (head == node) head = node->next;
		node->next = node->prev = NULL;
	}
public:
	LRUCache(int capacity) {
		ios;
		cap = capacity;
		n = 0;
		head = tail = NULL;
	}

	int size() {
		return n;
	}
	int capacity() {
		return cap;
	}
    
	int get(int key) {
		if (!m.count(key))
			return -1;
		remove(m[key]);
		push_front(m[key]);
		return m[key]->val;
	}
    
	void put(int key, int value) {
		if (get(key) != -1) {
			remove(m[key]);
			push_front(m[key]);
			m[key]->val = value;
			return;
		}
		
		if (n == cap) {
			Node *node = tail;
			m.erase(node->key);
			remove(node);
			delete node;
			n--;
		}
		Node *node = new Node(key, value);
		push_front(node);
		m.insert({key, node});
		n++;
	}
};


int main(void)
{
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << "\n";
	cache.put(3, 3);
	cout << cache.get(2) << "\n";
	cache.put(4, 4);
	cout << cache.get(1) << "\n";
	cout << cache.get(3) << "\n";
	cout << cache.get(4) << "\n";
	
	// Write to catch the test cases
	
	return 0;
}




