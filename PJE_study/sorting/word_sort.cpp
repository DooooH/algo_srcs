#include <bits/stdc++.h>
using namespace std;

bool sort_dict(string a, string b)
{
	int i;

	i = 0;
	while (a[i] != 0 && b[i] != 0)
	{
		if (a[i] != b[i])
			return a[i] < b[i];
		i++;
	}
	return false;
}

bool compare(string a, string b)
{
	if (a.size() == b.size())
		return sort_dict(a, b);
	else
		return a.size() < b.size();
}

int main()
{
	int N;
	string temp;
	cin >> N;
	vector<string> words(N);
	for (int i = 0; i < N; i++)
	{
		cin >> words[i];
	}
	sort(words.begin(), words.end(), compare);

	// cout << "\n";
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1 && words[i].compare(words[i + 1]) == 0)
			continue ;
		cout << words[i] << "\n";
	}
	return 0;
}