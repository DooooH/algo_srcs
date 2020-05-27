#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void binary_max(vector<int> &V, int M, long long &max)
{
	long long start, end;
	long long mid;
	long long sum;

	max = 0;
	sum = 0;
	start = 1;
	end = *(V.end() - 1);
	while (start <= end)
	{
		mid = (start + end) / 2;
		for (unsigned int i = 0; i < V.size(); i++)
		{
			if (V[i] <= mid)
				sum += V[i];
			else
			{
				sum += mid;
			}
		}
		if (sum == M)
		{
			max = mid;
			return ;
		}
		else if (sum > M)
		{
			end = mid - 1;
		}
		else if (sum < M)
		{
			start = mid + 1;
			if (max < mid)
				max = mid;
		}
		sum = 0;
	}
}

int solution(vector<int> budgets, int M) {
    long long answer = 0;
    sort(budgets.begin(), budgets.end());
    for (unsigned int i = 0; i < budgets.size(); i++)
    {
        answer += budgets[i];
    }
    if (answer <= M)
        return *(budgets.end() - 1);
    else
        answer = 0;
	binary_max(budgets, M, answer);
    return answer;
}

int main()
{
	vector<int> budgets = {120, 110, 140, 150};
	int M = 485;
	cout << solution(budgets, M) << "\n";
	return 0;
}