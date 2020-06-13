#include <bits/stdc++.h>
using namespace std;
int minimum = -1;
stack<string> s;

bool is_convertable(string from, string to)
{
	int diff = 0;
	if (from.compare(to) == 0)
		return false;
	for (int i = 0; i < from.size(); i++)
	{
		if (from[i] != to[i])
		{
			if (diff == 0)
				diff = 1;
			else
				return false;
		}
	}
	return true;
}

void find_min(vector<int> visited, vector<string> words, string from, string target, int cnt)
{
	// string from;

	// if (s.empty())
	// 	return ;
	for (int i = 0; i < words.size(); i++)
	{
		if (from.compare(words[i]) != 0 && visited[i] == 0 && is_convertable(from, words[i]))
		{
			s.push(words[i]);
			visited[i] = 1;
		}
	}
	from = s.top();
	s.pop();
	cnt++;
	if (from.compare(target) == 0)
	{
		if (minimum == -1)
		{
			minimum = cnt;
		}
		else
			minimum = min(minimum, cnt);
		return ;
	}
	// while (!s.empty())
		find_min(visited, words, from, target, cnt);
}

int solution(string begin, string target, vector<string> words) {
	vector<int> visited(words.size(), 0);
    int answer = 0;
	int cnt = 0;
	bool is_exist = 0;

	for (auto t: words)
	{
		if (t == target)
		{
			is_exist = true;
			break ;
		}
	}
	if (!is_exist)
		return answer;
	// for (int i = 0; i < words.size(); i++)
	// {
	// 	if (begin.compare(words[i]) != 0 && visited[i] == 0 && is_convertable(begin, words[i]))
	// 	{
	// 		s.push(words[i]);
	// 		visited[i] = 1;
	// 	}
	// }
	find_min(visited, words, begin, target, cnt);
	answer = minimum;
    return answer;
}

int main()
{
	vector<std::string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout << solution("hit", "cog", words) << "\n"; 
	return 0;
}