#include <bits/stdc++.h>
using namespace std;
queue<int> q;

void BFS(vector<vector<int>> computers, vector<int> &visited)
{
	int front;

	while (!q.empty())
	{
		front = q.front();
		q.pop();
		// cout << front << "\n";
		for (int j = 0; j < computers[front].size(); j++)
		{
			// if (front == j)
			// 	continue ;
			if (computers[front][j] && visited[j] == 0)
			{
				q.push(j);
				visited[j] = 1;
			}
				// while (!q.empty())
				// {
				// 	cout << q.front() << " ";
				// 	q.pop();
				// }
				// cout << "\n";
		}
			// cout << "processing...\n";
	}
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
	vector<int> visited(n, 0);

	// for (auto t  :visited)
	// {
	// 	cout << t << " ";
	// }
	// cout << "\n";

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			q.push(i);
			visited[i] = 1;
			BFS(computers, visited);
			answer++;
		}
	}
    return answer;
}

int main()
{
	vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	// for (auto t : computers)
	// {
	// 	for (auto l : t)
	// 	{
	// 		cout << l << " ";
	// 	}
	// 	cout << "\n";
	// }
	cout << solution(3, computers) << "\n";
	return 0;
}