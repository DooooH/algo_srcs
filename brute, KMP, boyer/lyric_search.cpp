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

int kmp(string s, string p)
{
	vector<int> pi = makePi(p);
	int j = 0;
	int cnt = 0;

	for (int i = 0; i < s.size(); i++)
	{
		while (j > 0 && p[j] != '?' && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j] || p[j] == '?')
		{
			if (j == p.size() - 1)
			{
				cnt++;
				j = pi[j];
			}
			else
				j++;
		}
	}
	return cnt;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
	int cnt;

	for (int i = 0; i < queries.size(); i++)
	{
		cnt = 0;
		for (int j = 0; j < words.size(); j++)
		{
			if (words[j].length() == queries[i].length())
				cnt += kmp(words[j], queries[i]);
		}
		answer.push_back(cnt);
	}
    return answer;
}

int main()
{
	vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
	vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
	
	vector<int> answer = solution(words, queries);
	for (auto t: answer)
	{
		cout << t << " ";
	}
}