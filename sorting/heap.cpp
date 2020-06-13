#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;

void heap(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
		min_heap.push(arr[i]);
	for (int i = 0; i < arr.size(); i++){
		arr[i] = min_heap.top();
		min_heap.pop();
	}	
}

int main()
{
	vector<int> arr = {3, 2 , 1, 5 , 7};
	heap(arr);
	for (auto t : arr)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}
