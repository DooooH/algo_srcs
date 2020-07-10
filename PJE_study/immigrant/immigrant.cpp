#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void binary_min(vector<int> &V, int n, long long &min)
{
	long long start, end;
	long long mid;
	long long sum;

	sum = 0;
	start = 1;
	end = (long long)(*(V.end() - 1)) * n;
	min = end;
	while (start <= end)
	{
		sum = 0;
		mid = (start + end) / 2;
		for (unsigned int i = 0; i < V.size(); i++)
		{
			sum += mid / V[i];
		}
		if (sum < n)
			start = mid + 1;
		else if (sum >= n)
		{
			if (mid < min)
				min = mid;
			end = mid - 1;
		}
	}
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
	sort(times.begin(), times.end());
	binary_min(times, n, answer);
    return answer;
}

int main()
{
	vector<int> times = {7, 10};
	int n = 6;
	cout << solution(n, times) << "\n";
	return 0;
}