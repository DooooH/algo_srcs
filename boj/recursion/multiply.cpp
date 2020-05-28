#include <bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long c)
{
	long long val;

	if (b == 1)
		return a % c;
	val = mul(a, b / 2, c);
	if (b % 2 == 0)
		val = val * val;
	else
		val = val * val % c * a;
	val = val % c;
	return val;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << mul(a, b, c);
	return 0;
}