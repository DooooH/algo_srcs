#include <bits/stdc++.h>
using namespace std;

void print_star(int N, int row, int col, int accumulate, int blank, int bound_row)
{
	int bound;
	int r, c;

	if (N == 1)
	{
		if (blank)
			cout << " ";
		else
			cout << "*";
		return ;
	}
	bound = N / 3;
	for (int i = 0; i < 9; i++)
	{
		r = i / 3;
		c = i % 3;
		if (bound_row != r)
			continue ;
		if (blank == 0 && i == 4)
		{
			blank = 1;
			print_star(N / 3, row + r * bound, col + c * bound, accumulate, blank, );
			blank = 0;
		}
		else
		{
			print_star(N / 3, row + r * bound, col + c * bound, accumulate, blank, i);
		}
		if (pow(3, accumulate) == N && i % 3 == 2)
			cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int accumulate = 0;
	int temp = 1;
	int N;
	int first_bound;
	cin >> N;
	while (temp != N)
	{
		temp *= 3;
		accumulate++;
	}
	cout << "accumulate: " << accumulate << "\n";
	first_bound = N;
	print_star(N, 0, 0, accumulate, 0, N);
	return 0;
}