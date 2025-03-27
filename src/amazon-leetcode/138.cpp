#include <bits/stdc++.h>
#include <unordered_map>

#define N ((int) 1e6)

using namespace std;

#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ENDL '\n'

typedef long long ll;
typedef unsigned long long ul;
typedef long double ld;



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



class Solution {
public:
	// Code goes here

	// Time: O(n * log (n)), Space: O(n * log (n))
	Node* copyRandomList(Node* head)
	{
		Node *ans = NULL;
		unordered_map<Node *, Node *> m;

		for (Node *curr = head, *prev = NULL; curr != NULL; curr = curr->next) {
			Node *node = new Node(curr->val);
			m[curr] = node;
			if (prev != NULL) prev->next = node;
			else ans = node;
			prev = node;
		}
		
		for (Node *curr = head; curr != NULL; curr = curr->next)
			m[curr]->random = m[curr->random];
		
		return ans;
	}
};

int main(void)
{
	Solution sol;

	// Write to catch the test cases


	
	
	return 0;
}



