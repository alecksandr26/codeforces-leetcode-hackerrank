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
using namespace std;

// url = https://leetcode.com/problems/reverse-integer/

class Solution {
public:
	int reverse(int x) {
		int res, temp;
        
		res = 0;
		while (x != 0) {
			temp = x % 10;
			x /= 10;
			if (res > INT_MAX / 10 or (INT_MAX / 10 == res and temp > 7))
				return 0;
			if (res < INT_MIN / 10 or (INT_MIN / 10 == res and temp < -8))
				return 0;
            
			res = res * 10 + temp;
		}
        
		return res;
	}
};


