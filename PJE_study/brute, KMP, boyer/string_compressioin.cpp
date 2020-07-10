#include <bits/stdc++.h>
using namespace std;

vector<string> compress(vector<string> substrings)
{
	vector<string> compressed;
	string temp;
	int cnt;

	for (int i = 0; i < substrings.size(); i++)
	{
		cnt = 1;
		temp = substrings[i];
		while (i < substrings.size() - 1 && substrings[i].compare(substrings[i + 1]) == 0)
		{
			cnt++;
			i++;
		}
		// cout << cnt << "\n";
		if (cnt != 1)
			compressed.push_back(to_string(cnt));
		compressed.push_back(temp);
	}
	// for(auto t : compressed)
	// 	{
	// 		cout << t;
	// 	}
	// 	cout << "\n";
	return compressed;
}

int solution(string s) {
    int answer = 0;
	int N = s.size();

	for (int gap = 1; gap <= N; gap++)
	{
		vector<string> substrings;
		int bound;
		int temp_len = 0;
		for (bound = 0; bound < N / gap; bound++)
			substrings.push_back(s.substr(gap * bound, gap));
		if (N % gap != 0)
			substrings.push_back(s.substr(gap * bound));
		vector<string> compressed = compress(substrings);
		if (answer == 0)
		{
			for (int i = 0; i < compressed.size(); i++)
				answer += compressed[i].size();
		}
		else
		{
			for (int i = 0; i < compressed.size(); i++)
				temp_len += compressed[i].size();
			answer = min(temp_len, answer);
		}
		// cout << "---------------------------\n";
		// cout << "gap : " << gap << "--------------\n";
		// for(auto t : compressed)
		// {
		// 	cout << t;
		// }
		// cout << "\n";
		// cout << "---------------------------\n";
	}
    return answer;
}

int main()
{
	cout << solution("xababcdcdababcdcd") << "\n";
	return 0;
}