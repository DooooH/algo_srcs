#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool find_exist(string pattern, vector<int> &word_table, vector<int> &pattern_table){
		for (int i = 0; i < pattern.size(); i++)
		{
			if (word_table[pattern[i]] < pattern_table[pattern[i]])
				return false;
		}
		return true;
	}
	
	void makepatterntable(vector<int> &pre_table, string word)
	{
		vector<int> table(256, 0);

		for (int i = 0; i < word.size(); i++)
		{
			table[word[i]]++;
		}

		for (int i = 0; i < word.size(); i++)
		{
			pre_table[word[i]] = max(table[word[i]], pre_table[word[i]]);
		}
	}

	vector<int> maketable(string word)
	{
		vector<int> table(256, 0);

		for (int i = 0; i < word.size(); i++)
		{
			table[word[i]]++;
		}
		return table;
	}
	
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		int j;
		vector<string> answers;
		vector<int> pattern_table(256, 0);

		for (int i = 0; i < B.size(); i++)
		{
			makepatterntable(pattern_table, B[i]);
		}

        for (int i = 0; i < A.size(); i++)
		{
			vector<int> word_table = maketable(A[i]);
			for (j = 'a'; j <= 'z'; j++)
			{
				if (word_table[j] < pattern_table[j])
					break ;
			}
			if (j == 'z' + 1)
				answers.push_back(A[i]);
		}
		return answers;
    }
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	Solution *sol = new Solution;

	vector<string> words = { "amazon","apple","facebook","google","leetcode"};
	vector<string> pattern = { "e","o"};
	vector<string> answers;

	answers = sol->wordSubsets(words, pattern);
	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << " ";
	}
	return 0;
}