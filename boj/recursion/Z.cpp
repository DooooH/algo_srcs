#include <bits/stdc++.h>
using namespace std;
int r,c;


void draw_z(int N, int row, int col, int &cnt, int &answer)
{
	int current_row;
	int current_col;
	int bound;

	if (N == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				current_row = row;
				current_col = col;
				break;
			case 1:
				current_row = row;
				current_col = col + 1;
				break;
			case 2:
				current_row = row + 1;
				current_col = col;
				break;
			case 3:
				current_row = row + 1;
				current_col = col + 1;
				break;
			default:
				break;
			}
			cnt++;
			if (current_row == r && current_col == c)
			{
				answer = cnt;
				return ;
			}
		}
		return ;
	}
	bound = pow(2, N - 1);
	if (r >= row + bound)
	{
		row = row + bound;
		cnt += 2 * bound * bound;
	}
	if (c >= col + bound)
	{
		col = col + bound;
		cnt += bound * bound;
	}
	draw_z(N - 1, row, col, cnt, answer);
	// for (int i = 0; i < 4; i++)
	// {
	// 	switch (i)
	// 	{
	// 	case 0:
	// 		draw_z(N - 1, row, col, cnt, answer);
	// 		break;
	// 	case 1:
	// 		draw_z(N - 1, row, col + bound, cnt, answer);
	// 		break;
	// 	case 2:
	// 		draw_z(N - 1, row + bound, col, cnt, answer);
	// 		break;
	// 	case 3:
	// 		draw_z(N - 1, row + bound, col + bound, cnt, answer);
	// 		break;
	// 	default:
	// 		break;
	// 	}
	// }
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int cnt = -1;
	int answer;

	cin >> N >> r >> c;
	draw_z(N, 0, 0, cnt, answer);
	cout << answer << "\n";
	return 0;
}