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
	unsigned a, b, h;
	double A, T, h2;
	scanf("%u %u %u", &a, &b, &h);

	// Altura triangulo inferior
	h2 = (a * h) / (double) (b + a);
	
	// Area inferior
	A = (double) b * h2 / 2.0;
	T = (double) (a + b) * h / 2.0;

	printf("%0.9lf\n", ((T - 2.0 * A) / 2.0) - A);
	
	return 0;
}

