#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		double temp = n;
		if (temp / 3 == floor(temp / 3))
		{
			if (isPowerOfThree(n / 3))
				return 1;
			else
				return 0;
		}
		return  0;
    }
};

int main()
{
	Solution *s = new Solution;
	cout << s->isPowerOfThree(27);
	return 0;
}