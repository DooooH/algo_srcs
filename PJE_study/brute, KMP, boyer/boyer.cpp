#include <bits/stdc++.h>
#define SIZE 256
using namespace std;

vector<int> preprocess_p(string p)
{
	vector<int> bad_char(SIZE , -1);
	char temp;

	for (int i = 0; i < p.size(); i++)
	{
		bad_char[p[i]] = i;
	}
	return bad_char;
}

int boyer_moore(string s, string p, vector<int> &answers)
{
	vector<int> bad_char = preprocess_p(p);
	int s_len = s.size();
	int p_len = p.size();
	int cnt = 0;
	int i = 0;
	int j;

	while (i <= (s_len - p_len))
	{ 
		j = p_len - 1;

		while (j >= 0 && s[i + j] == p[j])
			j--;
		
		if (j < 0)
		{
			cnt++;
			answers.push_back(i + 1);
			i += (i + p_len < s_len) ? p_len - bad_char[s[i + p_len]] : 1;
		}
		else
			i += max(1, j - bad_char[s[i + j]]);
	}
	return cnt;
}

int main()
{
	vector<int> answers;
	string s, p;
	getline(cin, s);
	getline(cin, p);
	cout << boyer_moore(s, p, answers) << "\n";
	for (auto t: answers)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}