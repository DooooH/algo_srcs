#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int>> q;
int cnt = 0;

void BFS(vector<vector <int>> &paper, int &n, int &m)
{
	pair<int, int> temp;
	int r, c;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cnt++;
		r = temp.first;
		c = temp.second;
		if (c - 1 >= 0 && paper[r][c - 1] != -1 && paper[r][c - 1] == 1)
		{
			q.push(make_pair(r, c - 1));
			paper[r][c - 1] = -1;
		}
		if (r - 1 >= 0 && paper[r - 1][c] != -1 && paper[r - 1][c] == 1)
		{
			q.push(make_pair(r - 1, c));
			paper[r - 1][c] = -1;
		}
		if (c + 1 < m && paper[r][c + 1] != -1 && paper[r][c + 1] == 1)
		{
			q.push(make_pair(r, c + 1));
			paper[r][c + 1] = -1;
		}
		if (r + 1 < n && paper[r + 1][c] != -1 && paper[r + 1][c] == 1)
		{
			q.push(make_pair(r + 1, c));
			paper[r + 1][c] = -1;
		}
	}
}

int main()
{
	int n, m;
	int max = 0;
	int total = 0;
	cin >> n >> m;
	vector< vector<int>> paper(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (paper[i][j] != -1 && paper[i][j] == 1)
			{
				q.push(make_pair(i, j));
				paper[i][j] = -1;
				BFS(paper, n, m);
				max = std::max(max, cnt);
				cnt = 0;
				total++;
			}
		}
	}
	cout << total << "\n" << max << "\n";
	return 0;
}