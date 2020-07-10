#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
		vector<int> vowels(s.size(), 0);
		int N = s.size();
		int gap = k;
		int start;
		int temp = 0;
		int max = 0;
		
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				vowels[i] = 1;
		}
		start = 0;
		for (int i = start; i < start + gap; i++)
		{
			temp += vowels[i];
		}
		max = temp;
		for (start = 1; start <= s.size() - gap; start++)
		{
			temp -= vowels[start - 1];
			temp += vowels[start + gap - 1];
			max = std::max(max, temp);
		}
		return max;
    }
};