#include <bits/stdc++.h>
using namespace std;

vector<int> makePi(string p)
{
	vector<int> pi(p.size(), 0);
	int j = 0;

	for (int i = 1; i < p.size(); i++){
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
		{
			pi[i] = ++j;
		}
	}
	return pi;
}

int kmp(string s, string p, vector<int> &answers)
{
	vector<int> pi = makePi(p);
	int j = 0;
	int cnt = 0;

	for (int i = 0; i < s.size(); i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == p.size() - 1)
			{
				cnt++;
				answers.push_back(i - (p.size() - 1) + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return cnt;
}

int main()
{
	vector<int> answers;
	string s, p;
	getline(cin, s);
	getline(cin, p);
	cout << kmp(s, p, answers) << "\n";
	for (auto t: answers)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}