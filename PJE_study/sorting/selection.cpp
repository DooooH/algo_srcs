#include <iostream>
#include <vector>
using namespace std;

void selelction(vector<int> &arr)
{
	int min_idx;

	for (int i = 0; i < arr.size() - 1; i++){
		min_idx = i;
		for (int j = i + 1; j < arr.size(); j++){
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		if (i != min_idx)
			swap(arr[i], arr[min_idx]);
	}	
}

int main()
{
	vector<int> arr = {3, 2 , 1, 5 , 7};
	selelction(arr);
	for (auto t : arr)
	{
		cout << t << " ";
	}
	cout << "\n";
	return 0;
}
