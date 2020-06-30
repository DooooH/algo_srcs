#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

bool cmp(vector<int> a, vector<int> b)
{
	return a[1] < b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    vector<vector<int>> answer;
	map<int, pair<int, int>> m;
	pair<int, int> temp;
	pair<int, pair<int, int>> m_temp;


	for (int i = 0; i < nodeinfo.size(); i++)
	{
		temp = make_pair(nodeinfo[i][0], nodeinfo[i][1]);
		m_temp = make_pair(i + 1, temp);
		m.insert(m_temp);
	}

	cout << (*max(answer.begin(), answer.end(), cmp))[1] << "\n";

	for (auto p : m)
	{
		cout << p.first << " / " << p.second.first << " " << p.second.second << "\n";
	}
    return answer;
}

int main()
{
	vector<vector<int>> nodeinfo = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
	solution(nodeinfo);
	return 0;
}