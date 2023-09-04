
#include <bits/stdc++.h>

std::string isBalanced(std::string s)
{
	std::stack<char> stack;
	std::unordered_map<char, char> m;

	m['}'] = '{';
	m[')'] = '(';
	m[']'] = '[';
	
	for (auto &c : s) {
		if (m.find(c) == m.end())
			stack.push(c);
		else {
			if (stack.empty() || stack.top() != m[c])
				return "NO";
			stack.pop();
		}
	}
	return (stack.empty()) ? "YES" : "NO";
}

int main(void)
{
	std::string str = std::string("((((((((((((((((((((");
	std::cout << isBalanced(str) << std::endl;

	return 0;
}


