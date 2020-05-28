#include <bits/stdc++.h>
using namespace std;

typedef struct	s_print{
	int from;
	int target;
}				t_print;
vector<t_print> q;

int hanoi(int n, int from, int temp, int target, int &cnt)
{
	int precede;
	t_print print_struct;

	if (n == 1)
	{
		print_struct.from = from;
		print_struct.target = target;
		q.push_back(print_struct);
		cnt++;
		return 1;
	}
	precede = hanoi(n - 1, from, target, temp, cnt);
	print_struct.from = from;
	print_struct.target = target;
	q.push_back(print_struct);
	cnt++;
	return temp + 1 + hanoi(n - 1, temp, from, target, cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num, cnt = 0;

	cin >> num;
	hanoi(num, 1, 2, 3, cnt);
	cout << cnt << "\n";
	for (auto t: q)
		cout << t.from << " " << t.target << "\n";
	return 0;
}