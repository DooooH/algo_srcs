#include <bits/stdc++.h>
using namespace std;

int greedy(vector<int> &A, int &K)
{
	int num = 0;
	int i = A.size() - 1;

	while (K > 0 && i >= 0)
	{
		num += K / A[i];
		K = K % A[i--];
	}
	return num;
}

int main()
{
	int N, K;

	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	cout << greedy(A, K) << "\n";
	return 0;
}