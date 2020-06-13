#include <iostream>
#include <vector>
using namespace std;

void count(vector<int> &arr, int max)
{
	int *f = new int[max + 1];
	int *sorted = new int[arr.size()];
	
	for (int i = 0; i < max + 1; i++)
		f[i] = 0;
	// for (int i = 0; i < arr.size(); i++)
	// 	sorted = 0;
	// vector<int> f(max + 1, 0);
	// vector<int> sorted(arr.size(), 0);

	for (int i = 0; i < arr.size(); i++)
		f[arr[i]]++;
	
	for (int i = 1; i <= max; i++)
		f[i] += f[i - 1];

	for (int i = arr.size() - 1; i>= 0; i--)
		sorted[--f[arr[i]]] = arr[i];

	for (int i = 0; i < arr.size(); i++)
		arr[i] = sorted[i];

	// delete[] f;
	// delete[] sorted;
}

int main()
{
	vector<int> arr = {3, 2 , 1, 5 , 7};
	count(arr, 10);
	for (auto t : arr)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}
