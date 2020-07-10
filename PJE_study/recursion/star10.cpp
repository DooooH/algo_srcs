#include <bits/stdc++.h>
using namespace std;
char star[2187][2187];

void print_star(int N, int row, int col, int blank)
{
	int bound;
	int r, c;

	if (N == 1)
	{
		if (blank)
			star[row][col] = ' ';
		else
			star[row][col] = '*';
		return ;
	}
	bound = N / 3;
	// switch (bound_row)
	// {
	// case 0:
	// 	for (int i = 0; i < bound; i++)
	// 	{
	// 		print_star(N / 3, row, col, accumulate, blank, i);
	// 		print_star(N / 3, row, col + bound, accumulate, blank, i);
	// 		print_star(N / 3, row, col + 2 * bound, accumulate, blank, i);
	// 		if (pow(3, accumulate) == N)
	// 			cout << "\n";
	// 	}
	// 	break;
	// case 1:
	// 	for (int i = 0; i < bound; i++)
	// 	{
	// 		print_star(N / 3, row + bound, col, accumulate, blank, i);
	// 		print_star(N / 3, row + bound, col + bound, accumulate, 1, i);
	// 		print_star(N / 3, row + bound, col + 2 * bound, accumulate, blank, i);
	// 		if (pow(3, accumulate) == N)
	// 			cout << "\n";
	// 	}
	// 	break;
	// case 2:
	// 	for (int i = 0; i < bound; i++)
	// 	{
	// 		print_star(N / 3, row + 2 * bound, col, accumulate, blank, i);
	// 		print_star(N / 3, row + 2 * bound, col + bound, accumulate, blank, i);
	// 		print_star(N / 3, row + 2 * bound, col + 2 * bound, accumulate, blank, i);
	// 		if (pow(3, accumulate) == N)
	// 			cout << "\n";
	// 	}
	// 	break;
	// default:
	// 	break;
	// }
	for (int i = 0; i < 9; i++)
	{
		r = i / 3;
		c = i % 3;
		if (blank == 0 && i == 4)
		{
			blank = 1;
			print_star(N / 3, row + r * bound, col + c * bound, blank);
			blank = 0;
		}
		else
		{
			print_star(N / 3, row + r * bound, col + c * bound, blank);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	print_star(N, 0, 0, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << star[i][j];
		}
		cout << "\n";
	}
	return 0;
}