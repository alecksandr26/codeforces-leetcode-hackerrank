#include <iostream>

/*
  url: https://codeforces.com/problemset/problem/1352/A
 */

int main(void)
{
	int n;
	
	std::cin >> n;
	
	unsigned int arr[n];

	for (unsigned int &num : arr)
		std::cin >> num;

	for (unsigned int &num : arr) {
		unsigned int mul = 10, output[6] = {0}; // 6 digits
		size_t c = 0;

		while (num > 0) {
			unsigned int mod = num % mul;
			if (mod)
				output[c++] = mod;
			mul *= 10;
			num -= mod;
		}
		std::cout << c << std::endl;
		for (size_t i = 0; i < c; i++)
			std::cout << output[i] << " ";
		std::cout << std::endl;
	}

	
	std::cout << std::endl;
	
	return 0;
}
