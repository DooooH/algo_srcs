#include <iostream>
#include <vector>
using namespace std;

void merge_two(vector<int> &arr, int left, int right)
{
	int mid = (left + right) / 2;
	int front_idx = left;
	int rear_idx = mid + 1;

	vector<int> sorted;
	while (front_idx <= mid && rear_idx <= right)
	{
		if (arr[front_idx] <= arr[rear_idx])
			sorted.push_back(arr[front_idx++]);
		else
			sorted.push_back(arr[rear_idx++]);
	}

	if (front_idx > mid)
	{
		for (int i = rear_idx; i <= right; i++)
			sorted.push_back(arr[i]);
	}
	else
	{
		for (int i = front_idx; i <= mid; i++)
			sorted.push_back(arr[i]);
	}
	
	for(int i = left; i <= right; i++)
	{
		arr[i] = sorted[i - left];
	}
} 

void merge_sort(vector<int> &arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);

		merge_two(arr, left, right);
	}
}

int main()
{
	vector<int> arr = {3, 2 , 1, 5 , 7};
	merge_sort(arr, 0, arr.size() - 1);
	for (auto t : arr)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}
