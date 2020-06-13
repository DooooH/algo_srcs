#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
	int i;
	sort(citations.begin(), citations.end());
	for (i = citations.size() - 1; i >= 0; i--)
	{
		if (citations.size() - i >= citations[i])
		{
			answer = citations[i];
			break ;
		}
	}
	if (i == citations.size() - 1)
		return answer;
	while (answer < citations[i + 1] - 1 && citations.size() - i - 1 >= answer + 1)
		answer++;
    return answer;
}

int main()
{
	vector<int> citations  = {0, 1, 3, 5, 6, 10, 12};

	cout << solution(citations) << "\n"; 
	return 0;
}