#include <iostream>
#include <limits.h>

/*
  url: https://codeforces.com/problemset/problem/1690/D
*/

int main(void)
{
	unsigned int n;
	std::cin >> n;

	while (n--) {
		unsigned int s_size, k;
		int m = INT_MAX;
		std::string stripe;
		
		std::cin >> s_size >> k;
		std::cin >> stripe;

		unsigned long cells[s_size + 1];
		cells[0] = (stripe[0] == 'W');
		for (size_t i = 1; i <= s_size; i++)
			cells[i] = (stripe[i - 1] == 'W')
				? cells[i - 1] + 1
				: cells[i - 1];

		for (size_t i = k; i <= s_size; i++)
			if (m > (int) (cells[i] - cells[i - k]))
				m = (int) (cells[i] - cells[i - k]);
		
		std::cout << m << std::endl;
	}
	
	return 0;
}
