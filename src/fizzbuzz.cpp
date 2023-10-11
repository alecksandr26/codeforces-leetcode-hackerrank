#include <bits/stdc++.h>
#define st size_t
#define ll long long
#define ul unsigned long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define abs(a) (((a) > 0) ? (a) : -1 * (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define ENDL '\n'
template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
using namespace std;

int main(void)
{
	ios;
	
	
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0 && i % 5 == 0)
			cout << "FizzBuzz" << ENDL;
		else if (i % 5 == 0)
			cout << "Buzz" << ENDL;
		else if (i % 3 == 0)
			cout << "Fizz" << ENDL;
		else
			cout << i << ENDL;
	}
	
	
	return 0;
}

