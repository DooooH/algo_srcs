#include <bits/stdc++.h>
using namespace std;

vector<int> makePi(string p)
{
	vector<int> Pi(p.size(), 0);
	int j = 0;
	for (int i = 1; i < p.size(); i++)
	{
		while (j > 0 && p[i] != p[j])
			j = Pi[j - 1];
		if (p[i] == p[j])
		{
			Pi[i] = ++j;
		}
	}
	return Pi;
}

int kmp(string s, string p)
{
	vector<int> pi = makePi(p);
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == p.size() - 1)
			{
				return 1;
			}
			j++;
		}
	}
	return 0;
}

int main()
{
	string words, pattern;

	getline(cin, words);
	getline(cin, pattern);
	if (kmp(words, pattern))
		cout << 1;
	else
		cout << 0;
	return 0;
}