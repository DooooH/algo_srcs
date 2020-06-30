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

int boyer_moore(string s, string p)
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

		while (j >= 0 && (s[i + j] == p[j] || p[j] == '?'))
			j--;
		
		if (j < 0)
		{
			cnt++;
			i += (i + p_len < s_len) ? p_len - bad_char[s[i + p_len]] : 1;
		}
		else
			i += max(1, j - bad_char[s[i + j]]);
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
				cnt += boyer_moore(words[j], queries[i]);
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